/**
 * \file     gpioMux.c
 *
 * \brief    This file selects the pin 12 of GPIO Bank 6 for use.
 *
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

/* HW Macros */
#include "hw_types.h"

/* System Defines */
#include "lcdkC6748.h"
#include "soc_C6748.h"
#include "hw_syscfg0_C6748.h"


/*****************************************************************************
**                       MACRO DEFINITION
*****************************************************************************/
/* Pin Multiplexing bit mask to select GP4[0] pin. */
#define PINMUX10_GPIO4_0_ENABLE    (SYSCFG_PINMUX10_PINMUX10_31_28_GPIO4_0  << \
                                    SYSCFG_PINMUX10_PINMUX10_31_28_SHIFT)

/* Pin Multiplexing bit mask to select GP6[13] pin. D4*/
#define PINMUX13_GPIO6_13_ENABLE    (SYSCFG_PINMUX13_PINMUX13_11_8_GPIO6_13  << \
                                    SYSCFG_PINMUX13_PINMUX13_11_8_SHIFT)


/* Pin Multiplexing bit mask to select GP6[12] pin. D5*/
#define PINMUX13_GPIO6_12_ENABLE    (SYSCFG_PINMUX13_PINMUX13_15_12_GPIO6_12  << \
                                    SYSCFG_PINMUX13_PINMUX13_15_12_SHIFT)

/* Pin Multiplexing bit mask to select GP2[12] pin. D6*/
#define PINMUX5_GPIO2_12_ENABLE    (SYSCFG_PINMUX5_PINMUX5_15_12_GPIO2_12   << \
                                    SYSCFG_PINMUX5_PINMUX5_15_12_SHIFT)

/* Pin Multiplexing bit mask to select GP0[9] pin. D7*/
#define PINMUX0_GPIO0_9_ENABLE    (SYSCFG_PINMUX0_PINMUX0_27_24_GPIO0_9   << \
                                    SYSCFG_PINMUX0_PINMUX0_27_24_SHIFT)

/* Pin Multiplexing bit mask to select GP2[4] pin. S2*/
#define PINMUX6_GPIO2_4_ENABLE    (SYSCFG_PINMUX6_PINMUX6_15_12_GPIO2_4  << \
                                    SYSCFG_PINMUX6_PINMUX6_15_12_SHIFT)

/* Pin Multiplexing bit mask to select GP2[5] pin. S3*/
#define PINMUX6_GPIO2_5_ENABLE    (SYSCFG_PINMUX6_PINMUX6_11_8_GPIO2_5  << \
                                    SYSCFG_PINMUX6_PINMUX6_11_8_SHIFT)

/* Pin Multiplexing bit mask to select GP0[1] pin. Switch 5*/
#define PINMUX1_GPIO0_1_ENABLE    (SYSCFG_PINMUX1_PINMUX1_27_24_GPIO0_1  << \
                                    SYSCFG_PINMUX1_PINMUX1_27_24_SHIFT)

/* Pin Multiplexing bit mask to select GP0[2] pin. Switch 6*/
#define PINMUX1_GPIO0_2_ENABLE    (SYSCFG_PINMUX1_PINMUX1_23_20_GPIO0_2  << \
                                    SYSCFG_PINMUX1_PINMUX1_23_20_SHIFT)

/* Pin Multiplexing bit mask to select GP0[3] pin. Switch 7*/
#define PINMUX1_GPIO0_3_ENABLE    (SYSCFG_PINMUX1_PINMUX1_19_16_GPIO0_3   << \
                                    SYSCFG_PINMUX1_PINMUX1_19_16_SHIFT)

/* Pin Multiplexing bit mask to select GP0[4] pin. Switch 8*/
#define PINMUX1_GPIO0_4_ENABLE    (SYSCFG_PINMUX1_PINMUX1_15_12_GPIO0_4  << \
                                    SYSCFG_PINMUX1_PINMUX1_15_12_SHIFT)  
/*****************************************************************************
**                       FUNCTION DEFINITION
*****************************************************************************/

/**
 * \brief   This function selects the Pin 0 of GPIO bank 4 for use.
 *          This GPIO pin is multiplexed with pins of other peripherals
 *          in the System on Chip(SoC).
 *         
 * \return  None.
 *
 */

void GPIOBank4Pin0PinMuxSetup(void)
{
     unsigned int savePinmux = 0;

     /*
     ** Clearing the bit in context and retaining the other bit values
     ** in PINMUX10 register.
     */
     savePinmux = (HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(10)) &
                  ~(SYSCFG_PINMUX10_PINMUX10_31_28));

     /* Setting the pins corresponding to GP4[0] in PINMUX10 register.*/
     HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(10)) =
          (PINMUX10_GPIO4_0_ENABLE | savePinmux);

}

/**
 * \brief   This function selects the Pin 13 of GPIO bank 6 for use.
 *          This GPIO pin is multiplexed with pins of other peripherals
 *          in the System on Chip(SoC).
 *
 * \return  None.
 *
 */
void GPIOBank6Pin13PinMuxSetup(void)
{
     unsigned int savePinmux = 0;

     /*
     ** Clearing the bit in context and retaining the other bit values
     ** in PINMUX13 register.
     */
     savePinmux = (HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(13)) &
                  ~(SYSCFG_PINMUX13_PINMUX13_11_8));

     /* Setting the pins corresponding to GP6[13] in PINMUX13 register.*/
     HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(13)) =
          (PINMUX13_GPIO6_13_ENABLE | savePinmux);
}

/**
 * \brief   This function selects the Pin 12 of GPIO bank 6 for use.
 *          This GPIO pin is multiplexed with pins of other peripherals
 *          in the System on Chip(SoC).
 *
 * \return  None.
 *
 */

void GPIOBank6Pin12PinMuxSetup(void)
{
     unsigned int savePinmux = 0;
     
     /*
     ** Clearing the bit in context and retaining the other bit values 
     ** in PINMUX13 register.
     */
     savePinmux = (HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(13)) &
                  ~(SYSCFG_PINMUX13_PINMUX13_15_12));

     /* Setting the pins corresponding to GP6[12] in PINMUX13 register.*/
     HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(13)) =
          (PINMUX13_GPIO6_12_ENABLE | savePinmux);

}

/**
 * \brief   This function selects the Pin 12 of GPIO bank 2 for use.
 *          This GPIO pin is multiplexed with pins of other peripherals
 *          in the System on Chip(SoC).
 *
 * \return  None.
 *
 */

void GPIOBank2Pin12PinMuxSetup(void)
{
     unsigned int savePinmux = 0;
     
     /*
     ** Clearing the bit in context and retaining the other bit values 
     ** in PINMUX5 register.
     */
     savePinmux = (HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(5)) &
                  ~(SYSCFG_PINMUX5_PINMUX5_15_12));

     /* Setting the pins corresponding to GP6[12] in PINMUX13 register.*/
     HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(5)) =
          (PINMUX5_GPIO2_12_ENABLE | savePinmux);

}

/**
 * \brief   This function selects the Pin 12 of GPIO bank 2 for use.
 *          This GPIO pin is multiplexed with pins of other peripherals
 *          in the System on Chip(SoC).
 *
 * \return  None.
 *
 */

void GPIOBank0Pin9PinMuxSetup(void)
{
     unsigned int savePinmux = 0;

     /*
     ** Clearing the bit in context and retaining the other bit values
     ** in PINMUX0 register.
     */
     savePinmux = (HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(0)) &
                  ~(SYSCFG_PINMUX0_PINMUX0_27_24));

     /* Setting the pins corresponding to GP0[9] in PINMUX0 register.*/
     HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(0)) =
          (PINMUX0_GPIO0_9_ENABLE | savePinmux);

}

void GPIOBank2Pin4PinMuxSetup(void)
{
     unsigned int savePinmux = 0;

     /*
     ** Clearing the bit in context and retaining the other bit values
     ** in PINMUX6 register.
     */
     savePinmux = (HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(6)) &
                  ~(SYSCFG_PINMUX6_PINMUX6_15_12));

     /* Setting the pins corresponding to GP2[4] in PINMUX6 register.*/
     HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(6)) =
          (PINMUX6_GPIO2_4_ENABLE | savePinmux);
}

void GPIOBank2Pin5PinMuxSetup(void)
{
     unsigned int savePinmux = 0;

     /*
     ** Clearing the bit in context and retaining the other bit values
     ** in PINMUX6 register.
     */
     savePinmux = (HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(6)) &
                  ~(SYSCFG_PINMUX6_PINMUX6_11_8));

     /* Setting the pins corresponding to GP2[5] in PINMUX6 register.*/
     HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(6)) =
          (PINMUX6_GPIO2_5_ENABLE | savePinmux);
}

void GPIOBank0Pin1PinMuxSetup(void)
{
     unsigned int savePinmux = 0;

     /*
     ** Clearing the bit in context and retaining the other bit values
     ** in PINMUX1 register.
     */
     savePinmux = (HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(1)) &
                  ~(SYSCFG_PINMUX1_PINMUX1_27_24));

     /* Setting the pins corresponding to GP0[4] in PINMUX1 register.*/
     HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(1)) =
          (PINMUX1_GPIO0_1_ENABLE | savePinmux);
}

void GPIOBank0Pin2PinMuxSetup(void)
{
     unsigned int savePinmux = 0;

     /*
     ** Clearing the bit in context and retaining the other bit values
     ** in PINMUX1 register.
     */
     savePinmux = (HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(1)) &
                  ~(SYSCFG_PINMUX1_PINMUX1_23_20));

     /* Setting the pins corresponding to GP0[4] in PINMUX1 register.*/
     HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(1)) =
          (PINMUX1_GPIO0_2_ENABLE | savePinmux);
}

void GPIOBank0Pin3PinMuxSetup(void)
{
     unsigned int savePinmux = 0;

     /*
     ** Clearing the bit in context and retaining the other bit values
     ** in PINMUX1 register.
     */
     savePinmux = (HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(1)) &
                  ~(SYSCFG_PINMUX1_PINMUX1_19_16));

     /* Setting the pins corresponding to GP0[3] in PINMUX1 register.*/
     HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(1)) =
          (PINMUX1_GPIO0_3_ENABLE | savePinmux);
}


void GPIOBank0Pin4PinMuxSetup(void)
{
     unsigned int savePinmux = 0;
     
     /*
     ** Clearing the bit in context and retaining the other bit values 
     ** in PINMUX1 register.
     */
     savePinmux = (HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(13)) &
                  ~(SYSCFG_PINMUX1_PINMUX1_15_12));

     /* Setting the pins corresponding to GP0[4] in PINMUX1 register.*/
     HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(1)) =
          (PINMUX1_GPIO0_4_ENABLE | savePinmux);
}

/******************************* End of file ********************************/
