#define METHOD_VOID(C,RetType,Name)                             \
    RetType W_CAT(CLASS,__,Name)(CLASS* self);
#define METHOD_WITH_ARGS(C,RetType,Name,Args)                   \
    RetType W_CAT(CLASS,__,Name)(CLASS* self, BOOST_PP_REMOVE_PARENS(Args));

#define INTERFACE_NAME(Name)
#define CLASS_NAME(...)
#define VAR(...)
#define OVERRIDE(...)


/* Expand methods. */
W_CLASS_EXPAND(CLASS)


#undef METHOD_VOID
#undef METHOD_WITH_ARGS
#undef INTERFACE_NAME
#undef OVERRIDE
#undef CLASS_NAME
#undef VAR


/* Forward declare constructor and destructor. */
#ifdef HAS_CONSTRUCTOR
    void W_METHOD_NAME(CLASS,_construct)(CLASS* self);
#endif
#ifdef HAS_DESTRUCTOR
    void W_METHOD_NAME(CLASS,_destruct)(CLASS* self);
#endif

