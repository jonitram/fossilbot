#ifndef _INSTRUCTIONS_H_
#define _INSTRUCTIONS_H_

#include "Joystick.h"

#if !defined(ARRAY_SIZE)
    #define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))
#endif

// change this value to alter how many fossils are restored
static const uint16_t fossils = 3;

typedef enum {
    move_up,
    move_down,
    move_right,
    move_left,
    press_a,
    press_b,
    press_x,
    press_y,
    press_r,
    hang
} action_t;

typedef struct {
    action_t action;
    uint16_t duration;
} command_t;

static const command_t wake_up_hang[] = {
    { hang, 100 }
};

static const command_t restore_fossil_steps[] = {

    { hang, 10 },
    { press_b, 5 },
    { hang, 10 },

    { press_a, 5 },
    { hang, 40 },
    { press_a, 5 },
    { hang, 50 },

    // select fossil for dracovish
    { move_down, 5 },
    { hang, 5 },

    { press_a, 5 },
    { hang, 40 },
    { press_a, 5 },
    { hang, 40 },
    { press_a, 5 },
    { hang, 40 },

    { press_a, 5 },
    { hang, 180 },

    { press_a, 5 },
    { hang, 40 },
    { press_a, 5 },
    { hang, 40 },
    { press_a, 5 },
    { hang, 30 },

    { press_a, 5 },
    { hang, 200 },

    { press_a, 5 },
    { hang, 90 },

    { press_b, 5 },
    { hang, 40 },
    { press_a, 5 },
    { hang, 30 }

};

#endif