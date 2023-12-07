#include "LCD.h"
#define LCD_Dir  DDRD			
#define LCD_Port PORTD	
#define RS_EN_Dir  DDRB		
#define RS_EN_Port PORTB 
#define RS PB0				   
#define EN PB1 				   

void LCD_Init (void)			
{ LCD_Dir = 0xFF;			   
  RS_EN_Dir |= (1 << EN) | (1 << RS);

  _delay_ms(20);			   
	LCD_CMD(0x02);		  
	LCD_CMD(0x28);     
	LCD_CMD(0x0c);     
	LCD_CMD(0x06);     
	LCD_CMD(0x01);      
	_delay_ms(2);}

void LCD_STR (char *str)		
{int i;
 for(i=0;str[i]!=0;i++)		
 LCD_TEXT (str[i]);}

void LCD_CMD( unsigned char cmnd )
{ LCD_Port = (LCD_Port & 0x0F) | (cmnd & 0xF0);
	RS_EN_Port &= ~ (1<<RS);	
	RS_EN_Port |= (1<<EN);		
	_delay_us(1);
	RS_EN_Port &= ~ (1<<EN);
	_delay_us(250);
	LCD_Port = (LCD_Port & 0x0F) | (cmnd << 4);  
	RS_EN_Port |= (1<<EN);
	_delay_us(1);
	RS_EN_Port &= ~ (1<<EN);
	_delay_ms(2);}

void LCD_TEXT( unsigned char data )
{ LCD_Port = (LCD_Port & 0x0F) | (data & 0xF0);
	RS_EN_Port |= (1<<RS);		
	RS_EN_Port|= (1<<EN);
	_delay_us(1);
	RS_EN_Port &= ~ (1<<EN);
	_delay_us(250);
	LCD_Port = (LCD_Port & 0x0F) | (data << 4); 
	RS_EN_Port |= (1<<EN);
	_delay_us(1);
	RS_EN_Port &= ~ (1<<EN);
	_delay_ms(2);}

void LCD_CLR()
{ LCD_CMD (0x01);		
	_delay_ms(2);
	LCD_CMD (0x80);}

char* Convert(int num, char* str, int base)
{int i = 0;
 bool isNegative = false;
 if (num == 0) 
 {str[i++] = '0';
  str[i] = '\0';
  return str;}
 if (num < 0 && base == 10) 
 {isNegative = true;
 num = -num;}
 while (num != 0) 
 {int rem = num % base;
  str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
  num = num / base;}
  if (isNegative)
  str[i++] = '-';
  str[i] = '\0';   
  reverse(str, i);
  return str;}

void reverse(char str[], int length)
{ int start = 0;
  int end = length - 1;
  while (start < end) {
  char temp = str[start];
  str[start] = str[end];
  str[end] = temp;
  end--;
  start++;}}