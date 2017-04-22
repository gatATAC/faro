/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include "FM1lin1dFSM.h"
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */

#include "FM1DRE.h"

extern t_dreFM1 dreFM1;

#define upReqAcq (dreFM1.upReqAcq)
#define upReqDI (dreFM1.upReqDI)
#define posAchieved (dreFM1.posAchieved)
#define posMode (dreFM1.posMode)
#define upButTimer (dreFM1.upButTimer)

/* ['FM1ModeSelector' begin (DON'T REMOVE THIS LINE!)] */
void FM1ModeSelector() {
    /* set initial state */
    static STATE_T state = ID_FM1MODESELECTOR_INIT;

    switch (state) {
            /* State ID: ID_FM1MODESELECTOR_INIT */
        case ID_FM1MODESELECTOR_INIT:
        {
            /* Transition ID: ID_FM1MODESELECTOR_INITIAL */
            /* Actions: */
            /* ['<global>::setStopMode' begin] */
            posMode = CFG_POS_MODE_STOP;
            /* ['<global>::setStopMode' end] */
            state = ID_FM1MODESELECTOR_STOP;
            break;
        }
            /* State ID: ID_FM1MODESELECTOR_STOP */
        case ID_FM1MODESELECTOR_STOP:
        {
            if (upReqAcq == TRUE) {
                /* Transition ID: ID_FM1MODESELECTOR_TOUP */
                /* Actions: */
                /* ['<global>::setUpMode' begin] */
                posMode = CFG_POS_MODE_UP;
                /* ['<global>::setUpMode' end] */
                state = ID_FM1MODESELECTOR_UP;
            }
            break;
        }
            /* State ID: ID_FM1MODESELECTOR_UP */
        case ID_FM1MODESELECTOR_UP:
        {
            if ((posAchieved == TRUE)) {
                /* Transition ID: ID_FM1MODESELECTOR_OPTIMIZED_TRANSITION_1 */
                /* Actions: */
                /* ['<global>::setStopMode' begin] */
                posMode = CFG_POS_MODE_STOP;
                /* ['<global>::setStopMode' end] */
                state = ID_FM1MODESELECTOR_STOPWAIT;
            }
            break;
        }
            /* State ID: ID_FM1MODESELECTOR_STOPWAIT */
        case ID_FM1MODESELECTOR_STOPWAIT:
        {
            if ((upReqAcq == FALSE)) {
                /* Transition ID: ID_FM1MODESELECTOR_RELEASE */
                /* Actions: */
                /* ['<global>::setStopMode' begin] */
                posMode = CFG_POS_MODE_STOP;
                /* ['<global>::setStopMode' end] */
                state = ID_FM1MODESELECTOR_STOP;
            }
            break;
        }
            /* State ID: ID_FM1MODESELECTOR_DOWN */
        case ID_FM1MODESELECTOR_DOWN:
        {
            if ((upReqAcq == TRUE) || (posAchieved == TRUE)) {
                /* Transition ID: ID_FM1MODESELECTOR_OPTIMIZED_TRANSITION_1 */
                /* Actions: */
                /* ['<global>::setStopMode' begin] */
                posMode = CFG_POS_MODE_STOP;
                /* ['<global>::setStopMode' end] */
                state = ID_FM1MODESELECTOR_STOPWAIT;
            }
            break;
        }
    }
}
/* ['FM1ModeSelector' end (DON'T REMOVE THIS LINE!)] */

/* ['FM1UpButAcq' begin (DON'T REMOVE THIS LINE!)] */
void FM1UpButAcq() {
    /* set initial state */
    static STATE_T state = ID_FM1UPBUTACQ_INIT;

    switch (state) {
            /* State ID: ID_FM1UPBUTACQ_INIT */
        case ID_FM1UPBUTACQ_INIT:
        {
            /* Transition ID: ID_FM1UPBUTACQ_INITIAL */
            /* Actions: */
            /* ['<global>::resetUpButTimer' begin] */
            upButTimer = 0L;
            /* ['<global>::resetUpButTimer' end] */
            /* ['<global>::clearUpButton' begin] */
            upReqAcq = FALSE;
            /* ['<global>::clearUpButton' end] */
            state = ID_FM1UPBUTACQ_NOTPRESSED;
            break;
        }
            /* State ID: ID_FM1UPBUTACQ_NOTPRESSED */
        case ID_FM1UPBUTACQ_NOTPRESSED:
        {
            if (((upReqDI == TRUE)) && (upButTimer > CFG_FM1_UP_BUT_PRESS_TIMER)) {
                /* Transition ID: ID_FM1UPBUTACQ_PRESS */
                /* Actions: */
                /* ['<global>::resetUpButTimer' begin] */
                upButTimer = 0L;
                /* ['<global>::resetUpButTimer' end] */
                /* ['<global>::setUpButton' begin] */
                upReqAcq = TRUE;
                /* ['<global>::setUpButton' end] */
                state = ID_FM1UPBUTACQ_PRESSED;
            } else if (upReqDI == TRUE) {
                /* Transition ID: ID_FM1UPBUTACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementUpButTimer' begin] */
                upButTimer++;
                /* ['<global>::incrementUpButTimer' end] */
            } else if (upReqDI == FALSE) {
                /* Transition ID: ID_FM1UPBUTACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetUpButTimer' begin] */
                upButTimer = 0L;
                /* ['<global>::resetUpButTimer' end] */
            }
            break;
        }
            /* State ID: ID_FM1UPBUTACQ_PRESSED */
        case ID_FM1UPBUTACQ_PRESSED:
        {
            if ((upReqDI == FALSE) && (upButTimer > CFG_FM1_UP_BUT_UNPRESS_TIMER)
                    ) {
                /* Transition ID: ID_FM1UPBUTACQ_UNPRESS */
                /* Actions: */
                /* ['<global>::resetUpButTimer' begin] */
                upButTimer = 0L;
                /* ['<global>::resetUpButTimer' end] */
                /* ['<global>::clearUpButton' begin] */
                upReqAcq = FALSE;
                /* ['<global>::clearUpButton' end] */
                state = ID_FM1UPBUTACQ_NOTPRESSED;
            } else if (upReqDI == FALSE) {
                /* Transition ID: ID_FM1UPBUTACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementUpButTimer' begin] */
                upButTimer++;
                /* ['<global>::incrementUpButTimer' end] */
            } else if (upReqDI == TRUE) {
                /* Transition ID: ID_FM1UPBUTACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetUpButTimer' begin] */
                upButTimer = 0L;
                /* ['<global>::resetUpButTimer' end] */
            }
            break;
        }
    }
}
/* ['FM1UpButAcq' end (DON'T REMOVE THIS LINE!)] */

