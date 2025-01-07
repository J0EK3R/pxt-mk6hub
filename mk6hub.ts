/// <reference no-default-lib="true"/>
/**
 * Support for MK6Hub.
 */
//% color=#00c300 weight=100 icon="\uf294" block="MK6 Hub"
namespace mk6hub {

    export enum Channel {
        //% block="Channel A" enumval=0
        A = 0,
        //% block="Channel B" enumval=1
        B = 1,
        //% block="Channel C" enumval=2
        C = 2,
        //% block="Channel D" enumval=3
        D = 3,
        //% block="Channel E" enumval=4
        E = 4,
        //% block="Channel F" enumval=5
        F = 5
    }

    export enum Hub {
        //% block="Hub 1" enumval=0
        A = 0,
        //% block="Hub 2" enumval=1
        B = 1,
        //% block="Hub 3" enumval=2
        C = 2,
    }

    /**
    *  MK6Hub loop
    */
    //% blockId=mk6hub_loop
    //% block="MK6Hub loop"
    //% shim=mk6hub::loop
    //% blockGap=8 weight=60
    export function loop(): void {
        return;
    }


    /**
    *  MK6Hub init
    * @param hubNo hubNo, eg: "Hub A"
    */
    //% blockId=mk6hub_init
    //% block="MK6Hub %hubNo init"
    //% shim=mk6hub::init
    //% blockGap=8 weight=60
    export function init(hubNo: Hub): void {
        return;
    }

    /**
    *  MK6Hub SetChannel
    * @param hubNo hubNo, eg: "Hub A"
    * @param channel channel, eg: "Channel A"
    * @param value -127..127, eg: "value 0"
    */
    //% blockId=mk6hub_setchannel 
    //% block="MK6Hub %hubNo set %channel to value %value"
    //% shim=mk6hub::setChannel
    //% blockGap=8 weight=60
    export function setChannel(hubNo: Hub, channel: Channel, value: number): void {
        return;
    }

    /**
    *  MK6Hub SetChannelOffset
    * @param hubNo hubNo, eg: "Hub A"
    * @param channel channel, eg: "Channel A"
    * @param offset -127..127, eg: "value 0"
    */
    //% blockId=mk6hub_setchanneloffset
    //% block="MK6Hub %hubNo set %channel offset to value %offset"
    //% shim=mk6hub::setChannelOffset
    //% blockGap=8 weight=60
    export function setChannelOffset(hubNo: Hub, channel: Channel, offset: number): void {
        return;
    }

    /**
    *  MK6Hub SendData
    * @param hubNo hubNo, eg: "Hub A"
    */
    //% blockId=mk6hub_senddata 
    //% block="MK6Hub %hubNo send data"
    //% shim=mk6hub::sendData
    //% blockGap=8 weight=60
    export function senddata(hubNo: Hub): void {
        return;
    }

    /**
     * Stops advertising MK6Hub
     * @param hubNo hubNo, eg: "Hub A"
     */
    //% blockId=mk6hub_stop
    //% block="MK6Hub %hubNo stop"
    //% shim=mk6hub::stop
    //% weight=10 blockGap=8
    export function stop(hubNo: Hub): void {
        return;
    };


    /**
    *  MK6Hub get Version
    * @param hubNo hubNo, eg: "Hub A"
    */
    //% blockId=mk6hub_getversion 
    //% block="MK6Hub %hubNo get Version"
    //% shim=mk6hub::getVersion
    //% blockGap=8 weight=60 advanced=true
    export function getversion(hubNo: Hub): number {
        return 0;
    }
}