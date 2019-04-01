/********************************************************************************************************
 * @file     CDCClassCommon.h 
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
#include "StdDescriptors.h"

#if defined(__cplusplus)
extern "C" {
#endif



#define CDC_CONTROL_LINE_OUT_DTR         BIT(0)
#define CDC_CONTROL_LINE_OUT_RTS         BIT(1)
#define CDC_CONTROL_LINE_IN_DCD          BIT(0)
#define CDC_CONTROL_LINE_IN_DSR          BIT(1)
#define CDC_CONTROL_LINE_IN_BREAK        BIT(2)
#define CDC_CONTROL_LINE_IN_RING         BIT(3)
#define CDC_CONTROL_LINE_IN_FRAMEERROR   BIT(4)
#define CDC_CONTROL_LINE_IN_PARITYERROR  BIT(5)
#define CDC_CONTROL_LINE_IN_OVERRUNERROR BIT(6)

#define CDC_FUNCTIONAL_DESCRIPTOR(DataSize) \
	 struct \
	 { \
		  USB_Descriptor_Hdr_t Header; \
		  u8 SubType; \
		  u8 Data[DataSize]; \
	 }

//replace macro
#define CDC_CSCP_NoSpecificSubclass			CDC_CSCP_NoSpecific_Subclass
#define CDC_CSCP_NoSpecificProtocol			CDC_CSCP_NoSpecific_Protocol
#define CDC_CSCP_NoDataSubclass				CDC_CSCP_NoData_Subclass
#define CDC_CSCP_NoDataProtocol				CDC_CSCP_NoData_Protocol
#define CDC_CSCP_ATCommandProtocol			CDC_CSCP_ATCmd_Protocol
#define CDC_CSCP_CDCClass  					CDC_CSCP_CDC_Class
#define CDC_CSCP_ACMSubclass 				CDC_CSCP_ACM_Subclass
#define CDC_CSCP_CDCDataClass				CDC_CSCP_CDCData_Class
#define CDC_CSCP_VendorSpecificProtocol 	CDC_CSCP_VendorSpecific_Protocol

enum CDC_Descriptor_ClassSubclass_Protocol_t
{
	CDC_CSCP_NoSpecific_Subclass = 0x00,
	CDC_CSCP_NoSpecific_Protocol = 0x00,
	CDC_CSCP_NoData_Subclass = 0x00,
	CDC_CSCP_NoData_Protocol = 0x00,
	CDC_CSCP_ATCmd_Protocol = 0x01,
	CDC_CSCP_CDC_Class = 0x02,
	CDC_CSCP_ACM_Subclass = 0x02,
	CDC_CSCP_CDCData_Class = 0x0A,
	CDC_CSCP_VendorSpecific_Protocol = 0xFF,
};

//replace macro
#define CDC_REQ_SendEncapsulatedCommand 	CDC_REQ_SendEncapsulated_Cmd
#define CDC_REQ_GetEncapsulatedResponse  	CDC_REQ_GetEncapsulated_Rsp
#define CDC_REQ_SetLineEncoding          	CDC_REQ_SetLine_Encoding
#define CDC_REQ_GetLineEncoding         	CDC_REQ_GetLine_Encoding
#define CDC_REQ_SetControlLineState    		CDC_REQ_SetControlLine_State

enum CDC_Class_Requestions_t
{
	CDC_REQ_SendEncapsulated_Cmd,
	CDC_REQ_GetEncapsulated_Rsp,
	CDC_REQ_SetLine_Encoding = 0x20,
	CDC_REQ_GetLine_Encoding,
	CDC_REQ_SetControlLine_State,
	CDC_REQ_SendBreak,
};

enum CDC_Class_Notifications_t
{
	CDC_NOTIF_Serial_State = 0x20,
};


enum CDC_Descriptor_Subtypes_t
{
	CDC_DSUBTYPE_CSInterface_Header,
	CDC_DSUBTYPE_CSInterface_CallManagement,
	CDC_DSUBTYPE_CSInterface_ACM,
	CDC_DSUBTYPE_CSInterface_DirectLine,
	CDC_DSUBTYPE_CSInterface_TelephoneRinger,
	CDC_DSUBTYPE_CSInterface_TelephoneCall,
	CDC_DSUBTYPE_CSInterface_Union,
	CDC_DSUBTYPE_CSInterface_CountrySelection,
	CDC_DSUBTYPE_CSInterface_TelephoneOpModes,
	CDC_DSUBTYPE_CSInterface_USBTerminal,
	CDC_DSUBTYPE_CSInterface_NetworkChannel,
	CDC_DSUBTYPE_CSInterface_ProtocolUnit,
	CDC_DSUBTYPE_CSInterface_ExtensionUnit,
	CDC_DSUBTYPE_CSInterface_MultiChannel,
	CDC_DSUBTYPE_CSInterface_CAPI,
	CDC_DSUBTYPE_CSInterface_Ethernet,
	CDC_DSUBTYPE_CSInterface_ATM,
};

enum CDC_LineEncoding_Formats_t
{
	CDC_LINEENCODING_OneStopBit,
	CDC_LINEENCODING_OneAndAHalfStopBits,
	CDC_LINEENCODING_TwoStopBits,
};

enum CDC_LineEncoding_Parity_t
{
	CDC_PARITY_None,
	CDC_PARITY_Odd,
	CDC_PARITY_Even,
	CDC_PARITY_Mark,
	CDC_PARITY_Space,
};

typedef struct
{
	USB_Descriptor_Hdr_t Header;
	u8 Subtype;
	u16 CDCSpecification;
} USB_CDC_Descriptor_FunctionalHeader_t;

typedef struct
{
	u8 bFunctionLength;
	u8 bDescriptorType;
	u8 bDescriptorSubType;
	u16 bcdCDC;
} USB_CDC_StdDescriptor_FunctionalHeader_t;

typedef struct
{
	USB_Descriptor_Hdr_t Header;
	u8 Subtype;
	u8 Capabilities;
} USB_CDC_Descriptor_FunctionalACM_t;

typedef struct
{
	u8 bFunctionLength;
	u8 bDescriptorType;
	u8 bDescriptorSubType;
	u8 bmCapabilities;
} USB_CDC_StdDescriptor_FunctionalACM_t;

typedef struct
{
	USB_Descriptor_Hdr_t Header;
	u8 Subtype;
	u8 MasterInterfaceNumber;
	u8 SlaveInterfaceNumber;
} USB_CDC_Descriptor_FunctionalUnion_t;

typedef struct
{
	u8 bFunctionLength;
	u8 bDescriptorType;
	u8 bDescriptorSubType;
	u8 bMasterInterface;
	u8 bSlaveInterface0;
} USB_CDC_StdDescriptor_FunctionalUnion_t;

typedef struct
{
	u32 BaudRateBPS;
	u8 CharFormat;
	u8 ParityType;
	u8 DataBits;
} CDC_LineEncoding_t;

/* Disable C linkage for C++ Compilers: */
#if defined(__cplusplus)
	}
#endif
