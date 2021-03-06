/* $NoKeywords:$ */
/**
 * @file
 *
 * AMD F15Tn Microcode patch.
 *
 * F15Tn Microcode Patch rev 0600111F for 6101/6131 or equivalent.
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:      AGESA
 * @e sub-project:  CPU/Family/0x15/TN
 * @e \$Revision: 334098 $   @e \$Date: 2018-03-05 14:21:15 -0600 (Mon, 05 Mar 2018) $
 */
/*****************************************************************************
 *
 * Copyright (c) 2008 - 2018, Advanced Micro Devices, Inc.
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
 ***************************************************************************/



/*----------------------------------------------------------------------------------------
 *                             M O D U L E S    U S E D
 *----------------------------------------------------------------------------------------
 */
#include "AGESA.h"
#include "Ids.h"
#include "cpuRegisters.h"
#include "cpuEarlyInit.h"
CODE_GROUP (G3_DXE)
RDATA_GROUP (G3_DXE)

/*----------------------------------------------------------------------------------------
 *                   D E F I N I T I O N S    A N D    M A C R O S
 *----------------------------------------------------------------------------------------
 */

/*----------------------------------------------------------------------------------------
 *                  T Y P E D E F S     A N D     S T R U C T U R E S
 *----------------------------------------------------------------------------------------
 */


// Encrypt Patch code 0600111F for 6101/6131 and equivalent

CONST UINT8 ROMDATA CpuF15TnMicrocodePatch0600111F_Enc [IDS_PAD_4K] =
{
  0x18, 0x20, 0x05, 0x03, 0x1f, 0x11, 0x00, 0x06,
  0x02, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xd0, 0xb7, 0x58, 0x1c, 0xca, 0xa2, 0xf2, 0x52,
  0x72, 0xa4, 0xe1, 0x1b, 0x37, 0xe0, 0x9f, 0xb3,
  0x58, 0xf4, 0x76, 0x85, 0x1a, 0x83, 0x4a, 0x89,
  0x78, 0x82, 0x4e, 0xf3, 0xa1, 0x6a, 0xb7, 0x56,
  0x93, 0xcb, 0xfa, 0x4c, 0x03, 0x6b, 0xec, 0xb5,
  0x4f, 0xc0, 0x7d, 0x46, 0x0e, 0x04, 0x96, 0xec,
  0xab, 0xc3, 0x74, 0x0c, 0x4b, 0x1c, 0x19, 0x1f,
  0x62, 0x89, 0x66, 0xe4, 0x63, 0x1f, 0x9f, 0x0b,
  0xd6, 0x35, 0x08, 0xd3, 0xa3, 0xee, 0xbd, 0xf6,
  0x6d, 0x98, 0x95, 0x28, 0x75, 0x18, 0xce, 0x98,
  0x6e, 0xf6, 0x5c, 0x71, 0xf5, 0xf0, 0xeb, 0x06,
  0x59, 0xf1, 0x40, 0x8e, 0x84, 0xfe, 0xf0, 0x49,
  0x23, 0x4b, 0xb4, 0x6f, 0x38, 0xa4, 0xd8, 0x09,
  0x9e, 0xbe, 0x63, 0x9b, 0x20, 0xf3, 0xf7, 0xc7,
  0x2c, 0x71, 0xfe, 0x6a, 0xd3, 0x98, 0xe0, 0x74,
  0xea, 0x8e, 0xd8, 0x3c, 0x42, 0x7b, 0x03, 0x2d,
  0x02, 0x28, 0xb0, 0x99, 0x0f, 0x16, 0x54, 0x31,
  0x08, 0x27, 0x27, 0xb7, 0x7c, 0x31, 0x95, 0x1b,
  0x20, 0xfc, 0x47, 0x3b, 0xc6, 0x20, 0x8e, 0xd0,
  0xe7, 0x97, 0x43, 0xb6, 0x83, 0x74, 0x12, 0x01,
  0x43, 0x70, 0xc5, 0x71, 0x37, 0xf9, 0x13, 0xa2,
  0x7c, 0x4f, 0x7c, 0xf1, 0x8f, 0xec, 0x8a, 0xeb,
  0xb6, 0x04, 0x33, 0x99, 0xdc, 0xa5, 0x32, 0x9e,
  0x5c, 0xad, 0x7b, 0xbe, 0x1b, 0x8d, 0x0d, 0x79,
  0xbd, 0x51, 0x1f, 0xc2, 0x8d, 0x50, 0x2f, 0xbf,
  0x8f, 0x66, 0xa6, 0x22, 0x65, 0x73, 0xc6, 0xe5,
  0xf5, 0x66, 0x48, 0xf5, 0x75, 0x1c, 0x73, 0xec,
  0x4f, 0xc6, 0xa9, 0x59, 0x80, 0xa7, 0x52, 0xe5,
  0x51, 0xbc, 0x27, 0x2f, 0x1b, 0x6e, 0x7f, 0xc7,
  0xf6, 0x0a, 0x17, 0x51, 0xb5, 0x27, 0x44, 0xf9,
  0x5c, 0x0d, 0xb7, 0x10, 0xfb, 0x52, 0x1a, 0x21,
  0x03, 0x93, 0xaf, 0x60, 0xe2, 0xc7, 0x18, 0xa9,
  0xf2, 0xe9, 0x93, 0x42, 0xd2, 0x3c, 0xdb, 0xdb,
  0xcf, 0x0d, 0xbe, 0x03, 0x72, 0x52, 0xb7, 0x3d,
  0x0f, 0xda, 0x7a, 0x57, 0xbe, 0x15, 0x54, 0x3f,
  0xfd, 0x26, 0xd9, 0x55, 0xc1, 0xeb, 0xa4, 0x12,
  0x73, 0xe3, 0xf0, 0x45, 0x71, 0x9a, 0xdb, 0x47,
  0x3b, 0x64, 0xee, 0x6c, 0xfe, 0x05, 0x54, 0xee,
  0x1c, 0x6b, 0xf5, 0x44, 0x6d, 0xd0, 0x6b, 0x39,
  0x1c, 0x87, 0xe7, 0x99, 0x69, 0x84, 0xff, 0x32,
  0xe7, 0xbf, 0x54, 0x68, 0xa1, 0x01, 0xf0, 0x38,
  0x3d, 0x94, 0x39, 0x07, 0xfd, 0x87, 0x1b, 0x87,
  0x36, 0x15, 0xed, 0x54, 0x0e, 0x58, 0xb2, 0xac,
  0x73, 0x7c, 0xe9, 0x6e, 0xcb, 0xea, 0x32, 0xd3,
  0x2b, 0x97, 0x1d, 0x6d, 0x40, 0x75, 0xe1, 0x6f,
  0xa5, 0x4d, 0xd7, 0xdc, 0x64, 0xba, 0x52, 0x02,
  0xc5, 0x71, 0xe6, 0x55, 0xc0, 0xc6, 0xe3, 0x3f,
  0x51, 0x8f, 0x02, 0xa8, 0x25, 0x8e, 0x82, 0x0e,
  0x32, 0xf8, 0x66, 0x85, 0x26, 0xba, 0x66, 0x80,
  0x2b, 0x9f, 0x8a, 0xb7, 0xb3, 0x61, 0x8e, 0xa3,
  0xa5, 0x43, 0xa0, 0x0a, 0x67, 0x57, 0xb4, 0x3a,
  0x3f, 0x87, 0x60, 0x11, 0xec, 0xe6, 0xbb, 0x85,
  0x56, 0x27, 0x46, 0x68, 0x73, 0xd6, 0xc0, 0x87,
  0xd3, 0xde, 0x51, 0xec, 0x21, 0x68, 0x0a, 0x91,
  0xa5, 0x91, 0x11, 0x76, 0xc8, 0x0e, 0x8a, 0xc0,
  0xa0, 0x7a, 0xb4, 0x82, 0xbf, 0x83, 0x18, 0xa0,
  0xd5, 0xe2, 0x28, 0xc5, 0x86, 0x9f, 0x18, 0x33,
  0xaa, 0x58, 0x40, 0x14, 0x55, 0x81, 0xb1, 0x4c,
  0xce, 0x09, 0xc4, 0x4d, 0x01, 0x7d, 0x15, 0x8b,
  0xba, 0xfd, 0x05, 0xa2, 0x43, 0xb4, 0xad, 0x33,
  0xdc, 0x0b, 0x59, 0x2b, 0x9b, 0xb2, 0x71, 0xaa,
  0x4c, 0x26, 0x33, 0x60, 0x4d, 0xb3, 0x53, 0x71,
  0xdb, 0xf7, 0x21, 0xbc, 0x4b, 0x13, 0xf8, 0x37,
  0xf5, 0x94, 0xb7, 0x46, 0x10, 0x9d, 0x58, 0x7b,
  0xb0, 0x4f, 0xd7, 0x56, 0x75, 0x6c, 0x23, 0x5a,
  0x68, 0x68, 0xa2, 0x53, 0x7f, 0x1f, 0x38, 0x6f,
  0x69, 0x3f, 0x95, 0x3e, 0x7b, 0x59, 0x23, 0x04,
  0xab, 0xa0, 0xd4, 0xa6, 0x7a, 0xfa, 0x94, 0xbb,
  0x94, 0x71, 0x83, 0xa9, 0xc3, 0xf1, 0x21, 0x69,
  0x01, 0xf0, 0x65, 0x57, 0x75, 0x28, 0xc2, 0xa9,
  0x75, 0x3c, 0x4f, 0xd8, 0xd3, 0xc6, 0xb6, 0xd7,
  0x26, 0xce, 0x0c, 0xb8, 0x64, 0x11, 0x59, 0x2c,
  0x7f, 0x81, 0x6e, 0xf9, 0x7e, 0xa3, 0x32, 0x24,
  0x42, 0xdb, 0xe0, 0x5e, 0x09, 0xda, 0x32, 0xf5,
  0xa1, 0x49, 0x0c, 0x0f, 0xd4, 0x4b, 0xe2, 0x30,
  0xc6, 0xa9, 0x77, 0xb0, 0x06, 0xaa, 0x71, 0x3b,
  0x8e, 0x57, 0xcb, 0x78, 0xcb, 0x16, 0x52, 0x31,
  0x7d, 0xc7, 0x6c, 0x9d, 0x63, 0xa7, 0x4c, 0x2b,
  0xab, 0x6f, 0xf8, 0xdc, 0x03, 0x85, 0x8e, 0x24,
  0x5a, 0xf6, 0x4c, 0xf7, 0x63, 0x34, 0x3c, 0xbc,
  0xff, 0x2b, 0xc7, 0xfc, 0x3c, 0xa0, 0x8a, 0xb4,
  0x8a, 0x8c, 0x52, 0x53, 0xa2, 0x8f, 0xf3, 0xdc,
  0x19, 0x74, 0x83, 0x96, 0x70, 0x9e, 0x9a, 0x47,
  0x5d, 0xc7, 0x93, 0xd4, 0x74, 0x0b, 0xed, 0xdc,
  0x4f, 0x25, 0xa2, 0xe0, 0x4c, 0x8c, 0x1c, 0x7f,
  0x90, 0xd6, 0xa4, 0x92, 0xde, 0x63, 0xd7, 0x93,
  0x96, 0x2e, 0xbb, 0x62, 0x9b, 0x64, 0x16, 0x7d,
  0x44, 0x1b, 0xd0, 0xd0, 0xe7, 0xa3, 0x37, 0x53,
  0xb0, 0xd5, 0x08, 0xe5, 0x35, 0x8c, 0x5b, 0x7a,
  0xbb, 0xcb, 0x70, 0xe2, 0x38, 0x96, 0xc1, 0x5c,
  0x94, 0xd5, 0xc4, 0x51, 0x59, 0x3a, 0x7f, 0x3c,
  0xf9, 0x50, 0x52, 0x9b, 0x8e, 0x6c, 0x3a, 0x46,
  0x9e, 0xf5, 0xbc, 0x17, 0xd5, 0x12, 0x11, 0xcd,
  0xe8, 0xd0, 0xd6, 0x5b, 0xbc, 0xd1, 0x8f, 0x66,
  0x62, 0xa6, 0x35, 0xcb, 0x19, 0x24, 0x14, 0xb6,
  0x87, 0xf5, 0x3d, 0x53, 0xe7, 0xf3, 0x4a, 0xbf,
  0xd1, 0x57, 0xad, 0x0f, 0x78, 0x8b, 0x95, 0x1f,
  0x2d, 0x80, 0x89, 0xc8, 0x78, 0xa7, 0x65, 0x3d,
  0x9d, 0x39, 0x7c, 0x68, 0x0e, 0x39, 0xfe, 0x8e,
  0xcb, 0x26, 0xc0, 0x61, 0x40, 0x18, 0x67, 0x29,
  0x72, 0xa8, 0xfe, 0x26, 0x54, 0x15, 0x19, 0x3d,
  0xb2, 0x39, 0x67, 0x73, 0xc2, 0x9d, 0x5e, 0x5e,
  0x0d, 0x59, 0x6a, 0x2f, 0x99, 0xb2, 0x92, 0x13,
  0xd1, 0xc4, 0xf3, 0x21, 0x08, 0x93, 0xc1, 0x87,
  0x15, 0xac, 0x9b, 0xfb, 0x85, 0xda, 0xea, 0x92,
  0xaf, 0xa1, 0x33, 0x0b, 0x31, 0x46, 0xa9, 0x51,
  0xe9, 0xe8, 0xda, 0x48, 0x8d, 0xe9, 0xf2, 0x12,
  0xbf, 0x80, 0x00, 0x49, 0x57, 0x49, 0xb2, 0x7d,
  0x8b, 0x08, 0x7e, 0x0d, 0xb9, 0x67, 0xd2, 0x0c,
  0x52, 0x18, 0x6f, 0xa2, 0xbb, 0x5b, 0x69, 0x79,
  0xb4, 0x4a, 0x75, 0x17, 0x60, 0x19, 0xce, 0xbf,
  0xce, 0x78, 0xb2, 0x09, 0x53, 0x9d, 0x58, 0x37,
  0x7b, 0x2b, 0x29, 0x92, 0x9b, 0x2d, 0x56, 0x1a,
  0x11, 0xa4, 0x30, 0xae, 0xf2, 0xae, 0x54, 0x75,
  0x1b, 0xb8, 0xb0, 0xbb, 0x2f, 0x78, 0xfc, 0xc5,
  0xa9, 0x79, 0x98, 0x4c, 0xb4, 0x2f, 0x30, 0xe8,
  0xce, 0xaf, 0x6e, 0x67, 0x22, 0x24, 0x66, 0x72,
  0xb6, 0xc3, 0xf4, 0x6c, 0x72, 0x2f, 0x1d, 0xa6,
  0x48, 0x25, 0xba, 0x8d, 0x3c, 0x13, 0x76, 0x1d,
  0x3d, 0xb7, 0xd5, 0xbf, 0x0b, 0x8b, 0x71, 0x71,
  0x05, 0x7b, 0x95, 0xa3, 0x6b, 0x9f, 0x99, 0xb6,
  0xfd, 0x68, 0x73, 0x56, 0xbb, 0x65, 0x6e, 0xbc,
  0x4f, 0xa3, 0x79, 0x32, 0xc9, 0xc7, 0xb4, 0x09,
  0xd3, 0x35, 0x3b, 0x5c, 0x74, 0x54, 0x6d, 0xd0,
  0x5d, 0x0f, 0xb4, 0xb0, 0x1d, 0x96, 0xef, 0xf6,
  0x95, 0xe2, 0x12, 0xd8, 0xb0, 0x7b, 0xd7, 0xf9,
  0x6c, 0x9d, 0xc4, 0x8b, 0xe6, 0xb1, 0xc2, 0x41,
  0x4b, 0xbd, 0xd5, 0x3d, 0xcb, 0xc1, 0x02, 0x49,
  0xd1, 0x05, 0x70, 0x58, 0x95, 0x42, 0x24, 0xc7,
  0x0a, 0xa7, 0x1c, 0x3f, 0x12, 0x6d, 0x36, 0x14,
  0xc6, 0xdf, 0x6b, 0x88, 0x3e, 0x69, 0x7f, 0xa1,
  0xcf, 0x27, 0xa6, 0x7f, 0x30, 0xdb, 0xef, 0x1d,
  0xdd, 0x71, 0xe9, 0xc3, 0x50, 0x34, 0xf1, 0x15,
  0xf9, 0xa1, 0x7d, 0x64, 0x51, 0x94, 0xf7, 0x70,
  0xc6, 0x28, 0xa4, 0x23, 0xbf, 0x03, 0xd9, 0x90,
  0x6e, 0x2b, 0x22, 0x02, 0x95, 0xc2, 0x1f, 0xbf,
  0x33, 0x57, 0x54, 0x6e, 0x00, 0x3b, 0xce, 0xf2,
  0x74, 0x33, 0x6d, 0x1b, 0x6e, 0x84, 0x51, 0xc0,
  0xef, 0xa7, 0x4d, 0xa9, 0x49, 0x3a, 0x2a, 0x11,
  0x45, 0xbd, 0xbf, 0xac, 0xa1, 0xed, 0x03, 0x4f,
  0x0b, 0x36, 0xda, 0x73, 0x51, 0xec, 0x48, 0xa4,
  0xa0, 0x9a, 0x5e, 0xa3, 0x57, 0x96, 0xf4, 0xe9,
  0x2f, 0x52, 0xa1, 0x49, 0x3f, 0xe1, 0x3e, 0xe3,
  0x2e, 0x67, 0x77, 0x96, 0xe5, 0xbd, 0x63, 0x55,
  0x88, 0xdf, 0x69, 0xc6, 0x44, 0xf8, 0xb8, 0xa4,
  0x92, 0x9d, 0x15, 0x00, 0xe8, 0xdb, 0xf0, 0xd0,
  0x64, 0x31, 0xfb, 0x36, 0x4f, 0x50, 0x18, 0x8c,
  0xe1, 0x48, 0x3f, 0xbe, 0x3d, 0xaa, 0xae, 0x4c,
  0x34, 0xb7, 0xb1, 0x44, 0x0f, 0x2e, 0xa3, 0xa6,
  0xd7, 0xe3, 0x71, 0xe3, 0x9c, 0xe1, 0xc9, 0x2a,
  0xbd, 0x65, 0x94, 0x01, 0xbf, 0x29, 0x1b, 0x77,
  0x02, 0x47, 0xef, 0x7f, 0x41, 0xc7, 0x81, 0xa3,
  0xbf, 0x27, 0x2c, 0x85, 0x72, 0x10, 0x65, 0x40,
  0x53, 0x36, 0x0d, 0x40, 0x82, 0x78, 0x9c, 0x1f,
  0xa9, 0x03, 0x74, 0x3f, 0xd6, 0xbc, 0x16, 0xdc,
  0x78, 0x54, 0x72, 0x5d, 0x5c, 0xe5, 0x0d, 0xa5,
  0x56, 0x4f, 0x62, 0xa3, 0x83, 0x9f, 0x3b, 0xd6,
  0xa6, 0xc6, 0x63, 0x7f, 0xdc, 0x09, 0x21, 0x08,
  0x88, 0xfb, 0x34, 0xad, 0xcb, 0x7e, 0x67, 0x8d,
  0x68, 0xf2, 0x87, 0xdf, 0xb7, 0xb8, 0xe6, 0xe8,
  0xe5, 0x9c, 0x1e, 0xa5, 0xb4, 0x44, 0x27, 0x73,
  0x41, 0x5e, 0x12, 0x7a, 0x0c, 0x98, 0x3f, 0xc4,
  0x95, 0x77, 0x9f, 0x24, 0x89, 0x0a, 0xc8, 0xa4,
  0x7d, 0xfd, 0xa5, 0xbb, 0x3a, 0x87, 0x67, 0x43,
  0x75, 0x3f, 0x52, 0x75, 0x78, 0x4c, 0x13, 0xe1,
  0x7b, 0xad, 0x2c, 0x47, 0xa3, 0x15, 0x79, 0xbf,
  0x8e, 0x03, 0x51, 0xf4, 0xe7, 0x7d, 0x35, 0x16,
  0x03, 0x0c, 0x31, 0xf2, 0x87, 0x2b, 0x89, 0xb9,
  0xa2, 0x8a, 0xe8, 0xc2, 0x8b, 0x59, 0xde, 0xee,
  0x50, 0x17, 0x41, 0x56, 0xf9, 0x2f, 0x32, 0xcd,
  0x92, 0xfc, 0x1d, 0x14, 0xed, 0xe0, 0x6f, 0x2c,
  0xd5, 0x7c, 0xac, 0x7e, 0x6a, 0xbf, 0x8b, 0x48,
  0x94, 0xbb, 0x13, 0x2d, 0x49, 0x3e, 0xf1, 0x83,
  0x98, 0x8d, 0xb6, 0x30, 0x24, 0xcd, 0xaa, 0xd3,
  0x4a, 0xe1, 0xdd, 0xfd, 0x50, 0xdd, 0x63, 0x0f,
  0x70, 0xd6, 0x9e, 0x71, 0xe5, 0xa9, 0x8b, 0x40,
  0x62, 0x73, 0x8b, 0x81, 0xb6, 0x3c, 0x17, 0x9c,
  0x56, 0xc0, 0xd3, 0x75, 0x1a, 0x86, 0xa8, 0x13,
  0x75, 0xa0, 0xac, 0x56, 0xc8, 0x7f, 0xe2, 0x32,
  0xcb, 0x20, 0xe7, 0x98, 0xb7, 0x48, 0x83, 0xae,
  0x9b, 0x70, 0xc0, 0x50, 0xed, 0xa4, 0x8c, 0xc4,
  0x25, 0xae, 0x6a, 0xdf, 0x1a, 0xcd, 0x48, 0x06,
  0x80, 0x78, 0xed, 0xa4, 0xcc, 0x51, 0x8b, 0x40,
  0xa4, 0x05, 0xd3, 0xe6, 0x43, 0x5a, 0x77, 0x98,
  0x0e, 0xc6, 0x96, 0xdd, 0x72, 0x2c, 0x83, 0x43,
  0x0d, 0x09, 0x76, 0x79, 0xf9, 0xe7, 0xcb, 0xdd,
  0x48, 0xf3, 0x2e, 0xf8, 0x7c, 0xa2, 0xdd, 0xcc,
  0xe6, 0x97, 0x50, 0x9e, 0x73, 0x3d, 0x5f, 0x66,
  0xae, 0xeb, 0x05, 0x5c, 0xc9, 0xae, 0xc1, 0x89,
  0x23, 0x31, 0x1e, 0xfd, 0x89, 0xca, 0x7e, 0x87,
  0x16, 0xca, 0xff, 0x8d, 0x40, 0xb6, 0x1c, 0xad,
  0xd2, 0x0c, 0xa4, 0xcd, 0x26, 0x89, 0x22, 0x75,
  0x4d, 0xb3, 0x85, 0xf4, 0xc1, 0xaf, 0x7d, 0x0f,
  0x06, 0x40, 0x48, 0x2b, 0xba, 0x21, 0x5d, 0x41,
  0xfb, 0x38, 0xae, 0x6a, 0x6e, 0x1d, 0x83, 0xfb,
  0xb3, 0x50, 0x32, 0xf7, 0xb8, 0x2f, 0x3f, 0xcc,
  0x15, 0x9c, 0x04, 0x52, 0x0b, 0x07, 0xec, 0x56,
  0x13, 0x38, 0x9f, 0x7f, 0x89, 0xe3, 0xff, 0x13,
  0xe1, 0xbf, 0x32, 0x94, 0xa8, 0x2c, 0x0c, 0xb1,
  0x8d, 0xb9, 0x66, 0xa6, 0x43, 0xab, 0x2a, 0xd7,
  0xd0, 0xcd, 0x15, 0xf3, 0x92, 0xd0, 0x37, 0xa9,
  0x7e, 0x88, 0xd6, 0x5e, 0x9d, 0x09, 0xe0, 0x0d,
  0x22, 0x30, 0x1a, 0x38, 0xfe, 0xd8, 0x4a, 0x9a,
  0x19, 0x30, 0x85, 0x49, 0x3c, 0x3a, 0x20, 0x8b,
  0xcb, 0x83, 0x3f, 0x6b, 0xa4, 0x6c, 0x03, 0x35,
  0xd5, 0x3c, 0x7d, 0x36, 0x90, 0xb0, 0x2b, 0xf5,
  0x74, 0x3a, 0xc9, 0x2f, 0xdb, 0x30, 0x1c, 0x6d,
  0x12, 0x54, 0x95, 0x99, 0x91, 0xbd, 0x25, 0x40,
  0xd2, 0x08, 0x76, 0x9e, 0x1b, 0x17, 0x3c, 0xaf,
  0x61, 0x91, 0x17, 0x09, 0x0c, 0x28, 0x47, 0x58,
  0x07, 0xed, 0xac, 0x77, 0x00, 0xf7, 0x1d, 0x30,
  0xd7, 0xab, 0x47, 0xe3, 0x93, 0x88, 0xe9, 0xb6,
  0x35, 0x52, 0xe5, 0x97, 0x13, 0x4b, 0xb6, 0x60,
  0x67, 0x9c, 0xbf, 0xbd, 0x22, 0x8f, 0x12, 0xec,
  0x42, 0x9c, 0xc2, 0x40, 0x51, 0xa4, 0xd5, 0x04,
  0x8b, 0xfc, 0x0f, 0xf0, 0x52, 0xe5, 0x07, 0x0c,
  0xd5, 0xc9, 0x83, 0xc4, 0x60, 0x01, 0xd0, 0x2e,
  0x84, 0x90, 0xd7, 0xd2, 0x18, 0x87, 0xce, 0x6e,
  0x54, 0xbe, 0xbf, 0x8a, 0x51, 0xa8, 0x86, 0x6b,
  0xeb, 0x09, 0xc8, 0xd1, 0xcc, 0xa9, 0x5e, 0x36,
  0xd5, 0x36, 0xff, 0xb1, 0xf4, 0x00, 0x90, 0xf7,
  0xb4, 0x8b, 0x88, 0x83, 0xba, 0x5d, 0x01, 0x5c,
  0x25, 0x74, 0x4b, 0xb8, 0x93, 0x28, 0xa1, 0xe2,
  0x68, 0xa5, 0x9d, 0xe6, 0x40, 0xc3, 0xf1, 0x7e,
  0x29, 0x30, 0x18, 0xb3, 0x54, 0xa3, 0x43, 0x80,
  0xba, 0xa7, 0x92, 0x74, 0xb2, 0xd1, 0x76, 0xac,
  0xbd, 0x39, 0x0f, 0x09, 0x2a, 0xf5, 0xa2, 0x5a,
  0x41, 0x9f, 0x82, 0xa2, 0xef, 0x70, 0x6c, 0x62,
  0x85, 0xee, 0x2e, 0xc0, 0x10, 0x80, 0xc7, 0x2c,
  0x9a, 0x4a, 0xc3, 0xf2, 0x73, 0x8d, 0x69, 0xf5,
  0xfb, 0x2f, 0x35, 0x2d, 0xe9, 0xa8, 0x8c, 0x6b,
  0xa4, 0x0c, 0x8b, 0xa8, 0x96, 0xea, 0x66, 0xfc,
  0xeb, 0x9d, 0xe5, 0xb4, 0x31, 0xf9, 0xf1, 0x05,
  0x67, 0x2e, 0x97, 0x04, 0x00, 0xa7, 0x6c, 0xa3,
  0x41, 0x76, 0x76, 0x0b, 0x5f, 0xd3, 0x5e, 0xc9,
  0xf4, 0xac, 0x6f, 0x19, 0x68, 0x5b, 0xdb, 0x08,
  0x13, 0x2b, 0x1b, 0x5a, 0x05, 0xd8, 0x43, 0xc4,
  0x34, 0x7f, 0x13, 0x06, 0x4d, 0x49, 0x95, 0xb1,
  0xa3, 0xa2, 0x1a, 0x58, 0xf6, 0x84, 0x19, 0x1c,
  0x5a, 0x89, 0x62, 0xe0, 0xf3, 0xd6, 0x00, 0x03,
  0x79, 0xca, 0xc8, 0x4a, 0x30, 0xeb, 0x3f, 0xaf,
  0x29, 0x47, 0x1f, 0xa1, 0xef, 0x57, 0x98, 0x25,
  0xc9, 0xa0, 0xe9, 0x8b, 0xc2, 0x69, 0xf9, 0xa1,
  0x4f, 0x89, 0x2a, 0x70, 0xdf, 0x17, 0xf6, 0xfe,
  0xd2, 0xb6, 0xcb, 0x5e, 0x7c, 0xad, 0x9c, 0x9c,
  0xc3, 0x07, 0x0c, 0x70, 0x8d, 0xe0, 0xd4, 0x31,
  0x56, 0xfb, 0xb1, 0xa3, 0x1b, 0x90, 0x63, 0x9e,
  0x1e, 0x16, 0x5b, 0xd6, 0x33, 0xb7, 0x7e, 0xd3,
  0xd8, 0xf0, 0x62, 0x79, 0xce, 0xca, 0x50, 0x43,
  0x40, 0xc2, 0x41, 0xc6, 0xcd, 0x16, 0xa6, 0xc1,
  0x12, 0x0b, 0x28, 0xa1, 0x9a, 0xc2, 0xda, 0xfd,
  0x3f, 0x3a, 0xb9, 0xfe, 0xbc, 0x13, 0x3c, 0x75,
  0xc8, 0x36, 0x87, 0x29, 0xfe, 0x29, 0xb6, 0xf9,
  0x50, 0x17, 0xa8, 0xc8, 0x9c, 0x88, 0x6d, 0x44,
  0xfa, 0xa0, 0xeb, 0xa9, 0xdf, 0x50, 0x13, 0x15,
  0x70, 0xa1, 0x0b, 0x63, 0xed, 0x33, 0x97, 0x71,
  0xb6, 0xd1, 0xc3, 0xf0, 0x59, 0xf5, 0x18, 0xd3,
  0xb8, 0x79, 0xaa, 0x97, 0x42, 0x3f, 0x62, 0x66,
  0xf7, 0x04, 0x3d, 0x0f, 0x05, 0x5a, 0xbc, 0x08,
  0x0d, 0xec, 0x6c, 0x99, 0x30, 0x22, 0x16, 0x3d,
  0x93, 0x35, 0xee, 0x06, 0x0e, 0x17, 0x70, 0xb2,
  0x97, 0x88, 0x79, 0x91, 0x1b, 0x47, 0xb7, 0xdd,
  0x5c, 0x68, 0x0c, 0x50, 0xf2, 0x09, 0xe2, 0xaa,
  0x37, 0xc7, 0x9b, 0x47, 0xf7, 0x1b, 0x74, 0x46,
  0x95, 0x49, 0x5b, 0xf3, 0x50, 0x34, 0xfa, 0xf7,
  0x99, 0x27, 0x96, 0x5b, 0x7b, 0xd8, 0x3e, 0x3a,
  0x4a, 0xc2, 0x9a, 0x85, 0x07, 0x94, 0xc6, 0xdf,
  0x92, 0x40, 0x3c, 0xe2, 0x3b, 0x4c, 0x39, 0xe7,
  0x41, 0x8a, 0x4c, 0x95, 0x07, 0x0b, 0x26, 0x0e,
  0x45, 0x07, 0x73, 0xaf, 0x1f, 0x53, 0xe8, 0xc2,
  0x1e, 0x98, 0xb9, 0xd1, 0x34, 0xa7, 0xbe, 0x73,
  0xa7, 0x61, 0xcb, 0x1e, 0x42, 0xed, 0xe1, 0x20,
  0xfd, 0x2c, 0x85, 0x0f, 0x18, 0x21, 0xf6, 0x06,
  0xf3, 0x6d, 0x84, 0xff, 0xa4, 0xaa, 0x6b, 0xdd,
  0xbe, 0x55, 0x29, 0x8e, 0x4d, 0x81, 0xc1, 0x30,
  0x05, 0xf5, 0x1d, 0x69, 0x56, 0xa7, 0x0d, 0x72,
  0x10, 0xd0, 0x68, 0x27, 0x96, 0xda, 0x2e, 0xc0,
  0xd6, 0x6f, 0xc5, 0x41, 0xe7, 0xf6, 0xed, 0xc4,
  0xd9, 0xf3, 0x56, 0x40, 0x0b, 0xdb, 0x55, 0xda,
  0x5f, 0x95, 0x30, 0x53, 0x3c, 0xe5, 0xfd, 0x9f,
  0x69, 0xa1, 0x82, 0xa2, 0x2f, 0x07, 0x88, 0xf3,
  0x4a, 0xbc, 0xe7, 0xe0, 0xa3, 0x6f, 0xc6, 0x1e,
  0x56, 0x0c, 0xff, 0xe7, 0x8f, 0xf0, 0xa8, 0xf2,
  0x41, 0x34, 0x19, 0x7f, 0x5c, 0x4a, 0xd1, 0x30,
  0xc3, 0xfb, 0x24, 0xdf, 0x0c, 0xd8, 0x30, 0x54,
  0x1d, 0xad, 0xa3, 0x45, 0x9e, 0xae, 0x97, 0xc2,
  0x9f, 0xf7, 0x7b, 0x4d, 0x66, 0x8f, 0xcc, 0x86,
  0x29, 0x8d, 0xc5, 0x87, 0x61, 0x16, 0x97, 0x19,
  0x6f, 0xf7, 0x63, 0x37, 0xb1, 0x6e, 0x19, 0x04,
  0x20, 0x6f, 0x31, 0x09, 0x24, 0xf3, 0x61, 0x42,
  0x2b, 0x92, 0x44, 0x91, 0x42, 0x7f, 0xe3, 0x0d,
  0xba, 0xfb, 0x7f, 0x33, 0x88, 0xe8, 0x71, 0x25,
  0xf2, 0xbb, 0xd5, 0x25, 0x58, 0xd3, 0x2e, 0x38,
  0x4f, 0x57, 0x70, 0x32, 0xa5, 0x59, 0xe4, 0x02,
  0xbb, 0x33, 0x75, 0x35, 0xb5, 0xe1, 0x0d, 0xcd,
  0x46, 0x0f, 0x6d, 0x86, 0xd3, 0x8f, 0x1e, 0xe5,
  0xa5, 0x8b, 0x9a, 0xa7, 0x4c, 0x0b, 0xca, 0x9a,
  0x64, 0x6e, 0x2f, 0xab, 0x9f, 0x21, 0xd6, 0x8d,
  0x6b, 0x29, 0x6a, 0x78, 0xa8, 0x4c, 0x15, 0x3d,
  0x8c, 0x3b, 0xac, 0xc6, 0x70, 0xeb, 0x41, 0xbe,
  0x41, 0x74, 0x9b, 0xe5, 0x87, 0xa3, 0x1c, 0xbe,
  0x47, 0x6e, 0x2d, 0x92, 0xbe, 0x80, 0xb4, 0x92,
  0xcc, 0x9e, 0x0b, 0x05, 0x75, 0xab, 0x9b, 0x76,
  0xd1, 0xde, 0x22, 0x32, 0x78, 0x69, 0xfb, 0x1b,
  0xe8, 0x4d, 0x49, 0x97, 0x23, 0xeb, 0x51, 0x38,
  0x9a, 0x22, 0xa7, 0xc0, 0xcf, 0x25, 0x3a, 0x4e,
  0x50, 0x0d, 0xff, 0x8e, 0xb5, 0x91, 0xd3, 0x85,
  0x54, 0xe9, 0x1f, 0x70, 0xea, 0x64, 0x6a, 0x77,
  0xbe, 0xd2, 0x15, 0xce, 0x9c, 0xb0, 0x70, 0x61,
  0x8b, 0x58, 0xdb, 0x9f, 0x0a, 0xe4, 0x80, 0xb3,
  0x21, 0x44, 0x0b, 0xea, 0x43, 0xab, 0x0d, 0xf0,
  0x7e, 0xbc, 0xd5, 0xde, 0x29, 0x12, 0xcd, 0xde,
  0xd9, 0xf3, 0xf3, 0x0e, 0xf4, 0xb8, 0x3d, 0xd7,
  0x4e, 0x24, 0xcf, 0x9b, 0x4b, 0xad, 0x96, 0x1e,
  0xca, 0x6d, 0x3f, 0x9c, 0xe4, 0xb8, 0x8b, 0xf5,
  0x3a, 0x43, 0xb0, 0xce, 0x16, 0x27, 0x87, 0xe3,
  0x1b, 0x54, 0xd0, 0xed, 0x3c, 0xe2, 0xb0, 0x1f,
  0x24, 0xa3, 0x6d, 0x31, 0x00, 0x7d, 0x58, 0x69,
  0xc9, 0xc6, 0x50, 0xc8, 0x87, 0xac, 0x45, 0x54,
  0x66, 0x06, 0x7f, 0xc3, 0x51, 0xb8, 0xdf, 0x51
};

/*----------------------------------------------------------------------------------------
 *           P R O T O T Y P E S     O F     L O C A L     F U N C T I O N S
 *----------------------------------------------------------------------------------------
 */

/*----------------------------------------------------------------------------------------
 *                          E X P O R T E D    F U N C T I O N S
 *----------------------------------------------------------------------------------------
 */
