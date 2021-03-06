/* SPDX-License-Identifier: GPL-2.0-or-later */

#ifndef __SOC_STONEYRIDGE_ACPI_H__
#define __SOC_STONEYRIDGE_ACPI_H__

#include <acpi/acpi.h>

#if CONFIG(STONEYRIDGE_LEGACY_FREE)
	#define FADT_BOOT_ARCH ACPI_FADT_LEGACY_FREE
#else
	#define FADT_BOOT_ARCH (ACPI_FADT_LEGACY_DEVICES | ACPI_FADT_8042)
#endif

unsigned long southbridge_write_acpi_tables(const struct device *device,
		unsigned long current, struct acpi_rsdp *rsdp);

const char *soc_acpi_name(const struct device *dev);

#endif /* __SOC_STONEYRIDGE_ACPI_H__ */
