/* 
 * File:   PwmServoCtrl.h
 * Author: txinto
 *
 * Created on 21 de marzo de 2017, 16:25
 */

#ifndef PWMSERVOCTRL_H
#define PWMSERVOCTRL_H

#include "prj_cfg.h"
    
#include <Servo.h>
#ifdef CFG_FM1_USE_SERVO
   void fm1PwmServoCtrlInit();
   void fm1PwmServoCtrl();
#endif

#ifdef CFG_POL_USE_SERVO
    void polPwmServoCtrlInit();
    void polPwmServoCtrl();
#endif

#endif /* PWMSERVOCTRL_H */

