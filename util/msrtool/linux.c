/* SPDX-License-Identifier: GPL-2.0-only */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "msrtool.h"

static int msr_fd[MAX_CORES] = {-1, -1, -1, -1, -1, -1, -1, -1};

int linux_probe(const struct sysdef *system) {
	struct stat st;
	return 0 == stat("/dev/cpu/0/msr", &st);
}

int linux_open(uint8_t cpu, enum SysModes mode) {
	int fmode;
	char fn[32];
	switch (mode) {
	case SYS_RDWR:
		fmode = O_RDWR;
		break;
	case SYS_WRONLY:
		fmode = O_WRONLY;
		break;
	case SYS_RDONLY:
	default:
		fmode = O_RDONLY;
		break;
	}
	if (cpu >= MAX_CORES) {
		fprintf(stderr, "%s: only cores 0-%d are supported. requested=%d\n", __func__, MAX_CORES, cpu);
		return 0;
	}
	if (snprintf(fn, sizeof(fn), "/dev/cpu/%d/msr", cpu) == -1) {
		fprintf(stderr, "%s: snprintf: %s\n", __func__, strerror(errno));
		return 0;
	}
	msr_fd[cpu] = open(fn, fmode);
	if (-1 == msr_fd[cpu]) {
		fprintf(stderr, "open(%s): %s\n", fn, strerror(errno));
		return 0;
	}
	return 1;
}

int linux_close(uint8_t cpu) {
	int ret;
	if (cpu >= MAX_CORES) {
		fprintf(stderr, "%s: only cores 0-%d are supported. requested=%d\n", __func__, MAX_CORES, cpu);
		return 0;
	}
	ret = close(msr_fd[cpu]);
	msr_fd[cpu] = 0;
	return 0 == ret;
}

int linux_rdmsr(uint8_t cpu, uint32_t addr, struct msr *val) {
	struct msr tmp;
	if (lseek(msr_fd[cpu], addr, SEEK_SET) == -1) {
		SYSERROR(lseek, addr);
		return 0;
	}
	if (read(msr_fd[cpu], &tmp, 8) != 8) {
		SYSERROR(read, addr);
		return 0;
	}
	val->hi = tmp.lo;
	val->lo = tmp.hi;
	return 1;
}
