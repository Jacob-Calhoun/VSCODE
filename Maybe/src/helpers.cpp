#include "helpers.hpp"
#include "pros/misc.h"

int intakeMotorSetting = 0;

//Takes a velocity percentage and outputs in the voltage format
double motorVelocity(double givenVelocity) {
    if (abs((givenVelocity * 127) / 100) < 127) {
        return ((givenVelocity * 127) / 100);
    } else {
        if (givenVelocity > 0) {
            return (127);
        } else {
            return (-127);
        }
    }
}

//Controls the individual intake functions and what they do
void intakeControls() {
    //Intakes blocks
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        intakeMotorSetting = 1;
    }

    if (intakeMotorSetting == 1) {
        BottomBack.brake();
        BottomOut.move(motorVelocity(60));
        TopOut.move(motorVelocity(100));
        TopBack.move(motorVelocity(60));
        LeftMandible.move(motorVelocity(60));
        RightMandible.move(motorVelocity(-60));
        colorSorting(1);
    }

    //Bottom block export
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        intakeMotorSetting = 2;
    }

    if (intakeMotorSetting == 2) {
        TopOut.brake();
        TopBack.brake();
        BottomOut.move(motorVelocity(-60));
        BottomBack.move(motorVelocity(-100));
        LeftMandible.move(motorVelocity(-60));
        RightMandible.move(motorVelocity(60));
    }

    //Middle block export
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        intakeMotorSetting = 3;
    }

    if (intakeMotorSetting == 3 ) {
        TopOut.brake();
        LeftMandible.brake();
        RightMandible.brake();
        BottomOut.move(motorVelocity(60));
        BottomBack.move(motorVelocity(-100));
        TopBack.move(motorVelocity(-60));
    }

    //Top block export
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
        intakeMotorSetting = 4;
    }

    if (intakeMotorSetting == 4) {
        LeftMandible.brake();
        RightMandible.brake();
        BottomOut.move(motorVelocity(60));
        TopOut.move(motorVelocity(-100));
        BottomBack.move(motorVelocity(-100));
        TopBack.move(motorVelocity(60));
    }

    //Stops all intakes
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
        intakeMotorSetting = 5;
    }

    if (intakeMotorSetting == 5) {
        LeftMandible.brake();
        RightMandible.brake();
        BottomOut.brake();
        TopOut.brake();
        BottomBack.brake();
        TopBack.brake();
    }
}

//Controls the color sorting method of the intake
void colorSorting(int goodColor) {
    if (goodColor == 0) {
        //Red = good
        if (BlockColorSensor.get_hue() >= 200 && BlockColorSensor.get_hue() <= 240) {
            pros::delay(200);
            TopBack.move(motorVelocity(-60));
            pros::delay(200);
            TopBack.move(motorVelocity(60));
        }
    } if (goodColor == 1) {
        //Blue = good
        if (BlockColorSensor.get_hue() >= 340 && BlockColorSensor.get_hue() <= 360) {
            pros::delay(200);
            TopBack.move(motorVelocity(-60));
            pros::delay(200);
            TopBack.move(motorVelocity(60));
        }
    }
}

//Controls the mandibles and their pneumatics
void mandibleControls() {
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
        RightMandiblePnuematic.retract();
        LeftMandiblePnuematic.retract();
    }

    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
        RightMandiblePnuematic.extend();
        LeftMandiblePnuematic.extend();
    }
}