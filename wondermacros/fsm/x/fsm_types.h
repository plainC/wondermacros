#ifndef FSM
# error "FSM must be defined."
#endif


#include <wondermacros/meta/cat.h>

struct FSM;

#define W_FSM_EVENT_T  struct W_CAT(FSM,_event)
#define W_FSM_MODEL_T  struct W_CAT(FSM,_model)
#define W_FSM_STATUS_T enum W_CAT(FSM,_status)
#define W_FSM_T        struct FSM
#define W_FSM_STATE_T  enum W_CAT(FSM,_state_tag)
#define W_FSM_STATE_META_T struct W_CAT(FSM,_state_meta)

/**/

#define W_FSM_META        W_CAT(FSM,__meta_info)
#define W_FSM_STATE_NULL  W_CAT(FSM,__state_null)

/**/

/* State type table. */


#define STATE(s) W_CAT_OUTER(s,__define)
#define ENTRY(...)
#define EXIT(...)
#define SUPERSTATE(...)
#define INITIAL(...)
#define END
#define AUTO(...)
#define EVENTS(...)

#define BEGIN(name) W_CAT(FSM,__state_tag,__,name),

W_FSM_STATE_T {

    W_CAT(FSM,__state_null),

    /**/
    STATES
    /**/

};

#undef ENTRY
#undef EXIT
#undef STATE
#undef INITIAL
#undef BEGIN
#undef END
#undef SUPERSTATE
#undef AUTO
#undef EVENTS


/**/

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

W_FSM_STATE_META_T {
    int nbr_of_states;
    const char** name;
    W_FSM_STATE_T* superstate;
    W_FSM_STATE_T** substates;

    int (*auto_transition)(W_FSM_T* self);
    W_FSM_STATE_T initial_state;
    int* is_final;
};

W_FSM_T {
    W_FSM_STATE_META_T* meta;
    W_FSM_STATUS_T status;
    W_FSM_STATE_T state;
    W_FSM_MODEL_T model;
};

