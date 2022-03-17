 


#ifndef KEYPAD_DRIVER_H_
#define KEYPAD_DRIVER_H_
#define NOTPRESSED 0xff
#include "data_type.h"
uint8_ input_keypad(void);
void keypad_vInit(void);
char keypad_u8check_press(void);
#endif /* KEYPAD_DRIVER_H_ */
