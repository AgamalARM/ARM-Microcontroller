/***********************************************/
/* Author : Ahmed Gamal                        */
/* Version: 01                                 */
/* Date   : 28 Aug 2020                        */
/***********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

void (*callback)(void); // callback pointer to function

/*Apply Clock choice from configuration file
  Disable SysTick interrupt
  Disable SysTick                            */
void MSTK_voidInit(void)
{
	#if(STK_CLOCK_SOURCE == AHB_DIV_8)
	    STK_CTRL = 0x00000000;    //Clock Source (AHB/8)
    #elif (STK_CLOCK_SOURCE == AHB)
		STK_CTRL = 0x00000004;    //Clock Source (AHB)
    #else
		#error("you choose Wrong Clock Source")
	#endif
	
}
/*Apply CountTicks 
  Disable SysTick interrupt
  Enable SysTick   
  Syncronous Function                         */
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	/*Enable SysTick*/
	STK_LOAD = Copy_u32Ticks;
  /*Enable SysTick*/
	STK_CTRL |= 0x00000001;
  /*Wait until SysTick Flag = 1*/
	while((GET_BIT(STK_CTRL,16)) == 0);	
} 
/*Apply CountTicks and the Function I want to run when SysTick Interrupt Fired
  Enable SysTick interrupt
  Enable SysTick 
  Interval Single  
  ASyncronous Function                                                           */
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks , void (*Copy_ptr)(void))
{
	STK_LOAD = Copy_u32Ticks;
	
	/*Enable SysTick interrupt and Enable SysTick*/   
	STK_CTRL |= 0x00000003;
	
	callback = Copy_ptr;
	
}
/*Apply CountTicks and the Function I want to run when SysTick Interrupt Fired
  Enable SysTick interrupt
  Enable SysTick 
  Interval Periodic  
  ASyncronous Function                                                           */
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void (*Copy_ptr)(void))
{
	STK_LOAD = Copy_u32Ticks;
	
	/*Enable SysTick interrupt and Enable SysTick*/   
	STK_CTRL |= 0x00000003;
	
	callback = Copy_ptr;	
}
void MSTK_voidStopInterval(void)
{
	STK_CTRL = 0;
	STK_LOAD = 0;
	STK_VAL  = 0;
}
u32  MSTK_u32GetElapsedTime(void)
{
	u32 Local_ElapsedTime = 0;
	Local_ElapsedTime = STK_LOAD - STK_VAL ;
	return Local_ElapsedTime;
	
}
u32  MSTK_u32GetRemainingTime(void )
{
	
	u32 Local_RemainingTime = 0;
	Local_ElapsedTime = STK_VAL ;
	return Local_RemainingTime;
}



void SysTick_Handler(void)
{
	callback();
	STK_LOAD = 0;
	STK_VAL  = 0;	
}