#ifndef __W_OO_API_H
#define __W_OO_API_H

#include <wondermacros/meta/cat.h>
#include <wondermacros/meta/cat_outer.h>
#include <wondermacros/meta/stringize.h>

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
#endif


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
struct Nothing;
typedef struct Nothing Nothing;
struct W_CLASS_STRUCT_NAME(Nothing);
typedef struct W_CLASS_STRUCT_NAME(Nothing) Class;

enum ClassKind {
    CLASS_KIND_NONE,
    CLASS_KIND_META,
    CLASS_KIND_ABSTRACT,
    CLASS_KIND_CLASS,
    CLASS_KIND_INTERFACE,
    CLASS_KIND_SINGLETON,
};

struct w_oo_property {
    const char* name;
    Class* klass;
};

/* Each class has some meta data. */
struct w_oo_meta {
    const char* name;
    size_t size;
    Class** superclasses;
    Class** interfaces;
};

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
#define W_FAT_PTR_GET(Object,Interface) { .obj = (Interface*)(Object), .klass = (W_CLASS_STRUCT_NAME(Interface)*) &((Object)->klass->Interface) }


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
#define W_CALL(o,method) \
    (((o)->klass->method) ((void*)(o), W_CALL_CLOSE
#define W_CALL_CLOSE(...) __VA_ARGS__))

#define W_CALLV(o,method) \
    (((o)->klass->method)())

#define W_EMIT(Object,Signal,...)

#define W_FATCALL(fatPtr,method) \
    (((fatPtr).klass->method) ((fatPtr), W_CALL_CLOSE

#define W_FATCALLV(fatPtr,method) \
    ((fatPtr).klass->method(fatPtr))

#define W_FATEMIT(Object,Signal,...)

#define W_STATIC_CALL(Class,Method)

#define W_CALL_IF_DEFINED(Object,Method)
#define W_CALLV_IF_DEFINED(Object,Method)


/*
 * Property handling.
 */

#define W_OBJ_SET(Obj,Property,Json)
#define W_OBJ_SET_IF_HAS(Obj,Name,Json)


/*
 * Class meta data introspection through object.
 */
#define W_OBJ_IS(Obj,Class)
#define W_OBJ_GET_CLASS(Obj) ((Obj)->klass)
#define W_OBJ_GET_CLASS_NAME(Obj) (W_OBJ_GET_CLASS(Obj)->meta->name)
#define W_OBJ_GET_PROPERTY_HANDLE(Obj,Property)


/*
 * Class reflection.
 */
#define W_CLASS_OVERRIDE(Class,MethodName,Func) (Class)->MethodName = Func


/*
 * Global objects.
 */
struct NothingMeta__class {
    Class* klass;
    struct w_oo_meta* __meta;
};
extern struct W_CLASS_STRUCT_NAME(NothingMeta) W_CLASS_INSTANCE_NAME(NothingMeta);

static inline bool
w_oo_is_super(Class* _super, Class* _klass)
{
    struct NothingMeta__class* super = (void*) _super;
    struct NothingMeta__class* klass = (void*) _klass;

    if (super == klass)
        return false;

    for (int i=0; klass->__meta->superclasses[i]; ++i)
        if (super == (void*) klass->__meta->superclasses[i])
            return true;

    return false;
}

#define W_IS_SUPER(SuperClass,TestClass) \
    w_oo_is_super((Class*) (SuperClass), (Class*) (TestClass))



#define None ((void*) (&_none))

#endif

