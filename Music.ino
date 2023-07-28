#include <math.h>
#include "pitches.h"
#include <Tone.h>

const int Buzzer1 = 10; //buzzer1 to arduino pin 9
const int Buzzer2 = 9; //buzzer2 to arduino pin 10 
int lampOn = 1;


Tone notePlayer[2];
int tempo = 120;
float durPitch[2][2][9] = {
  {
    {C5,D5,E5,F5,G5,F5,E5,C5,-1},//pitch1
    {1,1,1,1,1,1,1,1,-1}//dur1
  
  },
  {
    {C6,D6,E6,F6,G6,F6,E6,C6,-1},//pitch2
    {1,1,1,1,1,1,1,1,-1}//dur2
  },
};

float tempo_to_millis(int tempo){
  float duration = (float)60*1000/(float)tempo;
  return duration;
}

// void play_normal(Tone *notePlayer, float one_per_quarterNote, float *pitch, int tempo){
//   float duration = (float)1 / one_per_quarterNote * tempo_to_millis(tempo);
//   notePlayer[0].play(pitch[0], duration);
//   notePlayer[1].play(pitch[1], duration);
//   // delay(duration*1);
//   delay(duration*0.9);
//   notePlayer[0].stop();
//   notePlayer[1].stop();
//   delay(duration*0.1);
// }

void play_unatached(Tone notePlayer, float one_per_quarterNote[], float pitch[], int tempo, int noteNum){
  // Base case
  if (pitch[noteNum] <= -1) return;

  float durationMs = (float)1 / one_per_quarterNote[noteNum] * tempo_to_millis(tempo);
  float timeStart = millis();
  notePlayer.play(pitch[noteNum], durationMs);

  if (millis() > timeStart + durationMs){
    play_unatached(notePlayer, one_per_quarterNote[], pitch[], tempo, noteNum + 1);
  }

}


void setup(){
  notePlayer[1].begin(10);
  notePlayer[0].begin(9);


  // for (int i = 0; i < NOTENUM; i++){
  //   play_normal(notePlayer, durPitch[i][0][0], durPitch[i][1], tempo);
  // }

}

void loop(){
  play_unatached(notePlayer[0], durPitch[0][1], durPitch[0][0], tempo, 0);
}

