#define METHOD_VOID(Interface,Scope,RetType,Name) \
    RetType (*Name)();
#define METHOD_WITH_ARGS(Interface,Scope,RetType,Name,Args) \
    RetType (*Name)Args;

#define INTERFACE_NAME(Name)                      \
    W_OO_CLASS(Name);
#define CLASS_NAME(...)
#define VAR(...)

struct W_CLASS_STRUCT_NAME(CLASS) {
    ObjectMeta__define
    W_CLASS_EXPAND(CLASS)
};


#ifdef W_CLASS_TYPEDEF
# if W_IS_PUBLIC
typedef struct W_CLASS_STRUCT_NAME(CLASS) W_CLASS_STRUCT_NAME(CLASS);
# endif
#endif


#undef INTERFACE_NAME
#undef CLASS_NAME
#undef METHOD_VOID
#undef METHOD_WITH_ARGS
#undef VAR

