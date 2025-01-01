/// <reference no-default-lib="true"/>
/**
 * Support for MK6 Hub.
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

    /**
    *  MK6 Hub Connect
    */
    //% blockId=mk6hub_connect 
    //% block="MK6 Hub connect"
    //% blockGap=8 weight=60
    export function connect(): void {
        return;
    }

    /**
    *  MK6 Hub SetChannel
    * @param channel channel, eg: "Channel A"
    * @param value -127..127, eg: "value 0"
    */
    //% blockId=mk6hub_setchannel 
    //% block="MK6 Hub set %channel to value %value"
    //% blockGap=8 weight=60
    export function setChannel(channel: Channel, value: number): void {
        return;
    }

    /**
    *  MK6 Hub SendData
    */
    //% blockId=mk6hub_senddata 
    //% block="MK6 Hub send data"
    //% blockGap=8 weight=60
    export function senddata(): void {
        return;
    }

    /**
     * Stops advertising MK6 Hub
     */
    //% blockId=mk6hub_stop
    //% block="MK6 Hub stop"
    //% shim=mk6hub::stop
    //% weight=10 blockGap=8
    export function stop(): void {
        return;
    };


    /**
    *  MK6 Hub get Version
    */
    //% blockId=mk6hub_getversion 
    //% block="MK6 Hub get Version"
    //% blockGap=8 weight=60 advanced=true
    export function getversion(): number {
        return 0;
    }
}