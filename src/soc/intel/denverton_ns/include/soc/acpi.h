/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef _DENVERTON_NS_ACPI_H_
#define _DENVERTON_NS_ACPI_H_

#include <acpi/acpi.h>
#include <soc/nvs.h>

void acpi_create_serialio_ssdt(acpi_header_t *ssdt);
unsigned long acpi_madt_irq_overrides(unsigned long current);
unsigned long southcluster_write_acpi_tables(const struct device *device,
					     unsigned long current,
					     struct acpi_rsdp *rsdp);
void southcluster_inject_dsdt(const struct device *device);

#endif /* _DENVERTON_NS_ACPI_H_ */
