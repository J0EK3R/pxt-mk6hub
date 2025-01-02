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

    MK6HubService* _pServiceHubA = NULL;
    MK6HubService* _pServiceHubB = NULL;
    MK6HubService* _pServiceHubC = NULL;

    //%
    void createService(uint8_t hubNo, MK6HubService** _pService) {

        if (NULL == _pService) {
#if MICROBIT_CODAL
            *_pService = new MK6HubService(hubNo);
#else
            *_pService = new MK6HubService(hubNo, *uBit.ble);
#endif
        }
    }


    //%
    void init(uint8_t hubNo) {

        switch (hubNo)
        {
        case 0:
            createService(hubNo, &_pServiceHubA);
            _pServiceHubA->connect();
            break;
        case 1:
            createService(hubNo, &_pServiceHubB);
            _pServiceHubB->connect();
            break;
        case 2:
            createService(hubNo, &_pServiceHubC);
            _pServiceHubC->connect();
            break;
        
        default:
            break;
        }
    }


    //% 
    void setChannel(uint8_t hubNo, uint8_t channel, float value) {        

        switch (hubNo)
        {
        case 0:
            createService(hubNo, &_pServiceHubA);
            _pServiceHubA->setChannel(channel, value);
            break;
        case 1:
            createService(hubNo, &_pServiceHubB);
            _pServiceHubB->setChannel(channel, value);
            break;
        case 2:
            createService(hubNo, &_pServiceHubC);
            _pServiceHubC->setChannel(channel, value);
            break;
        
        default:
            break;
        }
    }   


    //% 
    void setChannelOffset(uint8_t hubNo, uint8_t channel, float value) {        

        switch (hubNo)
        {
        case 0:
            createService(hubNo, &_pServiceHubA);
            _pServiceHubA->setChannelOffset(channel, value);
            break;
        case 1:
            createService(hubNo, &_pServiceHubB);
            _pServiceHubB->setChannelOffset(channel, value);
            break;
        case 2:
            createService(hubNo, &_pServiceHubC);
            _pServiceHubC->setChannelOffset(channel, value);
            break;
        
        default:
            break;
        }
    }   


    //% 
    void sendData(uint8_t hubNo) {        

        switch (hubNo)
        {
        case 0:
            createService(hubNo, &_pServiceHubA);
            _pServiceHubA->sendData();
            break;
        case 1:
            createService(hubNo, &_pServiceHubB);
            _pServiceHubB->sendData();
            break;
        case 2:
            createService(hubNo, &_pServiceHubC);
            _pServiceHubC->sendData();
            break;
        
        default:
            break;
        }

    }   


    //% 
    void stop(uint8_t hubNo) {        

        switch (hubNo)
        {
        case 0:
            if (NULL != _pServiceHubA) {
                _pServiceHubA->stop();
            }        
            break;
        case 1:
            if (NULL != _pServiceHubB) {
                _pServiceHubB->stop();
            }        
            break;
        case 2:
            if (NULL != _pServiceHubC) {
                _pServiceHubC->stop();
            }        
            break;
        
        default:
            break;
        }
    }   


    //% 
    uint8_t getVersion(uint8_t hubNo) {        

        switch (hubNo)
        {
        case 0:
            createService(hubNo, &_pServiceHubA);
            return _pServiceHubA->getVersion();
        case 1:
            createService(hubNo, &_pServiceHubB);
            return _pServiceHubB->getVersion();
        case 2:
            createService(hubNo, &_pServiceHubC);
            return _pServiceHubC->getVersion();
        
        default:
            return 0;
        }
    }   
}
