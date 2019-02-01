#define ENTRY(...)
#define EXIT(...)
#define STATE(s) W_CAT_OUTER(s,__define)
#define AUTO(start,...)                                    \
    BOOST_PP_OVERLOAD(_AUTO_,__VA_ARGS__)(start,__VA_ARGS__)
#define _AUTO_1(start,target)                              \
    _AUTO_3(start,target,/*none*/,1)
#define _AUTO_2(start,target,action)                       \
    _AUTO_3(start,target,action,1)
#define _AUTO_3(start,target,action,guard)                 \
static int                                                 \
W_CAT(FSM,__,start,_auto_transition)(struct FSM* self)      \
{                                                           \
    if (guard) {                                            \
        W_CAT(FSM,__,start,__,exit)(self);                  \
        action                                              \
        W_CAT(FSM,__,target,__,entry)(self);                \
        self->state = W_CAT(FSM,__,target);                 \
        return 1;                                           \
    }                                                       \
    return 0;                                               \
}

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

