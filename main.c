#pragma config(Sensor, S2, left, sensorEV3_Color)
#pragma config(Sensor, S3, right, sensorEV3_Color)
#pragma config(Sensor, S4, dist, sensorEV3_Ultrasonic)
#pragma config(Motor, motorA, mid, tmotorEV3_Large, openLoop, encoder)
#pragma config(Motor, motorB, right, tmotorEV3_Large, openLoop, encoder)
#pragma config(Motor, motorC, left, tmotorEV3_Large, openLoop, encoder)
#pragma config(Motor, motorD, , tmotorEV3_Large, openLoop)

#include <grab.c>
#include <movement.c>

task main() {
    NBCross(1, 40, true);
    TLeft(false);
    NBCross(1, 40, true);
}
