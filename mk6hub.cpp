#include "pxt.h"
#include "MK6HubService.h"
#include <stdio.h>
#include <ctype.h>
#include "MicroBitConfig.h"

using namespace pxt;

/**
 * Support for MK6 Hub.
 */
//% color=#00c300 weight=100 icon="\uf294" block="MK6"
namespace mk6hub {

    MK6HubService* _pService = NULL;

    //%
    void start() {

        if (NULL == _pService) {
#if MICROBIT_CODAL
            _pService = new MK6HubService();
#else
            _pService = new MK6HubService(*uBit.ble);
#endif
        }

        _pService->start();
    }

    //%
    void setChannel(uint8_t channelId, uint8_t value) {

        if (NULL == _pService) {
#if MICROBIT_CODAL
            _pService = new MK6HubService();
#else
            _pService = new MK6HubService(*uBit.ble);
#endif
        }

        _pService->setChannel(channelId, value);
    }

    //% 
    void stop() {        
        if (NULL != _pService) {
            _pService->stop();
        }        

        // uBit.bleManager.stopAdvertising();  
    }   

}
