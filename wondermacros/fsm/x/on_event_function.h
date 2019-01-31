void W_CAT(FSM,_on_event)(struct FSM* self, FSM_EVENT_TYPE event)
#if W_FSM_DECLARE
;
#else
{
    self->state.func(self, event);
}
#endif

