#include <wondermacros/meta/cat.h>
#include <wondermacros/meta/cat_inner.h>
#include <wondermacros/meta/cat_outer.h>
#include <wondermacros/meta/wrap.h>

#ifndef WDEBUG_EXPAND
# include <wondermacros/pp_char/charseq.h>
#endif

#include <wondermacros/fsm/x/fsm_tools.h>

#define W_FSM_DECLARE 0
#include <wondermacros/fsm/x/state_function.h>
#include <wondermacros/fsm/x/start_function.h>
#include <wondermacros/fsm/x/auto_transition_function.h>
#include <wondermacros/fsm/x/state_meta.h>
#undef W_FSM_DECLARE

