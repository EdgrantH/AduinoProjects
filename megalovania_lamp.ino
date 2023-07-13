#include <math.h>
const int red_light_pin= 11;//light to arduino pin 11
const int buzzer = 9; //buzzer to arduino pin 9
float nada = 493.88;// nada dasar = c4

//memainkan buzzer 1 kali
void sans(float bone){
  //bone adalah frekuensi yang dimainkan
  analogWrite(red_light_pin, 255);
  tone(buzzer, nada*pow(2, bone/12));
  delay(100);
  analogWrite(red_light_pin, 0);
  noTone(buzzer); 
  delay(25);
}

//sans dengan durasi setengah
void halfSans(float bone){
  //bone adalah frekuensi yang dimainkan
  analogWrite(red_light_pin, 255);
  tone(buzzer, nada*pow(2, bone/12));
  delay(50);
  analogWrite(red_light_pin, 0);
  noTone(buzzer); 
  delay(12.5);
}

//menghentikan nada
void rest(){
  noTone(buzzer); 
  delay(125);
}
//memainkan sebuah nada 2 kali 
void mega(int freq){
  sans(freq);
  sans(freq);
}

//memainkan satu baris intro megalovania bagian belakang
void lovania(){
  long long memlo = 56106050400302;
  for(float i = 1; i <= 14; i++){
    switch (memlo % 10){
      case 1:
        sans(3);
        break;
      case 2:
        sans(15);
        break;
      case 3:
        sans(10);
        break;
      case 4:
        sans(9);
        break;
      case 5:
        sans(8);
        break;
      case 6:
        sans(6);
        break;
      case 0:
        rest();
        break;
      }
      memlo /= 10;
  }
}

//memainkan satu baris lagu
void megalovania(int freq){
  mega(freq);
  lovania();
}

//memainkan 4 baris lagu atau satu tema
void theme(){
  megalovania(3);
  megalovania(1);
  megalovania(0);
  megalovania(-1);
}

void bridge(){
  sans(6);
  rest();
  sans(6);
  sans(6);
  rest();
  sans(6);
  rest();
  sans(6);
  rest();
  sans(3);
  rest();
  sans(3);
  rest();
  rest();
  rest();
  rest();

  sans(6);
  rest();
  sans(6);
  sans(6);
  rest();
  sans(8);
  rest();
  sans(9);
  rest();
  halfSans(8);
  halfSans(9);
  sans(8);
  sans(3);
  sans(6);
  sans(8);
  rest();
  rest();

  sans(6);
  rest();
  sans(6);
  sans(6);
  rest();
  sans(8);
  rest();
  sans(9);
  rest();
  sans(10);
  rest();
  sans(13);
  rest();
  sans(10);
  rest();
  rest();

  sans(15);
  rest();
  sans(15);
  rest();
  sans(15);
  sans(10);
  sans(15);
  sans(13);
  rest();
  rest();
  rest();
  rest();
  rest();
  rest();
  rest();
  rest();


  sans(10);
  rest();
  sans(10);
  sans(10);
  rest();
  sans(10);
  rest();
  sans(10);
  rest();
  sans(8);
  rest();
  sans(8);
  rest();
  rest();
  rest();
  rest();

  sans(10);
  rest();
  sans(10);
  rest();
  sans(10);
  sans(10);
  rest();
  sans(8);
  rest();
  sans(10);
  rest();
  sans(15);
  sans(15);
  sans(10);
  sans(8);
  rest();

  sans(15);
  rest();
  sans(10);
  rest();
  sans(8);
  rest();
  sans(6);
  rest();
  sans(13);
  rest();
  sans(8);
  rest();
  sans(6);
  rest();
  sans(5);
  rest();

  sans(-1);
  rest();
  sans(3);
  sans(5);
  rest();
  sans(6);
  rest();
  sans(13);
  rest();
  rest();
  rest();
  rest();
  rest();
  rest();
  rest();
  rest();
}

void theme2(){
  rest();
  rest();
  rest();
  rest();
  rest();
  rest();
  rest();
  rest();
  sans(6);
  sans(3);
  sans(6);
  sans(8);
  sans(9);
  sans(8);
  sans(6);
  sans(3);

  halfSans(9);
  halfSans(8);
  sans(3);
  sans(6);
  rest();
  sans(8);
  rest();
  rest();
  rest();
  rest();
  rest();
  rest();
  rest();
  rest();
  sans(9);
  rest();
  sans(10);

  sans(13);
  rest();
  sans(10);
  sans(9);
  sans(8);
  sans(6);
  sans(3);
  sans(5);
  sans(6);
  rest();
  sans(8);
  rest();
  sans(10);
  rest();
  sans(13);
  rest();

  sans(14);
  rest();
  sans(9);
  rest();
  sans(9);
  sans(8);
  sans(6);
  sans(8);
  rest();
  rest();
  rest();
  rest();
  rest();
  rest();
  rest();
  rest();


  sans(3);
  rest();
  sans(5);
  rest();
  sans(6);
  rest();
  sans(12+6);
  rest();
  sans(12+5);
  rest();
  rest();
  rest();
  sans(12+3);
  rest();
  rest();
  rest();
  
  
  sans(12+5);
  rest();
  rest();
  rest();
  sans(12+6);
  rest();
  rest();
  rest();
  sans(12+8);
  rest();
  rest();
  rest();
  sans(12+5);
  rest();
  rest();
  rest();

  sans(12+10);
  rest();
  rest();
  rest();
  rest();
  rest();
  rest();
  rest();
  sans(12+10);
  sans(12+9);
  sans(12+8);
  sans(12+7);
  sans(12+6);
  sans(12+5);
  sans(12+4);
  sans(12+3);

  sans(12+2);
  rest();
  rest();
  rest();
  rest();
  rest();
  rest();
  rest();
  sans(12+4);
  rest();
  rest();
  rest();
  rest();
  rest();
  rest();
  rest();
}

void setup(){
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  pinMode(red_light_pin, OUTPUT); // set light pin to 11
}

void loop(){
  theme();
  theme();
  nada = nada*2; //ganti octave
  theme();
  theme();
  
  nada = nada/2; //ganti balik octave
  bridge();
  
  theme2();
  theme2();
  
  theme();
  theme();
  

  //menghentikan program
  while(1){
    delay(1000);
  }
}