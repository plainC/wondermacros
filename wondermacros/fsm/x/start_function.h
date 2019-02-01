void W_CAT(FSM,_start)(struct FSM* self)
#if W_FSM_DECLARE
;
#else
{
#define STATE(Name) W_CAT_OUTER(Name,__define)

#define INITIAL(State,action)               \
    FSM_GO_NEXT_STATE(self,State,action);   \
    /**/
#define BEGIN(...)
#define END
#define SUPERSTATE(...)
#define AUTO(...)
#define EVENTS(...)
#define ENTRY(...)
#define EXIT(...)

/**/
    self->status = W_CAT(FSM,__status_running);
    STATES
/**/

}

#undef INITIAL
#undef BEGIN
#undef END
#undef SUPERSTATE
#undef AUTO
#undef EVENTS
#undef STATE
#undef ENTRY
#undef EXIT

#endif
