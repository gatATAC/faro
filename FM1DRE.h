#ifndef _FM1_DRE_H
#define _FM1_DRE_H

#include "ProjectTypes.h"
#include "ProjectFlows.h"

typedef struct {
    // Button -- Does not need declaration upReq;
    // Button -- Does not need declaration downReq;
    // Position -- Does not need declaration loadPos;
    t_upreqacq upReqAcq;
    BOOL upReqDI;
    BOOL posAchieved;
    t_posmode posMode;
    t_timer upButTimer;
    t_pwmservoenable pwmServoEnable;
    t_pwmservosetpoint pwmServoSetPoint;
    BOOL pwmServoActive;
    BOOL pwmServoPwm;
 } t_dreFM1;

typedef struct {
    // (null) No diag variables for upReq
    // (null) No diag variables for downReq
    // (null) No diag variables for loadPos
    BOOL enable_upReqAcq;
    t_upreqacq upReqAcq;
    BOOL enable_upReqDI;
    BOOL upReqDI;
    BOOL enable_posMode;
    t_posmode posMode;
    BOOL enable_upButTimer;
    t_timer upButTimer;
    BOOL enable_pwmServoEnable;
    t_pwmservoenable pwmServoEnable;
    BOOL enable_pwmServoSetPoint;
    t_pwmservosetpoint pwmServoSetPoint;
    BOOL enable_pwmServoActive;
    BOOL pwmServoActive;
    BOOL enable_pwmServoPwm;
    BOOL pwmServoPwm;
} t_diagFM1;

// Initialization functions



// upReqDI flow acquisition
void setup_FM1upReqDI(void);
// upReqDI flow synthesis
// (output disabled for DI_pu type);
// upReqDI flow acquisition
BOOL adquirir_FM1upReqDI(void);
// upReqDI flow synthesis
// (output disabled for DI_pu type);

#endif /* _DRE_H */
