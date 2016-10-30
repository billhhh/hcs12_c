//Sounding the Buzzer on PT5 using Chann 5 Timer (Output Compare option)
//PT5 of PORTT is connected to buzzer/speaker on Dragon12+ board
//Notice this is NOT using any Time Delay
//Modified from Example 9-29 HCS12 book by Mazidi & Causey for Dragon12+ board/CodeWarrior 

#include <hidef.h>      /* common defines and macros */
#include "derivative.h"   /* derivative-specific definitions */

void main(void)
  {
   unsigned int Tcount;

   TSCR1 = 0x90; 
   TSCR2 = 0x07;  //Prescaler=128. Change (0-7) to hear different sound
   TIOS = 0b00100000;   //Output Compare option for Channel 5
   TCTL1 = 0b00000100;  //Toggle PT5 pin option

  //Sound the Buzzer by toggling PT5 pin using Timer chan 5
   for(;;)
      { 
      Tcount = TCNT;
      Tcount = Tcount + 500; //change this number to hear different sound
      TC5 = Tcount;
      while (!(TFLG1 & TFLG1_C5F_MASK));
  
      }

  }
