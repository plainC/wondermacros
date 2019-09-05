#define CLASS_NAME(...)
#define INTERFACE_NAME(...)
#define VAR(...)
#define METHODV(...)
#define METHOD(...)
#define SIGNALV(...)
#define SIGNAL(...)

static inline void*
W_CAT(CLASS,__new)(CLASS* self, CLASS* templ)
{
    if (!self)
        self = malloc(sizeof(CLASS));

    if (templ)
        *self = *templ;
    else
        bzero(self, sizeof(CLASS));

    W_CAT(CLASS,__construct)(self);

    return self;
}

#undef CLASS_NAME
#undef INTERFACE_NAME
#undef VAR
#undef METHODV
#undef METHOD
#undef SIGNALV
#undef SIGNAL

