
/*
    Name:       motorControl.ino
    Created:	8/30/2019 
    Author:     Jacob Eshleman
	For:        EECE-4263
	
	Program allows for control of H-bridge motor controller
	with two buttons. One button controls speed, while the other controls direction
	Pressing both buttons at the same time resets the motor to default direction and off
*/

#include "motorControlFunctions.h"


void setup()
{
	Serial.begin(115200); // Starts Serial port for debugging
	Serial.println("Starting..."); // Test Serial port output
	initMotorControl(); // Sets inputs and outputs 
	motorOff(); // Makes sure the motor is off
	

}


int mdir = 1; // sets initial direction
int sw1Count = 0; // Sets sw1 count

void loop()
{
	if(digitalRead(sw1) == HIGH){ // checks switch 1
		sw1Count++; // increases sw1 count
		if(sw1Count == 3){ // if the button has been pressed 3 times reset
			sw1Count = 0;
		}
		if(digitalRead(sw2) == HIGH){  // checks if button 2 is also pressed
			sw1Count = 0; // resets sw1 count
			mdir = 1; // resets direction to default
			runMotor(mdir, 0); // sets motor
		}
		delay(100); // delay for simple debounce
	}
	else if(digitalRead(sw2) == HIGH){ // checks switch 2
		mdir = changeMotorDir(mdir);  // switches motor direction
		if(digitalRead(sw1) == HIGH){ // checks if button 1 is also pressed
			sw1Count = 0;  // resets sw1count
			mdir = 1;  // resets direction
			runMotor(mdir, 0); // sets motor
		}
		delay(100); // delay for simple debounce
	}
	
	if(sw1Count == 1){  // if sw1 has been pressed once
		runMotor(mdir, 500);    // run motor at half speed
		Serial.println("low");
	}
	else if(sw1Count == 2){ // if sw2 has been pressed twice
		runMotor(mdir, 1023); // run motor at full speed
		Serial.println("high");
	}
	else{
		motorOff();  // if motor has been pressed three times (or default) 
		// turn off motor
		Serial.println("off"); 
	}
	
	delay(100); 
	
}
