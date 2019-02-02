#include <wondermacros/meta/cat.h>
#include <wondermacros/meta/cat_outer.h>
#include <boost/preprocessor/control/if.hpp>

/* begin: state_function.h */

#if W_FSM_DECLARE == 0

# include <wondermacros/fsm/x/on_event.h>

#endif

#define STATE(s) W_CAT_OUTER(s,__define)
#define ENTRY(...)
#define EXIT(...)
#define SUPERSTATE(...)


#define INITIAL(...)
#define BEGIN(name) \
    int W_CAT(FSM,__,name)(W_FSM_T* self, W_FSM_EVENT_T* event)    \
    BOOST_PP_IF(W_FSM_DECLARE,;,                                   \
        {                                                          \
            return W_CAT(FSM,__,name,__on_event)(self,event);      \
        } \
    )
#define END
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

/* end: state_function.h */

