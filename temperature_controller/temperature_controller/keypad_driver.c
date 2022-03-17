#define F_CPU 8000000ul
 #include "keypad_driver.h"
 #include "DIO.h"
 #include "avr/delay.h"

 
 void keypad_vInit(void)
 {
	 DIO_vsetPINDir('C',0,0);
	 DIO_vsetPINDir('C',1,0);
	 DIO_vsetPINDir('C',2,0);
	 DIO_vsetPINDir('C',3,0);
	 DIO_vsetPINDir('C',4,0);
	 DIO_vsetPINDir('C',5,0);
	 DIO_vsetPINDir('C',6,0);
	 DIO_vsetPINDir('C',7,0);
	 DIO_vsetPINDir('D',0,0);
	 DIO_vsetPINDir('D',1,0);
	 DIO_vsetPINDir('D',2,0);
	 DIO_vsetPINDir('D',3,0);
	 DIO_vconnectpullup('C',(uint8_)0,(uint8_)1);
	 DIO_vconnectpullup('C',(uint8_)1,(uint8_)1);
	 DIO_vconnectpullup('C',(uint8_)2,(uint8_)1);
	 DIO_vconnectpullup('C',(uint8_)3,(uint8_)1);
	 DIO_vconnectpullup('C',(uint8_)4,(uint8_)1);
	 DIO_vconnectpullup('C',(uint8_)5,(uint8_)1);
	 DIO_vconnectpullup('C',(uint8_)6,(uint8_)1);
	 DIO_vconnectpullup('C',(uint8_)7,(uint8_)1);
	 DIO_vconnectpullup('D',(uint8_)0,(uint8_)1);
	 DIO_vconnectpullup('D',(uint8_)1,(uint8_)1);
	 DIO_vconnectpullup('D',(uint8_)2,(uint8_)1);
	 DIO_vconnectpullup('D',(uint8_)3,(uint8_)1); 
 }
 
 uint8_ input_keypad(void)
 {
	 uint8_ left_digit=0;
	 uint8_ KeyPadVal=0;
	 do
	 {
		 KeyPadVal=keypad_u8check_press();
	 } while ( (KeyPadVal==200) || (KeyPadVal =='*') || (KeyPadVal =='#') );

	 left_digit=(uint8_)KeyPadVal;
	 left_digit*=(uint8_)10;
	 _delay_ms(300);
	 do
	 {
		 KeyPadVal=keypad_u8check_press();
	 } while ( (KeyPadVal==200) || (KeyPadVal =='*') || (KeyPadVal =='#') );

	 left_digit+=(uint8_)KeyPadVal;

	 
	 return (uint8_)(left_digit-16);
 }
 
 
 
 char keypad_u8check_press(void)
 {
	 char arr[4][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};
	uint8_ row,coloumn,pin0_reading,pin1_reading,pin2_reading,pin3_reading,pin4_reading,pin5_reading,pin6_reading,pin7_reading,
	 pin0_reading2,pin1_reading2,pin2_reading2,pin3_reading2;
	 uint8_ returnval=200;
	 
	 DIO_write('C',0,1);
	 DIO_write('C',1,1);
	 DIO_write('C',2,1);
	 DIO_write('C',3,1);
	 DIO_write('C',4,1);
	 DIO_write('C',5,1);
	 DIO_write('C',6,1);
	 DIO_write('C',7,1);
	 DIO_write('D',0,1);
	 DIO_write('D',1,1);
	 DIO_write('D',2,1);
	 DIO_write('D',3,1);
	 
	 pin0_reading=DIO_u8read('C',0);
		 if((uint8_)pin0_reading==0)
			 {
			  returnval=arr[0][0];
			 
			 }  
	pin1_reading=DIO_u8read('C',1);
	 if((uint8_)pin1_reading==0)
	 {
		 returnval=arr[0][1];
		 
	 }
	 pin2_reading=DIO_u8read('C',2);
	 if((uint8_)pin2_reading==0)
	 {
		 returnval=arr[0][2];
		 
	 }
	 
	 
	  pin3_reading=DIO_u8read('C',3);
	  if((uint8_)pin3_reading==0)
	  {
		  returnval=arr[1][0];
		  
	  }
	   pin4_reading=DIO_u8read('C',4);
	   if((uint8_)pin4_reading==0)
	   {
		   returnval=arr[1][1];
		   
	   }
	    pin5_reading=DIO_u8read('C',5);
	    if((uint8_)pin5_reading==0)
	    {
		    returnval=arr[1][2];
		    
	    }
		 pin6_reading=DIO_u8read('C',6);
		 if((uint8_)pin6_reading==0)
		 {
			 returnval=arr[2][0];
			 
		 }
		  pin7_reading=DIO_u8read('C',7);
		  if((uint8_)pin7_reading==0)
		  {
			  returnval=arr[2][1];
			  
		  }
	 
	   pin0_reading2=DIO_u8read('D',0);
	   if((uint8_)pin0_reading2==0)
	   {
		   returnval=arr[2][2];
		   
	   }
	   
	   pin1_reading2=DIO_u8read('D',1);
	   if((uint8_)pin1_reading2==0)
	   {
		   returnval=arr[3][0];
		   
	   }
	   
	   
	   pin2_reading2=DIO_u8read('D',2);
	   if((uint8_)pin2_reading2==0)
	   {
		   returnval=arr[3][1];
		   
	   }
	   
	   
	   pin3_reading2=DIO_u8read('D',3);
	   if((uint8_)pin3_reading2==0)
	   {
		   returnval=arr[3][2]; 
	   }
	    
	 return returnval ;	 
 }
 
