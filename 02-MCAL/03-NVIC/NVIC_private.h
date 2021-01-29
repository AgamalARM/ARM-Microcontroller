/***********************************************/
/* Author : Ahmed Gamal                       */
/* Version: 01                                 */
/* Date   : 18 Aug 2020                         */
/***********************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/*Register Definitions*/
/*  0xE000E100  Base Address*/
/*The base address of the
main NVIC register block is 0xE000E100. The NVIC_STIR register is located in a separate
block at 0xE000EF00.*/



#define NVIC_ISER0       *((u32*)0xE000E100)  // Enable External Interrupt from 0 to 31
#define NVIC_ISER1       *((u32*)0xE000E104)  // Enable External Interrupt from 32 to 59

#define NVIC_ICER0       *((u32*)0xE000E180)  // Disable External Interrupt from 0 to 31
#define NVIC_ICER1       *((u32*)0xE000E184)  // Disable External Interrupt from 32 to 59

#define NVIC_ISPR0       *((u32*)0xE000E200)
#define NVIC_ISPR1       *((u32*)0xE000E204)

#define NVIC_ICPR0       *((u32*)0xE000E280)
#define NVIC_ICPR1       *((u32*)0xE000E284)

#define NVIC_IABR0       *((volatile u32*)0xE000E300)  //volatile at read only register
#define NVIC_IABR1       *((volatile u32*)0xE000E304)

#define NVIC_IPR          ((u8*)0xE000E400)          //pointer

#define NVIC_GROUP_4_SUB_0    0x05FA0300
#define NVIC_GROUP_3_SUB_1    0x05FA0400
#define NVIC_GROUP_2_SUB_2    0x05FA0500
#define NVIC_GROUP_1_SUB_3    0x05FA0600
#define NVIC_GROUP_0_SUB_4    0x05FA0700

#define NVIC_GROUP_SUB_DISTRIBUTION   NVIC_GROUP_2_SUB_2              

#endif