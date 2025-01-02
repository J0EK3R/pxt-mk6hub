#include "MicroBitConfig.h"
#include "MK6HubService.h"
#include "CryptTool.h"

//================================================================
#if MICROBIT_CODAL
//================================================================

/**
 * Copyright (c) 2014 - 2020, Nordic Semiconductor ASA
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 *
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
/** @file
 *
 * @defgroup ble_sdk_app_beacon_main main.c
 * @{
 * @ingroup ble_sdk_app_beacon
 * @brief Beacon Transmitter Sample Application main file.
 *
 * This file contains the source code for an Beacon transmitter sample application.
 */

#include <stdbool.h>
#include <stdint.h>
#include "nordic_common.h"
// #include "bsp.h"
#include "nrf_soc.h"
#include "nrf_sdh.h"
#include "nrf_sdh_ble.h"
#include "ble_advdata.h"
// #include "ble_gap.h"
#include "app_timer.h"
#include "nrf_pwr_mgmt.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"


#define APP_BLE_CONN_CFG_TAG            1                                  /**< A tag identifying the SoftDevice BLE configuration. */

#define NON_CONNECTABLE_ADV_INTERVAL    MSEC_TO_UNITS(152.5, UNIT_0_625_MS)  /**< The advertising interval for non-connectable advertisement (100 ms). This value can vary between 100ms to 10.24s). */

static uint8_t ctxValue            = 0x25; // CTXValue for Encryption
static uint8_t addressArray[5]     = { 0xC1, 0xC2, 0xC3, 0xC4, 0xC5 };
static uint8_t telegram_Connect[8] = { 0x6D, 0x7B, 0xA7, 0x80, 0x80, 0x80, 0x80, 0x92, };

/**@brief Function for initializing the Advertising functionality.
 *
 * @details Encodes the required advertising data and passes it to the stack.
 *          Also builds a structure to be passed to the stack when starting advertising.
 */
void MK6HubService::advertising_init(const uint8_t *data, const uint8_t dataLength)
{
    get_rf_payload(addressArray, 5, data, dataLength, ctxValue, m_rf_payload);

    ble_gap_adv_params_t gap_adv_params;
    memset(&gap_adv_params, 0, sizeof(gap_adv_params));

    gap_adv_params.properties.type  = BLE_GAP_ADV_TYPE_CONNECTABLE_SCANNABLE_UNDIRECTED;
    gap_adv_params.p_peer_addr      = NULL;    // Undirected advertisement.
    gap_adv_params.filter_policy    = BLE_GAP_ADV_FP_ANY;
    gap_adv_params.interval         = NON_CONNECTABLE_ADV_INTERVAL;
    gap_adv_params.duration         = 0;       // Never time out.

    gap_adv_params.primary_phy      = BLE_GAP_PHY_1MBPS; // BLE_GAP_PHY_CODED
    gap_adv_params.secondary_phy    = BLE_GAP_PHY_1MBPS; // BLE_GAP_PHY_CODED

    ble_gap_adv_data_t  gap_adv_data;
    memset(&gap_adv_data, 0, sizeof(gap_adv_data));

    gap_adv_data.adv_data.p_data    = m_rf_payload;
    gap_adv_data.adv_data.len       = 31;

    MICROBIT_BLE_ECHK(sd_ble_gap_adv_set_configure(&m_adv_handle, &gap_adv_data, &gap_adv_params));
}


/**@brief Function for starting advertising.
 */
void MK6HubService::advertising_start(void)
{
    MICROBIT_BLE_ECHK(sd_ble_gap_adv_start(m_adv_handle, APP_BLE_CONN_CFG_TAG));
}


/**@brief Function for initializing the BLE stack.
 *
 * @details Initializes the SoftDevice and the BLE event interrupt.
 */
void MK6HubService::ble_stack_init(void)
{
    MICROBIT_BLE_ECHK(nrf_sdh_enable_request());

    // Configure the BLE stack using the default settings.
    // Fetch the start address of the application RAM.
    uint32_t ram_start = 0;
    MICROBIT_BLE_ECHK(nrf_sdh_ble_default_cfg_set(APP_BLE_CONN_CFG_TAG, &ram_start));

    // Enable BLE stack.
    MICROBIT_BLE_ECHK(nrf_sdh_ble_enable(&ram_start));
}

/**
 * @brief Function for stop advertising.
 */
void MK6HubService::advertising_stop(void) {
    MICROBIT_DEBUG_DMESG("stopAdvertising");
    MICROBIT_BLE_ECHK(sd_ble_gap_adv_stop(m_adv_handle));
}


MK6HubService::MK6HubService(uint8_t hubNo) {
    m_hubNo = hubNo;

    // patch telegram data
    // 0x61, 0x7B, 0xA7, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x9E     // Hub A
    // 0x62, 0x7B, 0xA7, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x9D     // Hub B
    // 0x63, 0x7B, 0xA7, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x9C     // Hub C
    m_telegram_Data[0] = 0x61 + m_hubNo;
    m_telegram_Data[9] = 0x9E - m_hubNo;

    ble_stack_init();
}


void MK6HubService::connect() {

    MICROBIT_DEBUG_DMESG("MK6HubService::connect");
    // uBit.display.print("start");

    advertising_init(telegram_Connect, 8);

    // Start execution.
    // NRF_LOG_INFO("Beacon example started.");
    advertising_start();
}


void MK6HubService::setChannel(uint8_t channel, float value) {

    MICROBIT_DEBUG_DMESG("MK6HubService::setChannel");

    if(value == 0) {
        m_channelValues[channel] = 0x80;
    }
    else if(value < 0) {
        m_channelValues[channel] = (uint8_t)fmax(value - m_channelOffsets[channel] + 0x80, 0);
    }
    else {
        m_channelValues[channel] = (uint8_t)fmin(value + m_channelOffsets[channel] + 0x80, 0xFF);
    }
}


void MK6HubService::setChannelOffset(uint8_t channel, float offset) {

    m_channelOffsets[channel] = offset;
}


void MK6HubService::stop() {
    // uBit.display.print("stop");
    advertising_stop();
}


void MK6HubService::sendData() {

    memcpy(&m_telegram_Data[3], m_channelValues, sizeof(uint8_t) * 6);

    advertising_init(m_telegram_Data, 10);

    // Start execution.
    // NRF_LOG_INFO("Beacon example started.");
    advertising_start();
}


uint8_t MK6HubService::getVersion() {

    return 2;
}

//================================================================
#else // MICROBIT_CODAL
//================================================================

#include "ble/UUID.h"

/**
 * Constructor.
 * Create a representation of the MK6HubService
 * @param _ble The instance of a BLE device that we're running on.
 */
MK6HubService::MK6HubService(uint8_t hubNo, BLEDevice &_ble) : ble(_ble) {
    m_hubNo = hubNo;
}

void MK6HubService::connect() {

}


void MK6HubService::setChannel(uint8_t channel, float value) {

    if(value == 0) {
        m_channelValues[channel] = 0x80;
    }
    else if(value < 0) {
        m_channelValues[channel] = (uint8_t)fmax(value - m_channelOffsets[channel] + 0x80, 0);
    }
    else {
        m_channelValues[channel] = (uint8_t)fmin(value + m_channelOffsets[channel] + 0x80, 0xFF);
    }
}


void MK6HubService::setChannelOffset(uint8_t channel, float offset) {

    m_channelOffsets[channel] = offset;
}


void MK6HubService::sendData() {

}


void MK6HubService::stop() {
    // ble.gap().stopAdvertising();
    uBit.bleManager.stopAdvertising();
}


uint8_t MK6HubService::getVersion() {

    return 1;
}

//================================================================
#endif // MICROBIT_CODAL
//================================================================
