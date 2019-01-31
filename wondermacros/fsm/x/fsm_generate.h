#include <wondermacros/meta/cat.h>
#include <wondermacros/meta/cat_inner.h>
#include <wondermacros/meta/cat_outer.h>

#define W_FSM_DECLARE 0
#include <wondermacros/fsm/x/state_function.h>
#include <wondermacros/fsm/x/start_function.h>
#include <wondermacros/fsm/x/on_event_function.h>
#include <wondermacros/fsm/x/state_meta.h>
#undef W_FSM_DECLARE

#undef FSM
#undef FSM_EVENT_TYPE

