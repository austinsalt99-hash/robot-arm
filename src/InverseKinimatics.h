#pragma once
#include <ESP32Servo.h>
class InverseKinimatics {

public:
    void moveTo(float x, float y);

    float toDegrees(float radians);

    void setupServoPins(int hipPins, int kneePins);

    void walk();

    float x;
    float y;

private:

    float hipAngle;
    float kneeAngle;
    
    int i;
    float k;
    int stepPhase = 0;

    // 1 devided by steps
    const double u = 0.1;

    Servo hipServo;
    Servo kneeServo;



};