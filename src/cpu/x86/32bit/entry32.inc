/* SPDX-License-Identifier: GPL-2.0-only */

/* For starting coreboot in protected mode */

#include <arch/rom_segs.h>
#include <cpu/x86/post_code.h>
#include <arch/x86/gdt_init.S>

	.code32
/*
 *	When we come here we are in protected mode. We expand
 *	the stack and copies the data segment from ROM to the
 *	memory.
 *
 *	After that, we call the chipset bootstrap routine that
 *	does what is left of the chipset initialization.
 *
 *	NOTE aligned to 4 so that we are sure that the prefetch
 *	cache will be reloaded.
 *
 *	In the bootblock there is already a ljmp to __protected_start and
 *	the reset vector jumps to symbol _start16bit in entry16.inc from
 *	the reset vectors's symbol which is _start. Therefore, don't
 *	expose the _start symbol for bootblock.
 */
	.align	4
#if !ENV_BOOTBLOCK
.globl _start
_start:
#endif

	lgdt	%cs:gdtptr
	ljmp	$ROM_CODE_SEG, $__protected_start

__protected_start:
	/* Save the BIST value */
	movl	%eax, %ebp

#if !CONFIG(NO_EARLY_BOOTBLOCK_POSTCODES)
	post_code(POST_ENTER_PROTECTED_MODE)
#endif

	movw	$ROM_DATA_SEG, %ax
	movw	%ax, %ds
	movw	%ax, %es
	movw	%ax, %ss
	movw	%ax, %fs
	movw	%ax, %gs

	/* Restore the BIST value to %eax */
	movl	%ebp, %eax
