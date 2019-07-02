#define INTERFACE_NAME(Name)
#define CLASS_NAME(Name)
#define METHOD_VOID(Class,RetType,Name)
#define METHOD_WITH_ARGS(Class,RetType,Name,Args)
#define API_VOID(...)
#define API_WITH_ARGS(...)
#define VAR(Type,Name,...) Type Name;
#define OVERRIDE(...)
#define SIGNAL(Name,Args) Signal* Name;

struct CLASS {
    struct W_CLASS_STRUCT_NAME(CLASS)* klass;
    W_CLASS_EXPAND(CLASS)
};

#undef INTERFACE_NAME
#undef CLASS_NAME
#undef METHOD_VOID
#undef METHOD_WITH_ARGS
#undef API_VOID
#undef API_WITH_ARGS
#undef VAR
#undef OVERRIDE
#undef SIGNAL
