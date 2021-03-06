/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef CPU_SAMSUNG_EXYNOS5250_PERIPH_H
#define CPU_SAMSUNG_EXYNOS5250_PERIPH_H

/*
 * Peripherals requiring clock/pinmux configuration. List will
 * grow with support for more devices getting added.
 *
 * At present the order is arbitrary - we may be able to take advantage
 * of some orthogonality later.
 */
enum periph_id {
	PERIPH_ID_UART0,
	PERIPH_ID_UART1,
	PERIPH_ID_UART2,
	PERIPH_ID_UART3,
	PERIPH_ID_SDMMC0,
	PERIPH_ID_SDMMC1,
	PERIPH_ID_SDMMC2,
	PERIPH_ID_SDMMC3,

	PERIPH_ID_SROMC = 9,
	PERIPH_ID_SPI0,
	PERIPH_ID_SPI1,
	PERIPH_ID_SPI2,
	PERIPH_ID_SPI3,
	PERIPH_ID_SPI4,
	PERIPH_ID_LCD,
	PERIPH_ID_BACKLIGHT,
	PERIPH_ID_I2C0,
	PERIPH_ID_I2C1,
	PERIPH_ID_I2C2,
	PERIPH_ID_I2C3,
	PERIPH_ID_I2C4,
	PERIPH_ID_I2C5,
	PERIPH_ID_I2C6,
	PERIPH_ID_I2C7,
	PERIPH_ID_DPHPD,	/* eDP hot plug detect */
	PERIPH_ID_PWM0,
	PERIPH_ID_PWM1,
	PERIPH_ID_PWM2,
	PERIPH_ID_PWM3,
	PERIPH_ID_PWM4,
	PERIPH_ID_I2S1,
	PERIPH_ID_SATA,

	PERIPH_ID_COUNT,
	PERIPH_ID_NONE = -1,
};

#endif
