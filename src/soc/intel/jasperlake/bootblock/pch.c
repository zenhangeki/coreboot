/* SPDX-License-Identifier: GPL-2.0-only */

#include <console/console.h>
#include <console/post_codes.h>
#include <device/mmio.h>
#include <device/device.h>
#include <device/pci_ops.h>
#include <intelblocks/fast_spi.h>
#include <intelblocks/gspi.h>
#include <intelblocks/lpc_lib.h>
#include <intelblocks/p2sb.h>
#include <intelblocks/pcr.h>
#include <intelblocks/pmclib.h>
#include <intelblocks/rtc.h>
#include <soc/bootblock.h>
#include <soc/espi.h>
#include <soc/iomap.h>
#include <soc/p2sb.h>
#include <soc/pch.h>
#include <soc/pci_devs.h>
#include <soc/pcr_ids.h>
#include <soc/pm.h>

#define PCR_PSF3_TO_SHDW_PMC_REG_BASE	0xA00

#define PCR_PSFX_TO_SHDW_BAR0	0
#define PCR_PSFX_TO_SHDW_BAR1	0x4
#define PCR_PSFX_TO_SHDW_BAR2	0x8
#define PCR_PSFX_TO_SHDW_BAR3	0xC
#define PCR_PSFX_TO_SHDW_BAR4	0x10
#define PCR_PSFX_TO_SHDW_PCIEN_IOEN	0x01
#define PCR_PSFX_T0_SHDW_PCIEN	0x1C

#define PCR_DMI_DMICTL		0x2234
#define  PCR_DMI_DMICTL_SRLOCK	(1 << 31)

#define PCR_DMI_ACPIBA		0x27B4
#define PCR_DMI_ACPIBDID	0x27B8
#define PCR_DMI_PMBASEA		0x27AC
#define PCR_DMI_PMBASEC		0x27B0

#define PCR_DMI_LPCIOD		0x2770
#define PCR_DMI_LPCIOE		0x2774

static void soc_config_pwrmbase(void)
{
	/*
	 * Assign Resources to PWRMBASE
	 * Clear BIT 1-2 Command Register
	 */
	pci_and_config16(PCH_DEV_PMC, PCI_COMMAND, ~(PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER));

	/* Program PWRM Base */
	pci_write_config32(PCH_DEV_PMC, PWRMBASE, PCH_PWRM_BASE_ADDRESS);

	/* Enable Bus Master and MMIO Space */
	pci_or_config16(PCH_DEV_PMC, PCI_COMMAND, (PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER));

	/* Enable PWRM in PMC */
	setbits32((void *) PCH_PWRM_BASE_ADDRESS + ACTL, PWRM_EN);
}

void bootblock_pch_early_init(void)
{
	fast_spi_early_init(SPI_BASE_ADDRESS);
	gspi_early_bar_init();
	p2sb_enable_bar();
	p2sb_configure_hpet();

	/*
	 * Enabling PWRM Base for accessing
	 * Global Reset Cause Register.
	 */
	soc_config_pwrmbase();
}

static void soc_config_acpibase(void)
{
	uint32_t pmc_reg_value;
	uint32_t pmc_base_reg = PCR_PSF3_TO_SHDW_PMC_REG_BASE;

	pmc_reg_value = pcr_read32(PID_PSF3, pmc_base_reg + PCR_PSFX_TO_SHDW_BAR4);

	if (pmc_reg_value != 0xffffffff) {
		/* Disable Io Space before changing the address */
		pcr_rmw32(PID_PSF3, pmc_base_reg + PCR_PSFX_T0_SHDW_PCIEN,
				~PCR_PSFX_TO_SHDW_PCIEN_IOEN, 0);
		/* Program ABASE in PSF3 PMC space BAR4*/
		pcr_write32(PID_PSF3, pmc_base_reg + PCR_PSFX_TO_SHDW_BAR4,
				ACPI_BASE_ADDRESS);
		/* Enable IO Space */
		pcr_rmw32(PID_PSF3, pmc_base_reg + PCR_PSFX_T0_SHDW_PCIEN,
				~0, PCR_PSFX_TO_SHDW_PCIEN_IOEN);
	}
}

static int pch_check_decode_enable(void)
{
	uint32_t dmi_control;

	/*
	 * This cycle decoding is only allowed to set when
	 * DMICTL.SRLOCK is 0.
	 */
	dmi_control = pcr_read32(PID_DMI, PCR_DMI_DMICTL);
	if (dmi_control & PCR_DMI_DMICTL_SRLOCK)
		return -1;
	return 0;
}

void pch_early_iorange_init(void)
{
	uint16_t io_enables = LPC_IOE_SUPERIO_2E_2F | LPC_IOE_KBC_60_64 |
		LPC_IOE_EC_62_66 | LPC_IOE_LGE_200;

	/* IO Decode Range */
	if (CONFIG(DRIVERS_UART_8250IO))
		lpc_io_setup_comm_a_b();

	/* IO Decode Enable */
	if (pch_check_decode_enable() == 0) {
		io_enables = lpc_enable_fixed_io_ranges(io_enables);
		/*
		 * Set ESPI IO Enables PCR[DMI] + 2774h [15:0] to the same
		 * value programmed in ESPI PCI offset 82h.
		 */
		pcr_write16(PID_DMI, PCR_DMI_LPCIOE, io_enables);
		/*
		 * Set LPC IO Decode Ranges PCR[DMI] + 2770h [15:0] to the same
		 * value programmed in LPC PCI offset 80h.
		 */
		pcr_write16(PID_DMI, PCR_DMI_LPCIOD, lpc_get_fixed_io_decode());
	}

	/* Program generic IO Decode Range */
	pch_enable_lpc();
}

void bootblock_pch_init(void)
{
	/*
	 * Enabling ABASE for accessing PM1_STS, PM1_EN, PM1_CNT,
	 * GPE0_STS, GPE0_EN registers.
	 */
	soc_config_acpibase();

	/* Set up GPE configuration */
	pmc_gpe_init();

	enable_rtc_upper_bank();
}
