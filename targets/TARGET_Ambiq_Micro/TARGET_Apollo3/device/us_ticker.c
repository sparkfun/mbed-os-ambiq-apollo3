#include "us_ticker_api.h"

/**
 * \defgroup hal_us_ticker Microsecond Ticker
 * Low level interface to the microsecond ticker of a target
 *
 * # Defined behavior
 * * Has a reported frequency between 250KHz and 8MHz for counters which are less than 32 bits wide - Verified by test ::us_ticker_info_test
 * * Has a reported frequency up to 100MHz for counters which are 32 bits wide - Verified by test ::us_ticker_info_test
 * * Has a counter that is at least 16 bits wide - Verified by test ::us_ticker_info_test
 * * All behavior defined by the @ref hal_ticker_shared "ticker specification"
 *
 * # Undefined behavior
 * * See the @ref hal_ticker_shared "ticker specification"
 *
 * @see hal_us_ticker_tests
 *
 * # Compile-time optimization macros
 *

 * @{
 */

/**
 * \defgroup hal_us_ticker_tests Microsecond Ticker tests
 * Tests to validate the proper implementation of the microsecond ticker
 *
 * To run the microsecond ticker hal tests use the command:
 *
 *     mbed test -t <toolchain> -m <target> -n tests-mbed_hal-common_ticker*,tests-mbed_hal-us_ticker*
 *
 * @see hal_ticker_tests
 *
 */
/* HAL us ticker */

/** Initialize the ticker
 *
 * Initialize or re-initialize the ticker. This resets all the
 * clocking and prescaler registers, along with disabling
 * the compare interrupt.
 *
 * @note Initialization properties tested by ::ticker_init_test
 *
 */
void us_ticker_init(void)
{
    am_hal_stimer_config(AM_HAL_STIMER_CFG_CLEAR | AM_HAL_STIMER_CFG_FREEZE);
    am_hal_stimer_config(US_TICKER_FREQ);
    NVIC_SetVector(STIMER_CMPR0_IRQn, (uint32_t)us_ticker_irq_handler);
    NVIC_EnableIRQ(STIMER_CMPR0_IRQn);
}

/** Deinitialize the us ticker
 *
 * Powerdown the us ticker in preparation for sleep, powerdown, or reset.
 *
 * After this function is called, no other ticker functions should be called
 * except us_ticker_init(), calling any function other than init is undefined.
 *
 * @note This function stops the ticker from counting.
 *
 */
void us_ticker_free(void)
{
    am_hal_stimer_config(AM_HAL_STIMER_CFG_FREEZE);
    am_hal_stimer_int_disable(US_TICKER_STIMER_INT_COMPARE);
}

/** Read the current counter
 *
 * Read the current counter value without performing frequency conversions.
 * If no rollover has occurred, the seconds passed since us_ticker_init()
 * was called can be found by dividing the ticks returned by this function
 * by the frequency returned by ::us_ticker_get_info.
 *
 * @return The current timer's counter value in ticks
 *
 */
uint32_tus_ticker_read(void)
{
    return am_hal_stimer_counter_get();
}

/** Set interrupt for specified timestamp
 *
 * @param timestamp The time in ticks to be set
 *
 * @note no special handling needs to be done for times in the past
 * as the common timer code will detect this and call
 * us_ticker_fire_interrupt() if this is the case
 *
 * @note calling this function with timestamp of more than the supported
 * number of bits returned by ::us_ticker_get_info results in undefined
 * behavior.
 *
 */
void us_ticker_set_interrupt(timestamp_t timestamp)
{
    ui32CmprInstance instance = 0;
    switch (US_TICKER_STIMER_INT_COMPARE)
    {
    default:
    case AM_HAL_STIMER_INT_COMPAREA:
        instance = 0;
        break;
    case AM_HAL_STIMER_INT_COMPAREB:
        instance = 1;
        break;
    case AM_HAL_STIMER_INT_COMPAREC:
        instance = 2;
        break;
    case AM_HAL_STIMER_INT_COMPARED:
        instance = 3;
        break;
    case AM_HAL_STIMER_INT_COMPAREE:
        instance = 4;
        break;
    case AM_HAL_STIMER_INT_COMPAREF:
        instance = 5;
        break;
    case AM_HAL_STIMER_INT_COMPAREG:
        instance = 6;
        break;
    case AM_HAL_STIMER_INT_COMPAREH:
        instance = 7;
        break;
    }

    am_hal_stimer_int_enable(US_TICKER_STIMER_INT_COMPARE);
    timestamp_t now = (timestamp_t)am_hal_stimer_counter_get();
    am_hal_stimer_compare_delta_set(instance, (timestamp - now));
}

/** Disable us ticker interrupt
 *
 */
void us_ticker_disable_interrupt(void)
{
    am_hal_stimer_int_disable(US_TICKER_COMPARE_INSTANCE);
}

/** Clear us ticker interrupt
 *
 */
void us_ticker_clear_interrupt(void)
{
    am_hal_stimer_int_clear(US_TICKER_COMPARE_INSTANCE);
}

/** Set pending interrupt that should be fired right away.
 *
 * The ticker should be initialized prior calling this function.
 *
 */
void us_ticker_fire_interrupt(void);
{
    am_hal_stimer_int_set(US_TICKER_COMPARE_INSTANCE);
}

/** Get frequency and counter bits of this ticker.*/
const ticker_info_t *us_ticker_get_info(void);
{
    static const ticker_info_t info = {
        1000000, // 1 MHz
        32       // 32 bit counter
    };
    return &info;
}