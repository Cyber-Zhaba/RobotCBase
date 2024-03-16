void grab(short int d) {
    setMotorSpeed(mid, 80 * d);
    sleep(200);
    setMotorSpeed(mid, 1 * d);
}
