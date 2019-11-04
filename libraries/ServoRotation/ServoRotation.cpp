/*
ServoRotation.h - Library for controlling Servo of Rotation(Angle)
Created by JongJin Bae in CNU Korea, July 14, 2019.
*/

#include "ServoRotation.h"

Servo servo;

ServoRotation::ServoRotation()
{

}

void ServoRotation::init() {

	Serial.begin(SERIAL_NUMBER);
	Serial.println("도어락 초기설정(잠금)");
	servo.attach(SERVO_LOCK_PIN);
	servo.write(90);
	_angle = 90;
}

void ServoRotation::setServoRotation(String angle)
{

	Serial.print("도어락 회전 각도 : ");
	Serial.print(angle);
	servo.write(angle.toInt());
	_angle = angle.toInt();

}

void ServoRotation::temporaryOpenDoor()
{
	servo.write(0);
	Serial.println("문이 열렸습니다.");
	Serial.println("3초후에 문이 자동으로 잠깁니다.");
	delay(5000);
	servo.write(90);
	Serial.println("문이 잠겼습니다.");
	_angle = 90;
}

void ServoRotation::openDoor() 
{
	servo.write(0);
	Serial.println("문이 열렸습니다.");
	_angle = 0;
}

void ServoRotation::lockDoor() 
{
	servo.write(90);
	Serial.println("문이 잠겼습니다.");
	_angle = 90; 
}
