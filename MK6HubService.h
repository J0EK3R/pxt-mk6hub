#ifndef MK6HUB_SERVICE_H
#define MK6HUB_SERVICE_H

#include "MicroBitConfig.h"
#include "pxt.h"
#include "BLEAdvManager.h"

//================================================================
#if MICROBIT_CODAL
//================================================================

// https://github.com/lancaster-university/codal-microbit-v2/blob/master/inc/bluetooth/MicroBitBLEManager.h
// https://github.com/lancaster-university/codal-microbit-v2/blob/master/source/bluetooth/MicroBitBLEManager.cpp
#include "MicroBitBLEManager.h" 
// https://github.com/lancaster-university/codal-microbit-v2/blob/master/inc/MicroBitBLEService.h
// #include "MicroBitBLEService.h" 

class MK6HubService
{
    public:
    /**
      * Constructor.
      * Create a representation of the MK6HubService
      * @param _BLEAdvManager The instance of a BLEAdvManager that we're running on.
      * @param hubNo Number of the MK6 hub.
      */
    MK6HubService(BLEAdvManager &_BLEAdvManager, uint8_t hubNo);

    void connect();
    void stop();
    void setChannel(uint8_t channel, float value);
    void setChannelOffset(uint8_t channel, float offset);
    void sendData();

    uint8_t getVersion();

  private:
    BLEAdvManager &bleAdvManager;

    // number of hub [0..2]
    uint8_t m_hubNo;
    
    uint8_t m_adv_handle = BLE_GAP_ADV_SET_HANDLE_NOT_SET; /**< Advertising handle used to identify an advertising set. */

    float channelOffsets[6] = {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

    uint8_t channelValues[6] = {
        0x80, 0x80, 0x80, 0x80, 0x80, 0x80 };

    uint8_t m_rf_payload[31] = {
        0x02, // length: 0x2 (2)
        0x01, // type:   flags (0x01)
        0x06,

        0x1b, // length: 0x1b (27)
        0xff, // type:   manufacturer specific (0xff)
        0xf0, 0xff, // company Id: unkown 0xfff0
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
      };
      
      uint8_t m_telegram_Data[10] = { 
        0x61, 0x7B, 0xA7, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x9E };
};

//================================================================
#else // MICROBIT_CODAL
//================================================================

#include "ble/BLE.h"

/**
  * Class definition for the MK6HubService service.
  */
class MK6HubService
{
    public:

    /**
      * Constructor.
      * Create a representation of the MK6HubService
      * @param _BLEAdvManager The instance of a BLEAdvManager that we're running on.
      * @param hubNo Number of the MK6 hub.
      */
    MK6HubService(BLEAdvManager &_BLEAdvManager, uint8_t hubNo);

    void connect();
    void stop();
    void setChannel(uint8_t channel, float value);
    void setChannelOffset(uint8_t channel, float offset);
    void sendData();

    uint8_t getVersion();

    private:

    BLEAdvManager &bleAdvManager;

    // number of hub [0..2]
    uint8_t m_hubNo;
    
    float channelOffsets[6] = {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

    uint8_t channelValues[6] = {
        0x80, 0x80, 0x80, 0x80, 0x80, 0x80 };
};

//================================================================
#endif // MICROBIT_CODAL
//================================================================

#endif