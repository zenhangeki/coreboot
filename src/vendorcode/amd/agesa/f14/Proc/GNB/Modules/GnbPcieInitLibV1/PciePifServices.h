/* $NoKeywords:$ */
/**
 * @file
 *
 * PCIe PIF initialization routine
 *
 *
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:     AGESA
 * @e sub-project: GNB
 * @e \$Revision: 34897 $   @e \$Date: 2010-07-13 19:07:10 -0700 (Tue, 13 Jul 2010) $
 *
 */
/*
 *****************************************************************************
 *
 * Copyright (c) 2011, Advanced Micro Devices, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Advanced Micro Devices, Inc. nor the names of
 *       its contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ADVANCED MICRO DEVICES, INC. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ***************************************************************************
 *
 */

#ifndef _PCIEPIFSERVICES_H_
#define _PCIEPIFSERVICES_H_

VOID
PciePifApplyGanging (
  IN      PCIe_WRAPPER_CONFIG   *Wrapper,
  IN      PCIe_PLATFORM_CONFIG  *Pcie
  );

VOID
PciePifPllPowerDown (
  IN      UINT32                LaneBitmap,
  IN      PCIe_WRAPPER_CONFIG   *Wrapper,
  IN      PCIe_PLATFORM_CONFIG  *Pcie
  );

VOID
PciePifPllInitForDdi (
  IN      PCIe_WRAPPER_CONFIG   *Wrapper,
  IN      PCIe_PLATFORM_CONFIG  *Pcie
  );

VOID
PciePollPifForCompeletion (
  IN      PCIe_WRAPPER_CONFIG   *Wrapper,
  IN      PCIe_PLATFORM_CONFIG  *Pcie
  );

VOID
PciePifDisableFifoReset (
  IN      PCIe_WRAPPER_CONFIG   *Wrapper,
  IN      PCIe_PLATFORM_CONFIG  *Pcie
  );

VOID
PciePifSetLs2ExitTime (
  IN      PCIe_WRAPPER_CONFIG   *Wrapper,
  IN      PCIe_PLATFORM_CONFIG  *Pcie
  );

VOID
PciePifSetRxDetectPowerMode (
  IN      PCIe_WRAPPER_CONFIG   *Wrapper,
  IN      PCIe_PLATFORM_CONFIG  *Pcie
  );

VOID
PciePifSetPllRampTime (
  IN      PCIE_PLL_RAMPUP_TIME  Rampup,
  IN      PCIe_WRAPPER_CONFIG   *Wrapper,
  IN      PCIe_PLATFORM_CONFIG  *Pcie
  );

VOID
PciePifPllPowerControl (
  IN      PCIE_PIF_POWER_CONTROL  Control,
  IN      PCIe_WRAPPER_CONFIG     *Wrapper,
  IN      PCIe_PLATFORM_CONFIG    *Pcie
  );

#endif
