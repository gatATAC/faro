#include "gttc_timer.h"
#include "prj_cfg.h"
#include "prj_output.h"
#include "prj_pinout.h"
#include "FM1DRE.h"
#include "POLDRE.h"
#include <Arduino.h>

extern t_dreFM1 dreFM1;
extern t_drePOL drePOL;

#ifdef CFG_FM1_USE_SERVO
#include <Servo.h>
Servo fm1Servo; // create servo object to control a servo

void fm1PwmServoCtrlInit(void) {
}

void fm1PwmServoCtrl() {
    if (dreFM1.posMode == CFG_POS_MODE_UP) {
        dreFM1.pwmServoEnable = TRUE;
        dreFM1.pwmServoSetPoint = CFG_FM1_SERVO_ACTIVE_ANGLE;
    } else {
        if (dreFM1.posMode == CFG_POS_MODE_DOWN) {
            dreFM1.pwmServoEnable = TRUE;
            dreFM1.pwmServoSetPoint = CFG_FM1_SERVO_PARKED_ANGLE;
        } else {
            dreFM1.pwmServoEnable = FALSE;
            dreFM1.pwmServoSetPoint = 0;
        }
    }
    if (dreFM1.pwmServoEnable) {
        fm1Servo.attach(CFG_FM1_SERVO_PIN); // attaches the servo on pin CFG_FM1_SERVO_PIN to the servo object
        fm1Servo.write(dreFM1.pwmServoSetPoint);
    } else {
        fm1Servo.detach(); // dettaches the servo
    }
}
#endif

#ifdef CFG_POL_USE_SERVO
#include <Servo.h>
Servo polServo; // create servo object to control a servo

void polPwmServoCtrlInit(void) {
}

void polPwmServoCtrl() {
    if (drePOL.posMode == CFG_POS_MODE_UP) {
        drePOL.pwmServoEnable = TRUE;
        drePOL.pwmServoSetPoint = CFG_POL_SERVO_ACTIVE_ANGLE;
    } else {
        if (drePOL.posMode == CFG_POS_MODE_DOWN) {
            drePOL.pwmServoEnable = TRUE;
            drePOL.pwmServoSetPoint = CFG_POL_SERVO_PARKED_ANGLE;
        } else {
            drePOL.pwmServoEnable = FALSE;
            drePOL.pwmServoSetPoint = 0;
        }
    }
    if (drePOL.pwmServoEnable) {
        polServo.attach(CFG_POL_SERVO_PIN); // attaches the servo on pin CFG_POL_SERVO_PIN  to the servo object
        polServo.write(drePOL.pwmServoSetPoint);
    } else {
        polServo.detach(); // dettaches the servo
    }
}
#endif

