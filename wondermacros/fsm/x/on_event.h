#include <wondermacros/pp_char/charseq.h>

    switch (event) {
//#define STATE(s) W_CAT_OUTER(s,__define)
//#define ENTRY(...)
//#define EXIT(...)
#define INITIAL(...)
#define AUTO(...)
#define BEGIN(...)
#define EVENTS(...) __VA_ARGS__
#define END
#define ON_EVENT(start,Event,...)                      \
    BOOST_PP_OVERLOAD(_ON_EVENT_,__VA_ARGS__)(start,Event,__VA_ARGS__)
#define _ON_EVENT_1(start,Event,target)                \
    _ON_EVENT_3(start,Event,target,/*none*/,1)
#define _ON_EVENT_2(start,Event,target,action)         \
    _ON_EVENT_3(start,Event,target,action,1)
#define _ON_EVENT_3(start,Event,target,action,guard)   \
    case W_PP_CHARSEQ_TO_UINT(FSM_EVENT_TYPE,Event):   \
      if (guard)                                       \
          FSM_GO_NEXT_STATE(self,start,target,action); \
/**/
        STATES
/**/
//#undef STATE
//#undef ENTRY
//#undef EXIT
#undef INITIAL
#undef AUTO
#undef BEGIN
#undef END
#undef EVENTS

    }
