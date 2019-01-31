#include <wondermacros/meta/cat.h>
#include <wondermacros/meta/cat_inner.h>
#include <wondermacros/meta/cat_outer.h>

#define W_FSM_DECLARE 1
#include <wondermacros/fsm/x/fsm_types.h>
#include <wondermacros/fsm/x/state_meta.h>
#include <wondermacros/fsm/x/state_entry_and_exit.h>
#include <wondermacros/fsm/x/state_function.h>
#include <wondermacros/fsm/x/start_function.h>
#include <wondermacros/fsm/x/on_event_function.h>

#undef W_FSM_DECLARE
