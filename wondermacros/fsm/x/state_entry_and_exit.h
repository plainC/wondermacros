#ifndef FSM
# error "FSM must be defined"
#endif

#ifndef STATES
# error "STATES must be defined"
#endif


#include <wondermacros/meta/cat.h>
#include <wondermacros/meta/cat_outer.h>


/**/
#define ENTRY(state,action)                                             \
static inline void W_CAT(FSM,__,state,__entry)(struct FSM* self)        \
{ action }                                                              \
/**/
#define EXIT(state,action)                                              \
static inline void W_CAT(FSM,__,state,__exit)(struct FSM* self)         \
{ action }                                                              \
/**/
#define STATE(s) W_CAT_OUTER(s,__define)
#define BEGIN(...)
#define END
#define SUBSTATE(...)
#define AUTO(...)
#define EVENTS(...)

STATES

#undef ENTRY
#undef EXIT
#undef STATE
#undef BEGIN
#undef END
#undef SUBSTATE
#undef AUTO
#undef EVENTS
