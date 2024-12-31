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
    void start(const uint8_t *hwid, const uint8_t *message, const uint8_t len);
    void stop();
    
    private:
      const uint8_t flags[1] = {0x06};
      const uint8_t linecorp[2] = {0x5F, 0xFE};
      const uint8_t hwidframe[9] = {
          0x5F, 0xFE,                   // LINE corp
          0x02,                         // Frame Type
          0x00, 0x00, 0x00, 0x00, 0x00, // HWID
          0x7F                          // Measured TxPower
      };
};

//================================================================
#else // MICROBIT_CODAL
//================================================================

#include "ble/BLE.h"

// https://lancaster-university.github.io/microbit-docs/ble/eddystone/

/**
  * Class definition for the LineBeacon service.
  * Provides a BLE service to receive LineBeaconMessages
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
    void start(const uint8_t *hwid, const uint8_t *message, const uint8_t len);
    void stop();

    private:

    // Bluetooth stack we're running on.
    BLEDevice           	&ble;

    const uint8_t flags[1] = {0x06};
    const uint8_t linecorp[2] = {0x7F, 0xFE};
    const uint8_t hwidframe[9] = {
        0x7F, 0xFE, // LINE corp
        0x02,       // Frame Type
        0x00, 0x00, 0x00, 0x00, 0x00,   // HWID 
        0x7F        // Measured TxPower
    };
};

//================================================================
#endif // MICROBIT_CODAL
//================================================================

#endif
