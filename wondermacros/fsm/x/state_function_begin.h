#define INITIAL(...)
#define BEGIN(name) \
    struct W_CAT(FSM,_state) W_CAT(FSM,__,name)(struct FSM* self, FSM_EVENT_TYPE event) BOOST_PP_IF(W_FSM_DECLARE,;,{)
#define END
#define SUBSTATE(...)
#define AUTO(...)
#define EVENTS(...)


/**/
STATES
/**/

#undef INITIAL
#undef BEGIN
#undef END
#undef SUBSTATE
#undef AUTO
#undef EVENTS

