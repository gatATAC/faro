#include "prj_cfg.h"
#include "prj_input.h"
#include "prj_pinout.h"
#include "FM1DRE.h"
#include "POLDRE.h"
#include <Arduino.h>
extern t_dreFM1 dreFM1;
extern t_diagFM1 diagFM1;

extern t_drePOL drePOL;
extern t_diagPOL diagPOL;

void prjInputInit(void) {
  setup_FM1upReqDI();
  setup_POLupReqDI();
}

void prjInput(void) {
  dreFM1.upReqDI = !adquirir_FM1upReqDI();
  drePOL.upReqDI = !adquirir_POLupReqDI();
}
















