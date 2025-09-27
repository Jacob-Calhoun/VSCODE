#include "helpers.hpp"

int intakeMotorSetting = 0;

void intakeControls() {
    //Intakes blocks
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
        intakeMotorSetting = 1;
    }

    if (intakeMotorSetting == 1) {
        BottomBack.brake();
        BottomOut.move((85 * 127) / 100);
        TopOut.move((100 * 127) / 100);
        TopBack.move((80 * 127) / 100);
        LeftMandible.move((75 * 127) / 100);
        RightMandible.move((-75 * 127) / 100);
    }

    //Bottom block export
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        intakeMotorSetting = 2;
    }

    if (intakeMotorSetting == 2) {
        TopOut.brake();
        TopBack.brake();
        BottomOut.move((-75 * 127) / 100);
        BottomBack.move((-75 * 127) / 100);
        LeftMandible.move((-75 * 127) / 100);
        RightMandible.move((75 * 127) / 100);
    }

    //Middle block export
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        intakeMotorSetting = 3;
    }

    if (intakeMotorSetting == 3 ) {
        TopOut.brake();
        LeftMandible.brake();
        RightMandible.brake();
        BottomOut.move((85 * 127) / 100);
        BottomBack.move((-75 * 127) / 100);
        TopBack.move((-100 * 127) / 100);
    }

    //Top block export
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        intakeMotorSetting = 4;
    }

    if (intakeMotorSetting == 4) {
        LeftMandible.brake();
        RightMandible.brake();
        BottomOut.move((75 * 127) / 100);
        TopOut.move((-100 * 127) / 100);
        BottomBack.move((-75 * 127) / 100);
        TopBack.move((80 * 127) / 100);
    }
}