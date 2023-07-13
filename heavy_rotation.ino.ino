#include <math.h>
const int LightPin= 11;//light to arduino pin 11
const int Buzzer = 9; //buzzer to arduino pin 9
float basetone = 261.63;// nada dasar = c4
int tempo = 178;//tempo of the song (bpm)
int lampOn = 1;

float freq(int noteNumber, int octave);

/*penjelasan nama variabel
  float xyz = 
  x: nada dasar notnya
  y: oktafnya (c berarti oktaf 3, d oktaf 4, e oktaf 5, dst)
  z: s atau n, s artinya sharp, n artinya natural
*/
float ccn = freq(0, -1);
float ccs = freq(1, -1);
float dcn = freq(2, -1);
float dcs = freq(3, -1);
float ecn = freq(4, -1);
float fcn = freq(5, -1);
float fcs = freq(6, -1);
float gcn = freq(7, -1);
float gcs = freq(8, -1);
float acn = freq(9, -1);
float acs = freq(10, -1);
float bcn = freq(11, -1);

float cdn = freq(0, 0);
float cds = freq(1, 0);
float ddn = freq(2, 0);
float dds = freq(3, 0);
float edn = freq(4, 0);
float fdn = freq(5, 0);
float fds = freq(6, 0);
float gdn = freq(7, 0);
float gds = freq(8, 0);
float adn = freq(9, 0);
float ads = freq(10, 0);
float bdn = freq(11, 0);

float cen = freq(0, 1);
float ces = freq(1, 1);
float den = freq(2, 1);
float des = freq(3, 1);
float een = freq(4, 1);
float fen = freq(5, 1);
float fes = freq(6, 1);
float gen = freq(7, 1);
float ges = freq(8, 1);
float aen = freq(9, 1);
float aes = freq(10, 1);
float ben = freq(11, 1);


float cfn = freq(0, 2);
float cfs = freq(1, 2);


float skp = 420.69;


void setup(){
  pinMode(Buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  pinMode(LightPin, OUTPUT); // set light pin to 11

  heavyRotation();
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
void play(float freq, float noteBeats){
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
void section(float notes[], int arraySize){
  for (int i = 0; i < arraySize; i+=2){
    //jika input rst dimasukkan maka tidak akan memainkan nada tapi durasi tetap dimainkan
    if(notes[i] == 420.69){
      rest(notes[i + 1]);
    }
    else{
      //angka pada posisi genap adalah not dan ganjil adalah durasi
      play(notes[i], notes[i + 1]);
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

void heavyRotation(){
  float midi[] = {
    gds,-2,gds,-2,skp,-2,fds,-2,fds,-2,fds,-2,skp,-2,adn,-2,  adn,-2,adn,-2,skp,-2,gds,-2,skp,-2,fds,-2,skp,-2,fds,-2,  
    gds,-2,gds,-2,skp,-2,fds,-2,fds,-2,fds,-2,skp,-2,adn,-2,  skp,-1,bdn, 1       ,een, 1       ,fes, 1,

    ges, 2,edn, 1,fds, 1,gds, 2,een, 1,fes, 1,ges, 2,edn, 1,fds, 1,gds, 2,een, 1,fes, 1,ges, 2,edn, 1,fds, 1,gds, 2,ges, 1,aen, 1, ben,2,ges,2,fes,2,een,2,
  
    cfs, 1,cfs, 1,cfs, 1,aen, 1,fes, 1,fes, 1,ges, 1,aen, 1, ben, 1,ben, 1,ben, 1,ges, 1,een, 1,skp, 1,skp, 1,ges, 1, 
    aen, 2,ces, 2,een, 1,des, 1,ces, 1,des, 1,een, 2,bdn, 1, gds, 1,adn, 1,gds, 1,fds, 1,edn, 1,

    cds, 1,acn, 1,edn, 1,adn, 1,  gds, 1,fds, -2,fds, 1,skp,-2,fds, 1, 
    bdn, 2,bdn, 1,gds, 1,  ces, 1,bdn, 1,adn, 1,gds, 1, 
    adn, 1,gds, 1,fds, 1,dds,1,  edn, -2,edn, -2,edn, -2,edn, -2
  }; 
  section(midi, sizeof(midi)/4);
}

