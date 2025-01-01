#include "pxt.h"
#include "MK6HubService.h"
#include <stdio.h>
#include <ctype.h>
#include "MicroBitConfig.h"

using namespace pxt;

/**
 * Support for MK6 Hub.
 */
//% color=#00c300 weight=100 icon="\uf294" block="MK6 Hub"
namespace mk6hub {

    MK6HubService* _pService = NULL;

    void createService() {

        if (NULL == _pService) {
#if MICROBIT_CODAL
            _pService = new MK6HubService();
#else
            _pService = new MK6HubService(*uBit.ble);
#endif
        }
    }


    //%
    void connect() {

        createService();

        _pService->connect();
    }


    //% 
    void setChannel(uint8_t channel, uint8_t value) {        

        createService();

        _pService->setChannel(channel, value);
    }   


    //% 
    void sendData() {        

        createService();

        _pService->sendData();
    }   

    //% 
    void stop() {        

        if (NULL != _pService) {
            _pService->stop();
        }        

        // uBit.bleManager.stopAdvertising();  
    }   
}
