#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "tester.h"
#include "Ap_29demo.h"
#include "epd.h"

// the original loop from Arduino waveshare example
void waveshare_example() 
{
	unsigned int i;
#if 1 //Full screen refresh, fast refresh, and partial refresh demostration.
      EPD_HW_Init(); //Full screen refresh initialization.
      EPD_WhiteScreen_White(); //Clear screen function.
      EPD_DeepSleep(); //Enter the sleep mode and please do not delete it, otherwise it will reduce the lifespan of the screen.
      vTaskDelay(2000 / portTICK_PERIOD_MS); //Delay for 2s. 
     /************Full display(2s)*******************/
      EPD_HW_Init(); //Full screen refresh initialization.
      EPD_WhiteScreen_ALL(gImage_1); //To Display one image using full screen refresh.
      EPD_DeepSleep(); //Enter the sleep mode and please do not delete it, otherwise it will reduce the lifespan of the screen.
      vTaskDelay(2000 / portTICK_PERIOD_MS); //Delay for 2s. 
            
      /************Fast refresh mode(1.5s)*******************/
      EPD_HW_Init_Fast(); //Fast refresh initialization.
      EPD_WhiteScreen_ALL_Fast(gImage_2); //To display one image using fast refresh.
      EPD_DeepSleep(); //Enter the sleep mode and please do not delete it, otherwise it will reduce the lifespan of the screen.
      vTaskDelay(2000 / portTICK_PERIOD_MS); //Delay for 2s.

  #if 1 //Partial refresh demostration.
  //Partial refresh demo support displaying a clock at 5 locations with 00:00.  If you need to perform partial refresh more than 5 locations, please use the feature of using partial refresh at the full screen demo.
  //After 5 partial refreshes, implement a full screen refresh to clear the ghosting caused by partial refreshes.
  //////////////////////Partial refresh time demo/////////////////////////////////////
      EPD_HW_Init(); //Electronic paper initialization. 
      EPD_SetRAMValue_BaseMap(gImage_basemap); //Please do not delete the background color function, otherwise it will cause unstable display during partial refresh.
      for(i=0;i<6;i++)
      EPD_Dis_Part_Time(320,124+48*0, Num[1],         //x-A,y-A,DATA-A
                        320,124+48*1, Num[0],         //x-B,y-B,DATA-B
                        320,124+48*2, gImage_numdot, //x-C,y-C,DATA-C
                        320,124+48*3, Num[0],        //x-D,y-D,DATA-D
                        320,124+48*4,Num[i],48,104); //x-E,y-E,DATA-E,Resolution  32*64

      EPD_DeepSleep();  //Enter the sleep mode and please do not delete it, otherwise it will reduce the lifespan of the screen.
      vTaskDelay(2000 / portTICK_PERIOD_MS); //Delay for 2s.
      EPD_HW_Init(); //Full screen refresh initialization.
      EPD_WhiteScreen_White(); //Clear screen function.
      EPD_DeepSleep(); //Enter the sleep mode and please do not delete it, otherwise it will reduce the lifespan of the screen.
      vTaskDelay(2000 / portTICK_PERIOD_MS); //Delay for 2s.
  #endif 

  #if 0 //Demo of using partial refresh to update the full screen, to enable this feature, please change 0 to 1.
  //After 5 partial refreshes, implement a full screen refresh to clear the ghosting caused by partial refreshes.
  //////////////////////Partial refresh time demo/////////////////////////////////////
      EPD_HW_Init(); //E-paper initialization 
      EPD_SetRAMValue_BaseMap(gImage_p1); //Please do not delete the background color function, otherwise it will cause an unstable display during partial refresh.
      EPD_Dis_PartAll(gImage_p1); //Image 1
      EPD_Dis_PartAll(gImage_p2); //Image 2
      EPD_Dis_PartAll(gImage_p3); //Image 3
      EPD_DeepSleep();//Enter the sleep mode and please do not delete it, otherwise it will reduce the lifespan of the screen.
      vTaskDelay(2000 / portTICK_PERIOD_MS); //Delay for 2s. 
      EPD_HW_Init(); //Full screen refresh initialization.
      EPD_WhiteScreen_White(); //Clear screen function.
      EPD_DeepSleep(); //Enter the sleep mode and please do not delete it, otherwise it will reduce the lifespan of the screen.
      vTaskDelay(2000 / portTICK_PERIOD_MS); //Delay for 2s.
  #endif
  
  
  #if 0 //Demonstration of full screen refresh with 180-degree rotation, to enable this feature, please change 0 to 1.
      /************Full display(2s)*******************/
      EPD_HW_Init_180(); //Full screen refresh initialization.
      EPD_WhiteScreen_ALL(gImage_1); //To Display one image using full screen refresh.
      EPD_DeepSleep(); //Enter the sleep mode and please do not delete it, otherwise it will reduce the lifespan of the screen.
      vTaskDelay(2000 / portTICK_PERIOD_MS); //Delay for 2s.
  #endif        
  
#endif
}
