#include<xc.h>
#include "LCD.h"
#define _XTAL_FREQ 4000000

void lcd_cmd(unsigned char x){
    lcd_ready();
    LCD = x;
    RS = 0;
    RW = 0;
    lcd_lat();    
}

void lcd_lat(void){
    EN = 1;
   __delay_ms(30);
   EN = 0;
}
void lcd_ready(void) {
    LCD = 0xFF;
    LCD &= 0x80;
    RS = 0;
    RW = 1;
    EN = 0;
    __delay_ms(30);
    EN = 1;
    if (LCD == 0x80){
    EN = 0;
    __delay_ms(30);
    EN = 1;  
    }
    else{   
    }    
}

void lcd_dwr(unsigned char x){
    lcd_ready();
    LCD = x;
    RS = 1;
    RW = 0;
    lcd_lat(); 
}

void lcd_msg(unsigned char *c){
    while(*c != 0)
        lcd_dwr(*c++);
}

void lcd_init(void){   
    lcd_cmd(0x38);
    lcd_cmd(0x0C);
    lcd_cmd(0x01);
    lcd_cmd(0x06);
    lcd_cmd(0x80);  
}

