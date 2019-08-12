#define CLASS_NAME(...)
#define INTERFACE_NAME(...)
#define VAR(Name,T,...) { \
    .name = # Name, \
    .offset = offsetof(CLASS,Name) \
},
#define OVERRIDE(...)
#define METHODV(...)
#define METHOD(...)
#define SIGNALV(...)
#define SIGNAL(...)


struct ClassProperty W_CAT(CLASS,__properties)[] = {
    W_CAT_OUTER(CLASS,__define)
    NULL
};

#undef CLASS_NAME
#undef INTERFACE_NAME
#undef VAR
#undef OVERRIDE
#undef METHODV
#undef METHOD
#undef SIGNALV
#undef SIGNAL

