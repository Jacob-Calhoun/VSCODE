#include "helpers.hpp"

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
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
        intakeMotorSetting = 1;
    }

    if (intakeMotorSetting == 1) {
        BottomBack.brake();
        BottomOut.move(motorVelocity(60));
        TopOut.move(motorVelocity(100));
        TopBack.move(motorVelocity(60));
        LeftMandible.move(motorVelocity(75));
        RightMandible.move(motorVelocity(-75));
        //True means Red = bad, False means Blue = bad.
        if (true) {
            //Red = bad
            if (340 <= BlockColorSensor.get_hue() && BlockColorSensor.get_hue() <= 360) {
                TopBack.move(motorVelocity(-60));
                pros::delay(500);
                TopBack.move(motorVelocity(60));
            }
        } else {
            //Blue = bad
            if (210 <= BlockColorSensor.get_hue() && BlockColorSensor.get_hue() <= 220) {
                TopBack.move(motorVelocity(-60));
                pros::delay(500);
                TopBack.move(motorVelocity(60));
            }
        }
    }

    //Bottom block export
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        intakeMotorSetting = 2;
    }

    if (intakeMotorSetting == 2) {
        TopOut.brake();
        TopBack.brake();
        BottomOut.move(motorVelocity(-75));
        BottomBack.move(motorVelocity(-75));
        LeftMandible.move(motorVelocity(-75));
        RightMandible.move(motorVelocity(75));
    }

    //Middle block export
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        intakeMotorSetting = 3;
    }

    if (intakeMotorSetting == 3 ) {
        TopOut.brake();
        LeftMandible.brake();
        RightMandible.brake();
        BottomOut.move(motorVelocity(85));
        BottomBack.move(motorVelocity(-75));
        TopBack.move(motorVelocity(-100));
    }

    //Top block export
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        intakeMotorSetting = 4;
    }

    if (intakeMotorSetting == 4) {
        LeftMandible.brake();
        RightMandible.brake();
        BottomOut.move(motorVelocity(75));
        TopOut.move(motorVelocity(-100));
        BottomBack.move(motorVelocity(-75));
        TopBack.move(motorVelocity(80));
    }
}