#include <16F883.h>
#device adc=10

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(int=4000000)

#define LCD_ENABLE_PIN  PIN_B0                                    ////
#define LCD_RS_PIN      PIN_B1                                    ////
#define LCD_RW_PIN      PIN_B2                                    ////
#define LCD_DATA4       PIN_B4                                    ////
#define LCD_DATA5       PIN_B5                                    ////
#define LCD_DATA6       PIN_B6                                    ////
#define LCD_DATA7       PIN_B7
