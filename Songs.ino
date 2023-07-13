#include <math.h>
const int LightPin= 11;//light to arduino pin 11
const int Buzzer = 9; //buzzer to arduino pin 9
float basetone = 261.63*2;// nada dasar = c5
int tempo = 74;//tempo of the song (bpm)
int lampOn = 1;

float freq(int noteNumber);//number to freq
int time(float beats);//beats to time
void play(int noteNumber, float noteBeats);//play notes (note number, note beats)
void rest(float restBeats);//play rest (rest beats)
void music(float diatonicNumber, float noteBeats);//play diatonic notes (diatonic note number, note beats)
void section(float noteNum[], float noteLegth[], int arraySize);//playing a series of notes based on the inputed memory
void hotelCalifornia();//play the song

void setup(){
  pinMode(Buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  pinMode(LightPin, OUTPUT); // set light pin to 11
}

void loop(){
  hotelCalifornia();


  // menghentikan program
  while(1){
    delay(1000);
  }
}

//input note number --> note frequency
float freq(int noteNumber){
  float output = basetone*pow(2, (float)noteNumber/12);
  return output;
}

//note or rest beats --> note or rest length in ms
int time(float beats){
  return 60000*beats/tempo;
}

//playing notes of specified note number and note beats
void play(int noteNumber, float noteBeats){
  //alternate lights
  if(lampOn){
    analogWrite(LightPin, 255);
    lampOn = 0;
  }
  else{
    analogWrite(LightPin, 0);
    lampOn = 1;
  }

  tone(Buzzer, freq(noteNumber));
  delay((float)3/4*time(noteBeats));
  noTone(Buzzer);
  delay((float)1/4*time(noteBeats));
}

//pausing the music
void rest(float restBeats){
  noTone(Buzzer);
  analogWrite(LightPin, 0);
  delay(time(restBeats));
}

//play the diatonic notes in the key of D (1 = C#, 2 = D, ...)
void music(float diatonicNumber, float noteBeats){
  int octave = 0;

  int intDiaNum = (int)diatonicNumber;
  int sharp = 0;//the sharp of the note

  //checking for sharps
  if(diatonicNumber - floor(diatonicNumber) == 0.5){
    sharp++;
  }

  //mencari octave yang dimainkan
  while ((intDiaNum > 7)||(intDiaNum < 1)){
    if(intDiaNum > 7){
      intDiaNum -= 7;
      octave += 12;
    }
    else if(intDiaNum < 1){
      intDiaNum += 7;
      octave -= 12;
    }
  }

  switch(intDiaNum){
    case 1: 
      play(1 + octave + sharp, noteBeats);
      break;
    case 2: 
      play(2 + octave + sharp, noteBeats);
      break;
    case 3: 
      play(4 + octave + sharp, noteBeats);
      break;
    case 4: 
      play(6 + octave + sharp, noteBeats);
      break;
    case 5: 
      play(7 + octave + sharp, noteBeats);
      break;
    case 6: 
      play(9 + octave + sharp, noteBeats);
      break;
    case 7: 
      play(11 + octave + sharp, noteBeats);
      break;
  }  
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

void hotelCalifornia(){
  //intro
  float section1Num[40] = {4,0,2,0,4,2,0,7,2,3 ,6.5,3,4,3,8,4,3,6.5,99 ,6,3,10,6,7,6,-1,3,6,3,99,4 ,-2.5,7,4,7,4,2,0,7,99};
  float section1Dur[] = {2,4,4,4,4,4,4,1,2,2 ,2  ,4,4,4,4,4,4,1  ,1  ,2,4,4 ,4,2,4,2 ,4,4,2,4 ,4 ,2   ,4,4,4,4,4,4,1,1};
  section(section1Num, section1Dur, 40);

  float section2Num[] = {0,7,2,7,5,2,0,7,2,5,6,7,9 ,6,9,4,6,9,4,6,4,6,4,2,4,2 ,3,7,2,7,5,0,5,7,7,4,0,99,4 ,4,-0.5,3,10,4,3,1,99};
  float section2Dur[] = {2,4,4,4,4,4,4,2,4,4,4,4,2 ,2,4,4,4,4,4,4,2,4,4,2,4,4 ,2,4,4,4,4,4,4,2,4,4,2,4 ,4 ,2,4   ,4,4 ,2,4,1,1};
  section(section2Num, section2Dur, 47);

  section(section1Num, section1Dur, 40);

  section(section2Num, section2Dur, 39);

  float section2bEndNum[] = {4,-1.5,3,10,4,3,8,99};
  float section2bEndDur[] = {2,4,4,4  ,2,4,1,1};
  section(section2bEndNum, section2bEndDur, 9);

  //verse
  float sec3Num[] = {99,4,4,4,3,3,3,4,99 ,99,4,4,3,3,3,99 ,99,4,4,3,3,3,4,99, 99,4,4,4,3,3,3,99,2,0,99};
  float sec3Dur[] = {2 ,4,4,2,4,4,2,1,2  ,2 ,2,4,2,4,1,1  ,2 ,2,2,4,4,2,1,2 , 3 ,3,3,3,3,3,4,8 ,8,1,2};
  section(sec3Num, sec3Dur, 36);
  
  float sec4Num[] = {99,4,4,4,3,2,2,4,99 ,99,4,4,3,3,3,99 ,99,4,4,3,3,3,4,99, 99,4,4,4,3,3,3,99,2,0,99};
  float sec4Dur[] = {2 ,4,4,2,4,4,2,1,2  ,2 ,2,4,2,4,1,1  ,2 ,2,2,4,4,2,1,2 , 3 ,3,3,3,3,3,4,8 ,8,1,2};
  section(sec4Num, sec4Dur, 36);


}