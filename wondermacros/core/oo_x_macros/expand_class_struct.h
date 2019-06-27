#define METHOD_VOID(Interface,Scope,RetType,Name) \
    RetType (*Name)(CLASS* self);
#define METHOD_WITH_ARGS(Interface,Scope,RetType,Name,Args) \
    RetType (*Name)(CLASS* self, BOOST_PP_REMOVE_PARENS(Args));

#define INTERFACE_NAME(Name) \
    struct NothingMeta__class* Name; \
    const char* W_CAT(Name,__name);                               \
    enum ClassKind W_CAT(Name,__kind);                            \
    Class** W_CAT(Name,__superclasses);                           \
  size_t W_CAT(Name,__instance_size); \
  void (*W_CAT(Name,__constructor)) (ITest * self); \
  void (*W_CAT(Name,__destructor)) (ITest * self); \

#define CLASS_NAME(...)
#define VAR(...)

/* Expand class struct. */
struct W_CAT(CLASS,__class) {
#ifndef INTERFACE
    NothingMeta__define
    size_t instance_size;
    void (*constructor)(CLASS* self);
    void (*destructor)(CLASS* self);
#endif
    W_CLASS_EXPAND(CLASS)
};


/* Expand typedef class struct. */
#ifdef W_CLASS_TYPEDEF
# if IS_HEADER
typedef struct W_CLASS_STRUCT_NAME(CLASS) W_CLASS_STRUCT_NAME(CLASS);
# endif
#endif


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

