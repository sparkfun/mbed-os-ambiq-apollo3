/* mbed Microcontroller Library
 * Copyright (c) 2006-2013 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "PeripheralPins.h"

/************RTC***************/
const PinMap PinMap_RTC[] = {
	{NC, 0, 0},
};

/************ADC***************/
const PinMap PinMap_ADC[] = {
	{NC, NC, 0}
};

/************DAC***************/
const PinMap PinMap_DAC[] = {
	{NC, NC, 0}
};

/************I2C***************/
const PinMap PinMap_I2C_SDA[] = {
	{NC, NC, 0}
};

const PinMap PinMap_I2C_SCL[] = {
	{NC, NC, 0}
};

/************UART***************/
const PinMap PinMap_UART_TX[] = {
	{1, UART_0, AM_HAL_PIN_1_UART0TX},
	{7, UART_0, AM_HAL_PIN_7_UART0TX},
	{16, UART_0, AM_HAL_PIN_16_UART0TX},
	{20, UART_0, AM_HAL_PIN_20_UART0TX},
	{22, UART_0, AM_HAL_PIN_22_UART0TX},
	{26, UART_0, AM_HAL_PIN_26_UART0TX},
	{28, UART_0, AM_HAL_PIN_28_UART0TX},
	{39, UART_0, AM_HAL_PIN_39_UART0TX},
	{41, UART_0, AM_HAL_PIN_41_UART0TX},
	{44, UART_0, AM_HAL_PIN_44_UART0TX},
	{48, UART_0, AM_HAL_PIN_48_UART0TX},
	{8, UART_1, AM_HAL_PIN_8_UART1TX},
	{10, UART_1, AM_HAL_PIN_10_UART1TX},
	{12, UART_1, AM_HAL_PIN_12_UART1TX},
	{14, UART_1, AM_HAL_PIN_14_UART1TX},
	{18, UART_1, AM_HAL_PIN_18_UART1TX},
	{20, UART_1, AM_HAL_PIN_20_UART1TX},
	{24, UART_1, AM_HAL_PIN_24_UART1TX},
	{39, UART_1, AM_HAL_PIN_39_UART1TX},
#if defined (AM_PACKAGE_BGA)
	{30, UART_0, AM_HAL_PIN_30_UART0TX},
	{35, UART_1, AM_HAL_PIN_35_UART1TX},
	{37, UART_1, AM_HAL_PIN_37_UART1TX},
	{42, UART_1, AM_HAL_PIN_42_UART1TX},
	{46, UART_1, AM_HAL_PIN_46_UART1TX},
#endif // defined (AM_PACKAGE_BGA)
	{NC, NC, 0}
};

const PinMap PinMap_UART_RX[] = {
	{2, UART_0, AM_HAL_PIN_2_UART0RX},
	{11, UART_0, AM_HAL_PIN_11_UART0RX},
	{17, UART_0, AM_HAL_PIN_17_UART0RX},
	{21, UART_0, AM_HAL_PIN_21_UART0RX},
	{23, UART_0, AM_HAL_PIN_23_UART0RX},
	{27, UART_0, AM_HAL_PIN_27_UART0RX},
	{29, UART_0, AM_HAL_PIN_29_UART0RX},
	{40, UART_0, AM_HAL_PIN_40_UART0RX},
	{49, UART_0, AM_HAL_PIN_49_UART0RX},
	{2, UART_1, AM_HAL_PIN_2_UART1RX},
	{4, UART_1, AM_HAL_PIN_4_UART1RX},
	{9, UART_1, AM_HAL_PIN_9_UART1RX},
	{13, UART_1, AM_HAL_PIN_13_UART1RX},
	{15, UART_1, AM_HAL_PIN_15_UART1RX},
	{19, UART_1, AM_HAL_PIN_19_UART1RX},
	{21, UART_1, AM_HAL_PIN_21_UART1RX},
	{25, UART_1, AM_HAL_PIN_25_UART1RX},
	{40, UART_1, AM_HAL_PIN_40_UART1RX},
	{47, UART_1, AM_HAL_PIN_47_UART1RX},
#if defined (AM_PACKAGE_BGA)
	{31, UART_0, AM_HAL_PIN_31_UART0RX},
	{34, UART_0, AM_HAL_PIN_34_UART0RX},
	{45, UART_0, AM_HAL_PIN_45_UART0RX},
	{36, UART_1, AM_HAL_PIN_36_UART1RX},
	{38, UART_1, AM_HAL_PIN_38_UART1RX},
	{43, UART_1, AM_HAL_PIN_43_UART1RX},
#endif // defined (AM_PACKAGE_BGA)
	{NC, NC, 0}
};

const PinMap PinMap_UART_RTS[] = {
	{3, UART_0, AM_HAL_PIN_3_UART0RTS},
	{5, UART_0, AM_HAL_PIN_5_UART0RTS},
	{13, UART_0, AM_HAL_PIN_13_UART0RTS},
	{18, UART_0, AM_HAL_PIN_18_UART0RTS},
	{41, UART_0, AM_HAL_PIN_41_UART0RTS},
	{10, UART_1, AM_HAL_PIN_10_UART1RTS},
	{16, UART_1, AM_HAL_PIN_16_UART1RTS},
	{20, UART_1, AM_HAL_PIN_20_UART1RTS},
	{41, UART_1, AM_HAL_PIN_41_UART1RTS},
	{44, UART_1, AM_HAL_PIN_44_UART1RTS},
#if defined (AM_PACKAGE_BGA)
	{34, UART_0, AM_HAL_PIN_34_UART0RTS},
	{35, UART_0, AM_HAL_PIN_35_UART0RTS},
	{37, UART_0, AM_HAL_PIN_37_UART0RTS},
	{30, UART_1, AM_HAL_PIN_30_UART1RTS},
	{31, UART_1, AM_HAL_PIN_31_UART1RTS},
	{34, UART_1, AM_HAL_PIN_34_UART1RTS},
#endif // defined (AM_PACKAGE_BGA)
	{NC, NC, 0}
};

const PinMap PinMap_UART_CTS[] = {
	{4, UART_0, AM_HAL_PIN_4_UART0CTS},
	{6, UART_0, AM_HAL_PIN_6_UART0CTS},
	{12, UART_0, AM_HAL_PIN_12_UART0CTS},
	{24, UART_0, AM_HAL_PIN_24_UART0CTS},
	{29, UART_0, AM_HAL_PIN_29_UART0CTS},
	{11, UART_1, AM_HAL_PIN_11_UART1CTS},
	{17, UART_1, AM_HAL_PIN_17_UART1CTS},
	{21, UART_1, AM_HAL_PIN_21_UART1CTS},
	{26, UART_1, AM_HAL_PIN_26_UART1CTS},
	{29, UART_1, AM_HAL_PIN_29_UART1CTS},
#if defined (AM_PACKAGE_BGA)
	{33, UART_0, AM_HAL_PIN_33_UART0CTS},
	{36, UART_0, AM_HAL_PIN_36_UART0CTS},
	{38, UART_0, AM_HAL_PIN_38_UART0CTS},
	{32, UART_1, AM_HAL_PIN_32_UART1CTS},
	{36, UART_1, AM_HAL_PIN_36_UART1CTS},
	{45, UART_1, AM_HAL_PIN_45_UART1CTS},
#endif // defined (AM_PACKAGE_BGA)
	{NC, NC, 0}
};

/************SPI***************/
const PinMap PinMap_SPI_SCLK[] = {
	{5, IOM_0, AM_HAL_PIN_5_M0SCK},
	{8, IOM_1, AM_HAL_PIN_8_M1SCK},
	{27, IOM_2, AM_HAL_PIN_27_M2SCK},
	{39, IOM_4, AM_HAL_PIN_39_M4SCK},
	{48, IOM_5, AM_HAL_PIN_48_M5SCK},
#if defined (AM_PACKAGE_BGA)
	{42, IOM_3, AM_HAL_PIN_42_M3SCK},
#endif // defined (AM_PACKAGE_BGA)
	{NC, NC, 0}
};

const PinMap PinMap_SPI_MOSI[] = {
	{7, IOM_0, AM_HAL_PIN_7_M0MOSI},
	{10, IOM_1, AM_HAL_PIN_10_M1MOSI},
	{28, IOM_2, AM_HAL_PIN_28_M2MOSI},
	{44, IOM_4, AM_HAL_PIN_44_M4MOSI},
	{47, IOM_5, AM_HAL_PIN_47_M5MOSI},
#if defined (AM_PACKAGE_BGA)
	{38, IOM_3, AM_HAL_PIN_38_M3MOSI},
#endif // defined (AM_PACKAGE_BGA)
	{NC, NC, 0}
};

const PinMap PinMap_SPI_MISO[] = {
	{6, IOM_0, AM_HAL_PIN_6_M0MISO},
	{9, IOM_1, AM_HAL_PIN_9_M1MISO},
	{25, IOM_2, AM_HAL_PIN_25_M2MISO},
	{40, IOM_4, AM_HAL_PIN_40_M4MISO},
	{49, IOM_5, AM_HAL_PIN_49_M5MISO},
#if defined (AM_PACKAGE_BGA)
	{43, IOM_3, AM_HAL_PIN_43_M3MISO},
#endif // defined (AM_PACKAGE_BGA)
	{NC, NC, 0}
};

const PinMap PinMap_SPI_SSEL[] = {
	{0, IOM_ANY, AM_HAL_PIN_0_NCE0},
	{1, IOM_ANY, AM_HAL_PIN_1_NCE1},
	{2, IOM_ANY, AM_HAL_PIN_2_NCE2},
	{3, IOM_ANY, AM_HAL_PIN_3_NCE3},
	{4, IOM_ANY, AM_HAL_PIN_4_NCE4},
	{7, IOM_ANY, AM_HAL_PIN_7_NCE7},
	{8, IOM_ANY, AM_HAL_PIN_8_NCE8},
	{9, IOM_ANY, AM_HAL_PIN_9_NCE9},
	{10, IOM_ANY, AM_HAL_PIN_10_NCE10},
	{11, IOM_ANY, AM_HAL_PIN_11_NCE11},
	{12, IOM_ANY, AM_HAL_PIN_12_NCE12},
	{13, IOM_ANY, AM_HAL_PIN_13_NCE13},
	{14, IOM_ANY, AM_HAL_PIN_14_NCE14},
	{15, IOM_ANY, AM_HAL_PIN_15_NCE15},
	{16, IOM_ANY, AM_HAL_PIN_16_NCE16},
	{17, IOM_ANY, AM_HAL_PIN_17_NCE17},
	{18, IOM_ANY, AM_HAL_PIN_18_NCE18},
	{19, IOM_ANY, AM_HAL_PIN_19_NCE19},
	{20, IOM_ANY, AM_HAL_PIN_20_NCE20},
	{21, IOM_ANY, AM_HAL_PIN_21_NCE21},
	{22, IOM_ANY, AM_HAL_PIN_22_NCE22},
	{23, IOM_ANY, AM_HAL_PIN_23_NCE23},
	{24, IOM_ANY, AM_HAL_PIN_24_NCE24},
	{25, IOM_ANY, AM_HAL_PIN_25_NCE25},
	{26, IOM_ANY, AM_HAL_PIN_26_NCE26},
	{27, IOM_ANY, AM_HAL_PIN_27_NCE27},
	{28, IOM_ANY, AM_HAL_PIN_28_NCE28},
	{29, IOM_ANY, AM_HAL_PIN_29_NCE29},
	{41, IOM_ANY, AM_HAL_PIN_41_NCE41},
	{44, IOM_ANY, AM_HAL_PIN_44_NCE44},
	{47, IOM_ANY, AM_HAL_PIN_47_NCE47},
	{48, IOM_ANY, AM_HAL_PIN_48_NCE48},
	{49, IOM_ANY, AM_HAL_PIN_49_NCE49},
#if defined (AM_PACKAGE_BGA)
	{30, IOM_ANY, AM_HAL_PIN_30_NCE30},
	{31, IOM_ANY, AM_HAL_PIN_31_NCE31},
	{32, IOM_ANY, AM_HAL_PIN_32_NCE32},
	{33, IOM_ANY, AM_HAL_PIN_33_NCE33},
	{34, IOM_ANY, AM_HAL_PIN_34_NCE34},
	{35, IOM_ANY, AM_HAL_PIN_35_NCE35},
	{36, IOM_ANY, AM_HAL_PIN_36_NCE36},
	{37, IOM_ANY, AM_HAL_PIN_37_NCE37},
	{38, IOM_ANY, AM_HAL_PIN_38_NCE38},
	{42, IOM_ANY, AM_HAL_PIN_42_NCE42},
	{43, IOM_ANY, AM_HAL_PIN_43_NCE43},
	{45, IOM_ANY, AM_HAL_PIN_45_NCE45},
	{46, IOM_ANY, AM_HAL_PIN_46_NCE46},
#endif // defined (AM_PACKAGE_BGA)
	{NC, NC, 0}
};

/************PWM***************/
const PinMap PinMap_PWM[] = {
	{NC, NC, 0}
};
