#ifndef FSM
# error "FSM must be defined."
#endif


#include <wondermacros/meta/cat.h>

struct FSM;

struct W_CAT(FSM,_state) {
    struct W_CAT(FSM,_state) (*func)(struct FSM* self, unsigned event);
};

struct W_CAT(FSM,_model) {
    int foo;
};

struct FSM {
    struct W_CAT(FSM,_state) state;
    struct W_CAT(FSM,_model) model;
};

