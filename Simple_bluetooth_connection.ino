#include <SoftwareSerial.h>
SoftwareSerial myserial(6, 7); // rx | tx
// TX from bluetooth module must connect to rx pin and vice versa

char msg;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400); // opens the serial port
  myserial.begin(9600); // this must be the baud rate of the module not the arduino
  pinMode(13,OUTPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(myserial.available()>0) { // this listens for a msg from the bluetooth module
    msg = myserial.read(); // reads the message
  }

  Serial.write(msg); // this is so that we see the message sent in the serial monitor

  if (msg=='a') {
    digitalWrite(13, HIGH);
  } else{
    digitalWrite(13, LOW); 
  }
}
  
