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

#define MAX_CLIENTS           10
#define UNSET_HANDLE          0xFF

class BLEAdvManager
{
    public:

      BLEAdvManager();

      uint8_t register_client();
      void unregister_client(uint8_t clientHandle);

      void advertise(uint8_t clientHandle, uint8_t *p_payload);
      void stop(uint8_t clientHandle);

      void loop();

    private:

      void init();

      uint8_t m_registeredClients[MAX_CLIENTS];
    
      uint8_t* m_payloads[MAX_CLIENTS];

      uint8_t m_dropLoop[MAX_CLIENTS];

      uint8_t m_adv_handle = BLE_GAP_ADV_SET_HANDLE_NOT_SET; /**< Advertising handle used to identify an advertising set. */

      uint8_t m_currentClientHandle = 0;
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