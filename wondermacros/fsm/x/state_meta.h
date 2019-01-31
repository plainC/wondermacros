#define STATE(Name) W_CAT_OUTER(Name,__define)
#define INITIAL(...)
#define END
#define AUTO(...)
#define EVENTS(...)
#define ENTRY(...)
#define EXIT(...)


/**/
#if W_FSM_DECLARE
#define SUPERSTATE(...)
#define BEGIN(Name) \
extern struct W_CAT(FSM,_state_meta) W_CAT(FSM,__,Name,_state_meta);
struct W_CAT(FSM,_state_meta) {
    const char* name;
    struct W_CAT(FSM,_state_meta)* super;
};
STATES
#else
#define SUPERSTATE(Name) .super = W_CAT(FSM,__,Name,_state_meta),
#define BEGIN(Name) \
struct W_CAT(FSM,_state_meta) W_CAT(FSM,__,Name,_state_meta) = { \
    .name = # Name,
    STATES
};
#endif

/**/

#undef INITIAL
#undef BEGIN
#undef END
#undef SUPERSTATE
#undef AUTO
#undef EVENTS
#undef STATE
#undef ENTRY
#undef EXIT
#undef SUPERSTATE

