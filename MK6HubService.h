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
    MK6HubService();

    void start();
    void setchannel(const uint8_t channelid, const uint8_t value);
    void stop();
    
    private:

    const uint8_t channels[6] = {
        0x01,
        0x02,
        0x03,
        0x04,
        0x05,
        0x06
    };

    const uint8_t flags[1] = {0x06};
    const uint8_t linecorp[2] = {0x6F, 0xFE};
    const uint8_t hwidframe[9] = {
        0x6F, 0xFE, // LINE corp
        0x02,       // Frame Type
        0x00, 0x00, 0x00, 0x00, 0x00,   // HWID 
        0x7F        // Measured TxPower
    };
};

//================================================================
#else // MICROBIT_CODAL
//================================================================

#include "ble/BLE.h"

// https://lancaster-university.github.io/microbit-docs/ble/eddystone/

/**
  * Class definition for the MK6 Hub service.
  * Provides a BLE service to receive MK6 Hub Messages
  */
class MK6HubService
{
    public:

    /**
      * Constructor.
      * Create a representation of the BlueDotService
      * @param _ble The instance of a BLE device that we're running on.
      */
    MK6HubService(BLEDevice &_ble);

    void start();
    void setchannel(const uint8_t channelid, const uint8_t value);
    void stop();

    private:

    // Bluetooth stack we're running on.
    BLEDevice           	&ble;

    const uint8_t channels[6] = {
        0x01,
        0x02,
        0x03,
        0x04,
        0x05,
        0x06
    };

    const uint8_t flags[1] = {0x06};
    const uint8_t linecorp[2] = {0x6F, 0xFE};
};

//================================================================
#endif // MICROBIT_CODAL
//================================================================

#endif
