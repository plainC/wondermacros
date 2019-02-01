#ifndef FSM
# error "FSM must be defined"
#endif

#ifndef STATES
# error "STATES must be defined"
#endif

#ifndef FSM_EVENT_TYPE
# define FSM_EVENT_TYPE unsigned
#endif

#include <wondermacros/meta/wrap.h>
#include <wondermacros/fsm/x/fsm_tools.h>


#include <wondermacros/meta/cat.h>
#include <wondermacros/meta/cat_inner.h>
#include <wondermacros/meta/cat_outer.h>

#define W_FSM_DECLARE 1
#include <wondermacros/fsm/x/fsm_types.h>
#include <wondermacros/fsm/x/state_meta.h>
#include <wondermacros/fsm/x/state_entry_and_exit.h>
#include <wondermacros/fsm/x/state_function.h>
#include <wondermacros/fsm/x/start_function.h>
#include <wondermacros/fsm/x/auto_transition_function.h>

#undef W_FSM_DECLARE
