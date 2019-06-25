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
#if W_IS_PUBLIC == 0

#define INTERFACE_NAME(...)
#define CLASS_NAME(Name) (void*) &W_CLASS_INSTANCE_NAME(CLASS),
#define METHOD_VOID(...)
#define METHOD_WITH_ARGS(...)
#define VAR(...)
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

#if W_IS_PUBLIC
extern
#endif
struct W_CLASS_STRUCT_NAME(CLASS) W_CLASS_INSTANCE_NAME(CLASS)
#if W_IS_PUBLIC
;
#else
 = {
    .klass = &W_CLASS_INSTANCE_NAME(NothingMeta),
    .name = W_STRINGIZE(CLASS),
    .kind = KIND,
    .superclasses = (void*) &superclasses,
    W_CLASS_EXPAND(CLASS)
};
#endif

#undef CLASS_NAME
#undef INTERFACE_NAME
#undef METHOD_VOID
#undef METHOD_WITH_ARGS
#undef VAR
/**/

