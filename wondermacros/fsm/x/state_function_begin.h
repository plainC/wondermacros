#define INITIAL(...)
#define BEGIN(name) \
    int W_CAT(FSM,__,name)(struct FSM* self, FSM_EVENT_TYPE event) BOOST_PP_IF(W_FSM_DECLARE,;,{)
#define END
#define SUPERSTATE(...)
#define AUTO(...)
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

