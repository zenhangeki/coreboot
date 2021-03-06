/* SPDX-License-Identifier: GPL-2.0-only */

#include <acpi/acpi.h>

#define SDCARD_CD 81 /* Not used */

DefinitionBlock(
	"dsdt.aml",
	"DSDT",
	0x02,		/* DSDT revision: ACPI v2.0 and up */
	OEM_ID,
	ACPI_TABLE_CREATOR,
	0x20110725	/* OEM revision */
)
{
	#include <acpi/platform.asl>

	/* global NVS and variables */
	#include <acpi/globalnvs.asl>

	#include <cpu/intel/common/acpi/cpu.asl>

	Scope (\_SB) {
		Device (PCI0)
		{
			#include <acpi/southcluster.asl>
		}
	}

	#include <southbridge/intel/common/acpi/sleepstates.asl>
}
