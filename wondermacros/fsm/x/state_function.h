#include <wondermacros/meta/cat.h>
#include <wondermacros/meta/cat_outer.h>
#include <boost/preprocessor/control/if.hpp>

/**/

#define STATE(s) W_CAT_OUTER(s,__define)
#define ENTRY(...)
#define EXIT(...)
#define SUPERSTATE(...)

#if W_FSM_DECLARE

# include <wondermacros/fsm/x/state_function_begin.h>

#else

# include <wondermacros/fsm/x/on_event.h>
# include <wondermacros/fsm/x/state_function_begin.h>

#endif

#undef STATE
#undef ENTRY
#undef EXIT
#undef SUPERSTATE
