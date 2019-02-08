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

#ifndef __W_OBJECTS_API_H
#define __W_OBJECTS_API_H

#ifndef WDEBUG_EXPAND
# include <strings.h>
#endif
#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/variadic/size.hpp>
#include <boost/preprocessor/variadic/elem.hpp>

#define W_NEW(...) (                                                    \
    (void*)                                                             \
    BOOST_PP_IF(BOOST_PP_EQUAL(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), 1), \
        W_CAT(BOOST_PP_VARIADIC_ELEM(0,__VA_ARGS__),_new)(),            \
        _W_NEW(__VA_ARGS__)                                             \
    )                                                                   \
)
#define _W_NEW(T,...) \
    W_CAT(T,_new_with)(&((struct W_CAT(T)){__VA_ARGS__}))



#define W_CALL(o,method) (((o)->klass->method) ((void*) o, W_CALL_CLOSE
#define W_CALL_CLOSE(...) __VA_ARGS__))

#define W_CALL_VOID(o,method) (((o)->klass->method)((void*) o))

#define W_CLASS(name) W_CAT(name,__class_instance_ptr)

#define W_OBJECT_IS(o,type) ((void*) ((o)->klass) == W_CLASS(type))
#define W_OBJECT_AS(o,type) ((struct type*)(o))

#define W_OBJECT_CLASS_NAME(o) ((o)->klass->meta.name)
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
