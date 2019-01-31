#ifndef FSM
# error "FSM must be defined"
#endif

#ifndef STATES
# error "STATES must be defined"
#endif

#ifndef FSM_EVENT_TYPE
# define FSM_EVENT_TYPE unsigned
#endif

/**/

#include <wondermacros/meta/cat.h>
#include <wondermacros/meta/cat_outer.h>
#include <boost/preprocessor/control/if.hpp>

/**/

#define ENTRY(...)
#define EXIT(...)

#define STATE(s) W_CAT_OUTER(s,__define)
#define BEGIN(name) \
    struct W_CAT(FSM,_state) W_CAT(FSM,__,name)(struct FSM* self, FSM_EVENT_TYPE event) BOOST_PP_IF(W_FSM_DECLARE,;,{)

#if W_FSM_DECLARE
# define END
# define SUBSTATE(...)
# define AUTO(...)
# define EVENTS(...)
#else
# define END }
# define SUBSTATE(...)
# define AUTO(...)
# define EVENTS(...)
#endif

/**/
STATES
/**/

#undef ENTRY
#undef EXIT
#undef STATE
#undef BEGIN
#undef END
#undef SUBSTATE
#undef AUTO
#undef EVENTS
