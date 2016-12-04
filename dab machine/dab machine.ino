#include <Servo.h>
// TONES  ==========================================
// Start by defining the relationship between 
//       note, period, &  frequency. 
#define  c     3830    // 261 Hz 
#define  d     3400    // 294 Hz 
#define  e     3038    // 329 Hz 
#define  f     2864    // 349 Hz 
#define  g     2550    // 392 Hz 
#define  a     2272    // 440 Hz 
#define  b     2028    // 493 Hz 
#define  C     1912    // 523 Hz 
#define  m     2145   // 466 Hz
// Define a special note, 'R', to represent a rest
#define  R     0

// SETUP ============================================
// Set up speaker on a PWM pin (digital 9, 10 or 11)
int speakerOut = 11;
// Do we want debugging on serial out? 1 for yes, 0 for no
int DEBUG = 1;
int playIt = 0;

Servo dabservo; 
int pos = 0;   
int speed = 5;
void setup() { 
  pinMode(speakerOut, OUTPUT);
  dabservo.attach(9);  
  Serial.begin(9600);
}

void dab()
  {
     
      for(pos = 0; pos < 180; pos += speed)  
     {  
        dabservo.write(pos);  
        delay(15); 
      }
      
      for(pos = 180; pos>=1; pos-=speed)
      {                               
        dabservo.write(pos);
        delay(15);
      }
  }

// MELODY and TIMING  =======================================
//  melody[] is an array of notes, accompanied by beats[], 
//  which sets each note's relative length (higher #, longer note)
//1 2 3 4 5 6 7
//c d e f g a b
int melody[] = {g,a,f,g,R,m,a,f,g,R};
int beats[]  = {64,32,32,64,128,64,32,32,64,64}; 
int MAX_COUNT = sizeof(melody) / 2; // Melody length, for looping.

// Set overall tempo
long tempo = 10000;
// Set length of pause between notes
int pause = 1000;
// Loop variable to increase Rest length
int rest_count = 100; //<-BLETCHEROUS HACK; See NOTES

// Initialize core variables
int tone_ = 0;
int beat = 0;
long duration  = 0;

// PLAY TONE  ==============================================
// Pulse the speaker to play a tone for a particular duration
void playTone() {
  long elapsed_time = 0;
  if (tone_ > 0) { // if this isn't a Rest beat, while the tone has 
    //  played less long than 'duration', pulse speaker HIGH and LOW
    while (elapsed_time < duration) {

      digitalWrite(speakerOut,HIGH);
      delayMicroseconds(tone_ / 2);

      // DOWN
      digitalWrite(speakerOut, LOW);
      delayMicroseconds(tone_ / 2);

      // Keep track of how long we pulsed
      elapsed_time += (tone_);
    } 
  }
  else { // Rest beat; loop times delay
    for (int j = 0; j < rest_count; j++) { // See NOTE on rest_count
      delayMicroseconds(duration);  
    }                                
  }                                 
}

void play(){
  for (int i=0; i<MAX_COUNT; i++) {
    tone_ = melody[i];
    beat = beats[i];

    duration = beat * tempo; // Set up timing

    playTone(); 
    // A pause between notes...
    delayMicroseconds(pause);
    Serial.println(digitalRead(8));
  }
}
k
int runXTimes = 0;
// LET THE WILD RUMPUS BEGIN =============================
void loop() {
  if (runXTimes < 1)
 {
    play();
    runXTimes++;
 }
  dab();
}

