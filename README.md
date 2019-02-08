# P00: Project 1

**Author(s)**: Ram Bastola

**Google Document**: https://docs.google.com/document/d/1Nw7GXKbOS2rPyNvu1tcNE7gIDl1i7EjLSspzgxwOBHc/edit?usp=sharing

---
## Purpose
- The first thing I do when I wake up is check the temperature for the day. So, I wanted to build something that could easily output the current temperature measured in both celsius and Fahrenheit. And instead of looking it up on a phone, I wanted a voice output, and a easy way to change the channels of listening the temperature measured in different units.

## Initial Design Plan

- Physical Components:
    - TMP36 - Temperature sensor.
    - Emic2 - convert texts to speech
    - speaker - output the voice
    - Button - Part of user input that lets the system know user wants to know the temperature
    - Switch - switch between Celsius and Fahrenheit
    
- Code:
    - SoftwareSerial.h - library that connnect Arduino and Emic2
    - Emic2.h - Library that handles the voice commands
 
## Files
- Emic2 - Folder that contain our main file for code.
- Imags - Contain images of hardware componets setup and screenshot of Serial Monitor.
- License file - a copyright protection file.

## Summary
Initially Nathan and I started working on this project with a different ideas. However, Nathan had to drop the class for some weird reason(s). So, I started working on it by myself. I wanted to develop a system that can easily give voice output about the information I want to hear in my everyday basis. For example, News, weather - in celsius and Fahrenheit, etc. I spend more than 3 hours trying to find a way to make RESTFul API work in order to get news data from online source. However, later I found out that additional components are needed to connect to internet to call the get method. Even though RESTfUL API didn't work, I learned how to make HTTP requests. Then I narrowed down my idea to only calculating temperature and adding buttons to easily hear temperature in different unints. I spent around 13 hours for this project and most of the time was spent while researching and doing things that I didn't end up using. For example, HTTP request. 


## Instructions

-The button, switch, and speaker could easily come off. So make sure they are fully connected to circuit board.
- Make sure no wires are left out. Follwing the pins defined in the code will help.
- It just need to be connected to a power source. Then It will start speaking/guiding.
- Press the button once first sentence is spken out.
- Then switch the SWITCH to change between Fahrenheit and Celsius to hear the temperature.

## Errors and Constraints
- The button press is read only if pressed right after voice output completes.
## Reflection
- This has been a solo ride but a great learning experience. I have learned so much in this project and i enjoyed every single moment. It was exciting as well. I feel ready for bigger projects now and I intend to build something new with new hardware components. I would rate 10/10 for this learning experience.


## References


https://learn.adafruit.com/tmp36-temperature-sensor/using-a-temp-sensor - example code for calculating temperature.

https://www.parallax.com/sites/default/files/downloads/30016-Emic-2-Text-To-Speech-Documentation-v1.2.pdf - Read about EMIC2 and understand how it works, as well as how to set it up.

http://blog.codebender.cc/2014/02/20/emic2/   - example code of EMIC2 

https://steps2make.com/2017/09/text-speech-arduino/     - tried this library to convert text to speech but it didn't work.

https://1sheeld.com/shields/text-to-speech-shield/ --- by looking at example here, we intended to try this. But went with EMIC2.


## Final Self-Evaluations


### Ideation, Brainstorming, Design:

Ram Bastola: 10

### Code creation: 

Ram Bastola: 10

### Documentation creation:

Ram Bastola: 10

### Teamwork & Participation:

Ram Bastola: 10


---
