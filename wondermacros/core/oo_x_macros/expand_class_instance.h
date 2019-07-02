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

/* List superclasses. */
#if IS_HEADER == 0

#define INTERFACE_NAME(...)
#define CLASS_NAME(Name) (Class*) &W_CLASS_INSTANCE_NAME(Name),
#define METHOD_VOID(...)
#define METHOD_WITH_ARGS(...)
#define VAR(...)
#define OVERRIDE(...)
extern struct W_CLASS_STRUCT_NAME(CLASS) W_CLASS_INSTANCE_NAME(CLASS);
static Class* superclasses[] = {
    W_CLASS_EXPAND(CLASS)
    NULL
};
#undef INTERFACE_NAME
#undef CLASS_NAME
#undef METHOD_VOID
#undef METHOD_WITH_ARGS
#undef VAR
#undef OVERRIDE

#endif
/**/


/* Expand class instance. */
#define INTERFACE_NAME(Name)
#define CLASS_NAME(Name)
#define METHOD_VOID(Class,Scope,RetType,Name)           \
    .Name = (void*) W_METHOD_NAME(Class,Name),          \
    /**/
#define METHOD_WITH_ARGS(Class,Scope,RetType,Name,Args) \
    .Name = (void*) W_METHOD_NAME(Class,Name),          \
    /**/
#define VAR(...)
#define OVERRIDE(Class,Name) \
    .Name = W_METHOD_NAME(Class,Name), \
    /**/

EXTERN struct W_CLASS_STRUCT_NAME(CLASS) W_CLASS_INSTANCE_NAME(CLASS)
#if IS_HEADER
;
#else
 = {
#ifdef INTERFACE
    .CLASS = &W_CLASS_INSTANCE_NAME(NothingMeta),
#else
    .klass = &W_CLASS_INSTANCE_NAME(NothingMeta),
    .name = W_STRINGIZE(CLASS),
    .kind = KIND,
    .superclasses = superclasses,
#ifdef HAS_CONSTRUCTOR
    .constructor = (void*) W_METHOD_NAME(CLASS,_construct),
#endif
#ifdef HAS_DESTRUCTOR
    .destructor = (void*) W_METHOD_NAME(CLASS,_destruct),
#endif
#endif
    W_CLASS_EXPAND(CLASS)
};
#endif /* IS_HEADER */


#undef CLASS_NAME
#undef INTERFACE_NAME
#undef METHOD_VOID
#undef METHOD_WITH_ARGS
#undef VAR
#undef OVERRIDE
/**/

