/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef __STONEYRIDGE_CPU_H__
#define __STONEYRIDGE_CPU_H__

/*
 *  Set a variable MTRR in bootblock and/or romstage.  AGESA will use the lowest
 *  numbered registers.  Any values defined below are subtracted from the
 *  highest numbered registers.
 *
 *  todo: Revisit this once AGESA no longer programs MTRRs.
 */
#define SOC_EARLY_VMTRR_FLASH 1
#define SOC_EARLY_VMTRR_CAR_HEAP 2
#define SOC_EARLY_VMTRR_TEMPRAM 3

void check_mca(void);

#endif /* __STONEYRIDGE_CPU_H__ */
