#define W_FOR_EACH_SUPERCLASS(k,Klass) \
    W_DECLARE(1, Class* k) \
    for (int W_ID(i)=0; (k = (Klass)->_meta->superclasses[W_ID(i)]); ++W_ID(i) )


#define W_FOR_EACH_SUPERCLASS_REVERSED(k,Klass) \
    W_DECLARE(1, Class* k) \
    for (int W_ID(i)=(Klass)->_meta->nbr_superclasses-1; W_ID(i) >= 0 && (k = (Klass)->_meta->superclasses[W_ID(i)]); --W_ID(i) )


#ifndef INTERFACE

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
    W_FOR_EACH_SUPERCLASS(k, self->klass) {
        if (k->_construct)
            k->_construct((void*) self);
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
    W_FOR_EACH_SUPERCLASS(k, self->klass) {
        if (k->_construct)
            k->_construct((void*) self);
    }

    return (Nothing*) self;
}
#endif

/* Expand to_json method. */
int
W_CAT(CLASS,__to_json)(CLASS* self, IWriter* writer, void* context)
#ifdef IS_HEADER
;
#else
{
    Property* prop;
    int count=0;
    W_ICALL(IWriter,writer,put)('{');

#define METHOD_VOID(Interface,RetType,Name) 
#define METHOD_WITH_ARGS(Interface,RetType,Name,Args)
#define API_WITH_ARGS(...)
#define API_VOID(...)
#define INTERFACE_NAME(Name)
#define CLASS_NAME(...)
#define SIMPLE(T) T
#define VAR(T,...) BOOST_PP_OVERLOAD(_VAR_,__VA_ARGS__)(T,__VA_ARGS__)
#define _VAR_1(T,Name) \
    if (count++) \
        W_ICALL(IWriter,writer,put)(','); \
    W_ICALL(IWriter,writer,put)('\"'); \
    W_ICALL(IWriter,writer,append)(W_STRINGIZE(Name), sizeof(W_STRINGIZE(Name))-1); \
    W_ICALL(IWriter,writer,append)("\":",2); \
    T ## __class_instance.to_json(W_REF_VOID_PTR(self, prop->offset), writer, context);
#define _VAR_2(T,Name,Spec) \
    extern Class W_CAT(Spec,__class_instance); \
    if (count++) \
        W_ICALL(IWriter,writer,put)(','); \
    W_ICALL(IWriter,writer,put)('\"'); \
    W_ICALL(IWriter,writer,append)(W_STRINGIZE(Name), sizeof(W_STRINGIZE(Name))-1); \
    W_ICALL(IWriter,writer,append)("\":",2); \
    W_CAT(Spec,__class_instance).to_json(W_REF_VOID_PTR(self, offsetof(CLASS,Name)), writer, context);

#define OVERRIDE(...)
#define SIGNAL(...)

    W_CLASS_EXPAND(CLASS)

#undef SIMPLE
#undef _VAR_1
#undef _VAR_2
#undef INTERFACE_NAME
#undef CLASS_NAME
#undef METHOD_VOID
#undef METHOD_WITH_ARGS
#undef API_WITH_ARGS
#undef API_VOID
#undef VAR
#undef OVERRIDE
#undef SIGNAL

    W_ICALL(IWriter,writer,put)('}');
}
#endif

/* Expand free method. */
void
W_CAT(CLASS,__free)(CLASS* self)
#ifdef IS_HEADER
;
#else
{
#define METHOD_VOID(Interface,RetType,Name) 
#define METHOD_WITH_ARGS(Interface,RetType,Name,Args)
#define API_WITH_ARGS(...)
#define API_VOID(...)
#define INTERFACE_NAME(Name)
#define CLASS_NAME(...)
#define VAR(...)
#define OVERRIDE(...)
#define SIGNAL(name,...) w_oo_signal_disconnect_all(&self->name);

    W_CLASS_EXPAND(CLASS)

#undef INTERFACE_NAME
#undef CLASS_NAME
#undef METHOD_VOID
#undef METHOD_WITH_ARGS
#undef API_WITH_ARGS
#undef API_VOID
#undef VAR
#undef OVERRIDE
#undef SIGNAL

    W_FOR_EACH_SUPERCLASS_REVERSED(k, self->klass) {
        if (k->_destruct)
            k->_destruct((void*) self);
    }

    free(self);
}
#endif

#endif /* INTERFACE */

/* Expand ifmap method. */
#define METHOD_VOID(Interface,RetType,Name) 
#define METHOD_WITH_ARGS(Interface,RetType,Name,Args)
#define API_WITH_ARGS(...)
#define API_VOID(...)
#define INTERFACE_NAME(Name) \
    case W_PP_CHARSEQ_TO_COMPACT_UINT(uint64_t, W_CAT(Name,__name)): \
        return __COUNTER__ - start;
#define CLASS_NAME(...)
#define VAR(...)
#define OVERRIDE(...)
#define SIGNAL(...)

int
W_CAT(CLASS,__ifmap)(uint64_t interface)
#ifdef IS_HEADER
;
#else
{
    const int start = __COUNTER__ + 1;
    switch (interface) {
    W_CLASS_EXPAND(CLASS)
    default:
        return -1;
    }
}
#endif

#undef INTERFACE_NAME
#undef CLASS_NAME
#undef METHOD_VOID
#undef METHOD_WITH_ARGS
#undef API_WITH_ARGS
#undef API_VOID
#undef VAR
#undef OVERRIDE
#undef SIGNAL

//#endif /* INTERFACE */

