



//news api key = 0f73238db5714521a33002062535816b

/*
  Edited Example Code from - Author: Joe Grand [www.grandideastudio.com]                                      
  https://www.parallax.com/sites/default/files/downloads/30016-Emic-2-Text-To-Speech-Documentation-v1.2.pdf // learned to use EMIC from this website
  https://www.arduino.cc/en/Tutorial/HttpClient  // learned about HTTP Client 
*/

#include <SoftwareSerial.h>
#include "EMIC2.h"
EMIC2 emic;

#define rxPin   10  // Serial input (connects to Emic 2's SOUT pin)
#define txPin   11  // Serial output (connects to Emic 2's SIN pin)
#define ledPin  13  // Most Arduino boards have an on-board LED on this pin
int sensorPin = 0; //for temp

// set up a new serial port
SoftwareSerial emicSerial =  SoftwareSerial(rxPin, txPin);

void setup()  // Set up code called once on start-up
{

    emic.begin(rxPin, txPin);
    emic.setVoice(1);  //0-8 6..

      //temp
   int reading = analogRead(sensorPin);  
   float voltage = reading * 5.0;
   voltage /= 1024.0; 
   float temperatureC = (voltage - 0.5) * 100 ;
   float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
   Serial.print(temperatureF); Serial.println("degrees F");
   
   emic.setVolume(18);

   emic.speak("Hi, I hope you are doing well.");
   emic.speak("The current temperature is");
   emic.speak(temperatureF);
   emic.speak("degrees fahrenheit");
   

}

void loop()  // Main code, to run repeatedly
{


}
