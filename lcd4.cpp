#include "lcd4.h"
#include<avr/io.h>
#include<util/delay.h>

void LCD_Init (void)          /* LCD Initialize function */
{
 // LCD_Dir = 0xFF;           /* Make LCD port direction as o/p */
  //delay_ms(20);             /* LCD Power ON delay always >15ms */
  lcd_cmd(0x02);              /* send for 4 bit initialization of LCD  */
  lcd_cmd(0x28);              /* 2 line, 5*7 matrix in 4-bit mode */
  lcd_cmd(0x0c);              /* Display on cursor off*/
  lcd_cmd(0x06);              /* Increment cursor (shift cursor to right)*/
  lcd_cmd(0x01);              /* Clear display screen*/
  _delay_ms(2);
}			
void lcd_cmd(unsigned char ch) /*pass the commands to the lcd function */
{
PORTB&=~(1<<PB0);              /*Make the portb 0 th pin Low i.e RS=0 for command to display*/
PORTD=ch&0x0F|ch&0xF0;	      /*Mas*/
PORTB|=(1<<PB1);
_delay_ms(1);
PORTB&=~(1<<PB1);
PORTD=ch&0x0F|ch<<4;
PORTB|=(1<<PB1);
_delay_ms(1);
PORTB&=~(1<<PB1);
}
void lcd_data(unsigned char ch)
{
PORTB|=(1<<PB0);
PORTD=ch&0x0F|ch&0xF0;
PORTB|=(1<<PB1);
_delay_ms(1);
PORTB&=~(1<<PB1);
PORTD=ch&0x0F|ch<<4;
PORTB|=(1<<PB1);
_delay_ms(1);
PORTB&=~(1<<PB1);

}
void lcd_stirng(unsigned char *str)
{
while(*str)
lcd_data(*str++);
}
