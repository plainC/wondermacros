#define CLASS_NAME(Name)                    \
    .name = # Name,
#define INTERFACE_NAME(...)
#define VAR(...)
#define OVERRIDE(C,Name)                    \
    METHODV(C,/*empty*/,/*empty*/,Name)
#define METHODV(C,is_member,type,Name)      \
    METHOD(C,is_member,type,Name,/*empty*/)
#define METHOD(C,is_member,type,Name,args)  \
    .Name = W_CAT(C,__,Name),
#define SIGNALV(...)
#define SIGNAL(...)


struct W_CAT(CLASS,__class) W_CAT(CLASS,__class_instance) = {
    W_CAT_OUTER(CLASS,__define)
    .free = W_CAT(CLASS,__free)
};

#undef CLASS_NAME
#undef INTERFACE_NAME
#undef VAR
#undef OVERRIDE
#undef METHODV
#undef METHOD
#undef SIGNALV
#undef SIGNAL

