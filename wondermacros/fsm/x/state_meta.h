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

STATES

#undef AUTO
#undef END
#undef BEGIN

#else

/* Generate meta superstate variable. */

#define AUTO(...)
#define SUPERSTATE(name) = W_CAT(FSM,__,name)
#define BEGIN(Name) \
int (*W_CAT(FSM,__,Name,__meta_super))(W_FSM_T* self, W_FSM_EVENT_T* event)
#define END ;

STATES

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
#define BEGIN(Name) \
    const char* W_CAT(FSM,__,Name,__meta_name) = # Name;
#define END

STATES

#undef SUPERSTATE
#undef BEGIN
#undef END
#undef AUTO

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
