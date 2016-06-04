/**
 * \file    main.c
 *
 * \brief   This is a sample application file demonstrating the use of
 *          a GPIO to control leds, switches, Push Buttons
 */

/*
* Copyright (C) 2012 Texas Instruments Incorporated - http://www.ti.com/ 
*
*  Redistribution and use in source and binary forms, with or without 
*  modification, are permitted provided that the following conditions 
*  are met:
*
*    Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the   
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "gpio.h"
#include "psc.h"

#include "soc_C6748.h"
#include "lcdkC6748.h"
#include "interrupt.h"

/****************************************************************************/
/*              LOCAL FUNCTION PROTOTYPES                                   */
/****************************************************************************/
//static void Delay(volatile unsigned int delay);
static void Button_S2_interrupt(void);

/****************************************************************************/
/*              GLOBAL VARIABLES                                            */
/****************************************************************************/

/****************************************************************************/
/*             LOCAL FUNCTION DEFINITIONS                                   */
/****************************************************************************/
//test
//test2
//tets3
//tets4
int main(void)
{
	int test;
	test = 0;
    /* The Local PSC number for GPIO is 3. GPIO belongs to PSC1 module.*/
   PSCModuleControl(SOC_PSC_1_REGS, HW_PSC_GPIO, PSC_POWERDOMAIN_ALWAYS_ON, PSC_MDCTL_NEXT_ENABLE);

    /* Pin Multiplexing of pin 12 of GPIO Bank 6 (D5)*/
    //GPIOBank6Pin12PinMuxSetup();

   //PIN MUX of PIN 4 of GPIO Bank 0 (Switch #8)
   GPIOBank0Pin4PinMuxSetup();
   //PIN MUX of pin 13 of GPIO Bank 6 (D4)
   GPIOBank6Pin13PinMuxSetup();
   //PIN MUX of pin 4 of GPIO Bank 2 (Push Button S2)
   GPIOBank2Pin4PinMuxSetup();


   /*Interrupt management begin*/

   /* Initialize the DSPINTC */

   IntDSPINTCInit();

   /* Register the Interrupt Service Routine (ISR) */

   IntRegister( C674X_MASK_INT4, Button_S2_interrupt);

   /* Map GPIO interrupts to DSP maskable interrupt */

   IntEventMap(C674X_MASK_INT4, SYS_INT_GPIO_B2INT);

   /* Enable DSP interrupt in DSPINTC */

   IntEnable(C674X_MASK_INT4);

   /* Enable DSP interrupts */

   IntGlobalEnable();

   /* Enable the GPIO BANK interrupt */

   GPIOBankIntEnable(SOC_GPIO_0_REGS, 2);

   /*Configure the GPIO PIN interrupt*/

   GPIOIntTypeSet(SOC_GPIO_0_REGS,  37, GPIO_INT_TYPE_RISEDGE);

   /*Interrupt management end*/

    /* Sets the pin 109 (GP6[12]) as output.*/
   // GPIODirModeSet(SOC_GPIO_0_REGS, 109, GPIO_DIR_OUTPUT);

   //Sets the pin 110(GP6[13], LED D4 as output )
   GPIODirModeSet(SOC_GPIO_0_REGS, 110, GPIO_DIR_OUTPUT);

   //Sets the pin 5 (GP0[4], switch 8 as input )
   //GPIODirModeSet(SOC_GPIO_0_REGS, 5, GPIO_DIR_INPUT);

   //Sets pin 4  (GP2[4], Push Button S2 as input )
   GPIODirModeSet(SOC_GPIO_0_REGS, 37, GPIO_DIR_INPUT);


    while(1)
    {
      ;

    	   }
    }

interrupt void Button_S2_interrupt(void)
{
     int y;

	/* Disable the GPIO interrupt */
    GPIOBankIntDisable(SOC_GPIO_0_REGS, 2);


    /*Clear interrupt status in DSPINTC */
    IntEventClear(SYS_INT_GPIO_B2INT);

    /*Clear the GPIO pin interrupt*/
    GPIOPinIntClear(SOC_GPIO_0_REGS,  37);

    /*Interrupt handler begin*/

    /*State of D4*/
      y=GPIOPinRead(SOC_GPIO_0_REGS, 110);

      if (y==GPIO_PIN_LOW){
    	  GPIOPinWrite(SOC_GPIO_0_REGS, 110, GPIO_PIN_HIGH);
      }
      if (y==GPIO_PIN_HIGH){
    	  GPIOPinWrite(SOC_GPIO_0_REGS, 110, GPIO_PIN_LOW);
      }
    /*Interrupt handler end*/

    /* Enable the GPIO interrupt */
    GPIOBankIntEnable(SOC_GPIO_0_REGS, 2);

}


/*
** \brief   This function can be called to generate a delay.
*/
/*
static void Delay(volatile unsigned int delay)
{
    while(delay--);
}

*/
/*****************************END OF FILE************************************/
