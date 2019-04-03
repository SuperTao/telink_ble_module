
//#include "../../proj_lib/ble/att.h"
#include "../../proj/common/utility.h"

extern unsigned char uart_rx_irq;
extern __attribute__((aligned(4))) unsigned char uart_rec_buff[100];

int RfidRead(void * p)
{
	/*
    static u32 starttime;

    /// Bill - Need a better way to do this
    if (!clock_time_exceed(starttime, 200000))
    	return 0;

    starttime = clock_time();

    mClientData.AvailableSensorData = DataStorage_available_data();
*/
	return 0;
}

int RfidWrite(void*p)
{
	/*
	rf_packet_att_data_t *pw = (rf_packet_att_data_t *)p;
	int len = pw->l2cap - 3;

	if (len == 2)
	{
		mClientData.BankInfo.MacroInterval = (u16)pw->dat[0];
		mClientData.BankInfo.MacroInterval += (u16)pw->dat[1]<<8;
        printDebugL3("New macro interval 0x%02x\n\r", mClientData.BankInfo.MacroInterval);
        SaveClientBank();
	}

	return 1;
	*/
}

int RfidDataWrite(void*p)
{
/*
	if(uart_rx_irq){
		uart_rx_irq = 0;
		unsigned char *data_ptr = (unsigned char *)&uart_rec_buff;
		while(!uart_Send(uart_rec_buff));
		unsigned char length = sizeof(uart_rec_buff);

		while (length > 0)
		{
			int amount_to_send = min((20), length);
			bls_att_pushNotifyData(RFID_DATA_ATTRIBUTE_HANDLE, data_ptr, amount_to_send);
			data_ptr += amount_to_send;
			length -= amount_to_send;
		}

	}
*/
	return 1;

}
