#include "main.h"
#include "pros/adi.hpp"
#include "pros/vision.h"

//Motors
    //Intake/Outake motors
        extern pros::Motor LeftMandible;
        extern pros::Motor RightMandible; 
        extern pros::Motor TopBack;
        extern pros::Motor TopOut;
        extern pros::Motor BottomBack;
        extern pros::Motor BottomOut;
    //Drivetrain motors
        extern pros::Motor LeftFront;
        extern pros::Motor LeftBack;
        extern pros::Motor RightFront;
        extern pros::Motor RightBack;
        extern pros::MotorGroup DrivetrainLeft;
        extern pros::MotorGroup DrivetrainRight;

//Pneumatics
    //"Mandibles"
        extern pros::adi::Pneumatics LeftMandiblePnuematic;
        extern pros::adi::Pneumatics RightMandiblePnuematic;

//Sensors
    //Color sensors
        extern pros::Optical BlockColorSensor;