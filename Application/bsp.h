/******************************************************************************
* @file    bsp.h
* @brief   Board Support Package interface for EK-TM4C123GXL
* @board   EK-TM4C123GXL (TM4C123GH6PM)
* @author  Alexandre Panhaleux
******************************************************************************/
#ifndef __BSP_H__
#define __BSP_H__

/* System tick rate =========================================================*/
#define BSP_TICKS_PER_SEC 1000U

/* Public API =========================================================*/
void BSP_init(void);

void BSP_ledRedOn(void);
void BSP_ledRedOff(void);

void BSP_ledBlueOn(void);
void BSP_ledBlueOff(void);

void BSP_ledGreenOn(void);
void BSP_ledGreenOff(void);

/* Extern semaphore */
extern QXSemaphore SW1_sema;

#endif // __BSP_H__
