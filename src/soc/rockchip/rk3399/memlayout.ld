/* SPDX-License-Identifier: GPL-2.0-only */

#include <memlayout.h>
#include <arch/header.ld>

SECTIONS
{
	DRAM_START(0x00000000)
	BL31(0, 0x100000)
	POSTRAM_CBFS_CACHE(0x00100000, 8M)
	RAMSTAGE(0x00900000, 2M)
	DMA_COHERENT(0x10000000, 2M)

	/* 8K of special SRAM in PMU power domain. */
	SYMBOL(pmu_sram, 0xFF3B0000)
	WATCHDOG_TOMBSTONE(0xFF3B1FFC, 4)
	SYMBOL(epmu_sram, 0xFF3B2000)

	SRAM_START(0xFF8C0000)
#if ENV_RAMSTAGE
	REGION(bl31_sram, 0xFF8C0000, 64K, 1)
#else
	PRERAM_CBFS_CACHE(0xFF8C0000, 5K)
	FMAP_CACHE(0xFF8C1400, 2K)
	TIMESTAMP(0xFF8C1C00, 1K)
	/* 0xFF8C2004 is the entry point address the masked ROM will jump to. */
	OVERLAP_DECOMPRESSOR_VERSTAGE_ROMSTAGE(0xFF8C2004, 88K - 4)
	BOOTBLOCK(0xFF8D8000, 40K)
#endif
	VBOOT2_WORK(0XFF8E2000, 12K)
	TTB(0xFF8E5000, 24K)
	PRERAM_CBMEM_CONSOLE(0xFF8EB000, 8K)
	STACK(0xFF8ED000, 12K)
	SRAM_END(0xFF8F0000)
}
