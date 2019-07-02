#define INTERFACE_NAME(Name)
#define CLASS_NAME(Name)
#define METHOD_VOID(Class,RetType,Name)
#define METHOD_WITH_ARGS(Class,RetType,Name,Args)
#define VAR(Type,Name,...) Type Name;
#define OVERRIDE(...)

struct CLASS {
    struct W_CLASS_STRUCT_NAME(CLASS)* klass;
    W_CLASS_EXPAND(CLASS)
};

#undef INTERFACE_NAME
#undef CLASS_NAME
#undef METHOD_VOID
#undef METHOD_WITH_ARGS
#undef VAR
#undef OVERRIDE

