#define CLASS_NAME(...)
#define INTERFACE_NAME(...)
#define VAR(...)
#define METHODV(...)
#define METHOD(...)
#define SIGNALV(...)
#define SIGNAL(...)

static inline void
W_CAT(CLASS,__construct)(CLASS* self)
{
    self->klass = &W_CAT(CLASS,__class_instance);
#if HAS_CONSTRUCT
    W_CAT(CLASS,__user_construct)(self);
#endif
}

#undef CLASS_NAME
#undef INTERFACE_NAME
#undef VAR
#undef METHODV
#undef METHOD
#undef SIGNALV
#undef SIGNAL

