/* --------- This file is an example of a main file in an Arduino project -----------------------------
 -- Additional files with gttc_ prefix are the gatArduinOSEK files, not to be modified in normal use --
 -- Additional files with prj_ prefix are the ones that must be configured for each project, they    --
 -- are part of the example.                                                                         --
 -- Project Functionality:
 -- This project uses 4 buttons and 4 leds and the serial port of the arduino.
 -- Buttons are read and the statuses are sent through the serial console.
 -- The user can send commands through the serial console to light the leds.
 -- Buttons and leds are connected to pins configured in prj_pinout.h
 -- Global variables of the project are shared through a DRE (Data Runtime Environment) defined in prj_dre.h and prj_dre.c
 -- The serial console commands are processed in prj_tty_cmds.h and prj_tty_cmds.c
 -- The serial console broadcast of the input statuses is done in prj_tty_brcast.h and prj_tty_brcast.c
 -- Please visit the wiki page for this project in http://gatatac.org/projects/gttcosarduino/wiki/GatArduinOSEKino_example_1


 ***** Project configuration include (before OSEK includes to allow OSEK configuration ******/
#include <Arduino.h>

#include "prj_cfg.h"

/***** gatArduinOSEK includes *****/
/*** Types ***/
#include <gttc_types.h>
/*** Timer ***/
//#define TIMEBASE_USE_MS 1  // <-- Normally the timer unit is the us (microseconds) but you can use this define to use ms (milliseconds)
#include <gttc_timer.h>

/* ---------------------------------------*/

/***** Project includes *****/
#include "prj_pinout.h" // <-- The pinout of the project
#include "FM1DRE.h"    // <-- The DRE of the project (global variables pools to share)
#include "POLDRE.h"    // <-- The DRE of the project (global variables pools to share)
#include "prj_input.h"  // <-- The input module reads the microcontroller pinout
#include "prj_output.h"  // <-- The output module writes the microcontroller pinout
#include "FM1lin1dFSM.h"
#include "POLlin1dFSM.h"

extern t_dreFM1 dreFM1;
extern t_drePOL drePOL;

void dreInit() {
    dreFM1.upReqAcq = FALSE;
    dreFM1.upReqDI = FALSE;
    dreFM1.posMode = CFG_POS_MODE_STOP;
    dreFM1.upButTimer = 0L;
    dreFM1.pwmServoEnable = FALSE;
    dreFM1.pwmServoSetPoint = 0L;
    dreFM1.pwmServoActive = FALSE;
    dreFM1.pwmServoPwm = 0;
    
    drePOL.upReqAcq = FALSE;
    drePOL.upReqDI = FALSE;
    drePOL.posMode = CFG_POS_MODE_STOP;
    drePOL.upButTimer = 0L;
    drePOL.pwmServoEnable = FALSE;
    drePOL.pwmServoSetPoint = 0L;
    drePOL.pwmServoActive = FALSE;
    drePOL.pwmServoPwm = 0;
}

/* ---------------------------------------*/

/***** FSM tasks *****/
void fsmTasks(void) {
    // Acquisition
    FM1UpButAcq();

    // Government
    FM1ModeSelector();

    // Acquisition
    POLUpButAcq();

    // Government
    POLModeSelector();
}

/***** Setup & Startup functions *****/

void setup() {

    ////////////// Platform init
    timerSetCycleTime(CYCLE_TIME_IN_MICROS);

    ////////////// DRE init
    dreInit();

    ////////////// Pinout init
    pinoutInit();

    ////////////// Input init
    prjInputInit();

    ////////////// FSM init
    fsmTasks();

    ////////////// Output Init
    prjOutputInit();
}

/* ---------------------------------------*/

/***** Main Loop *****/

void loop() {
    // ----------- Functionality ----------------

    ////////////// Input task 
    prjInput();

    ////////////// FSM tasks
    fsmTasks();

    // ----------- End of Cycle Synchronization ----------------
#if 1
    // Now the microcontroller will loose time until the end of cycle sincronization time expires
    boolean timSync = timerSync();
    while (timSync == false) {
        if ((CYCLE_TIME_IN_MICROS - elapsedMicros) > CYCLE_SECURITY_TIME_MICROS) {
        }
        // timerSync returns true when the end of cycle syncronization time expired.
        timSync = timerSync();
    }
#endif  

    ////////////// Output task 
    prjOutput();

}


















