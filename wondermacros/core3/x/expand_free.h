#define CLASS_NAME(...)
#define INTERFACE_NAME(...)
#define VAR(...)
#define METHODV(...)
#define METHOD(...)
#define SIGNALV(...)
#define SIGNAL(...)

static inline void
W_CAT(CLASS,__free)(CLASS* self)
{
    free(self);
}

#undef CLASS_NAME
#undef INTERFACE_NAME
#undef VAR
#undef METHODV
#undef METHOD
#undef SIGNALV
#undef SIGNAL

