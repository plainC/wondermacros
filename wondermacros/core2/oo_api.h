#ifndef __W_OO_API_H
#define __W_OO_API_H

#include <wondermacros/meta/cat.h>
#include <wondermacros/meta/cat_outer.h>
#include <wondermacros/meta/stringize.h>
#include <wondermacros/meta/declare.h>
#include <wondermacros/meta/id.h>
#include <wondermacros/pointer/ref_void_ptr.h>
#include <wondermacros/list/cslist.h>

#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/control/expr_if.hpp>
#include <boost/preprocessor/facilities/overload.hpp>
#include <boost/preprocessor/punctuation/remove_parens.hpp>
#include <boost/preprocessor/variadic/elem.hpp>
#include <boost/preprocessor/comparison/equal.hpp>


#ifndef WDEBUG_EXPAND
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>
#endif
# include <wondermacros/pp_char/charseq.h>


/*
 * Names
 */
#define W_INSTANCE_STRUCT_NAME(Class)     \
    Class                                 \
    /**/
#define W_CLASS_STRUCT_NAME(Class)        \
    W_CAT(Class,__class)                  \
    /**/
#define W_CLASS_INSTANCE_NAME(Class)      \
    W_CAT(Class,__class_instance)         \
    /**/
#define W_OBJ_CONSTRUCTOR_NAME            \
    _new_with                             \
    /**/
#define W_OBJ_DESTRUCTOR_NAME             \
    _finalize                             \
    /**/
#define W_OBJ_USER_CONSTRUCTOR_NAME       \
    __construct                           \
    /**/
#define W_OBJ_USER_DESTRUCTOR_NAME        \
    finalize                              \
    /**/
#define W_CLASS_EXPAND(Class)             \
    W_CAT_OUTER(CLASS,__define)           \
    /**/
#define W_METHOD_NAME(Class,Name)         \
    W_CAT(Class,__,Name)                  \
    /**/


/* O-O Data Structures. */
struct w_oo_meta;
struct Nothing;
typedef struct Nothing Nothing;
struct IWriter;
typedef struct IWriter IWriter;

#define W_OO_CLASS_FIELDS(T)              \
    struct w_oo_meta* _meta;              \
    void (*_new)();                       \
    void (*_clone)(T* self);              \
    void (*_construct)(T* self);          \
    void (*_destruct)(T* self);           \
    void (*_equal)(T* self, T* other);    \
    int (*_ifmap)(uint64_t i); \
    void (*free)(T* self);                 \
    int (*to_json)(T* self, IWriter* writer, void* context) \
    /**/

struct Class {
    W_OO_CLASS_FIELDS(struct Class);
};

typedef struct Class Class;

enum ClassKind {
    CLASS_KIND_NONE,
    CLASS_KIND_META,
    CLASS_KIND_ABSTRACT,
    CLASS_KIND_CLASS,
    CLASS_KIND_INTERFACE,
    CLASS_KIND_SINGLETON,
};

struct w_oo_signal {
    void (*func)(Nothing* self, void* context, ...);
    void (*context_free_func)(void* context);
    void* context;
    struct w_oo_signal* next;
};
typedef struct w_oo_signal Signal;

struct w_oo_property {
    const char* name;
    Class* klass;
    size_t offset;
};

typedef struct w_oo_property Property;

struct w_oo_reference {
    Property* property;
    Nothing* object;
};

typedef struct w_oo_reference PropertyRef;

/* Each class has some meta data. */
struct w_oo_meta {
    const char* name;
    size_t size;
    Class** superclasses;
    Class** interfaces;
    size_t nbr_superclasses;
    Property** properties;
};

static inline void
w_oo_signal_connect(
        Signal** slot,
        void (*func)(Nothing* self,void* context, ...),
        void* context,
        void (*free_func)(void* context))
{
    Signal* s = malloc(sizeof(Signal));

    s->func = func;
    s->context_free_func = free_func;
    s->context = context;
    if (*slot)
        s->next = *slot;
    else
        s->next = s;

    W_CSLIST_PREPEND(Signal, *slot, s);
}

static inline void
w_oo_signal_disconnect_all(Signal** slot)
{
    W_CSLIST_FOR_EACH(Signal, s, *slot) {
        if (s->context_free_func)
            s->context_free_func(s->context);
        free(s);
    }
}

/*
 * Object creation, casts and assignments.
 */

#define W_PP_IS_UNARY(...) \
    BOOST_PP_EQUAL(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), 1)


/***
 *** Name:        W_NEW
 *** Proto:       W_NEW(T [,...])
 *** Arg:         T     a class name
 *** Arg:         ...   values to be set (e.g. W_NEW(point, .x=1, .y=2))
 *** Description: Use W_NEW to create (and to initialize) an object.
 ***/
#define W_NEW(...) (                                                             \
    ((void*) BOOST_PP_IF(W_PP_IS_UNARY(__VA_ARGS__),                             \
        W_CAT(BOOST_PP_VARIADIC_ELEM(0,__VA_ARGS__),__new)(),                    \
        _W_NEW(__VA_ARGS__)                                                      \
    )                                                                            \
)
#define _W_NEW(T,...)                                                            \
    ((void*) W_CAT(T,__clone)(&((struct W_CAT(T)){__VA_ARGS__}))))


#define W_OBJ_NEW(Class,Json)
#define W_OBJECT_AS(Object,Class)
#define W_FAT_PTR_GET(Object,Interface) { \
    .obj = (Interface*)(Object), \
    .klass = (W_CLASS_STRUCT_NAME(Interface)*) &((Object)->klass->Interface) \
}

#define W_FAT_PTR_LOOKUP(Object,Interface) { \
    .obj = (void*)(Object), \
    .klass = (void*) w_oo_lookup_interface((Class*) ((Object)->klass), Interface) \
}

/*
 * Member function calls and signaling.
 */

/***
 *** Name:        W_CALL
 *** Proto:       W_CALL(self,method)(...)
 *** Arg:         self     an object (an instance of a class)
 *** Arg:         method   a method name to be called
 *** Arg:         ...      arguments for the methods
 *** Description: Use W_CALL to call a method of an object with arguments. The macro will expand self automatically as the first argument of the argument list in the method call.
 ***/
#ifndef WDEBUG_EXPAND

#define W_CALL(o,method) \
    (((o)->klass->method) ((void*)(o), W_CALL_CLOSE
#define W_CALL_CLOSE(...) __VA_ARGS__))

#define W_CALLV(o,method) \
    (((o)->klass->method)((void*)(o)))

#define W_ICALLV(Interface,Obj,Method)    \
    (((struct W_CAT(Interface,__class)*)  \
        w_oo_lookup_interface_checked(    \
            (Class*) ((Obj)->klass),      \
            W_PP_CHARSEQ_TO_COMPACT_UINT(uint64_t, W_CAT(Interface,__name))))->Method(Obj))

#define W_ICALL(Interface,Obj,Method)     \
    (((struct W_CAT(Interface,__class)*)  \
        w_oo_lookup_interface_checked(    \
            (Class*) ((Obj)->klass),      \
            W_PP_CHARSEQ_TO_COMPACT_UINT(uint64_t, W_CAT(Interface,__name))))->Method((Obj), W_CALL_CLOSE

#endif /* WDEBUG_EXPAND */

#define W_CONNECT(Object,SigName,...) \
    BOOST_PP_OVERLOAD(_W_CONNECT_,__VA_ARGS__)(Object,SigName,__VA_ARGS__)

#define _W_CONNECT_1(Object,SigName,Func) \
    w_oo_signal_connect(&(Object)->SigName, (void*) Func, NULL, NULL)
#define _W_CONNECT_2(Object,SigName,Func,Context) \
    w_oo_signal_connect(&(Object)->SigName, (void*) Func, (void*) (Context), NULL)
#define _W_CONNECT_3(Object,SigName,Func,Context,FreeFunc) \
    w_oo_signal_connect(&(Object)->SigName, (void*) Func, (void*) (Context), FreeFunc)

#define W_EMIT(Object,...) \
    BOOST_PP_IF(BOOST_PP_EQUAL(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__),1), \
        _W_EMIT_1,_W_EMIT_VA)(Object,__VA_ARGS__)

#define _W_EMIT_1(Object,SigName,...) \
    W_CSLIST_FOR_EACH(Signal,s,(Object)->SigName) \
        s->func((void*) Object, s->context)
#define _W_EMIT_VA(Object,SigName,...) \
    W_CSLIST_FOR_EACH(Signal,s,(Object)->SigName) \
        s->func((void*) Object, s->context, __VA_ARGS__)



/*
 * Property handling.
 */

#define W_OBJECT_HAS_PROPERTY(Obj,Name) \
    (w_oo_lookup_property((Class*)((Obj)->klass), Name) != NULL)
#define W_OBJECT_HAS_INTERFACE(Obj,Name) \
    (w_oo_lookup_interface((Class*)((Obj)->klass), Name) != NULL)

#define W_FOR_OBJECT_PROPERTY(...)                                                     \
    BOOST_PP_OVERLOAD(_W_FOR_OBJECT_PROPERTY_,__VA_ARGS__)(__VA_ARGS__)

#define _W_FOR_OBJECT_PROPERTY_2(Obj,Name)                                             \
    _W_FOR_OBJECT_PROPERTY_3(Obj,Name,void)

#define _W_FOR_OBJECT_PROPERTY_3(Obj,Name,Type)                                        \
    _W_FOR_OBJECT_PROPERTY_4(Obj,Name,Type,Name)

#define _W_FOR_OBJECT_PROPERTY_4(Obj,Name,Type,Id)                                     \
    W_DECLARE(0, Type* Id)                                                             \
    for (Property* W_ID(Property) =                                                    \
        w_oo_lookup_property((Class*)((Obj)->klass), # Name);                          \
        W_ID(Property) && (Id = (Type*) W_REF_VOID_PTR(Obj, W_ID(Property)->offset));  \
        W_ID(Property) = NULL)

#define W_OBJECT_REFERENCE_GET(Obj,Name) \
    { .object = (void*) (Obj), .property = w_oo_lookup_property((Class*) ((Obj)->klass), Name) }

/*
 * Class meta data introspection through object.
 */
#define W_OBJECT_IS(Obj,Class) \
    ((Obj)->klass == &W_CLASS_INSTANCE_NAME(Class))


/*
 * Class reflection.
 */
#define W_CLASS_OVERRIDE(Class,MethodName,Func) (Class)->MethodName = Func


static inline bool
w_oo_is_super(Class* super, Class* klass)
{
    if (super == klass)
        return false;

    for (int i=0; klass->_meta->superclasses[i]; ++i)
        if (super == (void*) klass->_meta->superclasses[i])
            return true;

    return false;
}

static inline Property*
w_oo_lookup_property(Class* klass, const char* name)
{
    for (int i=0; klass->_meta->properties[i]; ++i)
        if (strcmp(klass->_meta->properties[i]->name, name) == 0)
            return klass->_meta->properties[i];

    return NULL;
}

typedef struct {
    const char* name;
} Interface;

static inline Class*
w_oo_lookup_interface(Class* klass, const char* name)
{
    for (int i=0; klass->_meta->interfaces[i]; ++i)
        if (strcmp(((Interface*) (klass->_meta->interfaces[i]))->name, name) == 0)
            return klass->_meta->interfaces[i];

    return NULL;
}

static inline Class*
w_oo_lookup_interface_checked(Class* klass, uint64_t interface)
{
    int i_mapped = klass->_ifmap(interface);

    if (i_mapped < 0) {
        printf("ERROR: Interface not supported\n");
        exit(1);
    }
    return klass->_meta->interfaces[i_mapped];
}


/*
 * Global objects.
 */
//extern struct W_CLASS_STRUCT_NAME(NothingMeta) W_CLASS_INSTANCE_NAME(NothingMeta);


/*
static inline Class*
w_oo_lookup_superclass(Class* klass, const char* name)
{
    for (int i=0; klass->__meta->superclasses[i]; ++i)
        if (strcmp(((struct NothingMeta__class*) (klass->__meta->superclasses[i]))->__meta->name, name) == 0)
            return klass->__meta->superclasses[i];

    return NULL;
}



*/
#define W_IS_SUPER(SuperClass,TestClass) \
    w_oo_is_super((Class*) (SuperClass), (Class*) (TestClass))
#define W_CLASS_HAS_PROPERTY(Klass,Name) \
    (w_oo_lookup_property((Class*) (Klass), Name) != NULL)
#define W_CLASS_HAS_INTERFACE(Klass,Name) \
    (w_oo_lookup_interface((Class*) (Klass), Name) != NULL)


#define None ((void*) (&_none))

#endif

