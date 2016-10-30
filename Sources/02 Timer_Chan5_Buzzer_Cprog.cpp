//Toggling PT5 to sound the buzzer for Dragon12 Plus Trainer Board 
//PT5 of PORTT is connected to buzzer/speaker on Dragon12+ board
//This program toggles PT5 to sound the buzzer. Change the delay size to get a different sound
//Modified from Example 7-23 Mazidi&Causey HCS12 book

#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */


  void MSDelay(unsigned int);
void main(void) 
{
  /* put your own code here */
  
       
    DDRT = DDRT | 0b00100000;    // PTT5 as output 
     
    for (;;) 			
      {
       PTT = PTT | 0x20;      //make PT5=1
      MSDelay(10);         //change the delay size to see what happens
       PTT = PTT & 0xDF;      //Make PT5=0
      MSDelay(10);         //change delay size....

      }

}

void MSDelay(unsigned int itime)  //msec delay
  {
    unsigned int i; unsigned int j;
    for(i=0;i<itime;i++)
      for(j=0;j<4000;j++);
  }