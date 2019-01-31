void W_CAT(FSM,_start)(struct FSM* self)
#if W_FSM_DECLARE
;
#else
{
#define STATE(Name) W_CAT_OUTER(Name,__define)

#define INITIAL(State,action)               \
    action                                  \
    self->state.func = W_CAT(FSM,__,State); \
    W_CAT(FSM,__,State,__entry)(self);      \
    /**/
#define BEGIN(...)
#define END
#define SUPERSTATE(...)
#define AUTO(...)
#define EVENTS(...)
#define ENTRY(...)
#define EXIT(...)

/**/
STATES
/**/

}

#undef INITIAL
#undef BEGIN
#undef END
#undef SUPERSTATE
#undef AUTO
#undef EVENTS
#undef STATE
#undef ENTRY
#undef EXIT

#endif
