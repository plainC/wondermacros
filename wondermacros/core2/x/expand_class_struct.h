#define METHOD_VOID(C,RetType,Name)                             \
    RetType (*Name)(CLASS* self);
#define METHOD_WITH_ARGS(C,RetType,Name,Args)                   \
    RetType (*Name)(CLASS* self, BOOST_PP_REMOVE_PARENS(Args));

#define INTERFACE_NAME(Name)                                    \
    struct NothingMeta__class* Name;                            \
    struct oo_class_meta* W_CAT(Name,__meta);                  \
    void (*W_CAT(Name,__constructor)) (ITest * self);           \
    void (*W_CAT(Name,__destructor)) (ITest * self);            \

#define CLASS_NAME(...)
#define VAR(...)
#define OVERRIDE(...)


/* Expand class struct. */
struct CLASS;
typedef struct CLASS CLASS;
struct W_CAT(CLASS,__class) {
    Class* klass;
    struct w_oo_meta* _meta;
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
#undef INTERFACE_NAME
#undef OVERRIDE
#undef CLASS_NAME
#undef VAR

