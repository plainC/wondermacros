/* begin: auto_transition_function.h */

#if W_FSM_DECLARE
#define AUTO_BODY(start,target,action,guard) ;
#else
#define AUTO_BODY(start,target,action,guard)                 \
{                                                            \
    if (guard) {                                             \
        W_CAT(FSM,__,start,__,exit)(self);                   \
        action                                               \
        W_CAT(FSM,__,target,__,entry)(self);                 \
        self->state = W_CAT(FSM,__,target);                  \
        return 1;                                            \
    }                                                        \
    return 0;                                                \
}

#define ENTRY(...)
#define EXIT(...)
#define STATE(s) W_CAT_OUTER(s,__define)
#define AUTO(start,...)                                      \
    BOOST_PP_OVERLOAD(_AUTO_,__VA_ARGS__)(start,__VA_ARGS__)
#define _AUTO_1(start,target)                                \
    _AUTO_3(start,target,/*none*/,1)
#define _AUTO_2(start,target,action)                         \
    _AUTO_3(start,target,action,1)
#define _AUTO_3(start,target,action,guard)                   \
int                                                          \
W_CAT(FSM,__,start,__auto_transition)(W_FSM_T* self)         \
AUTO_BODY(start,target,action,guard)

#define INITIAL(...)
#define BEGIN(name)
#define END
#define SUPERSTATE(...)
#define EVENTS(...)


/**/
STATES
/**/

#undef ENTRY
#undef EXIT
#undef INITIAL
#undef BEGIN
#undef END
#undef SUPERSTATE
#undef AUTO
#undef EVENTS
#undef STATE

#endif
/* end: auto_transition_function.h */

#undef AUTO_BODY
