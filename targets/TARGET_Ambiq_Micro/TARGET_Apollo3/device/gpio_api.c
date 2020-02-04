/*
Copyright (c) 2019 SparkFun Electronics

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "mbed_assert.h"
#include "gpio_api.h"

/** Set the given pin as GPIO
 *
 * @param pin The pin to be set as GPIO
 * @return The GPIO port mask for this pin
 **/
uint32_t gpio_set(PinName pin){
    MBED_ASSERT(pin != (PinName)NC);
    return (uint32_t)AM_HAL_GPIO_BIT(pin);
}

/** Checks if gpio object is connected (pin was not initialized with NC)
 * @param obj The GPIO object
 * @return 0 if object was initialized with NC
 * @return non-zero if object was initialized with a valid PinName
 **/
int gpio_is_connected(const gpio_t *obj){
    MBED_ASSERT(obj != NULL);
    return (int)(((PinName)obj->pad == (PinName)NC) ? 0 : 1);
}

/** Initialize the GPIO pin
 *
 * @param obj The GPIO object to initialize
 * @param pin The GPIO pin to initialize (may be NC)
 */
void gpio_init(gpio_t *obj, PinName pin){
    MBED_ASSERT(obj != NULL);
    obj->pad = (ap3_uart_pad_t)pin;
    return;
}

/** Set the input pin mode
 *
 * @param obj  The GPIO object (must be connected)
 * @param mode The pin mode to be set
 */
void gpio_mode(gpio_t *obj, PinMode mode){
    MBED_ASSERT(gpio_is_connected(obj));
    MBED_ASSERT(mode < (PinMode)PinModeElements);

    obj->cfg.uFuncSel = 3; // gpio

    if( mode & (PinMode)PowerSwNone ){ obj->cfg.ePowerSw = AM_HAL_GPIO_PIN_POWERSW_NONE; }
    if( mode & (PinMode)PowerSwVDD ){ obj->cfg.ePowerSw = AM_HAL_GPIO_PIN_POWERSW_VDD; }
    if( mode & (PinMode)PowerSwVSS ){ obj->cfg.ePowerSw = AM_HAL_GPIO_PIN_POWERSW_VSS; }

    if( mode & (PinMode)PullNone ){ obj->cfg.ePullup = AM_HAL_GPIO_PIN_PULLUP_NONE; }
    if( mode & (PinMode)PullUp ){ obj->cfg.ePullup = AM_HAL_GPIO_PIN_PULLUP_WEAK; }
    if( mode & (PinMode)PullDown ){ obj->cfg.ePullup = AM_HAL_GPIO_PIN_PULLDOWN; }

    if( mode & (PinMode)DriveStrength2mA ){ obj->cfg.eDriveStrength = AM_HAL_GPIO_PIN_DRIVESTRENGTH_2MA; }
    if( mode & (PinMode)DriveStrength4mA ){ obj->cfg.eDriveStrength = AM_HAL_GPIO_PIN_DRIVESTRENGTH_4MA; }
    if( mode & (PinMode)DriveStrength8mA ){ obj->cfg.eDriveStrength = AM_HAL_GPIO_PIN_DRIVESTRENGTH_8MA; }
    if( mode & (PinMode)DriveStrength12mA ){ obj->cfg.eDriveStrength = AM_HAL_GPIO_PIN_DRIVESTRENGTH_12MA; }

    if( mode & (PinMode)OutDisable ){ obj->cfg.eGPOutcfg = AM_HAL_GPIO_PIN_OUTCFG_DISABLE; }
    if( mode & (PinMode)OutPushPull ){ obj->cfg.eGPOutcfg = AM_HAL_GPIO_PIN_OUTCFG_PUSHPULL; }
    if( mode & (PinMode)OutOpenDrain ){ obj->cfg.eGPOutcfg = AM_HAL_GPIO_PIN_OUTCFG_OPENDRAIN; }
    if( mode & (PinMode)OutTristate ){ obj->cfg.eGPOutcfg = AM_HAL_GPIO_PIN_OUTCFG_TRISTATE; }

    if( mode & (PinMode)InAuto ){ obj->cfg.eGPInput = AM_HAL_GPIO_PIN_INPUT_AUTO; }
    if( mode & (PinMode)InNone ){ obj->cfg.eGPInput = AM_HAL_GPIO_PIN_INPUT_NONE; }
    if( mode & (PinMode)InEnable ){ obj->cfg.eGPInput = AM_HAL_GPIO_PIN_INPUT_ENABLE; }

    if( mode & (PinMode)ReadPin ){ obj->cfg.eGPRdZero = AM_HAL_GPIO_PIN_RDZERO_READPIN; }
    if( mode & (PinMode)ReadZero ){ obj->cfg.eGPRdZero = AM_HAL_GPIO_PIN_RDZERO_ZERO; }

    am_hal_gpio_pinconfig((uint32_t)(obj->pad), obj->cfg); // apply configuration
}

/** Set the pin direction
 *
 * @param obj       The GPIO object (must be connected)
 * @param direction The pin direction to be set
 */
void gpio_dir(gpio_t *obj, PinDirection direction){
    MBED_ASSERT(gpio_is_connected(obj));
    MBED_ASSERT(direction < (PinDirection)PIN_DIR_ELEMENTS);

    if( direction == (PinDirection)PIN_INPUT ){
        obj->cfg.eGPInput = AM_HAL_GPIO_PIN_INPUT_ENABLE;
        obj->cfg.eGPOutcfg = AM_HAL_GPIO_PIN_OUTCFG_DISABLE;
    }
    else if ( direction == (PinDirection)PIN_OUTPUT ){
        obj->cfg.eGPOutcfg = AM_HAL_GPIO_PIN_OUTCFG_PUSHPULL;
        obj->cfg.eDriveStrength = AM_HAL_GPIO_PIN_DRIVESTRENGTH_12MA;
        obj->cfg.eGPInput = AM_HAL_GPIO_PIN_INPUT_ENABLE;
        obj->cfg.eGPRdZero = AM_HAL_GPIO_PIN_RDZERO_READPIN;
    }else{
        MBED_ASSERT(false);
    }

    am_hal_gpio_pinconfig((uint32_t)(obj->pad), obj->cfg); // apply configuration
}

/** Set the output value
 *
 * @param obj   The GPIO object (must be connected)
 * @param value The value to be set
 */
void gpio_write(gpio_t *obj, int value){
    MBED_ASSERT(gpio_is_connected(obj));
    (value) ? am_hal_gpio_output_set(obj->pad) : am_hal_gpio_output_clear(obj->pad);
}

/** Read the input value
 *
 * @param obj The GPIO object (must be connected)
 * @return An integer value 1 or 0
 */
int gpio_read(gpio_t *obj){
    MBED_ASSERT(gpio_is_connected(obj));
    uint32_t ui32BaseAddr = (obj->pad) / 8;
    uint32_t ui32BaseShift = (((obj->pad) % 8) * 4) + 1;
    uint8_t output = ((AM_REGVAL(&GPIO->CFGA + ui32BaseAddr) >> ui32BaseShift) & 0x03);

    return (output) ? (int)am_hal_gpio_output_read(obj->pad) : (int)am_hal_gpio_input_read(obj->pad);
    return 0;
}

/** Get the pins that support all GPIO tests
 *
 * Return a PinMap array of pins that support GPIO. The
 * array is terminated with {NC, NC, 0}.
 *
 * Targets should override the weak implementation of this
 * function to provide the actual pinmap for GPIO testing.
 *
 * @return PinMap array
 */
const PinMap *gpio_pinmap(void){
    MBED_ASSERT(false);
    return NULL;
}
