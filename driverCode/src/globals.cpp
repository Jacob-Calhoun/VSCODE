#include "globals.hpp"
#include "pros/adi.hpp"

//Motors
    //Intake/Outake motors
        pros::Motor LeftMandible(2, pros::v5::MotorGears::green); //5.5, needs limit
        pros::Motor RightMandible(9, pros::v5::MotorGears::green); //5.5, needs limit
        pros::Motor TopBack(3, pros::v5::MotorGears::blue);
        pros::Motor TopOut(8, pros::v5::MotorGears::green); //5.5, needs limit
        pros::Motor BottomBack(21, pros::v5::MotorGears::green); //5.5, needs limit
        pros::Motor BottomOut(10, pros::v5::MotorGears::blue);
    //Drivetrain motors
    
//Pneumatics
    //"Mandibles"
        pros::adi::Pneumatics LeftMandiblePnuematic('A', false);
        pros::adi::Pneumatics RightMandiblePnuematic('B', false);

//Sensors
    //Color sensors
        pros::Optical BlockColorSensor(1);