#define METHOD_VOID(Interface,Scope,RetType,Name) 
#define METHOD_WITH_ARGS(Interface,Scope,RetType,Name,Args) 
#define INTERFACE_NAME(Name)
#define CLASS_NAME(...)
#define VAR(...)


#ifndef INTERFACE

/* Expand New method. */
#if IS_HEADER
CLASS*
W_CAT(CLASS,__private__new)();
#else
CLASS*
W_CAT(CLASS,__new)()
{
    CLASS* self = malloc(sizeof(CLASS));
    self->klass = (void*) &W_CLASS_INSTANCE_NAME(CLASS);
    if (self->klass->constructor)
        self->klass->constructor(self);
    return self;
}
#endif


/* Expand clone method. */
#if IS_HEADER
Nothing*
W_CAT(CLASS,__private__clone)(CLASS* other);
#else
Nothing*
W_CAT(CLASS,__clone)(CLASS* other)
{
    CLASS* self = malloc(sizeof(CLASS));
    *self = *other;
    self->klass = (void*) &W_CLASS_INSTANCE_NAME(CLASS);
    if (self->klass->constructor)
        self->klass->constructor(self);
    return (Nothing*) self;
}
#endif

#endif /* INTERFACE */

#undef INTERFACE_NAME
#undef CLASS_NAME
#undef METHOD_VOID
#undef METHOD_WITH_ARGS
#undef VAR

