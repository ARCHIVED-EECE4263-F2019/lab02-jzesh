/*
 * motorControlFunctions.h
 *
 * Created: 9/3/2019 
 *  Author: Jacob Eshleman
 *
 *	File provides the motor and button functions for the nodemcu motor control program
 *
 */ 

// defines pin numbers 
#define motorCtrl1 12
#define motorCtrl2 14
#define motorEn    13
#define sw1        16
#define sw2         5

// function sets pin modes and enables controller
void initMotorControl(){
	pinMode(motorCtrl1, OUTPUT);
	pinMode(motorCtrl2, OUTPUT);
	pinMode(motorEn, OUTPUT);
	pinMode(sw1, INPUT);
	pinMode(sw2, INPUT);
	
	digitalWrite(motorEn, HIGH);
}
// function runs motor give direction and "speed"
void runMotor(int dir, int speed){
	if(dir == 0){
		analogWrite(motorCtrl1, speed);
		digitalWrite(motorCtrl2, LOW);
	}
	else{
		analogWrite(motorCtrl2, speed);
		digitalWrite(motorCtrl1, LOW);
	}
}
// turns off motor
void motorOff(){
	digitalWrite(motorCtrl1, LOW);
	digitalWrite(motorCtrl2, LOW);
}
// switches direction variable
int changeMotorDir(int motorDir){
	if(motorDir == 0){
		return 1;
	}
	else{
		return 0;
	}
}





