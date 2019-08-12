static inline void
W_CAT(CLASS,__do_construct)(CLASS* self)
{
    self->klass = &W_CAT(CLASS,__class_instance);
#if HAS_CONSTRUCT
    W_CAT(CLASS,__user_construct)(self);
#endif
}

#define CLASS_NAME(name) \
    W_CAT(name,__do_construct)((name*) self);
#define INTERFACE_NAME(...)
#define VAR(...)
#define METHODV(...)
#define METHOD(...)
#define SIGNALV(...)
#define SIGNAL(...)

static inline void
W_CAT(CLASS,__construct)(CLASS* self)
{
    W_CAT_OUTER(CLASS,__define)
}

#undef CLASS_NAME
#undef INTERFACE_NAME
#undef VAR
#undef METHODV
#undef METHOD
#undef SIGNALV
#undef SIGNAL

