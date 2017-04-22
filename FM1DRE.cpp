#include "FM1DRE.h"

// --- DRE data structure declaration ---
t_dreFM1 dreFM1;
t_diagFM1 diagFM1;

// --- DRE flow initialization functions ---

// upReqDI flow acquisition

void setup_FM1upReqDI(void) {
    pinMode(PORT_FM1upReqDI, INPUT_PULLUP);
};
// upReqDI flow synthesis
// (output disabled for DI_pu type)

// upReqDI flow acquisition

BOOL adquirir_FM1upReqDI(void) {
#ifdef _DIAG_ACTIVE 
    if (diagFM1.enable_upReqDI == TRUE) {
        return diagFM1.upReqDI;
    } else {
#endif 
        return digitalRead(PORT_FM1upReqDI);
#ifdef _DIAG_ACTIVE 
    }
#endif 
};
// upReqDI flow synthesis
// (output disabled for DI_pu type)


