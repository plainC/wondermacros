void W_CAT(FSM,_start)(struct FSM* self)
#if W_FSM_DECLARE
;
#else
{
#define INITIAL(State,action)               \
    action                                  \
    self->state.func = W_CAT(FSM,__,State); \
    W_CAT(FSM,__,State,__entry)(self);      \
    /**/
#define BEGIN(...)
#define END
#define SUBSTATE(...)
#define AUTO(...)
#define EVENTS(...)


/**/
STATES
/**/

}
#endif
