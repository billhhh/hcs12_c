//Toggling PP5 to sound the buzzer using PWM (pulse width modulation) on Dragon12 Plus Trainer Board 
//The J26 jumper selection allows to SPK_SEL (speaker selection) to be PT5, PP5 (PWM chan 5) or DACB output
//When the Dragon12 board is shipped the J26 jumper is set for PT5 of PORTT speaker/buzzer selection (Default setting). 
//Because of this PT5 jumper setting you hear the speaker sound when the board is RESET
   
//This program toggles PP5 to sound the speaker/buzzer using the PWM of channel 5. 
//Modified from Example 17-16 Mazidi & Causey HCS12 book. See Chapter 17 for PWM discussion
//Written and tested by M. Mazidi

//Before you run this program MAKE SURE YOU MOVE THE JUMPER ON J26 FROM PT5 TO PP5

//AFTER YOU RUN THIS PROGRAM MAKE SURE TO MOVE THE JUMPER BACK TO PT5. 
//OTHERWISE UPON RESETING THE BOARD YOU WILL NOT HEAR THE SPEAKER/BUZZER SOUND 

#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */


void main(void) 
{
  /* put your own code here */
  
  PWMPRCLK=0x04; //ClockA=Fbus/2**4=24MHz/16=1.5MHz	
	PWMSCLA=125; 	 //ClockSA=1.5MHz/2x125=6000 Hz
	PWMCLK=0b00100000; 	 //ClockSA for chan 5
	PWMPOL=0x20; 		     //high then low for polarity
	PWMCAE=0x0; 		     //left aligned
	PWMCTL=0x0;	         //8-bit chan, pwm during freeze and wait
	PWMPER5=100; 	 //PWM_Freq=ClockSA/100=6000Hz/100=60Hz. CHANGE THIS
	PWMDTY5=50; 	 //50% duty cycle                        AND THIS TO GET DIFFERENT SOUND
	PWMCNT5=0;		 //clear initial counter. This is optional
	PWME=0x20; 	   //Enable chan 5 PWM
  while(1);      //stay here forever
  
 
}

