#ifndef FSM
# error "FSM must be defined."
#endif


#include <wondermacros/meta/cat.h>

struct FSM;

struct W_CAT(FSM,_model) {
    int foo;
};

enum W_CAT(FSM,_status) {
    W_CAT(FSM,__status_stopped),
    W_CAT(FSM,__status_running),
};

struct FSM {
    enum W_CAT(FSM,_status) status;
    int (*state)(struct FSM* self, FSM_EVENT_TYPE event);
    struct W_CAT(FSM,_model) model;
};

