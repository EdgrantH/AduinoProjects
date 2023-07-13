#include <math.h>
const int LightPin= 11;//light to arduino pin 11
const int Buzzer = 9; //buzzer to arduino pin 9
float basetone = 261.63;// nada dasar = c4
int tempo = 178;//tempo of the song (bpm)
int lampOn = 1;

float c5n = freq(0, -1);
float c5s = freq(1, -1);
float d5n = freq(2, -1);
float d5s = freq(3, -1);
float e5n = freq(4, -1);
float f5n = freq(5, -1);
float f5s = freq(6, -1);
float g5n = freq(7, -1);
float g5s = freq(8, -1);
float a5n = freq(9, -1);
float a5s = freq(10, -1);
float b5n = freq(11, -1);

float c4n = freq(0, 0);
float c4s = freq(1, 0);
float d4n = freq(2, 0);
float d4s = freq(3, 0);
float e4n = freq(4, 0);
float f4n = freq(5, 0);
float f4s = freq(6, 0);
float g4n = freq(7, 0);
float g4s = freq(8, 0);
float a4n = freq(9, 0);
float a4s = freq(10, 0);
float b4n = freq(11, 0);

float c5n = freq(0, 1);
float c5s = freq(1, 1);
float d5n = freq(2, 1);
float d5s = freq(3, 1);
float e5n = freq(4, 1);
float f5n = freq(5, 1);
float f5s = freq(6, 1);
float g5n = freq(7, 1);
float g5s = freq(8, 1);
float a5n = freq(9, 1);
float a5s = freq(10, 1);
float b5n = freq(11, 1);



void setup(){
  pinMode(Buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  pinMode(LightPin, OUTPUT); // set light pin to 11

  play(c4n, 1);
}

void loop(){
}


//input note number --> note frequency, octave --> octave from middle c, -1(c3), 0(c4), 1(c5)
float freq(int noteNumber, int octave){
  float output = basetone*pow(2, (float)(noteNumber + octave*12)/12);
  return output;
}

//note or rest beats --> note or rest length in ms
//-x will be outputed as 1/x
int time(int beats){
  if(beats < 0){
    return 60000/tempo/abs(beats);
  }
  return 60000*beats/tempo;
}

//playing notes of specified note number and note beats
void play(float freq, int noteBeats){
  //alternate lights
  if(lampOn){
    analogWrite(LightPin, 255);
    lampOn = 0;
  }
  else{
    analogWrite(LightPin, 0);
    lampOn = 1;
  }

  tone(Buzzer, freq);
  delay((float)3/4*time(noteBeats));
  noTone(Buzzer);
  delay((float)time(noteBeats)/4);
}

//pausing the music
void rest(float restBeats){
  noTone(Buzzer);
  analogWrite(LightPin, 0);
  delay(time(restBeats));
}

//playing a series of notes based on the inputed memory
void section(float noteNum[], float noteLegth[], int arraySize){

  for (int i = 0; i < arraySize; i++)
  {
    if(noteNum[i] == 99){
      rest(1/noteLegth[i]);
    }
    else{
      music(noteNum[i], 1/noteLegth[i]);
    }
  }
}

void chromAsc(float noteStart, int end){
  for(int i = 0; i < end; i++){
    play(noteStart + i, 0.25);
  }
}

void chromDes(float noteStart, int end){
  for(int i = 0; i > -end; i--){
    play(noteStart + i, 0.25);
  }
}