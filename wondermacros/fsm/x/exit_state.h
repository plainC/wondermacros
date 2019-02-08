/* begin: exit_state.h */

#define BEGIN(name,...)                                               \
static inline int                                                     \
W_CAT(FSM,__,name,__exit_superstates)(W_FSM_T* self,                  \
    int (*start)(struct FSM* self, W_FSM_EVENT_T* event))             \
{                                                                     \
    while (self->state != start) {                                    \
        W_ON_EVENT(self, (_)(x)(U)(p) );                              \
        assert(self->state);                                          \
    }                                                                 \
}                                                                     \
                                                                      \
static inline int                                                     \
W_CAT(FSM,__,name,__enter_substates)(struct FSM* self,                \
    int (*start)(struct FSM* self, FSM_EVENT_TYPE event),             \
    int (*target)(struct FSM* self, FSM_EVENT_TYPE event))            \
{                                                                     \
    W_CAT(FSM,_state) stack[16];                                      \
    int sp=0;                                                         \
    self->state = target;                                             \
    while (self->state != start) {                                    \
        stack[sp++] = self->state;                                    \
        W_ON_EVENT(self, (_)(_)(U)(p) );                              \
    }                                                                 \
    while (sp > 0) {                                                  \
        self->state = stack[--sp];                                    \
        W_ON_EVENT(self, (_)(n)(t)(R) );                              \
    }                                                                 \
}

#define END
#define STATE(s) W_CAT_OUTER(s,__define)
#define ENTRY(...)
#define EXIT(...)
#define INITIAL(...)
#define AUTO(...)
#define EVENTS(...)
#define SUPERSTATE(...)

/**/
        STATES
/**/
#undef STATE
#undef ENTRY
#undef EXIT
#undef INITIAL
#undef AUTO
#undef BEGIN
#undef END
#undef EVENTS
#undef SUPERSTATE

/* end: exit_state.h */
