/********************************************************************************************************
 * @file     HIDClassDevice.h 
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

#pragma once

#include "../common/types.h"

#if defined(__cplusplus)
	extern "C" {
#endif

typedef struct
{
	u8  InterfaceNumber;
	u8  ReportINEndpointNumber;
	u16 ReportINEndpointSize;
	bool ReportINEndpointDoubleBank;
	void* PrevReportINBuffer;
	u8  PrevReportINBufferSize;
} usbhid_config_t;

typedef struct
{
	bool UsingReportProtocol;
	u16 PrevFrameNum;
	u16 IdleCount;
	u16 IdleMSRemaining;
} usbhid_state_t;



#if defined(__cplusplus)
	}
#endif


