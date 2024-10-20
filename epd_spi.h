#ifndef _EPD_SPI_H_
#define _EPD_SPI_H_

#include "driver/gpio.h"
#include "driver/spi_master.h"

//IO settings
//SCK--GPIO23(SCLK)
//SDIN---GPIO18(MOSI)

// this is from main
extern spi_device_handle_t spi;

#define BUSY_PIN	25
#define RST_PIN		26
#define DC_PIN		27
#define CS_PIN		15
#define SCK_PIN		14
#define SDI_PIN		13

// these might already br defined in the IDF
#define LOW   0
#define HIGH  1

#define isEPD_W21_BUSY  gpio_get_level(BUSY_PIN)  //BUSY
#define EPD_W21_RST_0   gpio_set_level(RST_PIN, LOW)  //RES
#define EPD_W21_RST_1   gpio_set_level(RST_PIN, HIGH)
#define EPD_W21_DC_0    gpio_set_level(DC_PIN, LOW) //DC
#define EPD_W21_DC_1    gpio_set_level(DC_PIN, HIGH)
#define EPD_W21_CS_0    gpio_set_level(CS_PIN, LOW) //CS
#define EPD_W21_CS_1    gpio_set_level(CS_PIN, HIGH)

void SPI_Write(unsigned char value);
void EPD_W21_WriteDATA(unsigned char datas);
void EPD_W21_WriteCMD(unsigned char command);

#endif
