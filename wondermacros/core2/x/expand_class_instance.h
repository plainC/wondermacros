/* Determine class kind. */
#ifdef INTERFACE
# define KIND CLASS_KIND_INTERFACE
#else
# ifdef ABSTRACT
#  define KIND CLASS_KIND_ABSTRACT
# else
#   ifdef SINGLETON
#     define KIND CLASS_KIND_SINGLETON
#   else
#     define KIND CLASS_KIND_CLASS
#   endif
# endif
#endif
/**/



/****************************************************************************
 * These do not go into a header.
 */
#ifndef IS_HEADER


/* List of superclasses. */
#define INTERFACE_NAME(...)
#define CLASS_NAME(Name) (Class*) &W_CLASS_INSTANCE_NAME(Name),
#define METHOD_VOID(...)
#define METHOD_WITH_ARGS(...)
#define API_VOID(...)
#define API_WITH_ARGS(...)
#define VAR(...)
#define OVERRIDE(...)
#define SIGNAL(...)
extern struct W_CLASS_STRUCT_NAME(CLASS) W_CLASS_INSTANCE_NAME(CLASS);
static Class* superclasses[] = {
    W_CLASS_EXPAND(CLASS)
    NULL
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
/**/


/* List of interfaces. */
#define INTERFACE_NAME(Name) (Class*) &W_CLASS_INSTANCE_NAME(Name),
#define CLASS_NAME(...)
#define METHOD_VOID(...)
#define METHOD_WITH_ARGS(...)
#define API_VOID(...)
#define API_WITH_ARGS(...)
#define VAR(...)
#define OVERRIDE(...)
#define SIGNAL(...)
static Class* interfaces[] = {
    W_CLASS_EXPAND(CLASS)
    NULL
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
/**/


/* Properties. */
#define INTERFACE_NAME(Name)
#define CLASS_NAME(...)
#define METHOD_VOID(...)
#define METHOD_WITH_ARGS(...)
#define API_VOID(...)
#define API_WITH_ARGS(...)
#define VAR(Type,Name,...) \
    static Property W_CAT(CLASS,__property__,Name) = { \
        .name = W_STRINGIZE(Name), \
        .offset = offsetof(CLASS, Name), \
        .klass = NULL, \
    };
#define OVERRIDE(...)
#define SIGNAL(...)

W_CLASS_EXPAND(CLASS)

#undef INTERFACE_NAME
#undef CLASS_NAME
#undef METHOD_VOID
#undef METHOD_WITH_ARGS
#undef API_VOID
#undef API_WITH_ARGS
#undef VAR
#undef OVERRIDE
#undef SIGNAL
/**/


/* List of properties. */
#define INTERFACE_NAME(Name)
#define CLASS_NAME(...)
#define METHOD_VOID(...)
#define METHOD_WITH_ARGS(...)
#define API_VOID(...)
#define API_WITH_ARGS(...)
#define VAR(Type,Name,...) \
    &W_CAT(CLASS,__property__,Name),
#define OVERRIDE(...)
#define SIGNAL(...)

static Property* properties[] = {
    W_CLASS_EXPAND(CLASS)
    NULL
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
/**/


/* Meta data header. */
static struct w_oo_meta class_meta = {
    .name = W_STRINGIZE(CLASS),
    .size = sizeof(CLASS),
    .superclasses = superclasses,
    .nbr_superclasses = sizeof(superclasses)/sizeof(superclasses[0]) - 1,
    .interfaces = interfaces,
    .properties = properties,
};
/**/

#endif

/*****************************************************************************/



/* Expand class instance. */
#define INTERFACE_NAME(Name) \
    .Name = W_STRINGIZE(Name), \
    /**/
#define CLASS_NAME(Name)
#define METHOD_VOID(Class,RetType,Name)           \
    .Name = (RetType (*)(CLASS*)) W_METHOD_NAME(Class,Name),          \
    /**/
#define METHOD_WITH_ARGS(Class,RetType,Name,Args) \
    .Name = (RetType (*)(CLASS*, BOOST_PP_REMOVE_PARENS(Args))) W_METHOD_NAME(Class,Name),          \
    /**/
#define API_VOID(Interface,RetType,Name) \
    .Name = W_METHOD_NAME(Interface,Name),
#define API_WITH_ARGS(Interface,RetType,Name,Args) \
    .Name = W_METHOD_NAME(Interface,Name),
#define VAR(...)
#define OVERRIDE(Class,Name) \
    .Name = (void*) W_METHOD_NAME(Class,Name), \
    /**/
#define SIGNAL(...)

EXTERN struct W_CLASS_STRUCT_NAME(CLASS) W_CLASS_INSTANCE_NAME(CLASS)
#ifdef IS_HEADER
;
#else
 = {
//    .CLASS = (void*) &W_CLASS_INSTANCE_NAME(NothingMeta),
#ifndef INTERFACE
    ._meta = (void*) &class_meta,
    ._ifmap = W_CAT(CLASS,__ifmap),
#ifdef HAS_CONSTRUCTOR
    ._construct = W_CAT(CLASS,___construct),
#endif /* HAS_CONSTRUCTOR */
#endif /* INTERFACE */
   // .free = (void (*)(void* self)) W_CAT(CLASS,__free),
    W_CLASS_EXPAND(CLASS)
};
#endif /* IS_HEADER */


#undef CLASS_NAME
#undef INTERFACE_NAME
#undef METHOD_VOID
#undef METHOD_WITH_ARGS
#undef API_VOID
#undef API_WITH_ARGS
#undef VAR
#undef OVERRIDE
#undef SIGNAL
#undef KIND
/**/

