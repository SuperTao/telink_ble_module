/********************************************************************************************************
 * @file     gpio_8266.h 
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
#include "../common/bit.h"
#include "../common/utility.h"
#include "../mcu/compiler.h"
#include "../mcu/register.h"
#include "gpio_default_8266.h"

enum{
	    GPIO_PA0 = 0x000 | BIT(0), GPIO_SWS=GPIO_PA0,
		GPIO_PA1 = 0x000 | BIT(1), GPIO_PWM3=GPIO_PA1,
		GPIO_PA2 = 0x000 | BIT(2), GPIO_MSDI=GPIO_PA2,
		GPIO_PA3 = 0x000 | BIT(3), GPIO_MCLK=GPIO_PA3,
		GPIO_PA4 = 0x000 | BIT(4), GPIO_GP18=GPIO_PA4,
		GPIO_PA5 = 0x000 | BIT(5), GPIO_PWM4=GPIO_PA5,
		GPIO_PA6 = 0x000 | BIT(6), GPIO_GP19=GPIO_PA6,
		GPIO_PA7 = 0x000 | BIT(7), GPIO_SWM=GPIO_PA7,

		GPIO_PB0 = 0x100 | BIT(0), GPIO_PWM5=GPIO_PB0,
		GPIO_PB1 = 0x100 | BIT(1), GPIO_GP20=GPIO_PB1,
		GPIO_PB2 = 0x100 | BIT(2), GPIO_MSDO=GPIO_PB2,
		GPIO_PB3 = 0x100 | BIT(3), GPIO_MSCN=GPIO_PB3,
		GPIO_PB4 = 0x100 | BIT(4), GPIO_GP21=GPIO_PB4,
		GPIO_PB5 = 0x100 | BIT(5), GPIO_DM=GPIO_PB5,
		GPIO_PB6 = 0x100 | BIT(6), GPIO_DP=GPIO_PB6,
		GPIO_PB7 = 0x100 | BIT(7), GPIO_GP0=GPIO_PB7,

		GPIO_PC0 = 0x200 | BIT(0), GPIO_PWM0=GPIO_PC0,
		GPIO_PC1 = 0x200 | BIT(1), GPIO_GP1=GPIO_PC1,
		GPIO_PC2 = 0x200 | BIT(2), GPIO_PWM1=GPIO_PC2,
		GPIO_PC3 = 0x200 | BIT(3), GPIO_GP2=GPIO_PC3,
		GPIO_PC4 = 0x200 | BIT(4), GPIO_PWM2=GPIO_PC4,
		GPIO_PC5 = 0x200 | BIT(5), GPIO_GP3=GPIO_PC5,
		GPIO_PC6 = 0x200 | BIT(6), GPIO_GP4=GPIO_PC6, GPIO_UTX=GPIO_PC6,
		GPIO_PC7 = 0x200 | BIT(7), GPIO_GP5=GPIO_PC7, GPIO_URX=GPIO_PC7,

		GPIO_PD0 = 0x300 | BIT(0), GPIO_GP6=GPIO_PD0, GPIO_CTS=GPIO_PD0,
		GPIO_PD1 = 0x300 | BIT(1), GPIO_GP7=GPIO_PD1, GPIO_RTS=GPIO_PD1,
		GPIO_PD2 = 0x300 | BIT(2), GPIO_GP8=GPIO_PD2,
		GPIO_PD3 = 0x300 | BIT(3), GPIO_GP9=GPIO_PD3,
		GPIO_PD4 = 0x300 | BIT(4), GPIO_GP10=GPIO_PD4,
		GPIO_PD5 = 0x300 | BIT(5), GPIO_GP11=GPIO_PD5,
		GPIO_PD6 = 0x300 | BIT(6), GPIO_GP12=GPIO_PD6,
		GPIO_PD7 = 0x300 | BIT(7), GPIO_GP13=GPIO_PD7,

		GPIO_PE0 = 0x400 | BIT(0), GPIO_GP14=GPIO_PE0,
		GPIO_PE1 = 0x400 | BIT(1), GPIO_DMIC_CK=GPIO_PE1,
		GPIO_PE2 = 0x400 | BIT(2), GPIO_DMIC_DI=GPIO_PE2,
		GPIO_PE3 = 0x400 | BIT(3), GPIO_GP15=GPIO_PE3,
		GPIO_PE4 = 0x400 | BIT(4), GPIO_GP16=GPIO_PE4, GPIO_SDMP=GPIO_PE4,
		GPIO_PE5 = 0x400 | BIT(5), GPIO_GP17=GPIO_PE5, GPIO_SDMN=GPIO_PE5,
		GPIO_PE6 = 0x400 | BIT(6), GPIO_CN=GPIO_PE6,
		GPIO_PE7 = 0x400 | BIT(7), GPIO_DI=GPIO_PE7,


		GPIO_PF0 = 0x500 | BIT(0), GPIO_DO=GPIO_PF0,
		GPIO_PF1 = 0x500 | BIT(1), GPIO_CK=GPIO_PF1,

		GPIO_MAX_COUNT = 56,
};

#define reg_gpio_in(i)				REG_ADDR8(0x580+((i>>8)<<3))
#define reg_gpio_ie(i)				REG_ADDR8(0x581+((i>>8)<<3))
#define reg_gpio_oen(i)				REG_ADDR8(0x582+((i>>8)<<3))
#define reg_gpio_out(i)				REG_ADDR8(0x583+((i>>8)<<3))
#define reg_gpio_pol(i)				REG_ADDR8(0x584+((i>>8)<<3))
#define reg_gpio_ds(i)				REG_ADDR8(0x585+((i>>8)<<3))

#define reg_gpio_gpio_func(i)		REG_ADDR8(0x586+((i>>8)<<3))
#define reg_gpio_config_func(i)		REG_ADDR8(0x5b0 +(i>>8))  	  //5b0 5b1 5b2 5b3 5b4 5b5
//#define reg_gpio_config_func1       REG_ADDR16(0x5b6)

#define reg_gpio_irq_wakeup_en(i)	REG_ADDR8(0x587+((i>>8)<<3))  // reg_irq_mask: FLD_IRQ_GPIO_EN

#define reg_gpio_irq_risc0_en(i)  REG_ADDR8(0x5b8 + (i >> 8))	  // reg_irq_mask: FLD_IRQ_GPIO_RISC0_EN
#define reg_gpio_irq_risc1_en(i)  REG_ADDR8(0x5c0 + (i >> 8))	  // reg_irq_mask: FLD_IRQ_GPIO_RISC1_EN
#define reg_gpio_irq_risc2_en(i)  REG_ADDR8(0x5c8 + (i >> 8))     // reg_irq_mask: FLD_IRQ_GPIO_RISC2_EN




#define reg_gpio_wakeup_irq  REG_ADDR8(0x5b5)
enum{
    FLD_GPIO_CORE_WAKEUP_EN  = BIT(2),
    FLD_GPIO_CORE_INTERRUPT_EN = BIT(3),
};

static inline void gpio_core_wakeup_enable_all (int en)
{
    if (en) {
        BM_SET(reg_gpio_wakeup_irq, FLD_GPIO_CORE_WAKEUP_EN);
    }
    else {
        BM_CLR(reg_gpio_wakeup_irq, FLD_GPIO_CORE_WAKEUP_EN);
    }
}

static inline void gpio_core_irq_enable_all (int en)
{
    if (en) {
        BM_SET(reg_gpio_wakeup_irq, FLD_GPIO_CORE_INTERRUPT_EN);
    }
    else {
        BM_CLR(reg_gpio_wakeup_irq, FLD_GPIO_CORE_INTERRUPT_EN);
    }
}

static inline int gpio_is_output_en(u32 pin){
	return !BM_IS_SET(reg_gpio_oen(pin), pin & 0xff);
}

static inline int gpio_is_input_en(u32 pin){
	return BM_IS_SET(reg_gpio_ie(pin), pin & 0xff);
}

static inline void gpio_set_output_en(u32 pin, u32 value){
	u8	bit = pin & 0xff;
	if(!value){
		BM_SET(reg_gpio_oen(pin), bit);
	}else{
		BM_CLR(reg_gpio_oen(pin), bit);
	}
}

static inline void gpio_set_input_en(u32 pin, u32 value){
	u8	bit = pin & 0xff;
	if(value){
		BM_SET(reg_gpio_ie(pin), bit);
	}else{
		BM_CLR(reg_gpio_ie(pin), bit);
	}
}

static inline void gpio_set_data_strength(u32 pin, u32 value){
	u8	bit = pin & 0xff;
	if(value){
		BM_SET(reg_gpio_ds(pin), bit);
	}else{
		BM_CLR(reg_gpio_ds(pin), bit);
	}
}

static inline void gpio_write(u32 pin, u32 value){
	u8	bit = pin & 0xff;
	if(value){
		BM_SET(reg_gpio_out(pin), bit);
	}else{
		BM_CLR(reg_gpio_out(pin), bit);
	}
}

static inline void gpio_toggle(u32 pin) {
	reg_gpio_out(pin) ^= (pin & 0xFF);
}

static inline u32 gpio_read(u32 pin){
	return BM_IS_SET(reg_gpio_in(pin), pin & 0xff);
}

static inline u32 gpio_read_cache(u32 pin, u8 *p){
	return p[pin>>8] & (pin & 0xff);
}

static inline void gpio_read_all(u8 *p){
	p[0] = REG_ADDR8(0x580);
	p[1] = REG_ADDR8(0x588);
	p[2] = REG_ADDR8(0x590);
	p[3] = REG_ADDR8(0x598);
	p[4] = REG_ADDR8(0x5a0);
	p[5] = REG_ADDR8(0x5a8);
}



static inline void gpio_set_interrupt_pol(u32 pin, u32 falling){
	u8	bit = pin & 0xff;
	if(falling){
		BM_SET(reg_gpio_pol(pin), bit);
	}else{
		BM_CLR(reg_gpio_pol(pin), bit);
	}
}



static inline void gpio_en_interrupt(u32 pin, int en){  // reg_irq_mask: FLD_IRQ_GPIO_EN
	u8	bit = pin & 0xff;
	if(en){
		BM_SET(reg_gpio_irq_wakeup_en(pin), bit);
	}
	else{
		BM_CLR(reg_gpio_irq_wakeup_en(pin), bit);
	}
}

static inline void gpio_set_interrupt(u32 pin, u32 falling){
	u8	bit = pin & 0xff;
	BM_SET(reg_gpio_irq_wakeup_en(pin), bit);
	if(falling){
		BM_SET(reg_gpio_pol(pin), bit);
	}else{
		BM_CLR(reg_gpio_pol(pin), bit);
	}
}


static inline void gpio_en_interrupt_risc0(u32 pin, int en){  // reg_irq_mask: FLD_IRQ_GPIO_RISC0_EN
	u8	bit = pin & 0xff;
	if(en){
		BM_SET(reg_gpio_irq_risc0_en(pin), bit);
	}
	else{
		BM_CLR(reg_gpio_irq_risc0_en(pin), bit);
	}
}

static inline void gpio_set_interrupt_risc0(u32 pin, u32 falling){
	u8	bit = pin & 0xff;
	BM_SET(reg_gpio_irq_risc0_en(pin), bit);
	if(falling){
		BM_SET(reg_gpio_pol(pin), bit);
	}else{
		BM_CLR(reg_gpio_pol(pin), bit);
	}
}

static inline void gpio_en_interrupt_risc1(u32 pin, int en){  // reg_irq_mask: FLD_IRQ_GPIO_RISC1_EN
	u8	bit = pin & 0xff;
	if(en){
		BM_SET(reg_gpio_irq_risc1_en(pin), bit);
	}
	else{
		BM_CLR(reg_gpio_irq_risc1_en(pin), bit);
	}
}

static inline void gpio_set_interrupt_risc1(u32 pin, u32 falling){
	u8	bit = pin & 0xff;
	BM_SET(reg_gpio_irq_risc1_en(pin), bit);
	if(falling){
		BM_SET(reg_gpio_pol(pin), bit);
	}else{
		BM_CLR(reg_gpio_pol(pin), bit);
	}
}

static inline void gpio_en_interrupt_risc2(u32 pin, int en){  // reg_irq_mask: FLD_IRQ_GPIO_RISC2_EN
	u8	bit = pin & 0xff;
	if(en){
		BM_SET(reg_gpio_irq_risc2_en(pin), bit);
	}
	else{
		BM_CLR(reg_gpio_irq_risc2_en(pin), bit);
	}
}

static inline void gpio_set_interrupt_risc2(u32 pin, u32 falling){
	u8	bit = pin & 0xff;
	BM_SET(reg_gpio_irq_risc2_en(pin), bit);
	if(falling){
		BM_SET(reg_gpio_pol(pin), bit);
	}else{
		BM_CLR(reg_gpio_pol(pin), bit);
	}
}





static inline void gpio_init(void){
	//return;
	reg_gpio_pa_setting1 =
		(PA0_INPUT_ENABLE<<8) 	| (PA1_INPUT_ENABLE<<9)	| (PA2_INPUT_ENABLE<<10)	| (PA3_INPUT_ENABLE<<11) |
		(PA4_INPUT_ENABLE<<12)	| (PA5_INPUT_ENABLE<<13)	| (PA6_INPUT_ENABLE<<14)	| (PA7_INPUT_ENABLE<<15) |
		((PA0_OUTPUT_ENABLE?0:1)<<16)	| ((PA1_OUTPUT_ENABLE?0:1)<<17) | ((PA2_OUTPUT_ENABLE?0:1)<<18)	| ((PA3_OUTPUT_ENABLE?0:1)<<19) |
		((PA4_OUTPUT_ENABLE?0:1)<<20)	| ((PA5_OUTPUT_ENABLE?0:1)<<21) | ((PA6_OUTPUT_ENABLE?0:1)<<22)	| ((PA7_OUTPUT_ENABLE?0:1)<<23) |
		(PA0_DATA_OUT<<24)	| (PA1_DATA_OUT<<25)	| (PA2_DATA_OUT<<26)	| (PA3_DATA_OUT<<27) |
		(PA4_DATA_OUT<<28)	| (PA5_DATA_OUT<<29)	| (PA6_DATA_OUT<<30)	| (PA7_DATA_OUT<<31) ;
	reg_gpio_pa_setting2 =
		(PA0_DATA_STRENGTH<<8)		| (PA1_DATA_STRENGTH<<9)| (PA2_DATA_STRENGTH<<10)	| (PA3_DATA_STRENGTH<<11) |
		(PA4_DATA_STRENGTH<<12)	| (PA5_DATA_STRENGTH<<13)	| (PA6_DATA_STRENGTH<<14)	| (PA7_DATA_STRENGTH<<15) |
		(PA0_FUNC==AS_GPIO ? BIT(16):0)	| (PA1_FUNC==AS_GPIO ? BIT(17):0)| (PA2_FUNC==AS_GPIO ? BIT(18):0)| (PA3_FUNC==AS_GPIO ? BIT(19):0) |
		(PA4_FUNC==AS_GPIO ? BIT(20):0)	| (PA5_FUNC==AS_GPIO ? BIT(21):0)| (PA6_FUNC==AS_GPIO ? BIT(22):0)| (PA7_FUNC==AS_GPIO ? BIT(23):0);

	reg_gpio_pb_setting1 =
		(PB0_INPUT_ENABLE<<8) 	| (PB1_INPUT_ENABLE<<9)	| (PB2_INPUT_ENABLE<<10)	| (PB3_INPUT_ENABLE<<11) |
		(PB4_INPUT_ENABLE<<12)	| (PB5_INPUT_ENABLE<<13)| (PB6_INPUT_ENABLE<<14)	| (PB7_INPUT_ENABLE<<15) |
		((PB0_OUTPUT_ENABLE?0:1)<<16)	| ((PB1_OUTPUT_ENABLE?0:1)<<17) | ((PB2_OUTPUT_ENABLE?0:1)<<18)	| ((PB3_OUTPUT_ENABLE?0:1)<<19) |
		((PB4_OUTPUT_ENABLE?0:1)<<20)	| ((PB5_OUTPUT_ENABLE?0:1)<<21) | ((PB6_OUTPUT_ENABLE?0:1)<<22)	| ((PB7_OUTPUT_ENABLE?0:1)<<23) |
		(PB0_DATA_OUT<<24)	| (PB1_DATA_OUT<<25)	| (PB2_DATA_OUT<<26)	| (PB3_DATA_OUT<<27) |
		(PB4_DATA_OUT<<28)	| (PB5_DATA_OUT<<29)	| (PB6_DATA_OUT<<30)	| (PB7_DATA_OUT<<31) ;
	reg_gpio_pb_setting2 =
		(PB0_DATA_STRENGTH<<8)	| (PB1_DATA_STRENGTH<<9)	| (PB2_DATA_STRENGTH<<10)	| (PB3_DATA_STRENGTH<<11) |
		(PB4_DATA_STRENGTH<<12)	| (PB5_DATA_STRENGTH<<13)	| (PB6_DATA_STRENGTH<<14)	| (PB7_DATA_STRENGTH<<15) |
		(PB0_FUNC==AS_GPIO ? BIT(16):0)	| (PB1_FUNC==AS_GPIO ? BIT(17):0)| (PB2_FUNC==AS_GPIO ? BIT(18):0)| (PB3_FUNC==AS_GPIO ? BIT(19):0) |
		(PB4_FUNC==AS_GPIO ? BIT(20):0)	| (PB5_FUNC==AS_GPIO ? BIT(21):0)| (PB6_FUNC==AS_GPIO ? BIT(22):0)| (PB7_FUNC==AS_GPIO ? BIT(23):0);

	reg_gpio_pc_setting1 =
		(PC0_INPUT_ENABLE<<8) 	| (PC1_INPUT_ENABLE<<9)	| (PC2_INPUT_ENABLE<<10)	| (PC3_INPUT_ENABLE<<11) |
		(PC4_INPUT_ENABLE<<12)	| (PC5_INPUT_ENABLE<<13)| (PC6_INPUT_ENABLE<<14)	| (PC7_INPUT_ENABLE<<15) |
		((PC0_OUTPUT_ENABLE?0:1)<<16)	| ((PC1_OUTPUT_ENABLE?0:1)<<17) | ((PC2_OUTPUT_ENABLE?0:1)<<18)	| ((PC3_OUTPUT_ENABLE?0:1)<<19) |
		((PC4_OUTPUT_ENABLE?0:1)<<20)	| ((PC5_OUTPUT_ENABLE?0:1)<<21) | ((PC6_OUTPUT_ENABLE?0:1)<<22)	| ((PC7_OUTPUT_ENABLE?0:1)<<23) |
		(PC0_DATA_OUT<<24)	| (PC1_DATA_OUT<<25)	| (PC2_DATA_OUT<<26)	| (PC3_DATA_OUT<<27) |
		(PC4_DATA_OUT<<28)	| (PC5_DATA_OUT<<29)	| (PC6_DATA_OUT<<30)	| (PC7_DATA_OUT<<31) ;
	reg_gpio_pc_setting2 =
		(PC0_DATA_STRENGTH<<8)	| (PC1_DATA_STRENGTH<<9)	| (PC2_DATA_STRENGTH<<10)	| (PC3_DATA_STRENGTH<<11) |
		(PC4_DATA_STRENGTH<<12)	| (PC5_DATA_STRENGTH<<13)	| (PC6_DATA_STRENGTH<<14)	| (PC7_DATA_STRENGTH<<15) |
		(PC0_FUNC==AS_GPIO ? BIT(16):0)	| (PC1_FUNC==AS_GPIO ? BIT(17):0)| (PC2_FUNC==AS_GPIO ? BIT(18):0)| (PC3_FUNC==AS_GPIO ? BIT(19):0) |
		(PC4_FUNC==AS_GPIO ? BIT(20):0)	| (PC5_FUNC==AS_GPIO ? BIT(21):0)| (PC6_FUNC==AS_GPIO ? BIT(22):0)| (PC7_FUNC==AS_GPIO ? BIT(23):0);

	reg_gpio_pd_setting1 =
		(PD0_INPUT_ENABLE<<8) 	| (PD1_INPUT_ENABLE<<9)	| (PD2_INPUT_ENABLE<<10)	| (PD3_INPUT_ENABLE<<11) |
		(PD4_INPUT_ENABLE<<12)	| (PD5_INPUT_ENABLE<<13)| (PD6_INPUT_ENABLE<<14)	| (PD7_INPUT_ENABLE<<15) |
		((PD0_OUTPUT_ENABLE?0:1)<<16)	| ((PD1_OUTPUT_ENABLE?0:1)<<17) | ((PD2_OUTPUT_ENABLE?0:1)<<18)	| ((PD3_OUTPUT_ENABLE?0:1)<<19) |
		((PD4_OUTPUT_ENABLE?0:1)<<20)	| ((PD5_OUTPUT_ENABLE?0:1)<<21) | ((PD6_OUTPUT_ENABLE?0:1)<<22)	| ((PD7_OUTPUT_ENABLE?0:1)<<23) |
		(PD0_DATA_OUT<<24)	| (PD1_DATA_OUT<<25)	| (PD2_DATA_OUT<<26)	| (PD3_DATA_OUT<<27) |
		(PD4_DATA_OUT<<28)	| (PD5_DATA_OUT<<29)	| (PD6_DATA_OUT<<30)	| (PD7_DATA_OUT<<31) ;
	reg_gpio_pd_setting2 =
		(PD0_DATA_STRENGTH<<8)	| (PD1_DATA_STRENGTH<<9)	| (PD2_DATA_STRENGTH<<10)	| (PD3_DATA_STRENGTH<<11) |
		(PD4_DATA_STRENGTH<<12)	| (PD5_DATA_STRENGTH<<13)	| (PD6_DATA_STRENGTH<<14)	| (PD7_DATA_STRENGTH<<15) |
		(PD0_FUNC==AS_GPIO ? BIT(16):0)	| (PD1_FUNC==AS_GPIO ? BIT(17):0)| (PD2_FUNC==AS_GPIO ? BIT(18):0)| (PD3_FUNC==AS_GPIO ? BIT(19):0) |
		(PD4_FUNC==AS_GPIO ? BIT(20):0)	| (PD5_FUNC==AS_GPIO ? BIT(21):0)| (PD6_FUNC==AS_GPIO ? BIT(22):0)| (PD7_FUNC==AS_GPIO ? BIT(23):0);

	reg_gpio_pe_setting1 =
		(PE0_INPUT_ENABLE<<8) 	| (PE1_INPUT_ENABLE<<9)	| (PE2_INPUT_ENABLE<<10)	| (PE3_INPUT_ENABLE<<11) |
		(PE4_INPUT_ENABLE<<12)	| (PE5_INPUT_ENABLE<<13)| (PE6_INPUT_ENABLE<<14)	| (PE7_INPUT_ENABLE<<15) |
		((PE0_OUTPUT_ENABLE?0:1)<<16)	| ((PE1_OUTPUT_ENABLE?0:1)<<17) | ((PE2_OUTPUT_ENABLE?0:1)<<18)	| ((PE3_OUTPUT_ENABLE?0:1)<<19) |
		((PE4_OUTPUT_ENABLE?0:1)<<20)	| ((PE5_OUTPUT_ENABLE?0:1)<<21) | ((PE6_OUTPUT_ENABLE?0:1)<<22)	| ((PE7_OUTPUT_ENABLE?0:1)<<23) |
		(PE0_DATA_OUT<<24)	| (PE1_DATA_OUT<<25)	| (PE2_DATA_OUT<<26)	| (PE3_DATA_OUT<<27) |
		(PE4_DATA_OUT<<28)	| (PE5_DATA_OUT<<29)	| (PE6_DATA_OUT<<30)	| (PE7_DATA_OUT<<31);
	reg_gpio_pe_setting2 =
		(PE0_DATA_STRENGTH<<8)	| (PE1_DATA_STRENGTH<<9)	| (PE2_DATA_STRENGTH<<10)	| (PE3_DATA_STRENGTH<<11) |
		(PE4_DATA_STRENGTH<<12)	| (PE5_DATA_STRENGTH<<13)	| (PE6_DATA_STRENGTH<<14)	| (PE7_DATA_STRENGTH<<15) |
		(PE0_FUNC==AS_GPIO ? BIT(16):0)	| (PE1_FUNC==AS_GPIO ? BIT(17):0)| (PE2_FUNC==AS_GPIO ? BIT(18):0)| (PE3_FUNC==AS_GPIO ? BIT(19):0) |
		(PE4_FUNC==AS_GPIO ? BIT(20):0)	| (PE5_FUNC==AS_GPIO ? BIT(21):0)| (PE6_FUNC==AS_GPIO ? BIT(22):0)| (PE7_FUNC==AS_GPIO ? BIT(23):0);

	reg_gpio_pf_setting1 =
		(PF0_INPUT_ENABLE<<8) 	| (PF1_INPUT_ENABLE<<9)	 |
		((PF0_OUTPUT_ENABLE?0:1)<<16)	| ((PF1_OUTPUT_ENABLE?0:1)<<17) |
		(PF0_DATA_OUT<<24)	| (PF1_DATA_OUT<<25);
	reg_gpio_pf_setting2 =
		(PF0_DATA_STRENGTH<<8)	| (PF1_DATA_STRENGTH<<9) |
		(PF0_FUNC==AS_GPIO ? BIT(16):0)	| (PF1_FUNC==AS_GPIO ? BIT(17):0);

	/*  do later
	reg_gpio_config_func = ((PA0_FUNC==AS_DMIC||PA4_FUNC==AS_DMIC) ? BITS(0,7):0) | (PA1_FUNC==AS_PWM ? BIT(2):0) |
		((PA2_FUNC==AS_UART||PA3_FUNC==AS_UART) ? BITS(3,5):0) |
		(PA2_FUNC==AS_PWM ? BIT(4):0) | (PA3_FUNC==AS_PWM ? BIT(6):0) |
		((PB0_FUNC==AS_SDM||PB1_FUNC==AS_SDM||PB6_FUNC==AS_SDM||PB7_FUNC==AS_SDM) ? BIT_RNG(12,15):0) |
		((PA0_FUNC==AS_I2S||PA1_FUNC==AS_I2S||PA2_FUNC==AS_I2S||PA3_FUNC==AS_I2S||PA4_FUNC==AS_I2S) ? (BIT_RNG(21,23)|BIT_RNG(29,30)):0);
	*/


		u8 areg = analog_read (0x0a) & 0x0f;

		analog_write (0x0a, areg | (PULL_WAKEUP_SRC_PA0<<4) |
							(PULL_WAKEUP_SRC_PA1<<6));

		analog_write (0x0b,  PULL_WAKEUP_SRC_PA2 |
							(PULL_WAKEUP_SRC_PA3<<2) |
							(PULL_WAKEUP_SRC_PA4<<4) |
							(PULL_WAKEUP_SRC_PA5<<6));

		analog_write (0x0c,  PULL_WAKEUP_SRC_PA6 |
							(PULL_WAKEUP_SRC_PA7<<2) |
							(PULL_WAKEUP_SRC_PB0<<4) |
							(PULL_WAKEUP_SRC_PB1<<6));

		analog_write (0x0d,  PULL_WAKEUP_SRC_PB2 |
							(PULL_WAKEUP_SRC_PB3<<2) |
							(PULL_WAKEUP_SRC_PB4<<4) |
							(PULL_WAKEUP_SRC_PB5<<6));

		analog_write (0x0e,  PULL_WAKEUP_SRC_PB6 |
							(PULL_WAKEUP_SRC_PB7<<2) |
							(PULL_WAKEUP_SRC_PC0<<4) |
							(PULL_WAKEUP_SRC_PC1<<6));

		analog_write (0x0f,  PULL_WAKEUP_SRC_PC2 |
							(PULL_WAKEUP_SRC_PC3<<2) |
							(PULL_WAKEUP_SRC_PC4<<4) |
							(PULL_WAKEUP_SRC_PC5<<6));

		analog_write (0x10,  PULL_WAKEUP_SRC_PC6 |
							(PULL_WAKEUP_SRC_PC7<<2) |
							(PULL_WAKEUP_SRC_PD0<<4) |
							(PULL_WAKEUP_SRC_PD1<<6));

		analog_write (0x11,  PULL_WAKEUP_SRC_PD2 |
							(PULL_WAKEUP_SRC_PD3<<2) |
							(PULL_WAKEUP_SRC_PD4<<4) |
							(PULL_WAKEUP_SRC_PD5<<6));

		analog_write (0x12,  PULL_WAKEUP_SRC_PD6 |
							(PULL_WAKEUP_SRC_PD7<<2) |
							(PULL_WAKEUP_SRC_PE0<<4) |
							(PULL_WAKEUP_SRC_PE1<<6));

		analog_write (0x13,  PULL_WAKEUP_SRC_PE2 |
							(PULL_WAKEUP_SRC_PE3<<2) |
							(PULL_WAKEUP_SRC_PE4<<4) |
							(PULL_WAKEUP_SRC_PE5<<6));

		analog_write (0x14,  PULL_WAKEUP_SRC_PE6 |
							(PULL_WAKEUP_SRC_PE7<<2) |
							(PULL_WAKEUP_SRC_PF0<<4) |
							(PULL_WAKEUP_SRC_PF1<<6));
}




void gpio_set_wakeup(u32 pin, u32 level, int en);

void gpio_setup_up_down_resistor(u32 gpio, u32 up_down);
void gpio_set_func(u32 pin, u32 func);
