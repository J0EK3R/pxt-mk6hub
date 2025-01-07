#ifndef BLEADVMANAGER_H
#define BLEADVMANAGER_H

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

class BLEAdvManager
{
    public:

      BLEAdvManager();

      uint8_t register_client();
      void unregister_client(uint8_t handle);

      void advertise(uint8_t handle, uint8_t *p_payload);
      void stop(uint8_t handle);

      void loop();

    private:

      uint8_t m_registeredClients[10] = { 
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

      uint8_t* m_payloads[10] = { 
        NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };

      uint8_t m_dropLoop[10] = { 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };


      uint8_t m_currentClient = 0;
};

//================================================================
#else // MICROBIT_CODAL
//================================================================

#include "ble/BLE.h"

/**
  * Class definition for the MK6HubService service.
  */
class BLEAdvManager
{
    public:

      /**
        * Constructor.
        * Create a representation of the BlueDotService
        * @param _ble The instance of a BLE device that we're running on.
        */
      BLEAdvManager(BLEDevice &_ble);

      uint8_t register_client();
      void unregister_client(uint8_t handle);

      void advertise(uint8_t handle, uint8_t *p_payload);
      void stop(uint8_t handle);

      void loop();

    private:

      // Bluetooth stack we're running on.
      BLEDevice &ble;
};

//================================================================
#endif // MICROBIT_CODAL
//================================================================

#endif