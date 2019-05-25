/* (C) is Copyright 2019 J.P. Iivonen <wondermacros@yahoo.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#ifdef W_OBJECT_CAST_TO_VOID
# undef W_OBJECT_CASTING
# define W_OBJECT_CASTING 1
#else
# undef W_OBJECT_CASTING
# define W_OBJECT_CASTING 0
#endif


#ifndef __W_OBJECTS_API_H
#define __W_OBJECTS_API_H

#ifndef WDEBUG_EXPAND
# include <strings.h>
#endif
#include <boost/preprocessor/punctuation/is_begin_parens.hpp>
#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/variadic/size.hpp>
#include <boost/preprocessor/variadic/elem.hpp>
#include <boost/preprocessor/tuple/elem.hpp>


/***
 *** Name:        W_NEW
 *** Proto:       W_NEW(T [,...])
 *** Arg:         T     a class name
 *** Arg:         ...   values to be set (e.g. W_NEW(point, .x=1, .y=2))
 *** Description: Use W_NEW to create (and to initialize) an object.
 ***/
#define W_NEW(...) (                                                    \
    BOOST_PP_EXPR_IF(W_OBJECT_CASTING,(void*))                          \
    BOOST_PP_IF(BOOST_PP_EQUAL(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), 1), \
        W_CAT(BOOST_PP_VARIADIC_ELEM(0,__VA_ARGS__),_new)(),            \
        _W_NEW(__VA_ARGS__)                                             \
    )                                                                   \
)
#define _W_NEW(T,...)                                                   \
    BOOST_PP_EXPR_IF(W_OBJECT_CASTING,(void*))                          \
    W_CAT(T,_new_with)(&((struct W_CAT(T)){__VA_ARGS__}))


#define W_NEW_BY_STRING(str,...)                                        \
    w_class_lookup_new_by_name(str)(NULL)


/***
 *** Name:        W_CALL
 *** Proto:       W_CALL(self,method)(...)
 *** Arg:         self     an object (an instance of a class)
 *** Arg:         method   a method name to be called
 *** Arg:         ...      arguments for the methods
 *** Description: Use W_CALL to call a method of an object with arguments. The macro will expand self automatically as the first argument of the argument list in the method call.
 ***/
#define W_CALL(o,method) (((o)->klass->method) \
    (BOOST_PP_EXPR_IF(W_OBJECT_CASTING,(void*))(o), W_CALL_CLOSE
#define W_CALL_CLOSE(...) __VA_ARGS__))

/***
 *** Name:        W_CALL_STATIC
 *** Proto:       W_CALL_STATIC(klass,self,method)(...)
 *** Arg:         klass    a name of a class whose method is to be called
 *** Arg:         self     an object (an instance of a class)
 *** Arg:         method   a method name to be called
 *** Arg:         ...      arguments for the methods
 *** Description: Use W_CALL_STATIC to call a method of a specified class for an object with arguments following.
 ***/
#define W_CALL_STATIC(klass,o,method) ((klass ## __ ## method) \
    (BOOST_PP_EXPR_IF(W_OBJECT_CASTING,(void*))(o), W_CALL_CLOSE

/***
 *** Name:        W_CALL_VOID
 *** Proto:       W_CALL_VOID(self,method)
 *** Arg:         self     an object (an instance of a class)
 *** Arg:         method   a method name to be called
 *** Description: Use W_CALL_VOID to call a method of an object without any arguments.
 ***/
#define W_CALL_VOID(o,method)                  \
    (((o)->klass->method)(BOOST_PP_EXPR_IF(W_OBJECT_CASTING,(void*)) (o)))

/***
 *** Name:        W_CALL_STATIC_VOID
 *** Proto:       W_CALL_STATIC_VOID(self,method)
 *** Arg:         klass    a name of a class whose method is to be called
 *** Arg:         self     an object (an instance of a class)
 *** Arg:         method   a method name to be called
 *** Description: Use W_CALL_STATIC_VOID to call a method of a specified class.
 ***/
#define W_CALL_STATIC_VOID(klass,o,method)                  \
    (klass ## __ ## method(BOOST_PP_EXPR_IF(W_OBJECT_CASTING,(void*)) (o)))

/***
 *** Name:        W_CALL_CONSTRUCT
 *** Proto:       W_CALL_CONSTRUCT(klass)
 *** Arg:         klass    class name
 *** Description: Use W_CALL_CONSTRUCT to call a constructor of a superclass by the name of the class.
 ***/
#define W_CALL_CONSTRUCT(klass) \
    klass ## ____construct((void*) self)

/***
 *** Name:        W_CALL_FINALIZE
 *** Proto:       W_CALL_FINALIZE(klass)
 *** Arg:         klass    class name
 *** Description: Use W_CALL_FINALIZE to call a destructor of a superclass by the name of the class.
 ***/
#define W_CALL_FINALIZE(klass) \
    klass ## ____finalize((void*) self)

/***
 *** Name:        W_CALL_ACONSTRUCT
 *** Proto:       W_CALL_ACONSTRUCT(klass)
 *** Arg:         klass    class name
 *** Description: Use W_CALL_ACONSTRUCT to call a constructor of an abstract superclass.
 ***/
#define W_CALL_ACONSTRUCT(klass) \
    void klass ## ___construct(void* self); \
    klass ## ___construct((void*) self)

/***
 *** Name:        W_CALL_AFINALIZE
 *** Proto:       W_CALL_AFINALIZE(klass)
 *** Arg:         klass    class name
 *** Description: Use W_CALL_AFINALIZE to call a destructor of an abstract superclass.
 ***/
#define W_CALL_AFINALIZE(klass) \
    void klass ## ___finalize(void* self); \
    klass ## ___finalize((void*) self)

/***
 *** Name:        W_CLASS
 *** Proto:       W_CLASS(name)
 *** Arg:         name     a class name
 *** Description: Use W_CLASS to access the class instance.
 ***/
#define W_CLASS(name) W_CAT(name,__class_instance_ptr)

/***
 *** Name:        W_GET_SUPERCLASS
 *** Proto:       W_GET_SUPERCLASS(o)
 *** Arg:         o     an object
 *** Description: Use W_GET_SUPERCLASS to get pointer to the class object of o's superclass.
 ***/
#define W_GET_SUPERCLASS(o) ((o)->klass->meta.super)

/***
 *** Name:        W_OBJECT_IS
 *** Proto:       W_OBJECT_IS(self,T)
 *** Arg:         self     an object
 *** Arg:         T        a class name
 *** Description: Use W_OBJECT_IS to test if an object is of a specific class.
 ***/
#define W_OBJECT_IS(o,type) ((void*) ((o)->klass) == W_CLASS(type))

/***
 *** Name:        W_OBJECT_AD
 *** Proto:       W_OBJECT_AS(self,T)
 *** Arg:         self     an object
 *** Arg:         T        a class name
 *** Description: Use W_OBJECT_AS to coerce an object to a specific class type.
 ***/
#define W_OBJECT_AS(o,type) ((struct type*)(o))

/***
 *** Name:        W_OBJECT_CLASS_NAME
 *** Proto:       W_OBJECT_CLASS_NAME(self)
 *** Description: Use W_OBJECT_CLASS_NAME to get a const char pointer to the name of the class.
 ***/
#define W_OBJECT_CLASS_NAME(o) ((o)->klass->meta.name)

/***
 *** Name:        W_METHOD_GET
 *** Proto:       W_METHOD_GET(self,method)
 *** Arg:         self     an object
 *** Arg:         method   a method name
 *** Description: Use W_METHOD_GET to get a pointer to a method of an object by the name.
 ***/
#define W_METHOD_GET(o,method) ((o)->klass->method)


/***
 *** Name:        W_OBJECT_SIGNAL_TYPE
 *** Proto:       W_OBJECT_SIGNAL_TYPE
 *** Description: Use W_OBJECT_SIGNAL_TYPE to declare a variable that stores a handle to a callback binding
 ***/
#define W_OBJECT_SIGNAL_TYPE        \
    struct {                        \
        void (*cb)(void* self,...); \
        void* data;                 \
        void* next;                 \
    }


/***
 *** Name:        W_CONNECT
 *** Proto:       W_CONNECT(self,signal,callback,handle)
 *** Arg:         self      an object
 *** Arg:         signal    signal name
 *** Arg:         callback  a pointer to a callback (void (*)(struct CLASS* self, ...))
 *** Arg:         handle    a variable of type W_OBJECT_SIGNAL_TYPE to store handle to the binding
 *** Description: Use W_CONNECT to bind a callback to a signal of an object. The caller should save the handle to remove the binding when no longer needed.
 ***/
#define W_CONNECT(o,sig,Cb,handle)                                        \
    do {                                                                  \
        handle = malloc(sizeof(W_OBJECT_SIGNAL_TYPE));                    \
        BOOST_PP_IF(BOOST_PP_IS_BEGIN_PARENS(Cb),                         \
            /* Bind a closure. */                                         \
            handle->cb = (void (*)(void*,...)) BOOST_PP_TUPLE_ELEM(0,Cb); \
            handle->data = BOOST_PP_TUPLE_ELEM(1,Cb);                     \
        ,                                                                 \
            /* Bind a callback. */                                        \
            handle->cb = (void (*)(void*,...)) Cb;                        \
            handle->data = NULL;                                          \
        )                                                                 \
        handle->next = handle;                                            \
        W_CSLIST_APPEND(W_OBJECT_SIGNAL_TYPE, (o)->sig, handle);          \
    } while (0)

/***
 *** Name:        W_DISCONNECT
 *** Proto:       W_DISCONNECT(handle)
 *** Arg:         handle    a handle to a signal binding (of type W_OBJECT_SIGNAL_TYPE)
 *** Description: Use W_DISCONNECT to disconnect a binding to a signal.
 ***/
#define W_DISCONNECT(handle)                                 \
    ((handle)->cb = NULL)

/***
 *** Name:        W_DISCONNECT_ALL
 *** Proto:       W_DISCONNECT_ALL(self,signal)
 *** Arg:         self      an object
 *** Arg:         signal    signal name
 *** Description: Use W_DISCONNECT_ALL to disconnect all bindings to a signal of an object. All handles are invalid after its use.
 ***/
#define W_DISCONNECT_ALL(self,sig)                             \
    W_CSLIST_FOR_EACH(W_OBJECT_SIGNAL_TYPE, node, (self)->sig) \
        free(node)

/***
 *** Name:        W_EMIT
 *** Proto:       W_EMIT(self,signal,...)
 *** Arg:         self      an object
 *** Arg:         signal    signal name
 *** Arg:         ...       optional arguments to the signal
 *** Description: Use W_EMIT to emit a signal. All callbacks which are bind to the signal of the object are called.
 ***/
#define W_EMIT(o,sig,...)                                     \
    W_CSLIST_FOR_EACH(W_OBJECT_SIGNAL_TYPE,node,                  \
        (BOOST_PP_EXPR_IF(W_OBJECT_CASTING,(void*))(o)->sig)) \
        if (!node->cb) {                                      \
        } else node->cb(o,node->data,__VA_ARGS__)

/***
 *** Name:        W_EMIT_VOID
 *** Proto:       W_EMIT_VOID(self,signal)
 *** Arg:         self      an object
 *** Arg:         signal    signal name
 *** Description: Use W_EMIT_VOID to emit a signal without arguments. All callbacks which are bind to the signal of the object are called.
 ***/
#define W_EMIT_VOID(o,sig)                                    \
    W_CSLIST_FOR_EACH(W_OBJECT_SIGNAL_TYPE,node,                  \
        (BOOST_PP_EXPR_IF(W_OBJECT_CASTING,(void*))(o)->sig)) \
        if (!node->cb) {                                      \
        } else node->cb(o,node->data)




/* FIXME: not yet complete */
#define W_OBJECT_METHOD_BY_INDEX(o,ix) ((o)->klass->meta.method[(ix)])

#define W_OBJECT_GET_METHOD_PTR(o,method) \
    W_REF_VOID_PTR( (o)->klass, (o)->klass->meta.get_method_offset(# method) + W_BYTE_OFFSET((o)->klass->vftb,(o)->klass->start) )

#define W_SEND_VOID(T,o,method) \
    if ((o)->klass->meta.get_method_offset(#method) != -1) \
        ((T) (*((void**) W_OBJECT_GET_METHOD_PTR(o,method))))(o); \
    else

#define W_SEND(T,o,method,...) \
    if ((o)->klass->meta.get_method_offset(#method) != -1) \
        ((T) (*((void**) W_OBJECT_GET_METHOD_PTR(o,method))))(o,__VA_ARGS__); \
    else

#define W_OBJECT_SET(T,o,name,value) \
    if ((o)->klass->meta.get_property_offset(# name) != -1) \
        *((T*) W_REF_VOID_PTR((o),sizeof(void*) + (o)->klass->meta.get_property_offset(# name))) = (value); \
    else

#define W_OBJECT_GET(T,o,name,na_value) \
    (((o)->klass->meta.get_property_offset(# name) != -1) ? \
        *((T*) W_REF_VOID_PTR((o),sizeof(void*) + (o)->klass->meta.get_property_offset(# name))) : \
        (na_value) \
    )

#define W_OBJECT_HAS_PROPERTY(o,name) \
    ((o)->klass->meta.get_property_offset(# name) != -1)

#define W_OBJECT_HAS_METHOD(o,name) \
    ((o)->klass->meta.get_method_offset(# name) != -1)

#endif
