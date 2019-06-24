#ifndef __W_OO_API_H
#define __W_OO_API_H

#include <wondermacros/meta/cat.h>
#include <wondermacros/meta/cat_outer.h>
#include <wondermacros/meta/stringize.h>

#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/facilities/overload.hpp>


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
#define W_CLASS_STRUCT_NAME(Class)        \
    BOOST_PP_IF(                          \
            W_IS_PUBLIC,                  \
            W_CAT(Class,__class),         \
            W_CAT(Class,__class_private)) \
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


struct Object;
struct W_CLASS_STRUCT_NAME(Object);
typedef struct W_CLASS_STRUCT_NAME(Object) Class;

enum ClassKind {
    CLASS_KIND_META,
    CLASS_KIND_ABSTRACT,
    CLASS_KIND_CLASS,
    CLASS_KIND_INTERFACE,
};

#define ObjectMeta__define                         \
    struct W_CLASS_STRUCT_NAME(ObjectMeta)* klass; \
    const char* name;                              \
    enum ClassKind kind;                           \
    /**/

struct W_CLASS_STRUCT_NAME(ObjectMeta) {
    ObjectMeta__define
    bool (*is_super)(Class* self, Class* other);
    bool (*is_sub)(Class* self, Class* other);
};

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

#define W_CALL(Object,Method)
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


/*
 * Base classes
 */
#include "Object.h"

#endif

