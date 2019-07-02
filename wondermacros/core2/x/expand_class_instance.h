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
#ifndef IS_HEADER

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
#define METHOD_VOID(Class,RetType,Name)           \
    .Name = (void*) W_METHOD_NAME(Class,Name),          \
    /**/
#define METHOD_WITH_ARGS(Class,RetType,Name,Args) \
    .Name = (void*) W_METHOD_NAME(Class,Name),          \
    /**/
#define VAR(...)
#define OVERRIDE(Class,Name) \
    .Name = (void*) W_METHOD_NAME(Class,Name), \
    /**/

EXTERN struct W_CLASS_STRUCT_NAME(CLASS) W_CLASS_INSTANCE_NAME(CLASS)
#ifdef IS_HEADER
;
#else
 = {
    .klass = (void*) &W_CLASS_INSTANCE_NAME(NothingMeta),
    W_CLASS_EXPAND(CLASS)
};
#endif /* IS_HEADER */


#undef CLASS_NAME
#undef INTERFACE_NAME
#undef METHOD_VOID
#undef METHOD_WITH_ARGS
#undef VAR
#undef OVERRIDE
#undef KIND
/**/

