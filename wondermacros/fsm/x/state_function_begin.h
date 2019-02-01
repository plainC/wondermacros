/* begin: state_function_begin.h */

#define ENTRY(...)
#define EXIT(...)
#define STATE(s) W_CAT_OUTER(s,__define)
#define INITIAL(...)
#define BEGIN(name) \
    int W_CAT(FSM,__,name)(struct FSM* self, FSM_EVENT_TYPE event) \
    BOOST_PP_IF(W_FSM_DECLARE,;,\
        { \
            return W_CAT(FSM,__,name,__on_event)(self,event); \
        } \
    )
#define END
#define SUPERSTATE(...)
#define AUTO(...)
#define EVENTS(...)


/**/
STATES
/**/

#undef ENTRY
#undef EXIT
#undef STATE
#undef INITIAL
#undef BEGIN
#undef END
#undef SUPERSTATE
#undef AUTO
#undef EVENTS

/* end: state_function_begin.h */
