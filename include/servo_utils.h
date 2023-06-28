#ifndef SERVO_UTILS_H
#define SERVO_UTILS_H

#include <Servo.h>

// Pin numbers for the servo motors
#define PAN_SERVO_PIN 18
#define TILT_SERVO_PIN 33

// servo object for pan and tilt movements
Servo panServo;
Servo tiltServo;

// Function to initialize servo motors
void initializeServos()
{
    panServo.attach(PAN_SERVO_PIN);
    tiltServo.attach(TILT_SERVO_PIN);
}

// Function to set the servo positions
void setServoPositions(int panAngle, int tiltAngle)
{
    panServo.write(panAngle);
    tiltServo.write(tiltAngle);
}

#endif