/********************************************************************************************************
 * @file     usbmouse_i.h 
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

#include "usbmouse.h"
#include "../drivers/usb.h"
#include "../drivers/usbhw.h"
#include "../drivers/usbhw_i.h"
#include "../../vendor/common/default_config.h"
/** HID class report descriptor. This is a special descriptor constructed with values from the
 *  USBIF HID class specification to describe the reports and capabilities of the HID device. This
 *  descriptor is parsed by the host and its contents used to determine what data (and in what encoding)
 *  the device will send, and what it may be sent back from the host. Refer to the HID specification for
 *  more details on HID report descriptors.
 */

static const USB_Descriptor_HIDReport_Datatype_t mouse_report_desc[] = {
	0x05, 0x01, // usage_page (generic desktop)
	0x09, 0x02, // usage (mouse)
	0xa1, 0x01, // collection (application)
	0x85, USB_HID_MOUSE, //report id 01
	0x09, 0x01, // usage (pointer)
	0xa1, 0x00, // collection (physical)
	0x05, 0x09, // usage_page (button)
	// 1 is mouse left button,2 is mouse right button,3 is central button
	0x19, 0x01, // usage_minimum (button 1)
	0x29, 0x05, // usage_maximum (button 5)
	0x15, 0x00, // logical_minimum (0)
	0x25, 0x01, // logical_maximum (1)
	0x95, 0x05, // report_count (3)
	0x75, 0x01, // report_size (1)
	0x81, 0x02, // input (data,var,abs)
	0x95, 0x01, // report_count (1)
	0x75, 0x03, // report_size (3)

	0x81, 0x01, // input (cnst,var,abs)
	0x05, 0x01, // usage_page (generic desktop)
	0x09, 0x30, // usage (x)
	0x09, 0x31, // usage (y)
	0x15, 0x81, // logical_minimum (-127)
	0x25, 0x7f, // logical_maximum (127)
	0x75, 0x08, // report_size (16)
	0x95, 0x02, // report_count (2)
	0x81, 0x06, // input (data,var,rel)

	0x09, 0x38, // usage (wheel)
	0x15, 0x81, // logical_minimum (-127)
	0x25, 0x7f, // logical_maximum (127)
	0x75, 0x08, // report_size (16)
	0x95, 0x01, // report_count (1)
	0x81, 0x06, // input (data,var,rel)

	0xc0, //end of collection
	0xc0, //end of collection

#if (ONEKEY_WEB==0)
	// begin of media key
	0x05,0x0c,     //global, usage page (follow 1 bytes) consumer page
	0x09,0x01,     //local,  usage ID 01  Consumer Control
	0xA1,0x01,     //main, collection
	0x85,USB_HID_KB_MEDIA,  //global, report ID 0x03
	0x75,0x10,     //global, report size 16 bits
	0x95,0x02,     //global, report count 2
	0x15,0x01,     //global, min  0x01
	0x26,0x9c,0x02,//global, max  0x29c
#if CHIP_EOP_ERROR
	0x19,0x01,     //local, min   0x01
	0x2a,0xff,0x02,//local, max    0x2ff
#else
	0x19,0x01,     //local, min   0x01
	0x2a,0x8c,0x02,//local, max    0x28c
#endif
	0x81,0x00,     //main,  input data varible, absolute
	0xc0,          //main, end collection

	0x05,0x01,     //gobal,  USAGE_PAGE 1 (Generic Desktop)
	0x09,0x80,     //local, usage ID 0x80 system control
	0xa1,0x01,     //main conllection
	0x85,USB_HID_KB_SYS,     //global report ID 0x4
	0x75,0x02,     //global, report size 2
	0x95,0x01,     //report count  1
	0x15,0x01,     //global min 01
	0x25,0x03,     //gobal, max 3
	0x09,0x82,     //local usage ID 0x82 system sleep
	0x09,0x81,     //local usage ID 0x81 system power down
	0x09,0x83,     //local usage ID 0x83 system wakeup
	0x81,0x60,     //main, input data, var, abs, No Prefer, NULL state
	0x75,0x06,     //global report size 6
	0x81,0x03,     //main input, constant, array
	0xc0,          //end of collection
	// end of media key
#endif

    //need Jensen's help: report ID 5
    HID_RPT_USAGE_PAGE(8, 0x01),     //global,  USAGE_PAGE 1 (Generic Desktop)
	0x09,0x00,     //usage undefined
	0xa1,0x01,     //main collection
	0x85,0x05,     //global report ID 0x5
	0x06,0x00,0xff,//global usage page
	0x09,0x01,     //local,  usage ID 01  Consumer Control
	0x15,0x81,     //global min 81
	0x25,0x7f,     //global, max 7f
	0x75,0x08,     //global, report size 8
	0x95,0x07,     //report count  7
	0xb1,0x02,     //feature (data, var, abs)
	HID_RPT_END_COLLECTION(0),//main, end collection
};

static inline u8* usbmouse_get_report_desc(void) {
	return (u8*) (mouse_report_desc);
}

static inline u16 usbmouse_get_report_desc_size(void) {
	return sizeof(mouse_report_desc);
}

