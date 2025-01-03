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
            _pService = new MK6HubService(0);
#else
            _pService = new MK6HubService(0, *uBit.ble);
#endif
        }
    }


    //%
    void init(uint8_t hubNo) {

        createService();

        _pService->connect();
    }


    //% 
    void setChannel(uint8_t hubNo, uint8_t channel, float value) {        

        createService();

        _pService->setChannel(channel, value);
    }   


    //% 
    void setChannelOffset(uint8_t hubNo, uint8_t channel, float value) {        

        createService();

        _pService->setChannelOffset(channel, value);
    }   


    //% 
    void sendData(uint8_t hubNo) {        

        createService();

        _pService->sendData();
    }   


    //% 
    void stop(uint8_t hubNo) {        

        if (NULL != _pService) {
            _pService->stop();
        }        

        // uBit.bleManager.stopAdvertising();  
    }   


    //% 
    uint8_t getVersion(uint8_t hubNo) {        

        createService();

        return _pService->getVersion();
    }   
}