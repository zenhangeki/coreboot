/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef _COREBOOT_SRC_MAINBOARD_GOOGLE_TROGDOR_BOARD_H_
#define _COREBOOT_SRC_MAINBOARD_GOOGLE_TROGDOR_BOARD_H_

#include <boardid.h>
#include <gpio.h>
#include <soc/gpio.h>

#define GPIO_EC_IN_RW	GPIO(118)
#define GPIO_AP_EC_INT	GPIO(94)
#define GPIO_H1_AP_INT	(CONFIG(TROGDOR_REV0) ? GPIO(21) : GPIO(42))
#define GPIO_SD_CD_L	GPIO(69)
#define GPIO_AMP_ENABLE	GPIO(23)

/* Display specific GPIOS */
#define GPIO_BACKLIGHT_ENABLE  GPIO(12)
#define GPIO_EDP_BRIDGE_ENABLE (CONFIG(TROGDOR_REV0) ? GPIO(14) : GPIO(104))
#define GPIO_EN_PP3300_DX_EDP  (CONFIG(TROGDOR_REV0) ? GPIO(106) : GPIO(30))

void setup_chromeos_gpios(void);

#endif /* _COREBOOT_SRC_MAINBOARD_GOOGLE_TROGDOR_BOARD_H_ */
