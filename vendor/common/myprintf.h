/********************************************************************************************************
 * @file     myprintf.h 
 *
 * @brief    for TLSR chips
 *
 * @author	 telink
 *
 * @par      Copyright (c) Telink Semiconductor (Shanghai) Co., Ltd.
 *           All rights reserved.
 *           
 *			 The information contained herein is confidential and proprietary property of Telink 
 * 		     Semiconductor (Shanghai) Co., Ltd. and is available under the terms 
 *			 of Commercial License Agreement between Telink Semiconductor (Shanghai) 
 *			 Co., Ltd. and the licensee in separate contract or the terms described here-in. 
 *           This heading MUST NOT be removed from this file.
 *
 * 			 Licensees are granted free, non-transferable use of the information in this 
 *			 file under Mutual Non-Disclosure Agreement. NO WARRENTY of ANY KIND is provided. 
 *           
 *******************************************************************************************************/

#ifndef MYPRINTF_H
#define MYPRINTF_H

#if (PRINT_DEBUG_INFO)

void my_array_printf(char*data, int len);
int mini_printf(const char *format, ...);
void PrintHex(u8 x);

#define printf			mini_printf
#define	printfArray		arrayPrint
//#define	logPrint		mini_printf
//#define	logPrintArray	arrayPrint
#define	arrayPrint(arrayAddr,len)					\
{													\
	mini_printf("\n*********************************\n");		\
	unsigned char	i = 0;							\
	do{												\
		mini_printf(" %x",((unsigned char *)arrayAddr)[i++]);						\
	}while(i<len);										\
	mini_printf("\n*********************************\n");		\
}
#else
#define printf
#define	printfArray
#define	PrintHex
#endif

//#define debugBuffer (*(volatile unsigned char (*)[40])(0x8095d8))
#endif
