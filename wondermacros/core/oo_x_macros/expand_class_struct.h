#define METHOD_VOID(Interface,Scope,RetType,Name) \
    RetType (*Name)(CLASS* self);
#define METHOD_WITH_ARGS(Interface,Scope,RetType,Name,Args) \
    RetType (*Name)(CLASS* self, BOOST_PP_REMOVE_PARENS(Args));

#define INTERFACE_NAME(...)
#define CLASS_NAME(...)
#define VAR(...)

/* Expand class struct. */
struct W_CAT(CLASS,__class) {
    NothingMeta__define
    size_t instance_size;
    void (*constructor)(CLASS* self);
    void (*destructor)(CLASS* self);
    W_CLASS_EXPAND(CLASS)
};


/* Expand typedef class struct. */
#ifdef W_CLASS_TYPEDEF
# if IS_HEADER
typedef struct W_CLASS_STRUCT_NAME(CLASS) W_CLASS_STRUCT_NAME(CLASS);
# endif
#endif


/* Expand fat pointer. */
struct W_CAT(CLASS,FatPtr) {
    Nothing* obj;
    size_t offset;
};
typedef struct W_CAT(CLASS,FatPtr) W_CAT(CLASS,FatPtr);



/* Expand forward declarations of methods. */
#undef METHOD_VOID
#undef METHOD_WITH_ARGS
#undef INTERFACE_NAME

#define INTERFACE_NAME(...)
#define METHOD_VOID(Interface,Scope,RetType,Name) \
    RetType W_METHOD_NAME(CLASS,Name)(CLASS* self);
#define METHOD_WITH_ARGS(Interface,Scope,RetType,Name,Args) \
    RetType W_METHOD_NAME(CLASS,Name)(CLASS* self, BOOST_PP_REMOVE_PARENS(Args));

W_CLASS_EXPAND(CLASS)


#undef INTERFACE_NAME
#undef CLASS_NAME
#undef METHOD_VOID
#undef METHOD_WITH_ARGS
#undef VAR

