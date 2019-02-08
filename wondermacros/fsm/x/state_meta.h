#ifndef WDEBUG_EXPAND
# include <wondermacros/array/get_size.h>
# include <wondermacros/array/dynamic_array.h>
# include <wondermacros/configs/default_allocation.h>
#endif

/* begin: state_meta.h */

#define STATE(Name) W_CAT_OUTER(Name,__define)
#define INITIAL(...)
#define EVENTS(...)
#define ENTRY(...)
#define EXIT(...)


/**/
#if W_FSM_DECLARE

#define SUPERSTATE(...)
#define AUTO(...)
#define END
#define BEGIN(Name) \
extern int (*W_CAT(FSM,__,Name,__meta_super))(W_FSM_T* self, W_FSM_EVENT_T* event); \
extern int (*W_CAT(FSM,__,Name,__meta_auto_transition))(W_FSM_T* self); \
extern const char* W_CAT(FSM,__,Name,__meta_name);
extern W_FSM_STATE_META_T* W_CAT(FSM,__meta_info);
void W_CAT(FSM,__initialize)(W_FSM_T* self);

STATES

#undef AUTO
#undef END
#undef BEGIN

#else

/* Generate meta superstate variable. */

#define AUTO(...)
#define SUPERSTATE(name) W_CAT(FSM,__state_tag__,name) |
#define BEGIN(Name)
#define END 0,

W_FSM_STATE_T W_CAT(FSM,__meta_superstates)[] = {
    0,

    /**/
    STATES
    /**/

};

#undef SUPERSTATE
#undef BEGIN
#undef END
#undef AUTO

/* Generate meta auto_transition variable. */

#define AUTO(name,...) = W_CAT(FSM,__,name,__auto_transition)
#define SUPERSTATE(...)
#define BEGIN(Name) \
int (*W_CAT(FSM,__,Name,__meta_auto_transition))(W_FSM_T* self)
#define END ;

STATES

#undef SUPERSTATE
#undef BEGIN
#undef END
#undef AUTO

/* Generate meta name variable. */

#define AUTO(...)
#define SUPERSTATE(...)
#define BEGIN(Name) # Name,
#define END

const char* W_CAT(FSM,__state_names)[] = {
    "*NONE*",
    STATES
};

#undef SUPERSTATE
#undef BEGIN
#undef END
#undef AUTO

/* Generate meta table. */

//W_FSM_STATE_META_T* W_FSM_META = NULL;

void
W_CAT(FSM,__initialize)(W_FSM_T* self)
{
    printf("Initialize\n\n");

    self->meta = malloc(sizeof(W_FSM_STATE_META_T));
    self->meta->nbr_of_states = W_ARRAY_GET_SIZE(W_CAT(FSM,__state_names)) - 1;
    self->meta->name = W_CAT(FSM,__state_names);
    self->meta->superstate = W_CAT(FSM,__meta_superstates);
    self->meta->substates = W_MALLOC0(sizeof(W_FSM_STATE_T*) * W_ARRAY_GET_SIZE(W_CAT(FSM,__state_names)));

    /* Add substates, if any. */
    for (int i=1; i <= self->meta->nbr_of_states; i++)
        if (self->meta->superstate[i])
            W_DYNAMIC_ARRAY_PUSH(self->meta->substates[self->meta->superstate[i]], i);
}

/* end: state_meta.h */

#endif

#undef INITIAL
#undef BEGIN
#undef END
#undef SUPERSTATE
#undef AUTO
#undef EVENTS
#undef STATE
#undef ENTRY
#undef EXIT
#undef SUPERSTATE
