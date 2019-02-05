#include <SoftwareSerial.h>

//news api key = 0f73238db5714521a33002062535816b

/*
  Edited Example Code from - Author: Joe Grand [www.grandideastudio.com]                                      
  https://www.parallax.com/sites/default/files/downloads/30016-Emic-2-Text-To-Speech-Documentation-v1.2.pdf // learned to use EMIC from this website
  https://www.arduino.cc/en/Tutorial/HttpClient  // learned about HTTP Client 
*/

// include the SoftwareSerial library so we can use it to talk to the Emic 2 module



#define rxPin   10  // Serial input (connects to Emic 2's SOUT pin)
#define txPin   11  // Serial output (connects to Emic 2's SIN pin)
#define ledPin  13  // Most Arduino boards have an on-board LED on this pin

// set up a new serial port
SoftwareSerial emicSerial =  SoftwareSerial(rxPin, txPin);

void setup()  // Set up code called once on start-up
{
  // define pin modes
  pinMode(ledPin, OUTPUT);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT); 
  
  // set the data rate for the SoftwareSerial port
  emicSerial.begin(9600);

  digitalWrite(ledPin, LOW);  // turn LED off
  
  emicSerial.print('\n');             // Send a CR in case the system is already up
  while (emicSerial.read() != ':');   // When the Emic 2 has initialized and is ready, it will send a single ':' character, so wait here until we receive it
  delay(10);                          // Short delay
  emicSerial.flush();                 // Flush the receive buffer


}

void loop()  // Main code, to run repeatedly
{

  
  emicSerial.print('S');
  emicSerial.print("Hello Ram, How are you?");
  delay(500);
  emicSerial.print("Yo Aaron, whats good");

  digitalWrite(ledPin, HIGH);
  while (emicSerial.read() != ':')
  {
    digitalWrite(ledPin, LOW);
  }

}
