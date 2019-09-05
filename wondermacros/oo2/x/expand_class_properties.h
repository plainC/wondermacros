#define CLASS_NAME(...)
#define INTERFACE_NAME(...)
#define VAR(Name,T,Dims,Class,...) { \
    .name = # Name, \
    .offset = offsetof(CLASS,Name), \
    .klass = (void*) Class \
},
#define OVERRIDE(...)
#define METHODV(...)
#define METHOD(...)
#define SIGNALV(...)
#define SIGNAL(...)


struct ClassProperty W_CAT(CLASS,__properties)[] = {
    W_CAT_OUTER(CLASS,__define)
    {.name = NULL}
};

#undef CLASS_NAME
#undef INTERFACE_NAME
#undef VAR
#undef OVERRIDE
#undef METHODV
#undef METHOD
#undef SIGNALV
#undef SIGNAL

