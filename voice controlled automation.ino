#include <Servo.h>
Servo ServoMotor;
String voice;
int
led1 = 2, //Connect LED 1 To Pin #2
led2 = 3, //Connect LED 2 To Pin #3
led3 = 4, //Connect LED 3 To Pin #4
led4 = 5, //Connect LED 4 To Pin #5
led5 = 6; //Connect LED 5 To Pin #6
int led6 = 8;
//--------------------------Call A Function-------------------------------//
void allon(){
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, HIGH);
     digitalWrite(led4, HIGH);
     digitalWrite(led5, HIGH);
     digitalWrite(led6, HIGH);
}
void alloff(){
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, LOW);
     digitalWrite(led4, LOW);
     digitalWrite(led5, LOW);
     digitalWrite(led6, LOW);
     
}

void roomon(){
     digitalWrite(led2, HIGH);
     digitalWrite(led4, HIGH);
}

void roomoff(){
     digitalWrite(led2, LOW);
     digitalWrite(led4, LOW);
}

void droomon(){
     digitalWrite(led3, HIGH);
     digitalWrite(led5, HIGH);
}

void droomoff(){
     digitalWrite(led3, LOW);
     digitalWrite(led5, LOW);
}
void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  ServoMotor.attach(11);
}
void loop() {
  while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  }
  if (voice.length() > 0) {
    Serial.println(voice);
//-----------------------------------------------------------------------//  
  //----------Control Multiple Pins/ LEDs----------//
       if(voice == "*all on") {allon();}  //Turn Off All Pins (Call Function)
  else if(voice == "*all of"){alloff();} //Turn On  All Pins (Call Function)
  else if(voice == "*all off"){alloff();};

 if(voice == "*room on") {roomon();}  //Turn Off All Pins (Call Function)
  else if(voice == "*room of"){roomoff();} //Turn On  All Pins (Call Function)
  else if(voice == "*room off"){roomoff();} ;

  if(voice == "*drawing room on") {droomon();}  //Turn Off All Pins (Call Function)
  else if(voice == "*drawing room of"){droomoff();} //Turn On  All Pins (Call Function)
  else if(voice == "*drawingroom off"){droomoff();} 

  
  //----------Turn On One-By-One----------//
  else if(voice == "*door open") {ServoMotor.write(11);}
  else if(voice == "*room fan on") {digitalWrite(led2, HIGH);}
  else if(voice == "*TV on") {digitalWrite(led3, HIGH);}
  else if(voice == "*cupboard lights on") {digitalWrite(led4, HIGH);}
  else if(voice == "*lights on") {digitalWrite(led5, HIGH);}
else if(voice == "*drawing room fan on") {digitalWrite(led6, HIGH);}
  //----------Turn Off One-By-One----------//
  else if(voice == "*door closed") {ServoMotor.write(90);}
  else if(voice == "*room fan") {digitalWrite(led2, LOW);}
  else if(voice == "*TV") {digitalWrite(led3, LOW);}
  else if(voice == "*cupboard lights") {digitalWrite(led4, LOW);}
  else if(voice == "*lights") {digitalWrite(led5, LOW);}
  else if(voice == "*drawing room fan") {digitalWrite(led6, LOW);}
  
//-----------------------------------------------------------------------//

voice="";}} //Reset the variable after initiating
