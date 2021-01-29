/***********************************************/
/* Author : Ahmed Gamal                       */
/* Version: 01                                 */
/* Date   : 30 Aug 2020                         */
/***********************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H
typedef struct
{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
	
}EXTI_Type;

#define EXTI ((volatile EXTI_Type*))

#endif