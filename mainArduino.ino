
#include <Servo.h>
Servo cservo, dservo, eservo, fservo, gservo, aservo, bservo, Cservo;
int pos = 0;   
int speed = 3;
boolean swinging = false;
const int servo_c = 2;
const int servo_d = 4;
const int servo_e = 7;
const int servo_f = 8;
const int servo_g = 10;
const int servo_a = 11;
const int servo_b = 12;
const int servo_C = 13;

const int midilength = 32;

String data;
String playservos[32];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(2000);

  int i = 0;
  boolean startReading = false;
  while (i<midilength) {
    if (Serial.available()){
       int newRead = Serial.read();
       
       if (startReading) {
         data += newRead;
         if (data.length() >= 8) {
           playservos[i] = data;
           Serial.println(data);
           data = "";
           i++;
         }
       }
       
       if (newRead == 97){
         startReading = true;
         Serial.println(data);
         data = "";
         Serial.println("Start Reading");
       }
    }
  }
  while(1);
  
  pinMode(servo_c, OUTPUT);
  pinMode(servo_d, OUTPUT);
  pinMode(servo_e, OUTPUT);
  pinMode(servo_f, OUTPUT);
  pinMode(servo_g, OUTPUT);
  pinMode(servo_a, OUTPUT);
  pinMode(servo_b, OUTPUT);
  pinMode(servo_C, OUTPUT);
  
  cservo.attach(servo2output(0));
  dservo.attach(servo2output(1));
  eservo.attach(servo2output(2));
  fservo.attach(servo2output(3));
  gservo.attach(servo2output(4));
  aservo.attach(servo2output(5));
  bservo.attach(servo2output(6));
  Cservo.attach(servo2output(7));
  
  cservo.write(0);
  dservo.write(150);
  eservo.write(20);
  fservo.write(150);
  gservo.write(20);
  aservo.write(140);
  bservo.write(130);
  Cservo.write(25);
  
  

}

int servo2output(int servoid) {
  int output = 0;
  if (servoid == 0)
    output = 2;
  else if (servoid == 1)
    output = 4;
  else if (servoid == 2)
    output = 7;
  else if (servoid == 3)
    output = 8;
  else if (servoid == 4)
    output = 10;
  else if (servoid == 5)
    output = 11;
  else if (servoid == 6)
    output = 12;
  else if (servoid == 7)
    output = 13;
  
  return output;
}

//void servo_swing(int servo_num){
//   current_servo.attach(servo_num); 
//   int adjustment = 0;
//   if (servo_num == 4 || servo_num == 8  || servo_num == 11 || servo_num == 12){
//     adjustment = 155;
//   }
//   for(pos = 0+adjustment; pos < 25+adjustment; pos += speed)  
//   {  
//      current_servo.write(pos);  
//      delay(10); 
//   }
//     
//   for(pos = 25+adjustment; pos>=0+adjustment; pos-=speed)
//   {                               
//     current_servo.write(pos);
//     delay(10);
//   }
//}

void servo_swingAll(int servo1, int servo2, int servo3, int servo4, int servo5, int servo6, int servo7, int servo8) {
  swinging = true;
  Serial.println("Start Swinging");
  
  int delayCount = 0;
  
  for(pos = 0; pos < 25; pos += speed)
  {
    if (servo1 == 1)
      cservo.write(pos);
    if (servo2 == 1)
      dservo.write(pos+150);
    if (servo3 == 1)
      eservo.write(pos+20);
    if (servo4 == 1)
      fservo.write(pos+150);
    if (servo5 == 1)
      gservo.write(pos+20);
    if (servo6 == 1)
      aservo.write(pos+140);
    if (servo7 == 1)
      bservo.write(pos+130);
    if (servo8 == 1)
      Cservo.write(pos+25);
    delay(10);
    delayCount += 10;
    
    Serial.println("Hitting");
  }
  for(pos = 25; pos >= 0; pos -= speed)
  {
    if (servo1 == 1)
      cservo.write(pos);
    if (servo2 == 1)
      dservo.write(pos+150);
    if (servo3 == 1)
      eservo.write(pos+20);
    if (servo4 == 1)
      fservo.write(pos+150);
    if (servo5 == 1)
      gservo.write(pos+20);
    if (servo6 == 1)
      aservo.write(pos+140);
    if (servo7 == 1)
      bservo.write(pos+130);
    if (servo8 == 1)
      Cservo.write(pos+25);
    delay(10);
    delayCount += 10;
    
    Serial.println("Rewinding");
  }
  
  delay (250-delayCount);
  
  swinging = false;
  Serial.println("Done Swinging");
  
}

void loop() {
  for (int i = 0; i<midilength; i++) {
    String stepString = playservos[i];
    int servos[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (int servo = 0; servo<8; servo++) {
      int value = stepString[servo] + 0;
      if (value == 49) {
        servos[servo] = 1;
      }
    }
    if (!swinging)
      servo_swingAll(servos[0],servos[1],servos[2],servos[3],servos[4],servos[5],servos[6],servos[7]);
  }
  
  Serial.println("End!");
  
  while (1);
}

