/***********************************************/
/* Author : Ahmed Gamal                       */
/* Version: 01                                 */
/* Date   : 18 Aug 2020                         */
/***********************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void MNVIC_voidInit(void);
void MNVIC_voidSetPriority(u8 Copy_u8PeripheralIdx,u8 Copy_u8Priority);
void MNVIC_voidEnableInterrupt  (u8 copy_u8IntNumber);
void MNVIC_voidDisableInterrupt (u8 copy_u8IntNumber);
void MNVIC_voidSetPendingFlag   (u8 copy_u8IntNumber);
void MNVIC_voidClearPendingFlag (u8 copy_u8IntNumber);
u8 MNVIC_u8GetActiveFlag        (u8 copy_u8IntNumber);

#endif