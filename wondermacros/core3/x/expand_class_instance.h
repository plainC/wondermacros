#define CLASS_NAME(Name)                    \
    .name = # Name,
#define INTERFACE_NAME(...)
#define VAR(...)
#define OVERRIDE(C,Name)                    \
    METHODV(C,/*empty*/,/*empty*/,Name)
#define METHODV(C,is_member,type,Name)      \
    METHOD(C,is_member,type,Name,/*empty*/)
#define METHOD(C,is_member,type,Name,args)  \
    .Name = (void*) W_CAT(C,__,Name),
#define SIGNALV(...)
#define SIGNAL(...)


struct W_CAT(CLASS,__class) W_CAT(CLASS,__class_instance) = {
    .properties = W_CAT(CLASS,__properties),
    .methods = W_CAT(CLASS,__methods),
    .construct = W_CAT(CLASS,__construct),
    ._new = W_CAT(CLASS,__new),
    .free = W_CAT(CLASS,__free),
    W_CAT_OUTER(CLASS,__define)
};

#undef CLASS_NAME
#undef INTERFACE_NAME
#undef VAR
#undef OVERRIDE
#undef METHODV
#undef METHOD
#undef SIGNALV
#undef SIGNAL

