#include "test_states.h"

#define STATES STATE(s)
#define FSM xxx
#define FSM_EVENT_TYPE unsigned


#include <wondermacros/meta/cat.h>
#include <wondermacros/meta/cat_inner.h>
#include <wondermacros/meta/cat_outer.h>

#ifndef WDEBUG_EXPAND
# include <wondermacros/pp_char/charseq.h>
# include <stdio.h>
#endif


#include <wondermacros/fsm/x/fsm_declare.h>


int main()
{
}
