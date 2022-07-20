#include <Servo.h>
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* strtol */
char buffer[11];
Servo servo1; // Create a servo object
Servo servo2; // Create a second servo object



void setup()
{

int right = 13;
int left = 12;
int pin3 = 11;
int pin4 = 10;

pinMode(right,OUTPUT);
pinMode(left,OUTPUT);
pinMode(pin3,OUTPUT);
pinMode(pin4,OUTPUT);


servo1.attach(2); // Attaches the servo on pin 2 to the
//servo1 object
servo2.attach(4); // Attaches the servo on pin 4 to the                             BIGGER SERVO           Input- B
//servo2 object;
Serial.begin(115200);
while(Serial.available())
Serial.read();
servo1.write(180); // Put servo1 at home position
servo2.write(120); // Put servo2 at home postion
Serial.println("STARTING...");

}
void loop()
{
/*
servo1.write(180); 
servo2.write(80);
digitalWrite(12,HIGH);
delay(27000);
digitalWrite(12,LOW);
delay(1000);      */

if (Serial.available() > 0) { // Check if data has been
//entered
int index=0;
delay(100); // Let the buffer fill up
int numChar = Serial.available(); // Find the string
//length
if (numChar>10) {
numChar=10;
}
while (numChar--) {
// Fill the buffer with the string
buffer[index++] = Serial.read();
}
buffer[index]='\0';
splitString(buffer); // Run splitString function
}
}
void splitString(char* data) {
Serial.print("Data entered: ");
Serial.println(data);
char* parameter;
parameter = strtok (data, " ,"); //String to token
while (parameter != NULL) { // If we haven't reached the end
//of the string...
setServo(parameter); // ...run the setServo function
parameter = strtok (NULL, " ,");
}
while(Serial.available())
Serial.read();
}

void setServo(char* data) {
if ((data[0] == 'A') || (data[0] == 'a') ) {
int firstVal = strtol(data+1, NULL, 10); // String to
//long integer
firstVal = constrain(firstVal,0,180); // Constrain
//values
servo1.write(firstVal);
Serial.print("Servo1 is set to: ");
Serial.println(firstVal);
}
if ((data[0] == 'B') || (data[0] == 'b')) {
int secondVal = strtol(data+1, NULL, 10); // String
//to long integer
secondVal = constrain(secondVal,0,255); //
//Constrain the values
servo2.write(secondVal);
Serial.print("Servo2 is set to: ");
Serial.println(secondVal);
}
if ((data[0] == 'R') || (data[0] == 'r')) {
digitalWrite(13,HIGH);
delay(1000);
digitalWrite(13,LOW);
Serial.print("One step to right \n");
}
if ((data[0] == 'L') || (data[0] == 'l')) {
digitalWrite(12,HIGH);
delay(1000);
digitalWrite(12,LOW);
Serial.print(" One step to left \n");
}
}
