#define INTERFACE_NAME(Name)
#define CLASS_NAME(Name)
#define METHOD_VOID(Class,Scope,RetType,Name)           \
    .Name = (void*) W_METHOD_NAME(Class,Name),          \
    /**/
#define METHOD_WITH_ARGS(Class,Scope,RetType,Name,Args) \
    .Name = (void*) W_METHOD_NAME(Class,Name),          \
    /**/
#define VAR(...)

#ifdef INTERFACE
# define KIND CLASS_KIND_INTERFACE
#else
# ifdef ABSTRACT
#  define KIND CLASS_KIND_ABSTRACT
# else
#  define KIND CLASS_KIND_CLASS
# endif
#endif

#if W_IS_PUBLIC
extern
#endif
struct W_CLASS_STRUCT_NAME(CLASS) W_CLASS_INSTANCE_NAME(CLASS)
#if W_IS_PUBLIC
;
#else
 = {
    .klass = &W_CLASS_INSTANCE_NAME(ObjectMeta),
    .name = W_STRINGIZE(CLASS),
    .kind = KIND,
    .instance_size = sizeof(struct W_CLASS_STRUCT_NAME(CLASS)),
    W_CLASS_EXPAND(CLASS)
};
#endif


#undef CLASS_NAME
#undef INTERFACE_NAME
#undef METHOD_VOID
#undef METHOD_WITH_ARGS
#undef VAR

