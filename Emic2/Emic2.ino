
/*
  Edited Example Code from - Author: Joe Grand [www.grandideastudio.com]                                      
  https://www.parallax.com/sites/default/files/downloads/30016-Emic-2-Text-To-Speech-Documentation-v1.2.pdf // learned to use EMIC from this website
*/

#include <SoftwareSerial.h>
#include "EMIC2.h"
EMIC2 emic;

#define rxPin   10  // Serial input (connects to Emic 2's SOUT pin)
#define txPin   11  // Serial output (connects to Emic 2's SIN pin)
#define ledPin  13  // Most Arduino boards have an on-board LED on this pin
int sensorPin = 0; //for temp
int switchPin = 12; //get input of switch
int buttonPin = 8; //get input of button

// set up a new serial port
SoftwareSerial emicSerial =  SoftwareSerial(rxPin, txPin); //to connect emic2 and adafruit

void setup()  // Set up code called once on start-up

{
  Serial.begin(9600);
  pinMode(switchPin, INPUT);
  pinMode(buttonPin, INPUT);

  emic.begin(rxPin, txPin);
  emic.setVoice(1);  //0-8 ..
}

void loop()  // Main code, to run repeatedly
{
  float temperatureF, temperatureC; //define variables
  emic.setVolume(10);  //set volume. max=18

  int buttonPress = digitalRead(buttonPin); //read when button is pressed
  Serial.print("buttonPress"); Serial.println(buttonPress);
  
  if (buttonPress == 1){  //check if button is pressed
    int reading = analogRead(sensorPin); //get temperature data
    float voltage = reading * 5.0;
    voltage /= 1024.0; 
    temperatureC = (voltage - 0.5) * 100 ;  //temp in celsius
    temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;  //temp in fahrenheit
      
    int celfah = (digitalRead(switchPin));  //read the data from switch
    if (celfah ==1){ //1 reads fahrenheit
    Serial.print(celfah); Serial.println("fah");
    Serial.print(temperatureF); Serial.println("degrees F");  //print in serial monitor
    
    emic.speak("The current temperature is ");  //speak
    emic.speak(temperatureF);   //speak
    emic.speak("degrees fahrenheit.");  //speak
    emic.speak("Have a good day");

    return;
    }
  else if (celfah ==0){  //0 speaks celsius
    Serial.print(celfah); Serial.println("cel"); 
    emic.speak("The current temperature is"); //read
    emic.speak(temperatureC); //read
    emic.speak("degrees celsius"); //read
    emic.speak("Have a good day");
    return; 
    }
  }
  else
  {
    emic.speak("Hi, I hope you are doing well.");
    emic.speak("Please press the button to find out the current temperature; And use the switch to swtich between Celsius and fahrenheit");
  }

}
