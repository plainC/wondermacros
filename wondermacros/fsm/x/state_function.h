#include <wondermacros/meta/cat.h>
#include <wondermacros/meta/cat_outer.h>
#include <boost/preprocessor/control/if.hpp>

/* begin: state_function.h */

#if W_FSM_DECLARE

extern int (*W_CAT(FSM,__,states)[])(W_FSM_T* self, W_FSM_EVENT_T* event);

#else

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


/**/

/* State function table. */

#if W_FSM_DECLARE == 0

#define STATE(s) W_CAT_OUTER(s,__define)
#define ENTRY(...)
#define EXIT(...)
#define SUPERSTATE(...)
#define INITIAL(...)
#define END
#define AUTO(...)
#define EVENTS(...)

#define BEGIN(name) W_CAT(FSM,__,name),

int (*W_CAT(FSM,__,states)[])(W_FSM_T* self, W_FSM_EVENT_T* event) = {

/**/
STATES
/**/

};

#undef ENTRY
#undef EXIT
#undef STATE
#undef INITIAL
#undef BEGIN
#undef END
#undef SUPERSTATE
#undef AUTO
#undef EVENTS

#endif


/**/

/**/

/* Super state table. */

#if W_FSM_DECLARE == 0

#define STATE(s) W_CAT_OUTER(s,__define)
#define ENTRY(...)
#define EXIT(...)
#define SUPERSTATE(Name) W_CAT(FSM,__state_tag,__,Name) | 
#define INITIAL(...)
#define END 0,
#define AUTO(...)
#define EVENTS(...)

#define BEGIN(name)

int W_CAT(FSM,__,superstates)[] = {

/**/
STATES
/**/

};

#undef ENTRY
#undef EXIT
#undef STATE
#undef INITIAL
#undef BEGIN
#undef END
#undef SUPERSTATE
#undef AUTO
#undef EVENTS

#endif

/* end: state_function.h */

