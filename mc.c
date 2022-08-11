// // #include <LPC214X.h>

// void delay(int);

// void main(){
//     IODIR0 = 0x00000001;
//     while(1){
//         IOSET0 = 0x00000001;
//         delay(500);
//         IOCLR0 = 0x00000001;
//         delay(500);
//     }
// }

// void delay(int i){
//     for(int j = 0; j < i; j++);
// }

// // prog2
// // #include <LPC214x.h>

// void wait(){
//     T0TCR = 1;
//     while(T0TC != T0MR1);
// }

// void main(){
//     T0MR1 = 0x1234;
//     T0MCR = 0x10;

//     while(1){

//     }
// }

// prg 4

#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvUART.h"

void main(){
    UNLOCKREG();
    DrvSYS_Open(48000000);
    LOCKREG();

    DrvGPIO_Open(E_GPB, 11, E_IO_OUTPUT);

    while(1){
        DrvGPIO_ClrBit(E_GBP, 11);
        DrvSYS_Delay(100000);
        DrvGPIO_SetBit(E_GBP, 11);
        DrvSYS_Delay(100000);
    }
}