#ifndef FSM
# error "FSM must be defined."
#endif


#include <wondermacros/meta/cat.h>

struct FSM;

#define W_FSM_EVENT_T struct W_CAT(FSM,_event)
#define W_FSM_MODEL_T struct W_CAT(FSM,_model)
#define W_FSM_STATUS_T enum W_CAT(FSM,_status)
#define W_FSM_T        struct FSM


W_FSM_EVENT_T {
    FSM_EVENT_TYPE tag;
    void* data;
};

W_FSM_MODEL_T {
    int foo;
};

W_FSM_STATUS_T {
    W_CAT(FSM,__status_stopped),
    W_CAT(FSM,__status_running),
};

typedef int (*W_CAT(FSM,_state))(struct FSM* self, W_FSM_EVENT_T* event);

W_FSM_T {
    W_FSM_STATUS_T status;
    int (*state)(struct FSM* self, W_FSM_EVENT_T* event);
    W_FSM_MODEL_T model;
};
