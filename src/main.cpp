/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LadoDerecho          motor_group   1, 2            
// LadoIzquierdo        motor_group   11, 12          
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
int DireccionRecogedor = 0;

void UsarRecogedor()
{
Recogedor.setVelocity(100, pct)

}

void usercontrol(void) {
  //User declared variables
  int deadband = 5;
  int dir = 0;
  int VelocidadMotorIzquierdo = 0;
  int VelocidadMotorDerecho = 0;
  int standadSpd=80;
  

  // User control code here, inside the loop
  while (true) {
    //boton de Recogedor
    //---Control de Recogedor---
    Recogedor.setVelocity(standadSpd, percent);
    if (Controller1.ButtonL1.pressing()
    {
        while(Controller1.ButtonL1.pressing())
        {task::sleep(150);}
        DireccionRecogedor=1;
        if(DireccionRecogedor==0)
        {DireccionRecogedor=1}
        else if(DireccionRecogedor==1)
    }
    else if (Controller1.ButtonL2.pressing()){
        Recogedor.spin(reverse);
    }
    else {
      Recogedor.stop();
    }
    // Set the direcction of the arcade stick
    if(Controller1.ButtonA.pressing())
    {
      while(Controller1.ButtonA.pressing())
      {
          task::sleep(150);
      }
      dir++;
    }
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    
        if(dir==1)
    {
    // Get the velocity percentage of the left motor. (Axis3 + Axis4)
    VelocidadMotorIzquierdo =
        Controller1.Axis3.position() + Controller1.Axis4.position();
    // Get the velocity percentage of the right motor. (Axis3 - Axis4)
    VelocidadMotorDerecho =
        Controller1.Axis3.position() - Controller1.Axis4.position();   
    //start the motor groups
    LadoDerecho.spin(forward);
    LadoIzquierdo.spin(forward);
    }
    else if(dir==0)
    {
    // Get the velocity percentage of the left motor. (Axis3 + Axis4)
    VelocidadMotorIzquierdo =
       - Controller1.Axis3.position() + Controller1.Axis4.position();
    // Get the velocity percentage of the right motor. (Axis3 - Axis4)
    VelocidadMotorDerecho =
        - Controller1.Axis3.position() - Controller1.Axis4.position();   
      //start the motor groups
    LadoDerecho.spin(forward);
    LadoIzquierdo.spin(forward); 
    }
    else if (dir==2)
    {
        dir=0;
    }
 

    // Set the speed of the left motor. If the value is less than the deadband,
    // set it to zero.

    //print the current speed of the 
    Controller1.Screen.setCursor(1,2);
    Controller1.Screen.print("%d",VelocidadMotorIzquierdo);
    
    Controller1.Screen.setCursor(1,3);
    Controller1.Screen.print("%d",VelocidadMotorIzquierdo);

    if (abs(VelocidadMotorIzquierdo) < deadband) {
      // Set the speed to zero.
      LadoIzquierdo.setVelocity(0, percent);
    } else {
      // Set the speed to VelocidadMotorIzquierdo
      LadoIzquierdo.setVelocity(VelocidadMotorIzquierdo, percent);
    }

    // Set the speed of the right motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(VelocidadMotorDerecho) < deadband) {
      // Set the speed to zero
      LadoDerecho.setVelocity(0, percent);
    } else {
      // Set the speed to VelocidadMotorDerecho
      LadoDerecho.setVelocity(VelocidadMotorDerecho, percent);
    }


    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(25, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
