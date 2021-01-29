/***********************************************/
/* Author : Ahmed Gamal                        */
/* Version: 01                                 */
/* Date   : 13 sep 2020                        */
/***********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"




void MDMA_voidChannelInit(void)
{
	/*
      1- Mem to Mem
      2-very high
	  3-source size , destination size = 32 bit
	  4-MINC , PINC activated
	  5-No circular = no repet
	  6-Direction :
	  7-transfer interrupt enable
	*/
	#if(CHANNEL_ID == 1)
		DMA -> Channel[0].CCR = 
	
	
}
void MDMA_voidChannelSart(u32 * Copy_ptr_u32_SrcAdress , u32 * Copy_ptr_u32_DesAdress , u16 Copy_u16BlockLength )
{
	/*  Make sure channel is disable*/
	CLR_BIT(DMA -> Channel[0].CCR , 0);
	/*  Write the address*/
	DMA -> Channel[0].CPAR  = Copy_ptr_u32_SrcAdress;
	DMA -> Channel[0].CMAR  = Copy_ptr_u32_DesAdress;
	/*  Block Length*/
	DMA -> Channel[0].CNDTR = Copy_u16BlockLength;
	/*  Make sure channel is Enable*/
	 SET_BIT(DMA -> Channel[0].CCR , 0);
	
}
 