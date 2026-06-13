#include <cmath>
#include "config.h"
#include "InverseKinimatics.h"
#include <ESP32Servo.h>

float InverseKinimatics::toDegrees(float radians){
    return radians * (180/PI);
}

void InverseKinimatics::setupServoPins(int hipServoPin, int kneeServoPin){
    hipServo.attach(hipServoPin);
    kneeServo.attach(kneeServoPin);
}

void InverseKinimatics::moveTo(float x, float y){

    float length = sqrt( (pow(x,2)) + (pow(y,2)) );

    triangleAngle = toDegrees( atan(y/x));

    //cosine law to find angle in raidans and all inside toDegrees
    hipAngle = toDegrees(acos((pow(femur, 2) + pow(length, 2) - pow(calf, 2)) / (2 * femur * length)));

    kneeAngle = toDegrees(acos((pow(femur, 2) + pow(calf, 2) - pow(length, 2)) / (2 * femur * calf)));

    finalAngle = hipAngle + triangleAngle;

    
        hipServo.write(finalAngle);   
        kneeServo.write(kneeAngle);
    
}

void InverseKinimatics::walk(){

    if(stepPhase == 0){
         k=1;
        for(i = -5; i<5; ++i){
            moveTo(i,12);
            delay(100);
        }
        stepPhase = 1;
    }

    else if( stepPhase == 1){
        k=0;
        for(i=5; i>-5; --i){
            moveTo(i, 12.0 + sin((PI *k) )); //6.0 is the base height
            k += u; //u=0.1
            delay(100);
        }
         stepPhase = 0;
    }
}




