#include "MicroBitConfig.h"
#include "MK6HubService.h"
#include "CryptTool.h"

static uint8_t _ctxValue = 0x25; // CTXValue for Encryption
static uint8_t _addressArray[5]     = { 0xC1, 0xC2, 0xC3, 0xC4, 0xC5 };
static uint8_t _telegram_Connect[8] = { 0x6D, 0x7B, 0xA7, 0x80, 0x80, 0x80, 0x80, 0x92, };


MK6HubService::MK6HubService(BLEAdvManager &_BLEAdvManager, uint8_t hubNo) : m_bleAdvManager(_BLEAdvManager), m_hubNo(hubNo) {

    m_bleAdvManager_handle = m_bleAdvManager.register_client();

    m_telegram_Data[0] = 0x61 + m_hubNo;
    m_telegram_Data[9] = 0x9E - m_hubNo;
}


void MK6HubService::connect() {

    // MICROBIT_DEBUG_DMESG("MK6HubService::connect");

    get_rf_payload(_addressArray, 5, _telegram_Connect, 8, _ctxValue, m_pPayload);

    m_bleAdvManager.advertise(m_bleAdvManager_handle, m_pPayload);
}


void MK6HubService::stop() {

    m_bleAdvManager.stop(m_bleAdvManager_handle);
}


void MK6HubService::sendData() {

    memcpy(&m_telegram_Data[3], m_channelValues, sizeof(uint8_t) * 6);

    get_rf_payload(_addressArray, 5, m_telegram_Data, 10, _ctxValue, m_pPayload);

    m_bleAdvManager.advertise(m_bleAdvManager_handle, m_pPayload);
}


void MK6HubService::setChannel(uint8_t channel, float value) {

    // MICROBIT_DEBUG_DMESG("MK6HubService::setChannel");

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


uint8_t MK6HubService::getVersion() {

    return 2;
}
