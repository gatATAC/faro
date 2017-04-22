/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include "POLlin1dFSM.h"
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */

#include "POLDRE.h"
#include "FM1DRE.h"       // Both subsystems (POL and FM1) share same hmi

extern t_drePOL drePOL;
extern t_dreFM1 dreFM1; // Both subsystems (POL and FM1) share same hmi

#define upReqAcq (drePOL.upReqAcq)
#define upReqDI (drePOL.upReqDI)
#define posAchieved (drePOL.posAchieved)
#define posMode (drePOL.posMode)
#define upButTimer (drePOL.upButTimer)

/* ['POLModeSelector' begin (DON'T REMOVE THIS LINE!)] */
void POLModeSelector() {
    /* set initial state */
    static STATE_T state = ID_POLMODESELECTOR_INIT;

    switch (state) {
            /* State ID: ID_POLMODESELECTOR_INIT */
        case ID_POLMODESELECTOR_INIT:
        {
            /* Transition ID: ID_POLMODESELECTOR_INITIAL */
            /* Actions: */
            /* ['<global>::setStopMode' begin] */
            posMode = CFG_POS_MODE_STOP;
            /* ['<global>::setStopMode' end] */
            state = ID_POLMODESELECTOR_STOP;
            break;
        }
            /* State ID: ID_POLMODESELECTOR_STOP */
        case ID_POLMODESELECTOR_STOP:
        {
            if (upReqAcq == TRUE) {
                /* Transition ID: ID_POLMODESELECTOR_TOUP */
                /* Actions: */
                /* ['<global>::setUpMode' begin] */
                posMode = CFG_POS_MODE_UP;
                /* ['<global>::setUpMode' end] */
                state = ID_POLMODESELECTOR_UP;
            } 
            break;
        }
            /* State ID: ID_POLMODESELECTOR_UP */
        case ID_POLMODESELECTOR_UP:
        {
            if (posAchieved == TRUE) {
                /* Transition ID: ID_POLMODESELECTOR_OPTIMIZED_TRANSITION_1 */
                /* Actions: */
                /* ['<global>::setStopMode' begin] */
                posMode = CFG_POS_MODE_STOP;
                /* ['<global>::setStopMode' end] */
                state = ID_POLMODESELECTOR_STOPWAIT;
            }
            break;
        }
            /* State ID: ID_POLMODESELECTOR_STOPWAIT */
        case ID_POLMODESELECTOR_STOPWAIT:
        {
            if (upReqAcq == FALSE) {
                /* Transition ID: ID_POLMODESELECTOR_RELEASE */
                /* Actions: */
                /* ['<global>::setStopMode' begin] */
                posMode = CFG_POS_MODE_STOP;
                /* ['<global>::setStopMode' end] */
                state = ID_POLMODESELECTOR_STOP;
            }
            break;
        }
            /* State ID: ID_POLMODESELECTOR_DOWN */
        case ID_POLMODESELECTOR_DOWN:
        {
            if ((upReqAcq == TRUE) || (posAchieved == TRUE)) {
                /* Transition ID: ID_POLMODESELECTOR_OPTIMIZED_TRANSITION_1 */
                /* Actions: */
                /* ['<global>::setStopMode' begin] */
                posMode = CFG_POS_MODE_STOP;
                /* ['<global>::setStopMode' end] */
                state = ID_POLMODESELECTOR_STOPWAIT;
            }
            break;
        }
    }
}
/* ['POLModeSelector' end (DON'T REMOVE THIS LINE!)] */

/* ['POLUpButAcq' begin (DON'T REMOVE THIS LINE!)] */
void POLUpButAcq() {
    /* set initial state */
    static STATE_T state = ID_POLUPBUTACQ_INIT;

    switch (state) {
            /* State ID: ID_POLUPBUTACQ_INIT */
        case ID_POLUPBUTACQ_INIT:
        {
            /* Transition ID: ID_POLUPBUTACQ_INITIAL */
            /* Actions: */
            /* ['<global>::resetUpButTimer' begin] */
            upButTimer = 0L;
            /* ['<global>::resetUpButTimer' end] */
            /* ['<global>::clearUpButton' begin] */
            upReqAcq = FALSE;
            /* ['<global>::clearUpButton' end] */
            state = ID_POLUPBUTACQ_NOTPRESSED;
            break;
        }
            /* State ID: ID_POLUPBUTACQ_NOTPRESSED */
        case ID_POLUPBUTACQ_NOTPRESSED:
        {
            if ((upReqDI == TRUE) && (upButTimer > CFG_POL_UP_BUT_PRESS_TIMER)) {
                /* Transition ID: ID_POLUPBUTACQ_PRESS */
                /* Actions: */
                /* ['<global>::resetUpButTimer' begin] */
                upButTimer = 0L;
                /* ['<global>::resetUpButTimer' end] */
                /* ['<global>::setUpButton' begin] */
                upReqAcq = TRUE;
                /* ['<global>::setUpButton' end] */
                state = ID_POLUPBUTACQ_PRESSED;
            } else if (upReqDI == TRUE) {
                /* Transition ID: ID_POLUPBUTACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementUpButTimer' begin] */
                upButTimer++;
                /* ['<global>::incrementUpButTimer' end] */
            } else if (upReqDI == FALSE) {
                /* Transition ID: ID_POLUPBUTACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetUpButTimer' begin] */
                upButTimer = 0L;
                /* ['<global>::resetUpButTimer' end] */
            }
            break;
        }
            /* State ID: ID_POLUPBUTACQ_PRESSED */
        case ID_POLUPBUTACQ_PRESSED:
        {
            if ((upReqDI == FALSE) && (upButTimer > CFG_POL_UP_BUT_UNPRESS_TIMER)
                    ) {
                /* Transition ID: ID_POLUPBUTACQ_UNPRESS */
                /* Actions: */
                /* ['<global>::resetUpButTimer' begin] */
                upButTimer = 0L;
                /* ['<global>::resetUpButTimer' end] */
                /* ['<global>::clearUpButton' begin] */
                upReqAcq = FALSE;
                /* ['<global>::clearUpButton' end] */
                state = ID_POLUPBUTACQ_NOTPRESSED;
            } else if (upReqDI == FALSE) {
                /* Transition ID: ID_POLUPBUTACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementUpButTimer' begin] */
                upButTimer++;
                /* ['<global>::incrementUpButTimer' end] */
            } else if (upReqDI == TRUE) {
                /* Transition ID: ID_POLUPBUTACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetUpButTimer' begin] */
                upButTimer = 0L;
                /* ['<global>::resetUpButTimer' end] */
            }
            break;
        }
    }
}
/* ['POLUpButAcq' end (DON'T REMOVE THIS LINE!)] */

