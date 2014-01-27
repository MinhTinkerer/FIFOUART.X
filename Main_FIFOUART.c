/* 
 * File:   Main_FIFOUART.c
 * Author: Connor
 *
 * Created on January 18, 2014, 2:18 PM
 */

#pragma config FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FPLLODIV = DIV_1, FWDTEN = OFF
#pragma config POSCMOD = HS, FNOSC = PRIPLL, FPBDIV = DIV_1

#include <stdio.h>
#include <stdlib.h>
#include "FIFOUART1.h"




void DelayTime(int ms)
{
    int i = 0;
    while (i < (ms*1000))
    {
        i++;
    }
}


int main(int argc, char** argv)
{
    uint8 dat[100];
    dat[0] = 'h';
    dat[1] = 'e';
    dat[2] = 'l';
    dat[3] = 'l';
    dat[4] = 'o';

    int byt = 0;
    uint8 byt2 = 0;


    FIFOUART1_initialize();

    INTConfigureSystem(INT_SYSTEM_CONFIG_MULT_VECTOR);
    INTEnableInterrupts();

    FIFOUART1_pushTxQueue(dat, 5);

    int a = 0;
    while(1)
    {
        a = a + 1;

        if (a > 1000000)
        {
            //check queue and send stuff
        }
    }

    return (EXIT_SUCCESS);
}


