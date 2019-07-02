#define METHOD_VOID(C,RetType,Name)                             \
    RetType (*Name)(CLASS* self);
#define METHOD_WITH_ARGS(C,RetType,Name,Args)                   \
    RetType (*Name)(CLASS* self, BOOST_PP_REMOVE_PARENS(Args));

#define API_VOID(C,RetType,Name)                             \
    RetType (*Name)(W_CAT(C,FatPtr) self);
#define API_WITH_ARGS(C,RetType,Name,Args)                   \
    RetType (*Name)(W_CAT(C,FatPtr) self, BOOST_PP_REMOVE_PARENS(Args));


#define INTERFACE_NAME(Name)                                    \
    struct W_CLASS_STRUCT_NAME(Name)* Name;                            \
    struct oo_class_meta* W_CAT(Name,__meta);                  \

#define CLASS_NAME(Name) \
    Class* Name; \
    struct w_oo_meta* W_CAT(Name,__meta);
#define VAR(...)
#define OVERRIDE(...)
#define SIGNAL(...)


/* Expand class struct. */
struct CLASS;
typedef struct CLASS CLASS;
struct W_CAT(CLASS,__class) {
    W_CLASS_EXPAND(CLASS)
};


/* Expand typedef class struct. */
#ifdef W_CLASS_TYPEDEF
# ifdef IS_HEADER
typedef struct W_CLASS_STRUCT_NAME(CLASS) W_CLASS_STRUCT_NAME(CLASS);
# endif
#endif


#undef METHOD_VOID
#undef METHOD_WITH_ARGS
#undef API_VOID
#undef API_WITH_ARGS

#undef INTERFACE_NAME
#undef OVERRIDE
#undef CLASS_NAME
#undef VAR
#undef SIGNAL
