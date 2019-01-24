
#define CUSTOM_SETTINGS
#define INCLUDE_TEXT_TO_SPEECH_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

float sensorValue = 0;
char charValue[4];


int sensorPin = A0;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 OneSheeld.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(sensorPin);
  float voltage = reading * 5;
  voltage /= 1024.0;
  Serial.print(voltage); Serial.println(" Volts");

  //temperature
  float temperatureC = (voltage - 0.5) * 100;
  Serial.print(temperatureC);
  Serial.println( " Degrees Celsius"); 

  dtostrf(temperatureC,4,1,charValue);
  TextToSpeech.say("Temprature equals");
  delay(1400);
  TextToSpeech.say(charValue);
  delay(1300);
  TextToSpeech.say("Celsius");
  delay(3000);

}
