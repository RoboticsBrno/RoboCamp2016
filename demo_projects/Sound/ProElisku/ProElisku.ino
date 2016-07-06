/**
 * Falesna stupnice
 * 
 * circuit:
 * 8-ohm speaker on digital pin 8 + resistor!
 */

#include <Tone.h>
#include "pitches.h"

void setup()
{
  const int oneTactDuration = 4000; // duration of 1/1 note in milliseconds

  int melody1[] = {
    //NE6, NDS6, NE6, NDS6, NE6, NB5, ND6, NC6, NA5, 0, NC5, NE5, NA5, NB5, 0, NE5, NGS5, NB5, NC6, 0, NE5, NE6, NDS6, NE6, NDS6, NE6, NB5, ND6, NC6, NA5, 0, NC5, NE5, NA5, NB5, 0, ND5, NC6, NB5, NA5
    NA4,00,NB4,NC5,ND5, NE5,NE5,NG4,NF5,NE5, ND5,ND5,NF4,NE5,ND5, NC5,NC5,NE4,ND5,NC5, NB4,00,NE4,NE5,00, 00,NE5,NE6,00,NDS5, NE5,00,NDS5,NE5,ND5, NE5,NDS5,NE5,NB4,ND5,NC5, NA4,00,NC4,NE4,NA4, NB4,00,NE4,NGS4,NB4, NC5,00,NE4,NE5,NDS5, NE5,NDS5,NE5,NB4,ND5,NC4, NA4,00,NC4,NE4,NA4, NB4,00,ND4,NC5,NB4, NA4,00,NC4,NE4,NA4, NB4,00,ND4,NC5,NB4
  };
  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  int durations1[] = {
    //16,  16,  16,   16,   16,  16,  16,  16,  8,  16,  16,  16,  16,   8,16,  16,   16,  16,   8,16,  16,  16,   16,  16,   16,  16,  16,  16,  16,   8,16,  16,  16,  16,   8,16,  16,  16,  16, 5
     8 ,16,16 ,16 ,16 , 8  ,16 , 16, 16, 16,   8, 16, 16, 16, 16, 8  , 16, 16, 16, 16,   8,16, 16, 16,16, 16, 16, 16, 8,  16,  16, 8,  16, 16, 16,  16,  16, 16, 16, 16, 16,   8,16, 16, 16, 16,   8,16, 16,  16, 16,   8,16, 16, 16,  16,  16,  16, 16, 16, 16, 16,   8,16, 16, 16, 16,   8,16, 16, 16, 16, 8,16, 16, 16, 16,   8,16, 16, 16, 16
  };
  
  int melody2[] = {
    //0, 0, NA3, NE4, NA4, 0, 0, NE3, NE4, NGS4, 0, 0, NA3, NE4, NA4, 0, 0, 0, NA3, NE4, NA4, 0, 0, NE3, NE4, NGS4, 0, 0, NA3, NE4, NA4, 0
    NA3,NE4,NA4,0,0, NC4,NG4,NC5,0,0, NG3,NG4,NB4,0,0, NA3,NE4,NA4,0,0, NE3,NE4,NE5,0,0,NE4, NE5,0,0,NDS5,NE5,0, 0,NDS5,NE5,0,0, 0, NA3,NE4,NA4,0,0, NE3,NE4,NGS4,0,0, NA3,NE4,NA4, 0, NA3,NE4,NA4,0,0, NE3,NE4,NGS4,0,0, NA3,NE4,NA4,0,0, NE3,NE4,NGS4,0,0
  };
  int durations2[] = {
    //5, 5,  16,  16,  16,16, 8,  16,  16,   16,16, 8,  16,  16,  16,16, 5, 5,  16,  16,  16,16, 8,  16,  16,   16,16, 8,  16,  16,  16, 1
    16,16,16,16,8,   16,16,16,16,8,   16,16,16,16,8,   16,16,16,16,8,   16,16,16,16,16,16,   16,16,16,16,16,16,  16,16,16,16,4,  4, 16,16,16,16,8,   16,16,16,16,8,   16,16,16,16,4,4, 16,16,16,16,8,   16,16,16,16,8, 16,16,16,16,8,   16,16,16,16,8
  };
  int duration = 6;

  Tone notePlayer1;
  Tone notePlayer2;
  notePlayer1.begin(11);
  notePlayer2.begin(12);

  int noteIndex1 = 0;
  int noteIndex2 = 0;
  int nextNote1 = 0;
  int nextNote2 = 0;
  for(int t = 0; t < duration*oneTactDuration; t++)
  {
    if(t == nextNote1)
    {
      notePlayer1.play(melody1[noteIndex1]);
      nextNote1 += oneTactDuration/durations1[noteIndex1++];
    }
    if(t == nextNote2)
    {
      notePlayer2.play(melody2[noteIndex2]);
      nextNote2 += oneTactDuration/durations2[noteIndex2++];
    }
    delay(1);
  }
  notePlayer1.stop();
  notePlayer2.stop();
}

void loop()
{
}
