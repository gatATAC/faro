#include "gttc_timer.h"
#include "prj_cfg.h"
#include "prj_output.h"
#include "prj_pinout.h"
#include "FM1DRE.h"
#include "POLDRE.h"
#include "PwmServoCtrl.h"
#include <Arduino.h>

extern t_dreFM1 dreFM1;
extern t_drePOL drePOL;

void prjOutputInit(void) {

#ifdef CFG_FM1_USE_SERVO
    fm1PwmServoCtrlInit();
#endif
#ifdef CFG_POL_USE_SERVO
    polPwmServoCtrlInit();
#endif
}

void prjOutput(void) {
    
#ifdef CFG_FM1_USE_SERVO
    fm1PwmServoCtrl();
#endif
#ifdef CFG_POL_USE_SERVO
    polPwmServoCtrl();
#endif
}
