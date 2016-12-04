#include <Servo.h>
   Servo current_servo; 
   int pos = 0;   
   int speed = 3;
   const int servo_c = 2;
   const int servo_d = 4;
   const int servo_e = 7;
   const int servo_f = 8;
   const int servo_g = 10;
   const int servo_a = 11;
   const int servo_b = 12;
   const int servo_C = 13;

   void setup()
   {
    pinMode(servo_c, OUTPUT);
    pinMode(servo_d, OUTPUT);
    pinMode(servo_e, OUTPUT);
    pinMode(servo_f, OUTPUT);
    pinMode(servo_g, OUTPUT);
    pinMode(servo_a, OUTPUT);
    pinMode(servo_b, OUTPUT);
    pinMode(servo_C, OUTPUT);
   }

   
   void servo_swing(int servo_num){
    current_servo.attach(servo_num); 
    int adjustment = 0;
    if (servo_num == 4){
        adjustment = 150;
    }
    if (servo_num == 7){
        adjustment = 18;
    }
    if (servo_num == 8){
        adjustment = 160;
    }
    if (servo_num == 10){
        adjustment = 20;
    }
    if (servo_num == 11){
        adjustment = 140;
    }
    if (servo_num == 12){
        adjustment = 130;
    }
    if (servo_num == 13){
        adjustment = 25;
    }
    for(pos = 0+adjustment; pos < 25+adjustment; pos += speed)  
     {  
        current_servo.write(pos);  
        delay(10); 
      }
      
      for(pos = 25+adjustment; pos>=0+adjustment; pos-=speed)
      {                               
        current_servo.write(pos);
        delay(10);
      }
   }
 
   void loop()
  { 
     servo_swing(servo_c);
     delay(500);
     servo_swing(servo_d);
     delay(500);
     servo_swing(servo_e);
     delay(500);
     servo_swing(servo_f);
     delay(500);
     servo_swing(servo_g);
     delay(500);
     servo_swing(servo_a);
     delay(500);
     servo_swing(servo_b);
     delay(500);
     servo_swing(servo_C);
     delay(500);
     
     servo_swing(servo_c);
     delay(50);
     servo_swing(servo_d);
     delay(50);
     servo_swing(servo_e);
     delay(50);
     servo_swing(servo_f);
     delay(50);
     servo_swing(servo_g);
     delay(50);
     servo_swing(servo_a);
     delay(50);
     servo_swing(servo_b);
     delay(50);
     servo_swing(servo_C);
     delay(50);
      servo_swing(servo_b);
     delay(50);
     servo_swing(servo_a);
     delay(50);
     servo_swing(servo_g);
     delay(50);
     servo_swing(servo_f);
     delay(50);
     servo_swing(servo_e);
     delay(50);
     servo_swing(servo_d);
     delay(50);
     servo_swing(servo_c);
     delay(50);
     
  }
  

