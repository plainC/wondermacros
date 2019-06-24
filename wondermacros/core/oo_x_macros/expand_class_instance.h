#define INTERFACE_NAME(Name)
#define CLASS_NAME(Name)
#define METHOD_VOID(Class,Scope,RetType,Name)           \
    .Name = (void*) W_CAT(Class,__,Name),               \
    /**/
#define METHOD_WITH_ARGS(Class,Scope,RetType,Name,Args) \
    .Name = (void*) W_CAT(Class,__,Name),               \
    /**/
#define VAR(...)


struct W_CLASS_STRUCT_NAME(CLASS) W_CLASS_INSTANCE_NAME(CLASS) = {
    W_CLASS_EXPAND(CLASS)
};


#undef CLASS_NAME
#undef INTERFACE_NAME
#undef METHOD_VOID
#undef METHOD_WITH_ARGS
#undef VAR

