#include "Pwm.h"

void PWM_Init()
{ DDRD |= (1<<PD3);
  DDRB |= (1<<PB3);

  TCCR2A |= (1<<COM2A1) | (1<<WGM21) | (1<<WGM20) |  (1<<COM2B1);
	TCCR2B |= (1<<CS20);}

void Pwm_SDC(int pin, int duty)
{ if(pin == 3)
  {OCR2B = duty;}
  else if(pin == 11)
  {OCR2A = duty;}
}