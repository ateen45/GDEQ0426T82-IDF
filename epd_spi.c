#include "epd_spi.h"
#include "driver/spi_master.h"
#include <string.h> // used for memset

/* --- debug libraries to test pin setters --- */
// #include "debug.h"
// #include <stdio.h>
// #include "driver/gpio.h"

//SPI write byte
void SPI_Write(unsigned char value)
{				   			 
	spi_transaction_t trans;
	memset(&trans, 0, sizeof(trans));

	trans.flags = (SPI_TRANS_USE_TXDATA);
	trans.length = 8;
	// trans.tx_buffer = &value; // comment out if using txdata flag
	trans.tx_data[0] = value; // comment out if not using txdata flag
	trans.rx_buffer = NULL;
	
	// spi_device_transmit(spi, &trans);
	spi_device_polling_transmit(spi, &trans);
}

//SPI write command
void EPD_W21_WriteCMD(unsigned char command)
{
	EPD_W21_CS_0;
	// printf("set CS : %d \n", isEqual(0, gpio_get_level(CS_PIN)));
	EPD_W21_DC_0;  // D/C#   0:command  1:data  
	// printf("set DC : %d \n", isEqual(0, gpio_get_level(DC_PIN)));
	SPI_Write(command);
	EPD_W21_CS_1;
	// printf("set CS : %d \n", isEqual(1, gpio_get_level(CS_PIN)));
}
//SPI write data
void EPD_W21_WriteDATA(unsigned char datas)
{
	EPD_W21_CS_0;
	// printf("set CS : %d \n", isEqual(0, gpio_get_level(CS_PIN)));
	EPD_W21_DC_1;  // D/C#   0:command  1:data
	// printf("set DC : %d \n", isEqual(1, gpio_get_level(DC_PIN)));
	SPI_Write(datas);
	EPD_W21_CS_1;
	// printf("set CS : %d \n", isEqual(1, gpio_get_level(CS_PIN)));
}
