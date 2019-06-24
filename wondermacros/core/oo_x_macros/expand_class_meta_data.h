/*
 **************************** Expand superclasses
 */

#define INTERFACE_NAME(Name)
#define CLASS_NAME(Name) &W_CLASS_INSTANCE_NAME(Name),
#define METHOD_VOID(...)
#define METHOD_WITH_ARGS(...)
#define VAR(...)

#if W_IS_PUBLIC == 0
static struct W_CLASS_STRUCT_NAME(Object)* W_CAT(__meta_superclass__,CLASS)[] = {
    W_CLASS_EXPAND(CLASS)
    NULL
};
#endif

#undef INTERFACE_NAME
#undef CLASS_NAME
#undef METHOD_VOID
#undef METHOD_WITH_ARGS
#undef VAR
