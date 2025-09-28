#include "myCode.hpp"
#include "globals.hpp"
#include "helpers.hpp"

//If testing small functions, they go here
void TestCode() {
    //   N/A
}

//Initialization stuff
void codeInitialize() {
    BlockColorSensor.set_led_pwm(50);
}

void driverControl() {
    intakeControls();
}