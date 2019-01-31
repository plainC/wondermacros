#define INITIAL(...)
#define BEGIN(name)
#define END
#define SUPERSTATE(...)
#define AUTO(start,...) BOOST_PP_OVERLOAD(_AUTO_,__VA_ARGS__)(start,__VA_ARGS__)
#define _AUTO_1(start,target) _AUTO_3(start,target,/*none*/,1)
#define _AUTO_2(start,target,action) _AUTO_3(start,target,action,1)
#define _AUTO_3(start,target,action,guard) \
    if (guard) { \
        W_CAT(FSM,__,start,__,exit)(self); \
        action \
        W_CAT(FSM,__,target,__,entry)(self); \
        return (struct W_CAT(FSM,_state)) { .func = W_CAT(FSM,__,target) }; \
    }
#define EVENTS(...)


/**/
STATES
/**/

#undef INITIAL
#undef BEGIN
#undef END
#undef SUPERSTATE
#undef AUTO
#undef EVENTS

