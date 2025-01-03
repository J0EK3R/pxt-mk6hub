#ifndef MK6HUB_SERVICE_H
#define MK6HUB_SERVICE_H

#include "MicroBitConfig.h"
#include "pxt.h"

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
    MK6HubService(uint8_t hubNo);
    void connect();
    void stop();
    void setChannel(uint8_t channel, float value);
    void setChannelOffset(uint8_t channel, float offset);
    void sendData();

    uint8_t getVersion();

  private:
    // number of hub [0..2]
    uint8_t m_hubNo;
    
    float channelOffsets[6] = {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
    uint8_t channelValues[6] = {
        0x80, 0x80, 0x80, 0x80, 0x80, 0x80 };
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
      * Create a representation of the BlueDotService
      * @param _ble The instance of a BLE device that we're running on.
      */
    MK6HubService(uint8_t hubNo, BLEDevice &_ble);
    void connect();
    void stop();
    void setChannel(uint8_t channel, float value);
    void setChannelOffset(uint8_t channel, float offset);
    void sendData();

    uint8_t getVersion();

    private:

    // Bluetooth stack we're running on.
    BLEDevice &ble;

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