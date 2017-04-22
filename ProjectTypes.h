#ifndef _PROJECT_TYPES
#define _PROJECT_TYPES

#include <Arduino.h>

#define TRUE true
#define FALSE false

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef uint16_t t_tbd;

typedef uint8_t BOOL;
typedef uint8_t t_upreqacq;
typedef uint8_t t_posmode;
typedef uint16_t t_pwm;
typedef t_pwm t_pwm_duty;
typedef uint32_t t_timer;
typedef BOOL t_pwmservoenable;
typedef t_pwm_duty t_pwmservosetpoint;

#define CFG_POS_MODE_STOP 0
#define CFG_POS_MODE_UP 1
#define CFG_POS_MODE_DOWN 2

#endif

















