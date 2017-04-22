#include "POLDRE.h"

// --- DRE data structure declaration ---
t_drePOL drePOL;
t_diagPOL diagPOL;

// --- DRE flow initialization functions ---

// upReqDI flow acquisition

void setup_POLupReqDI(void) {
    pinMode(PORT_POLupReqDI, INPUT_PULLUP);
};
// upReqDI flow synthesis
// (output disabled for DI_pu type)


// upReqDI flow acquisition

BOOL adquirir_POLupReqDI(void) {
#ifdef _DIAG_ACTIVE 
    if (diagPOL.enable_upReqDI == TRUE) {
        return diagPOL.upReqDI;
    } else {
#endif 
        return digitalRead(PORT_POLupReqDI);
#ifdef _DIAG_ACTIVE 
    }
#endif 
};
// upReqDI flow synthesis
// (output disabled for DI_pu type)

