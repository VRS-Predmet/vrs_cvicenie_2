/*
 * assignment.h
 *
 *  Created on: 27. 9. 2020
 *      Author: Stancoj
 */

#ifndef ASSIGNMENT_H_
#define ASSIGNMENT_H_


/**
 * 		This header file provides macros to the MCU's registers required for this assignment.
 * 		Your task is to provide their actual implementation so you can use them in application in "main.c"
 * 		and make your "LED blink" application code readable and great again!
 */

/* General purpose input output port A macros */

#define	GPIOA_BASE_ADDR			(uint32_t)(0x48000000U)	//GPIOA peripheral base address

#define	GPIOA_MODER_REG			*(uint32_t*)(GPIOA_BASE_ADDR+0x00U)	//MODER register

#define	GPIOA_OTYPER_REG		*(uint32_t*)(GPIOA_BASE_ADDR+0x04U) //OTYPER register

#define GPIOA_OSPEEDER_REG		*(uint32_t*)(GPIOA_BASE_ADDR+0x08U) //OSPEEDER register

#define GPIOA_PUPDR_REG			*(uint32_t*)(GPIOA_BASE_ADDR+0x0CU) //PUPDR register

#define GPIOA_IDR_REG			*(uint32_t*)(GPIOA_BASE_ADDR+0x10U) //IDR register

#define GPIOA_ODR_REG			*(uint32_t*)(GPIOA_BASE_ADDR+0x14U) //ODR register

#define GPIOA_BSRR_REG			*(uint32_t*)(GPIOA_BASE_ADDR+0x18U) //BSRR register

#define GPIOA_BRR_REG			*(uint32_t*)(GPIOA_BASE_ADDR+0x28U) //BRR register

/*Reset clock control register macros */

#define	RCC_BASE_ADDR			(uint32_t)(0x40021000U) //RCC base address

#define	RCC_AHBENR_REG			*((volatile uint32_t*)(uint32_t)(RCC_BASE_ADDR+0x14U)) //AHBEN register

/* LED and button macros */

#define LED_ON					GPIOA_BSRR_REG |= (1<<4)

#define LED_OFF					GPIOA_BRR_REG |= (1<<4)

#define BUTTON_GET_STATE		GPIOA_IDR_REG & (1<<3)


enum EDGE_TYPE {NONE=0, RISE=1, FALL=2};

#endif /* ASSIGNMENT_H_ */
