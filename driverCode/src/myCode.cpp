#include "myCode.hpp"
#include "EZ-Template/util.hpp"
#include "globals.hpp"
#include "helpers.hpp"
#include "pros/misc.h"
#include "pros/rtos.h"

//If testing small functions, they go here
void testCode() {
    //   N/A
}

//Initialization stuff
void codeInitialize() {
    BlockColorSensor.set_led_pwm(0);
}

void driverControl() {
    intakeControls();
    mandibleControls();
}