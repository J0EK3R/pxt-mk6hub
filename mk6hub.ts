/// <reference no-default-lib="true"/>

enum Channel {
    //% block="Channel A"
    A = 0,
    //% block="Channel B"
    B = 1,
    //% block="Channel C"
    C = 2,
    //% block="Channel D"
    D = 3,
    //% block="Channel E"
    E = 4,
    //% block="Channel F"
    F = 5
}


/**
 * Support for MK6 Hub.
 */
//% color=#00c300 weight=100 icon="\uf294" block="MK6Hub"
namespace mk6hub {

    // color="#00c300" weight=100 icon="\uf3c0"

    /**
    *  Starts advertising to MK6Hub
    */
    //% blockId=mk6hub_start 
    //% block="MK6Hub start"
    //% blockGap=8 weight=60
    // //% help=pxt-mk6hub/start 
    export function start(): void {
        return;
    }

    /**
     * Stops advertising to MK6Hub
     */
    //% blockId=mk6hub_stop
    //% block="MK6Hub stop"
    //% shim=mk6hub::stop
    //% weight=10 blockGap=8
    export function stop(): void {
        return;
    };


    /**
    *  MK6Hub SetChannel
    * @param channelId channelId, eg: "0"
    */
    //% blockId=mk6hub_setChannel 
    //% block="MK6Hub set Channel %channelId|with Value %value"
    //% blockGap=8 weight=60
    // //% help=pxt-mk6hub/setChannel 
    export function setChannel(channelId: Channel, value: number): void {
        return;
    }


//     /**
//      * Stops advertising MK6Hub end points
//      */
//     //% blockId=mk6hub_central
//     //% block="MK6Hub central"
//     //% weight=10 blockGap=8 advanced=true
//     //% group="micro:bit (V2)"
//     export function onCentralEvent() {
//         #if MICROBIT_CODAL
//         registerWithDal(uBit.logo.id, action, body);
// #else
//         target_panic(PANIC_VARIANT_NOT_SUPPORTED);
// #endif
//         return;
//     };
}