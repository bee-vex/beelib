#include "main.h"

#include "bee/chassis/chassis.hpp"
#include "bee/chassis/chassisController.hpp"
#include "bee/control/pid.hpp"
#include "bee/math/util.hpp"
#include "bee/odom/twoEncoderOdom.hpp"
#include "bee/settler/bound.hpp"
#include "bee/tracker/motorTracker.hpp"
#include "bee/tracker/rotTracker.hpp"
#include "bee/tracker/inertial.hpp"

#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "pros/motors.hpp"
#include "pros/rotation.hpp"

#include "autons.hpp"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Devices
auto leftMotorGroup = std::make_shared<pros::MotorGroup>(std::initializer_list<pros::Motor> {
    pros::Motor(-8, pros::E_MOTOR_GEAR_BLUE), 
    pros::Motor(-2, pros::E_MOTOR_GEAR_BLUE), 
    pros::Motor(3, pros::E_MOTOR_GEAR_BLUE)});

auto rightMotorGroup = std::make_shared<pros::MotorGroup>(std::initializer_list<pros::Motor> {
    pros::Motor(4, pros::E_MOTOR_GEAR_BLUE), 
    pros::Motor(5, pros::E_MOTOR_GEAR_BLUE), 
    pros::Motor(-6, pros::E_MOTOR_GEAR_BLUE)});

bee::Chassis chassis(leftMotorGroup, rightMotorGroup);

auto horzRotation = std::make_shared<pros::Rotation>(21, false);
auto inertial = std::make_shared<pros::IMU>(1);

// Trackers
auto leftTracker = std::make_shared<bee::MotorGroupTracker>(-11.725 / 2, leftMotorGroup, 2.75, 400);
auto horzTracker = std::make_shared<bee::RotTracker>(-8.476, horzRotation, 2.75);
auto headingTracker = std::make_shared<bee::Inertial>(inertial);

auto odom = std::make_shared<bee::TwoEncoderOdom>(leftTracker, horzTracker, headingTracker);

bee::ChassisMotionAlgs Chassis(bee::Chassis, bee::TwoEncoderOdom);

void settlerDemo() {
    auto pid = std::make_shared<bee::PID>(0,0,0,0);
    auto boundSettler = bee::Bound<bee::PID>(pid, 0, 0);
}

// Autonomous Selector 
int autonState = 0; 
pros::ADIDigitalIn limitSwitch('F');

void autonSelect(){
    while (true) {
        pros::delay(20);
        if(limitSwitch.get_new_press()){
            autonState ++;
            if (autonState>4){
                autonState = 0;
            }
        }
        switch(autonState){
            case 0: 
                pros::lcd::set_text(2, "QualClose");
                break;
            case 1: 
                pros::lcd::set_text(2, "QualFar");
                break;
            case 2: 
                pros::lcd::set_text(2, "ElimsClose");
                break;
            case 3: 
                pros::lcd::set_text(2, "ElimsFar");
                break;
            case 4: 
                pros::lcd::set_text(2, "Skills");
                break;
            default: 
                pros::lcd::set_text(2, "QualClose");
                break;      
        }
    }

}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    pros::lcd::initialize();

    leftTracker->tare();
    odom->calibrate();

    pros::Task odomTask([=]() {
        while (true) {
            odom->update();

            bee::Pose pose = odom->getPose();
            pros::lcd::print(1, "x: %f", pose.x);
            pros::lcd::print(2, "y: %f", pose.y);
            pros::lcd::print(3, "theta: %f", bee::radToDeg(pose.theta));

            pros::delay(10);
        }
    });
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    switch(autonState){
        case 0: 
            qualClose(); 
            break;
        case 1: 
            qualFar(); 
            break;
        case 2: 
            elimsClose(); 
            break;
        case 3: 
            elimsFar(); 
            break;
        case 4: 
            skills(); 
            break;
        default: 
            break; 
    }
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
    while (true) {
        chassis.drive_curve();
        // chassis.arcade(controller.get_analog(ANALOG_RIGHT_X),
        // controller.get_analog(ANALOG_LEFT_Y));
        pros::delay(10);
    }
}
