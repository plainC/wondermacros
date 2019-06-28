#define METHOD_VOID(Interface,Scope,RetType,Name) 
#define METHOD_WITH_ARGS(Interface,Scope,RetType,Name,Args) 
#define INTERFACE_NAME(Name)
#define CLASS_NAME(...)
#define VAR(...)


#ifndef INTERFACE

#ifndef __NOTHING_CLASS
#define __NOTHING_CLASS

//FIXME: Clean up
struct __Nothing__class
{
  struct NothingMeta__class *klass;
  const char *name;
  enum ClassKind kind;
  Class **superclasses;
  size_t instance_size;
  void (*constructor) (Nothing* self);
  void (*destructor) (Nothing* self);
};

#endif

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

    /* Call constructors. */
    struct __Nothing__class* klass = (void*) self->klass->superclasses[0];
    for (int i=0; klass; klass = (void*) self->klass->superclasses[++i]) {
        if (klass->constructor)
            klass->constructor((Nothing*) self);
    }
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

