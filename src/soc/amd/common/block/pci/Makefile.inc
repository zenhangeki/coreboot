
ramstage-$(CONFIG_SOC_AMD_COMMON_BLOCK_PCI) += amd_pci_util.c

bootblock-y += amd_pci_mmconf.c
verstage_x86-y += amd_pci_mmconf.c
romstage-y += amd_pci_mmconf.c
postcar-y += amd_pci_mmconf.c
ramstage-y += amd_pci_mmconf.c
