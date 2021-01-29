/***********************************************/
/* Author : Ahmed Gamal                        */
/* Version: 01                                 */
/* Date   : 12 Aug 2020                        */
/***********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"

void GPIO_voidSetPinDirection(u8 copy_u8Port,u8 copy_u8Pin,u8 copy_u8Mode)
{
	if(copy_u8Pin < 8)            //CRL
	{
		switch(copy_u8Port)
		{
			case GPIOA:
			       GPIOA_CRL &= ~((0b1111)<<(copy_u8Pin * 4)); //clear for CRL
				   GPIOA_CRL |=  ((copy_u8Mode)<<(copy_u8Pin * 4));
				   break;
			
			case GPIOB:
			       GPIOB_CRL &= ~((0b1111)<<(copy_u8Pin * 4)); //clear for CRL
				   GPIOB_CRL |=  ((copy_u8Mode)<<(copy_u8Pin * 4));
				   break;
			
			case GPIOC:
			       GPIOC_CRL &= ~((0b1111)<<(copy_u8Pin * 4)); //clear for CRL
				   GPIOC_CRL |=  ((copy_u8Mode)<<(copy_u8Pin * 4));
				   break;
		    default : break;
		}
		
	}
	else if(copy_u8Pin < 16)      //CRH
	{
		copy_u8Pin = copy_u8Pin - 8;
		switch(copy_u8Port)
		{
			case GPIOA:
			       GPIOA_CRH &= ~((0b1111)<<(copy_u8Pin * 4)); //clear for CRL
				   GPIOA_CRH |=  ((copy_u8Mode)<<(copy_u8Pin * 4));
				   break;
			
			case GPIOB:
			       GPIOB_CRH &= ~((0b1111)<<(copy_u8Pin * 4)); //clear for CRL
				   GPIOB_CRH |=  ((copy_u8Mode)<<(copy_u8Pin * 4));
				   break;
			
			case GPIOC:
			       GPIOC_CRH &= ~((0b1111)<<(copy_u8Pin * 4)); //clear for CRL
				   GPIOC_CRH |=  ((copy_u8Mode)<<(copy_u8Pin * 4));
				   break;
			default : break;
		}
		
	}

	
}
void GPIO_voidSetPinValue(u8 copy_u8Port,u8 copy_u8Pin,u8 copy_u8Value)
{
	if(copy_u8Value == HIGH)            
	{
		switch(copy_u8Port)
		{
			case GPIOA:
			       SET_BIT(GPIOA_ODR,copy_u8Pin);
				   break;
			
			case GPIOB:
			       SET_BIT(GPIOB_ODR,copy_u8Pin);
				   break;
			
			case GPIOC:
			       SET_BIT(GPIOC_ODR,copy_u8Pin);
				   break;
		    default : break;
		}
		
	}
	else if(copy_u8Value == LOW)      
	{
		switch(copy_u8Port)
		{
			case GPIOA:
			       CLR_BIT(GPIOA_ODR,copy_u8Pin);
				   break;
			
			case GPIOB:
			       CLR_BIT(GPIOB_ODR,copy_u8Pin);
				   break;
			
			case GPIOC:
			       CLR_BIT(GPIOC_ODR,copy_u8Pin);
				   break;
		    default : break;
		}
	}
		
}
u8 GPIO_u8GetPinValue(u8 copy_u8Port,u8 copy_u8Pin)
{
	u8 Loc_u8Result  = 0;
	switch(copy_u8Port)
		{
			case GPIOA:
			       Loc_u8Result = GET_BIT(GPIOA_IDR,copy_u8Pin);
				   break;
			
			case GPIOB:
			       Loc_u8Result = GET_BIT(GPIOB_IDR,copy_u8Pin);
				   break;
			
			case GPIOC:
			       Loc_u8Result = GET_BIT(GPIOC_IDR,copy_u8Pin);
				   break;
		    default : break;
		}
	
	return Loc_u8Result;
	
	
}

