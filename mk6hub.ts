/// <reference no-default-lib="true"/>
/**
 * Support for MK6 Hub.
 */
//% color=#00c300 weight=100 icon="\uf294" block="MK6 Hub"
namespace mk6hub {

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
     * Stops advertising MK6 Hub
     */
    //% blockId=mk6hub_stop
    //% block="MK6 Hub stop"
    //% shim=mk6hub::stop
    //% weight=10 blockGap=8 advanced=true
    export function stop() {
        return;
    };
}