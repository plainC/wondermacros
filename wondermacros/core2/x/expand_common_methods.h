#define METHOD_VOID(Interface,RetType,Name) 
#define METHOD_WITH_ARGS(Interface,RetType,Name,Args) 
#define INTERFACE_NAME(Name)
#define CLASS_NAME(...)
#define VAR(...)
#define OVERRIDE(...)


#define W_OO_FOREACH_SUPERCLASS(klass,Klass) for (Class* klass; 0; )

//#ifndef INTERFACE

struct W_CLASS_STRUCT_NAME(CLASS);
typedef struct W_CLASS_STRUCT_NAME(CLASS) W_CLASS_STRUCT_NAME(CLASS);
extern struct W_CLASS_STRUCT_NAME(CLASS) W_CLASS_INSTANCE_NAME(CLASS);

/* Expand New method. */
CLASS*
W_CAT(CLASS,__new)()
#ifdef IS_HEADER
;
#else
{
    CLASS* self = malloc(sizeof(CLASS));
    self->klass = (void*) &W_CLASS_INSTANCE_NAME(CLASS);

    /* Call constructors. */
    W_OO_FOREACH_SUPERCLASS(klass, self->klass) {
     //   if (klass->constructor)
     //       klass->constructor((Nothing*) self);
    }
    return self;
}
#endif

/* Expand clone method. */
Nothing*
W_CAT(CLASS,__clone)(CLASS* other)
#ifdef IS_HEADER
;
#else
{
    CLASS* self = malloc(sizeof(CLASS));
    *self = *other;
    self->klass = (void*) &W_CLASS_INSTANCE_NAME(CLASS);
    /* Call constructors. */
    W_OO_FOREACH_SUPERCLASS(klass,self->klass) {
     //   if (klass->constructor)
     //       klass->constructor((Nothing*) self);
    }
    return (Nothing*) self;
}
#endif

//#endif /* INTERFACE */

#undef INTERFACE_NAME
#undef CLASS_NAME
#undef METHOD_VOID
#undef METHOD_WITH_ARGS
#undef VAR
#undef OVERRIDE


