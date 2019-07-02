#define METHOD_VOID(Interface,Scope,RetType,Name)
#define METHOD_WITH_ARGS(Interface,Scope,RetType,Name,Args)

#define INTERFACE_NAME(Interface)                           \
    struct W_CAT(CLASS,__,Interface,_FatPtr) {              \
        CLASS* obj;                                         \
        struct W_CAT(Interface,__class)* klass;             \
    };                                                      \
    typedef struct W_CAT(CLASS,__,Interface,_FatPtr)        \
        W_CAT(CLASS,__,Interface,_FatPtr);                  \
    /**/

#define CLASS_NAME(...)
#define VAR(...)
#define OVERRIDE(...)


/* Expand fat pointer interfaces. */
W_CLASS_EXPAND(CLASS)


#undef INTERFACE_NAME
#undef CLASS_NAME
#undef METHOD_VOID
#undef METHOD_WITH_ARGS
#undef VAR
#undef OVERRIDE
