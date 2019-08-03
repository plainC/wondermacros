#define CLASS_NAME(...)
#define INTERFACE_NAME(...)
#define VAR(...)
#define METHODV(...)
#define METHOD(...)
#define SIGNALV(...)
#define SIGNAL(...)

static inline void*
W_CAT(CLASS,__new)(CLASS* template)
{
    CLASS* self = malloc(sizeof(CLASS));
    self->klass = &W_CAT(CLASS,__class_instance);
    return self;
}

#undef CLASS_NAME
#undef INTERFACE_NAME
#undef VAR
#undef METHODV
#undef METHOD
#undef SIGNALV
#undef SIGNAL

