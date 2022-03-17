

#ifndef LCD_H_
#define LCD_H_

#define CLR_SCREEN 0x01
#define CURSOR_OFF_DISPLAN_ON 0x0c
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06

#define EN 3
#define RS 1
#define RW 2
#define FOUR_BITS 0x28
#include "data_type.h"
void LCD_vInit(void);
static void send_falling_edge(void);
void LCD_vSend_cmd(char cmd);
void LCD_vSend_char(char data);
void LCD_vSend_string(char *data);
void LCD_clearscreen(void);
void LCD_movecursor(uint8_ row,uint8_ coloumn);

#endif /* LCD_H_ */
