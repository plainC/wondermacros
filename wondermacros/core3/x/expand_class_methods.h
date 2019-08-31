#define CLASS_NAME(...)
#define INTERFACE_NAME(...)
#define VAR(...)
#define OVERRIDE(C,Name)  { \
    .name = # Name, \
    .func = (void*) W_CAT(C,__,Name), \
},
#define METHODV(C,is_member,T,Name) { \
    .name = # Name, \
    .func = (void*) W_CAT(C,__,Name), \
},
#define METHOD(C,is_member,T,Name,args) { \
    .name = # Name, \
    .func = (void*) W_CAT(C,__,Name), \
},
#define SIGNALV(...)
#define SIGNAL(...)


struct ClassMethod W_CAT(CLASS,__methods)[] = {
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

