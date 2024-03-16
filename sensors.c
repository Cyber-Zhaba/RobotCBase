#include <globals.c>

float getError() {
    float l = (float) (sensorRaw[left] - BlackLeft) / (WhiteLeft - BlackLeft);
    float r = (float) (sensorRaw[right] - BlackRight) / (WhiteRight - BlackRight);
    return l - r;
}

bool LCross() {
    return sensorRaw[left] - BlackLeft < 5 &&
            sensorRaw[left] - BlackLeft > -5;
}

bool RCross() {
    return sensorRaw[right] - BlackRight < 5 &&
            sensorRaw[right] - BlackRight > -5;
}