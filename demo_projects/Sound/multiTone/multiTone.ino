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
  const int oneNoteDuration = 1000; // duration of 1/1 note in milliseconds
  const int numberOfNotes = 14;

  // notes in the melody:
  int melody[] = {
    NC4, ND4, NE4, NF4, NG4, NA4, NB4, NC5, ND5, NE5, NF5, NG5, NA5, NB5
  };
  int melody2[] = {
    //NC5, ND5, NE5, NF5, NG5, NA5, NB5, NC4, ND4, NE4, NF4, NG4, NA4, NB4
    NB5, NA5, NG5, NF5, NE5, ND5, NC5, NB4, NA4, NG4, NF4, NE4, ND4, NC4
  };

  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  int noteDurations[] = {
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8
  };

  Tone notePlayer1;
  Tone notePlayer2;
  notePlayer1.begin(11);
  notePlayer2.begin(12);
  
  for(;;)
  for (int thisNote = 0; thisNote < numberOfNotes; thisNote++)
  {
    // calculate the note duration in milliseconds
    int noteDuration = oneNoteDuration / noteDurations[thisNote];
    notePlayer1.play(melody[thisNote], noteDuration);
    notePlayer2.play(melody2[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 10 / 13;
    delay(pauseBetweenNotes);
    // stop the tone playing
    notePlayer1.stop();
    notePlayer2.stop();
  }
}

void loop()
{
}
