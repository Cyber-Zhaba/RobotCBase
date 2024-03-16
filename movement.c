#include <globals.c>
#include <sensors.c>

void line(short int speed = 40) {
    float error = getError();

    float drive = (error * kp) + ((error - lastError) * kd);
    lastError = error;

    drive *= speed;

    setMotorSpeed(left, -drive + speed);
    setMotorSpeed(right, drive + speed);
}

void NBCross(short int n, short int speed, bool onCross) {
    for (int i = 0; i < n; i++) {
        while (!LCross() || !RCross()) {
            line(speed);
        }
        resetMotorEncoder(left);
        sleep(100);
    }
    if (onCross) {
        while (getMotorEncoder(left) < ToCross) {}
    }
}

void NLCross(short int n, short int speed, bool onCross) {
    for (int i = 0; i < n; i++) {
        while (!LCross()) {
            line(speed);
        }
        resetMotorEncoder(left);
        sleep(100);
    }
    if (onCross) {
        while (getMotorEncoder(left) < ToCross) {}
    }
}

void NRCross(short int n, short int speed, bool onCross) {
    for (int i = 0; i < n; i++) {
        while (!RCross()) {
            line(speed);
        }
        resetMotorEncoder(left);
        sleep(100);
    }
    if (onCross) {
        while (getMotorEncoder(left) < ToCross) {}
    }
}

void TLeft(bool stop) {
    setMotorSpeed(left, -35);
    setMotorSpeed(right, +35);

    resetMotorEncoder(right);
    while (getMotorEncoder(right) < 150) {}
    while (!RCross()) {}

    sleep(75);

    if (stop) {
        setMotorSpeed(left, 0)
        setMotorSpeed(right, 0);
    }
}

void TRight(bool stop) {
    setMotorSpeed(left, +35);
    setMotorSpeed(right, -35);

    resetMotorEncoder(left);
    while (getMotorEncoder(left) < 150) {}
    while (!LCross()) {}

    sleep(75);

    if (stop) {
        setMotorSpeed(left, 0)
        setMotorSpeed(right, 0);
    }
}

void TAround() {
    setMotorSpeed(left, +35);
    setMotorSpeed(right, -35);

    resetMotorEncoder(left);
    while (getMotorEncoder(left) < 300) {}
    while (!LCross()) {}

    sleep(75);

    setMotorSpeed(left, 0)
    setMotorSpeed(right, 0);
}
