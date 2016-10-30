//Toggling PT5 to sound the buzzer for Dragon12 Plus Trainer Board 
//PT5 of PORTT is connected to buzzer/speaker on Dragon12+ board
//This program toggles PT5 to sound the buzzer. Change the delay size to get a different sound
//Modified from Example 7-23 Mazidi&Causey HCS12 book

#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

int melody[10] = {1,12,3,12,1,14,3,14,5,13};
int tempo[] = {1,1,1,1,1,1,1,1,1,1};


void MSDelay(unsigned int);

void main(void) 
{
  /* put your own code here */
  
       
    DDRT = DDRT | 0b00100000;    // PTT5 as output 
     
    for (;;) 			
      {  
    
        for(int i=0;i<10;++i) {
          
          for(int j=0;j<1000/melody[i]*tempo[i];++j) {
            PTT = PTT | 0x20;      //make PT5=1
            MSDelay(melody[i]);         //change the delay size to see what happens
            PTT = PTT & 0xDF;      //Make PT5=0
            MSDelay(melody[i]);         //change delay size....
          }
      
        }
       

      }

}

void MSDelay(unsigned int itime)  //msec delay
  {
    unsigned int i; unsigned int j;
    for(i=0;i<itime;i++)
      for(j=0;j<400;j++);
  }