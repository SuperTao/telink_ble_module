/********************************************************************************************************
 * @file     app_uart.c
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

#include "../../proj/tl_common.h"
#include "../../proj_lib/rf_drv.h"
#include "../../proj_lib/pm.h"
#include "../../proj/drivers/adc.h"
#include "../../proj/drivers/uart.h"
#include "../../proj/drivers/i2c.h"
#include "../../proj/drivers/spi.h"

#if (DRIVER_TEST_MODE == TEST_UART)

#define UART_DMA_MODE_EN     1  //1:dma mode ; ; ; 0: not dma mode

#if UART_DMA_MODE_EN
//#define UART_RX_BUFF_SIZE      2236
#define UART_RX_BUFF_SIZE      2556
#define UART_RX_TMP_BUFF_SIZE      508
	#define UART_TX_BUFF_SIZE      16
	typedef struct{
		unsigned int dma_len;        // dma len must be 4 byte
		unsigned char data[UART_RX_BUFF_SIZE];
	}uart_data_t;

	typedef struct{
		unsigned int dma_len;        // dma len must be 4 byte
		unsigned char data[UART_RX_TMP_BUFF_SIZE];
	}uart_tmp_data_t;
	unsigned char uart_rx_irq = 0, uart_tx_irq = 0;

uart_data_t rec_buff = {0, {0, } };
uart_tmp_data_t T_tmp_buf = {0, {0, } };
	__attribute__((aligned(4))) unsigned char uart_rec_buff[UART_RX_BUFF_SIZE] = {0x00,0x00,0x00,0x00,}; // the first four byte is length to receive data.
	__attribute__((aligned(4))) unsigned char uart_tx_buff[UART_TX_BUFF_SIZE]  = {0x0b,0x00,0x00,0x00,'t','e','l','i','n','k','-','s','e','m','i'}; // the first four byte is length to send data.
#else
	unsigned char uart_no_dma_rev_data = 0, uart_no_dma_rev_flag = 0;
#endif

void app_uart_test_init(void){

#if UART_DMA_MODE_EN
	//	uart_Init(9,13,PARITY_NONE,STOP_BIT_ONE); //set baud rate, parity bit and stop bit
	//	uart_DmaModeInit(UART_DMA_TX_IRQ_EN, UART_DMA_RX_IRQ_EN);   // enable tx and rx interrupt
//	CLK16M_UART115200;
	uart_Init(9,13,PARITY_NONE,STOP_BIT_ONE);
	uart_DmaModeInit(UART_DMA_TX_IRQ_DIS, UART_DMA_RX_IRQ_EN);

	uart_RecBuffInit((unsigned char *)&rec_buff, sizeof(rec_buff));  //set uart rev buffer and buffer size
//	uart_txBuffInit(UART_TX_BUFF_SIZE);

//	#if ((MCU_CORE_TYPE == MCU_CORE_8261)||(MCU_CORE_TYPE == MCU_CORE_8267)||(MCU_CORE_TYPE == MCU_CORE_8269))
//		UART_GPIO_CFG_PC2_PC3();  //enable uart function and enable input
//	#elif CHIP_TYPE == CHIP_TYPE_8266
		UART_GPIO_CFG_PA6_PA7();
//	#endif

#else
	uart_Init(9, 13, PARITY_NONE, STOP_BIT_ONE); //set baud rate, parity bit and stop bit.(9,13,115200) other baud rate can get from tool
	uart_notDmaModeInit(1, 0, UART_NODMA_RX_IRQ_EN, UART_NODMA_TX_IRQ_DIS);

	#if ((MCU_CORE_TYPE == MCU_CORE_8261)||(MCU_CORE_TYPE == MCU_CORE_8267)||(MCU_CORE_TYPE == MCU_CORE_8269))
		UART_GPIO_CFG_PC2_PC3();  //enable uart function and enable input
	#elif CHIP_TYPE == CHIP_TYPE_8266
		UART_GPIO_CFG_PC6_PC7();
	#endif

#endif
//	irq_enable();
}


void app_uart_test_start(void){
#if UART_DMA_MODE_EN
	if(uart_rx_irq){
//		uart_rx_irq = 0;
		/*receive buffer,the first four bytes is the length information of received data.send the received data*/
//		while(!uart_Send(uart_rec_buff));
#define RFID_DATA_ATTRIBUTE_HANDLE 29
//		bls_att_pushNotifyData(RFID_DATA_ATTRIBUTE_HANDLE, uart_rec_buff, sizeof(uart_rec_buff));
#if 1
		unsigned char *data_ptr = rec_buff.data;

//		unsigned char length = sizeof(&uart_rec_buff[4]);
		unsigned int length = rec_buff.dma_len;
		unsigned char len[10] = {0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x0d};
		len[4] = (rec_buff.dma_len)/256/16;
		if (len[4] > 9)
			len[4] += ('a'-10);
		else
			len[4] += '0';
		len[5] = (rec_buff.dma_len)/256%16;
		if (len[5] > 9)
			len[5] += ('a'-10);
		else
			len[5] += '0';
		len[6] = (rec_buff.dma_len)%256/16;
		if (len[6] > 9)
			len[6] += ('a'-10);
		else
			len[6] += '0';
		len[7] = ((rec_buff.dma_len)%256)%16;
		if (len[7] > 9)
			len[7] += ('a'-10);
		else
			len[7] += '0';
		u32 total_len,buf_len,pos;
				total_len=rec_buff.dma_len;
				uart_Send((unsigned char *)len);
				sleep_us(2000000);
				while(1){

					if(total_len > 500){
						buf_len = 500;
					}else{
						buf_len = total_len;
					}

					memcpy(T_tmp_buf.data, (rec_buff.data + pos), buf_len);

					T_tmp_buf.dma_len = buf_len;

					pos 		+= buf_len;
					total_len 	-= buf_len;

					uart_Send( (unsigned char*)&T_tmp_buf);
					if(total_len == 0){
						uart_rx_irq = 0;
						break;
					}
					sleep_us(2000000);
				}

/*
		while (length > 0)
		{
			int amount_to_send = min((20), length);
			bls_att_pushNotifyData(RFID_DATA_ATTRIBUTE_HANDLE, data_ptr, amount_to_send);
			data_ptr += amount_to_send;
			length -= amount_to_send;
		}
*/
//		while(!uart_Send(uart_rec_buff));
//		memset(uart_rec_buff, 0, sizeof(uart_rec_buff));
#endif
		/*transmit buffer, the first four bytes is the length information of transmitting data.the DMA module will send the data based on the length.
		* so the useful data start from the fifth byte and start to send to other device from the fifth byte.*/
//		while(!uart_Send(uart_tx_buff));
	}
#else
	if(uart_no_dma_rev_flag == 1){
		uart_no_dma_rev_flag = 0;
		uart_notDmaModeSendByte(uart_no_dma_rev_data);
	}
#endif

}


_attribute_ram_code_ void app_uart_test_irq_proc(void){
	static unsigned char irqS;
	static unsigned char idx = 0;
	#if UART_DMA_MODE_EN

		irqS = uart_IRQSourceGet(); // get the irq source and clear the irq.
		if(irqS & UARTRXIRQ){
			uart_rx_irq = 1;

		}
//		if(irqS & UARTTXIRQ){
//			uart_tx_irq++;
//		}
	#else
		irqS = GET_UART_NOT_DMA_IRQ();  ///get the status of uart irq.
		if(irqS){
			uart_no_dma_rev_data = uart_notDmaModeRevData();//cycle the four registers 0x90 0x91 0x92 0x93,in addition reading will clear the irq.
			idx++;
			idx &= 0x03;// cycle the four registers 0x90 0x91 0x92 0x93, it must be done like this for the design of SOC.

			uart_no_dma_rev_flag = 1;
		}
	#endif
}

#endif
