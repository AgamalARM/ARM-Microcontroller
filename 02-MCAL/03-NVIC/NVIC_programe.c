/***********************************************/
/* Author : Ahmed Gamal                       */
/* Version: 01                                */
/* Date   : 18 Aug 2020                       */
/***********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidInit(void)       //choice group bits and Sub bits
{
	#define SCB_AIRCR  *((u32*)0xE000ED0C)
	SCB_AIRCR = NVIC_GROUP_SUB_DISTRIBUTION ;
	
}
void MNVIC_voidSetPriority(u8 Copy_u8PeripheralIdx,u8 Copy_u8Priority)
{
	if(Copy_u8PeripheralIdx < 60)
	{
		NVIC_IPR[Copy_u8PeripheralIdx] = Copy_u8Priority ;
	}
	else
	{
		/*Report Error*/
	}
	
	
}
void MNVIC_voidEnableInterrupt (u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <= 31)
	{
		NVIC_ISER0 = (1 << copy_u8IntNumber);   //SET_BIT(NVIC_ISER0 , copy_u8IntNumber);
	}
	else if (copy_u8IntNumber <= 59)
	{
		copy_u8IntNumber -= 32;
		NVIC_ISER1 = (1 << copy_u8IntNumber);    //SET_BIT(NVIC_ISER1 , copy_u8IntNumber);
	}
	else
	{
		/*return Error*/
	}
}

void MNVIC_voidDisableInterrupt (u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <= 31)
	{
		NVIC_ICER0 = (1 << copy_u8IntNumber);   //SET_BIT(NVIC_ICER0 , copy_u8IntNumber);
	}
	else if (copy_u8IntNumber <= 59)
	{
		copy_u8IntNumber -= 32;
		NVIC_ICER1 = (1 << copy_u8IntNumber);    //SET_BIT(NVIC_ICER1 , copy_u8IntNumber);
	}
	else
	{
		/*return Error*/
	}
}

void MNVIC_voidSetPendingFlag (u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <= 31)
	{
		NVIC_ISPR0 = (1 << copy_u8IntNumber);   //SET_BIT(NVIC_ICER0 , copy_u8IntNumber);
	}
	else if (copy_u8IntNumber <= 59)
	{
		copy_u8IntNumber -= 32;
		NVIC_ISPR1 = (1 << copy_u8IntNumber);    //SET_BIT(NVIC_ICER1 , copy_u8IntNumber);
	}
	else
	{
		/*return Error*/
	}
}

void MNVIC_voidClearPendingFlag (u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <= 31)
	{
		NVIC_ICPR0 = (1 << copy_u8IntNumber);   //SET_BIT(NVIC_ICER0 , copy_u8IntNumber);
	}
	else if (copy_u8IntNumber <= 59)
	{
		copy_u8IntNumber -= 32;
		NVIC_ICPR1 = (1 << copy_u8IntNumber);    //SET_BIT(NVIC_ICER1 , copy_u8IntNumber);
	}
	else
	{
		/*return Error*/
	}
}

u8 MNVIC_u8GetActiveFlag (u8 copy_u8IntNumber)
{
	u8 Local_u8Result = 0;
	if(copy_u8IntNumber <= 31)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0 , copy_u8IntNumber);
	}
	else if (copy_u8IntNumber <= 59)
	{
		copy_u8IntNumber -= 32;
		Local_u8Result = GET_BIT(NVIC_IABR1 , copy_u8IntNumber);
	}
	else
	{
		/*return Error*/
	}
	
	return Local_u8Result;
}



