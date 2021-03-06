/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef PSP_VERSTAGE_PSP_TRANSFER_H
#define PSP_VERSTAGE_PSP_TRANSFER_H

# if (CONFIG_CMOS_RECOVERY_BYTE != 0)
#  define CMOS_RECOVERY_BYTE CONFIG_CMOS_RECOVERY_BYTE
# elif CONFIG(VBOOT_STARTS_BEFORE_BOOTBLOCK)
#  error "Must set CONFIG_CMOS_RECOVERY_BYTE"
# endif

#define CMOS_RECOVERY_MAGIC_VAL	0x96

#define TRANSFER_INFO_SIZE		64
#define TIMESTAMP_BUFFER_SIZE		0x200

#define TRANSFER_MAGIC_VAL		0x50544953

/* Area for things that would cause errors in a linker script */
#if !defined(__ASSEMBLER__)
#include <stdint.h>

struct transfer_info_struct {
	uint32_t	magic_val;		/* Identifier */
	uint32_t	struct_bytes;		/* Size of this structure */
	uint32_t	buffer_size;		/* Size of the transfer buffer area */

	/* Offsets from start of transfer buffer */
	uint32_t	workbuf_offset;
	uint32_t	console_offset;
	uint32_t	timestamp_offset;
	uint32_t	fmap_offset;
	uint32_t	unused[9];		/* Pad to 64 bytes */
};

_Static_assert(sizeof(struct transfer_info_struct) == TRANSFER_INFO_SIZE, \
		"TRANSFER_INFO_SIZE is incorrect");
#endif

#endif	/* PSP_VERSTAGE_PSP_TRANSFER_H */
