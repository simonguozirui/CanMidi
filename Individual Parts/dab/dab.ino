#include <Servo.h>
 
   Servo dabservo; 
 
   int pos = 0;   
   int speed = 5;
 
   void setup()
   {
      dabservo.attach(2);  
   }
 
   void loop()
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

