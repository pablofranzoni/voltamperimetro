#include "main.h"
#include <lcd.c>

void main(){
   setup_adc_ports(sAN0|sAN1|VSS_VDD);
   setup_adc(ADC_CLOCK_DIV_2);
   lcd_init();
   int i;
   int16 vecCorr[10], vecVolt[10];
   int16 auxCorr=0, auxVolt=0;
   int16 currentADC, voltajeADC;
   float current, voltaje;
   
   while(TRUE){
      for(i=0;i<10;i++){
         set_adc_channel(0);
         delay_us(200);
         currentADC=read_adc();
         vecCorr[i]=currentADC;
         set_adc_channel(1);
         delay_us(200);
         voltajeADC=read_adc();
         vecVolt[i]=voltajeADC;
      }
      
      auxCorr=0;
      auxVolt=0;
      for(i=0;i<10;i++){ 
         auxCorr=vecCorr[i]+auxCorr;
         auxVolt=vecVolt[i]+auxVolt;
      }

      delay_ms(500);
      current=(5.0*(auxCorr/10)/1023.0)/1.6665;
      voltaje=((5.0*(auxVolt/10)/1023.0)/0.151)-(current/10);
      
      lcd_gotoxy(1,1);
      printf(lcd_putc," %02.2fV",voltaje);
      lcd_gotoxy(1,2);
      printf(lcd_putc," %02.3fA",current);
      
   }
}
