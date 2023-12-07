
//--------------------------------------------     AC PROJECT    -------------------------------------------//

//-------------------------------------     Youssef Kamal 202100546    -------------------------------------------//
//-------------------------------------     Mohamed Kafagy 202100558   -------------------------------------------//
//------------------------------------     Mohamed Gadallah 202201082   ------------------------------------------//



//--------------------------------------------------------------------------------//

#include <avr/io.h> 
#include <util/delay.h>
#include "Lcd.h"
#include "dio.h"
#include "Pwm.h"

//--------------------------------------------------------------------------------// 

#define SET(reg, bit)    (reg |= (1<<bit))
#define CLEAR(reg, bit)  (reg &= ~(1<<bit)) 
#define GET(reg, bit)    ((reg >> bit) & 1)

int main()

{	DIO_init();  
  PWM_Init();
  Read_Init(); 
	LCD_Init();	

  int D = 1;
  int Setting = 0;

//--------------------------------------------------------------------------------//

  while(1)

//--------------------------------------------------------------------------------//

 {int Add = DIO_GPS('c',3);           
  int Sub = DIO_GPS('c',4);
  int Rev = DIO_GPS('c',5);  

  if(Add ==  HIGH)
  {Setting = Setting + 1;}
  
  if(Sub == HIGH)
  {Setting = Setting - 1;}

  if(Rev ==  HIGH)
   {if(D == 0)
     {D = D + 1;}
    if(D == 1)
     {D = D - 1;}}

//--------------------------------------------------------------------------------//

  char * Convert(int num, char* str, int base);
  unsigned char Temp = Read(1);
  unsigned char CTemp[2];     
  unsigned char TempReading1 = (Temp) * 5000/1024;
  unsigned char TempReading = TempReading1/10;
  Convert (TempReading , CTemp , 10);
  _delay_ms(500);

 if(D == 0)
 {if(Setting == 1)
  {Pwm_SDC(3,170);
   Pwm_SDC(11,0);
   LCD_CMD(0x01); 
   LCD_CMD(0x80); 
	 LCD_STR("TEMP: ");	  
   LCD_STR(CTemp); 
   LCD_CMD(0xC0);
   LCD_STR("MODE: Low"); 
   LCD_CMD(0xC0);
   }

  if(Setting == 2)
  {Pwm_SDC(3,200);
   Pwm_SDC(11,0);
   LCD_CMD(0x01); 
   LCD_CMD(0x80); 
	 LCD_STR("TEMP: ");	  
   LCD_STR(CTemp); 
   LCD_CMD(0xC0);
   LCD_STR("MODE: Mid"); 
   LCD_CMD(0xC0);
   }

  if(Setting == 3)
  {Pwm_SDC(3,255);
   Pwm_SDC(11,0);
   LCD_CMD(0x01); 
   LCD_CMD(0x80); 
	 LCD_STR("TEMP: ");	  
   LCD_STR(CTemp); 
   LCD_CMD(0xC0);
   LCD_STR("MODE: High"); 
   LCD_CMD(0xC0);
   }}



 if(D == 1)
 {if(Setting == 1)
  {Pwm_SDC(11,170);
   Pwm_SDC(3,0);
   LCD_CMD(0x01); 
   LCD_CMD(0x80); 
	 LCD_STR("TEMP: ");	  
   LCD_STR(CTemp); 
   LCD_CMD(0xC0);
   LCD_STR("MODE: Low"); 
   LCD_CMD(0xC0);
   }

  if(Setting == 2)
  {Pwm_SDC(11,200);
   Pwm_SDC(3,0);
   LCD_CMD(0x01); 
   LCD_CMD(0x80); 
	 LCD_STR("TEMP: ");	  
   LCD_STR(CTemp); 
   LCD_CMD(0xC0);
   LCD_STR("MODE: Mid");
   LCD_CMD(0xC0); 
   }

  if(Setting == 3)
  {Pwm_SDC(11,255);
   Pwm_SDC(3,0);
   LCD_CMD(0x01); 
   LCD_CMD(0x80); 
	 LCD_STR("TEMP: ");	  
   LCD_STR(CTemp); 
   LCD_CMD(0xC0);
   LCD_STR("MODE: High");
   LCD_CMD(0xC0);
   }}
  
  if(Setting <= 0)
  { LCD_CMD(0x01); 
    LCD_CMD(0x80);
    LCD_STR("      OFF    " );
    LCD_CMD(0xC0);
    Pwm_SDC(3,0);
    Pwm_SDC(11,0);
    }}

 _delay_ms(500);

//--------------------------------------------------------------------------------// 

	return 0;}

//--------------------------------------------------------------------------------// 