#include <stdio.h>
// #include <string.h>
// idf libraries
  // #include "freertos/FreeRTOS.h"
  // #include "freertos/task.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"
// local libraries
#include "epd_spi.h"
#include "epd.h"
#include "tester.h"
// #include "Ap_29demo.h"

spi_bus_config_t spiBus = {};
spi_host_device_t spiHost = SPI2_HOST;
spi_device_interface_config_t spiDev = {};
spi_device_handle_t spi;

void gpio_setup() 
{
	gpio_reset_pin(BUSY_PIN);
	gpio_set_direction(BUSY_PIN, GPIO_MODE_INPUT);
	
	gpio_reset_pin(RST_PIN);
	gpio_set_direction(RST_PIN, GPIO_MODE_INPUT_OUTPUT);
	
	gpio_reset_pin(DC_PIN);
	gpio_set_direction(DC_PIN, GPIO_MODE_INPUT_OUTPUT);

	gpio_reset_pin(CS_PIN);
	gpio_set_direction(CS_PIN, GPIO_MODE_INPUT_OUTPUT);

	gpio_reset_pin(SCK_PIN);
	gpio_set_direction(SCK_PIN, GPIO_MODE_INPUT_OUTPUT);
	
	gpio_reset_pin(SDI_PIN);
	gpio_set_direction(SDI_PIN, GPIO_MODE_INPUT_OUTPUT);

}

void spi_setup() 
{
  // setup all
	spiBus.mosi_io_num = SDI_PIN;
	spiBus.miso_io_num = -1;
	spiBus.sclk_io_num = SCK_PIN;
	spiBus.quadwp_io_num = -1;
	spiBus.quadhd_io_num = -1;
	spiBus.max_transfer_sz = 4094; // is this necessary
	// spiBus.flags = (SPICOMMON_BUSFLAG_GPIO_PINS /* | SPICOMMON_BUSFLAG_MASTER */ );
	spi_bus_initialize(spiHost, &spiBus, SPI_DMA_CH_AUTO);

	spiDev.mode = 0;
	spiDev.clock_speed_hz = 10 * 1000 * 1000;
	spiDev.input_delay_ns = 0;
	spiDev.spics_io_num =CS_PIN;
	spiDev.queue_size = 1; // throws error if zero...
	spiDev.flags = ( SPI_DEVICE_NO_DUMMY | SPI_DEVICE_3WIRE | SPI_DEVICE_HALFDUPLEX );
	spi_bus_add_device(spiHost, &spiDev, &spi);
}

void app_main(void) 
{
	spi_setup();
	gpio_setup();
	
	waveshare_example();	

	// EPD_HW_Init();
	// EPD_WhiteScreen_White();
	// EPD_DeepSleep();
}
