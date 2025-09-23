#include "globals.hpp"

//Motors
    //Intake/Outake motors
        LeftMandible(2, pros::v5::MotorGears::green); //5.5, needs limit
        RightMandible(9, pros::v5::MotorGears::green); //5.5, needs limit
        TopBack(3, pros::v5::MotorGears::blue);
        TopOut(8, pros::v5::MotorGears::green); //5.5, needs limit
        BottomBack(21, pros::v5::MotorGears::green); //5.5, needs limit
        BottomOut(10, pros::v5::MotorGears::blue);
    //Drivetrain motors