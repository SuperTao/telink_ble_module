/********************************************************************************************************
 * @file     usbgamepad.h 
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
/*
 * usbgamepad.h
 *
 *  Created on: 2017-3-8
 *      Author: Telink
 */

#ifndef USBGAMEPAD_H_
#define USBGAMEPAD_H_

typedef struct {
    u8 z;
    u8 Rz;
    u8 x ;
    u8 y;
    u16 gamekey;   // include 16 keys
} usbgamepad_hid_report_t;

int usbgamepad_report(u8 *data);


#endif /* USBGAMEPAD_H_ */
