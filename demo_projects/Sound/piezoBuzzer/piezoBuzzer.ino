/**
 * Kocka leze dirou
 * 
 * circuit:
 * 8-ohm speaker on digital pin 8 + resistor!
 */
#include "pitches.h"

void setup()
{
  const int oneNoteDuration = 1000; // duration of 1/1 note in milliseconds
  const int numberOfNotes = 42;

  // notes in the melody:
  int melody[] = {
    NC4, ND4, NE4, NF4, NG4, NG4, NA4, NA4, NG4, NA4, NA4, NG4, NF4, NF4, NF4, NF4, NE4, NE4, ND4, ND4, NG4, NC4, ND4, NE4, NF4, NG4, NG4, NA4, NA4, NG4, NA4, NA4, NG4, NF4, NF4, NF4, NF4, NE4, NE4, ND4, ND4, NC4
  };

  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  int noteDurations[] = {
    8, 8, 8, 8, 4, 4, 4, 4, 2, 4, 4, 2, 8, 8, 8, 8, 4, 4, 4, 4, 2, 8, 8, 8, 8, 4, 4, 4, 4, 2, 4, 4, 2, 8, 8, 8, 8, 4, 4, 4, 4, 2
  };
  
  for (int thisNote = 0; thisNote < numberOfNotes; thisNote++)
  {
    // calculate the note duration in milliseconds
    int noteDuration = oneNoteDuration / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 13 / 10;
    delay(pauseBetweenNotes);
    // stop the tone playing
    noTone(8);
  }
}

void loop()
{
}
