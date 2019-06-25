#ifndef __W_OO_API_H
#define __W_OO_API_H

#include <wondermacros/meta/cat.h>
#include <wondermacros/meta/cat_outer.h>
#include <wondermacros/meta/stringize.h>

#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/control/expr_if.hpp>
#include <boost/preprocessor/facilities/overload.hpp>
#include <boost/preprocessor/punctuation/remove_parens.hpp>


#ifndef WDEBUG_EXPAND
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
#endif

/*
 * Configuration:
 *
 * W_IS_PUBLIC   [0..1]
 * W_HAS_CONSTRUCTOR
 * W_HAS_DESTRUCTOR
 * W_CLASS_TYPEDEF
 */

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


struct Nothing;
typedef struct Nothing Nothing;
struct W_CLASS_STRUCT_NAME(Nothing);
typedef struct W_CLASS_STRUCT_NAME(Nothing) Class;

enum ClassKind {
    CLASS_KIND_META,
    CLASS_KIND_ABSTRACT,
    CLASS_KIND_CLASS,
    CLASS_KIND_INTERFACE,
    CLASS_KIND_SINGLETON,
};

#define NothingMeta__define                         \
    struct W_CLASS_STRUCT_NAME(NothingMeta)* klass; \
    const char* name;                               \
    enum ClassKind kind;                            \
    Class** superclasses;                           \
    /**/

struct W_CLASS_STRUCT_NAME(NothingMeta) {
    NothingMeta__define
    bool (*is_super)(Class* self, Class* other);
    bool (*is_sub)(Class* self, Class* other);
};

extern struct W_CLASS_STRUCT_NAME(NothingMeta) W_CLASS_INSTANCE_NAME(NothingMeta);

/*
 * Object creation, casts and assignments.
 */

#define W_NEW(Class,...)
#define W_OBJ_NEW(Class,Json)
#define W_OBJECT_AS(Object,Class)
#define W_FAT_PTR_GET(Object,Interface)


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
#define W_CALL(o,method) (((o)->klass->method) \
    ((void*)(o), W_CALL_CLOSE
#define W_CALL_CLOSE(...) __VA_ARGS__))

#define W_CALLV(Object,Method)
#define W_EMIT(Object,Signal,...)

#define W_FATCALL(Interface,Object,Method)
#define W_FATCALLV(Interface,Object,Method)
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


#endif

