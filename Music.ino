#include <math.h>
#include "pitches.h"
#include <Tone.h>

#define NOTENUM 94

const int Buzzer1 = 10; //buzzer1 to arduino pin 9
const int Buzzer2 = 9; //buzzer2 to arduino pin 10 
int lampOn = 1;

float tempo_to_millis(int tempo){
  float duration = (float)60*1000/(float)tempo;
  return duration;
}

void play_normal(Tone *notePlayer, float one_per_quarterNote, float *pitch, int tempo){
  float duration = (float)1 / one_per_quarterNote * tempo_to_millis(tempo);
  notePlayer[0].play(pitch[0], duration);
  notePlayer[1].play(pitch[1], duration);
  delay(duration*1);
  // delay(duration*0.75);
  notePlayer[0].stop();
  notePlayer[1].stop();
  // delay(duration*0.25);
}



void setup(){
  Tone notePlayer[2];

  notePlayer[1].begin(9);
  notePlayer[0].begin(10);

  int tempo = 120;
  float durPitch[NOTENUM][2][2] = {
    {{1}, {C5, C3}},
    {{1}, {C5, C4}},
    {{1}, {G5, E4}},
    {{1}, {G5, C4}},
    {{1}, {A5, F4}},
    {{1}, {A5, C4}},
    {{1}, {G5, E4}},
    {{1}, {G5, C4}},

    {{1}, {F5, D4}},
    {{1}, {F5, B3}},
    {{1}, {E5, C4}},
    {{1}, {E5, A3}},
    {{1}, {D5, F3}},
    {{1}, {D5, G3}},
    {{0.5}, {C5, C3}},
    

    {{1}, {C5, C3}},
    {{1}, {C5, C4}},
    {{1}, {G5, E4}},
    {{1}, {G5, C4}},
    {{1}, {A5, F4}},
    {{1}, {A5, C4}},
    {{1}, {G5, E4}},
    {{1}, {G5, C4}},

    {{1}, {F5, D4}},
    {{1}, {F5, B3}},
    {{1}, {E5, C4}},
    {{1}, {E5, A3}},
    {{1}, {D5, F3}},
    {{1}, {D5, G3}},
    {{0.5}, {C5, C3}},
    

    {{1}, {G5, E4}},
    {{1}, {G5, G3}},
    {{1}, {F5, D4}},
    {{1}, {F5, G3}},
    {{1}, {E5, C4}},
    {{1}, {E5, G3}},
    {{1}, {D5, B3}},
    {{1}, {D5, G3}},
    
    {{1}, {G5, E4}},
    {{1}, {G5, G3}},
    {{1}, {F5, D4}},
    {{1}, {F5, G3}},
    {{1}, {E5, C4}},
    {{1.25}, {E5, C4}},
    {{4}, {F5, D4}},
    {{1}, {E5, C4}},
    {{1}, {D5, C4}},
    
    {{1}, {C5, C3}},
    {{1}, {C5, C4}},
    {{1}, {G5, E4}},
    {{1}, {G5, C4}},
    {{1}, {A5, F4}},
    {{1}, {A5, C4}},
    {{1}, {G5, E4}},
    {{1}, {G5, C4}},

    {{1}, {F5, D4}},
    {{1}, {F5, B3}},
    {{1}, {E5, C4}},
    {{1}, {E5, A3}},
    {{1}, {D5, F3}},
    {{1}, {D5, G3}},
    {{0.5}, {C5, C3}},

    

    {{1}, {G5, E4}},
    {{1}, {G5, G3}},
    {{1}, {F5, D4}},
    {{1}, {F5, G3}},
    {{1}, {E5, C4}},
    {{1}, {E5, G3}},
    {{1}, {D5, B3}},
    {{1}, {D5, G3}},
    
    {{1}, {G5, E4}},
    {{1}, {G5, G3}},
    {{1}, {F5, D4}},
    {{1}, {F5, G3}},
    {{1}, {E5, C4}},
    {{1.25}, {E5, C4}},
    {{4}, {F5, D4}},
    {{1}, {E5, C4}},
    {{1}, {D5, C4}},
    
    {{1}, {C5, C3}},
    {{1}, {C5, C4}},
    {{1}, {G5, E4}},
    {{1}, {G5, C4}},
    {{1}, {A5, F4}},
    {{1}, {A5, C4}},
    {{1}, {G5, E4}},
    {{1}, {G5, C4}},

    {{1}, {F5, D4}},
    {{1}, {F5, B3}},
    {{1}, {E5, C4}},
    {{1}, {E5, A3}},
    {{1}, {D5, F3}},
    {{1}, {D5, G3}},
    {{0.5}, {C5, C3}}
  };

  for (int i = 0; i < NOTENUM; i++){
    play_normal(notePlayer, durPitch[i][0][0], durPitch[i][1], 120);
  }

}

void loop(){
}

