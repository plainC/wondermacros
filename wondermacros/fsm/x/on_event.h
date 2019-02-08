/* begin: on_event.h */

#define SUPERSTATE(...)

#define BEGIN(name,...)                                               \
static inline int                                                     \
W_CAT(FSM,__,name,__on_event)(W_FSM_T* self, W_FSM_EVENT_T* event)    \
{                                                                     \
    switch (event->tag) {

#define END                                                           \
    }                                                                 \
}
    /**/
#define STATE(s) W_CAT_OUTER(s,__define)
#define ENTRY(...)
#define EXIT(...)
#define INITIAL(...)
#define AUTO(...)
#define EVENTS(...) __VA_ARGS__
#define ON_EVENT(start,Event,...)                                     \
    BOOST_PP_OVERLOAD(_ON_EVENT_,__VA_ARGS__)(start,Event,__VA_ARGS__)
#define _ON_EVENT_1(start,Event,target)                               \
    _ON_EVENT_3(start,Event,target,/*none*/,1)
#define _ON_EVENT_2(start,Event,target,action)         \
    _ON_EVENT_3(start,Event,target,action,1)
#define _ON_EVENT_3(start,Event,target,action,guard)   \
    case W_PP_CHARSEQ_TO_UINT(FSM_EVENT_TYPE,Event):   \
      if (guard) {                                     \
          FSM_GO_NEXT_STATE(self,start,target,action); \
          return 1;                                    \
      }                                                \
      break;
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

/* end: on_event.h */
