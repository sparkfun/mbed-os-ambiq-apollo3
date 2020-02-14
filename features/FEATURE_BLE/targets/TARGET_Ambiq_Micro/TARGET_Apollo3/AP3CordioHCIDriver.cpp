#include "AP3CordioHCIDriver.h"
#include "AP3CordioHCITransportDriver.h"
#include "am_mcu_apollo.h"

#include "stdio.h"

using namespace ble::vendor::ambiq_micro;
using namespace ble::vendor::cordio;

extern "C" void am_ble_isr(void);

AP3CordioHCIDriver::AP3CordioHCIDriver(cordio::CordioHCITransportDriver &transport_driver)
    : cordio::CordioHCIDriver(transport_driver)
{
    AP3CordioHCITransportDriver *p_trspt_drv = (AP3CordioHCITransportDriver *)&transport_driver;
    _ptr_to_handle = &p_trspt_drv->handle;
}

AP3CordioHCIDriver::~AP3CordioHCIDriver() {}

void AP3CordioHCIDriver::do_initialize()
{
    MBED_ASSERT(*_ptr_to_handle);
    _ble_config = am_hal_ble_default_config;
    am_hal_ble_power_control(*_ptr_to_handle, AM_HAL_BLE_POWER_ACTIVE);
    am_hal_ble_config(*_ptr_to_handle, &_ble_config);
    am_hal_ble_boot(*_ptr_to_handle);
    NVIC_SetVector(BLE_IRQn, (uint32_t)am_ble_isr);
    NVIC_EnableIRQ(BLE_IRQn);
}
void AP3CordioHCIDriver::do_terminate()
{
    am_hal_ble_power_control(*_ptr_to_handle, AM_HAL_BLE_POWER_OFF);
}

ble::vendor::cordio::buf_pool_desc_t AP3CordioHCIDriver::get_buffer_pool_description()
{
    return get_default_buffer_pool_description();
}

// AP3CordioHCIDriver::start_reset_sequence();

// AP3CordioHCIDriver::handle_reset_sequence(uint8_t *msg);

ble::vendor::cordio::CordioHCIDriver &ble_cordio_get_hci_driver()
{
    static AP3CordioHCITransportDriver transport_driver;

    static AP3CordioHCIDriver hci_driver(transport_driver);

    return hci_driver;
}

extern "C" void am_ble_isr(void)
{
    while (1)
    {
    }
}
