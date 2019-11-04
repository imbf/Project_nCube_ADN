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
	Serial.println("����� �ʱ⼳��(���)");
	servo.attach(SERVO_LOCK_PIN);
	servo.write(90);
	_angle = 90;
}

void ServoRotation::setServoRotation(String angle)
{

	Serial.print("����� ȸ�� ���� : ");
	Serial.print(angle);
	servo.write(angle.toInt());
	_angle = angle.toInt();

}

void ServoRotation::temporaryOpenDoor()
{
	servo.write(0);
	Serial.println("���� ���Ƚ��ϴ�.");
	Serial.println("3���Ŀ� ���� �ڵ����� ���ϴ�.");
	delay(5000);
	servo.write(90);
	Serial.println("���� �����ϴ�.");
	_angle = 90;
}

void ServoRotation::openDoor() 
{
	servo.write(0);
	Serial.println("���� ���Ƚ��ϴ�.");
	_angle = 0;
}

void ServoRotation::lockDoor() 
{
	servo.write(90);
	Serial.println("���� �����ϴ�.");
	_angle = 90; 
}
