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

#include <boost/preprocessor/punctuation/remove_parens.hpp>
#include <boost/preprocessor/logical/not.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/control/expr_if.hpp>
#include <wondermacros/meta/cat.h>
#include <wondermacros/meta/cat_inner.h>
#include <wondermacros/pointer/ref_void_ptr.h>

#ifndef WDEBUG_EXPAND
# include <stddef.h>
#endif

#ifndef CLASS
# error "Macro CLASS is not defined"
#endif


#ifdef W_CLASS_DECLARE
extern struct W_CAT(CLASS,__class_private) W_CAT(CLASS,__class_instance);
#endif

#ifdef W_CLASS_GENERATE
static const char* W_CAT_INNER(CLASS,__property_name)[] = {
# define Array(...)
# define VAR(scope,type,name,...) # name,
# define OVERRIDE(C,name)
# define METHOD(C,P,type,...)

    /**/
    W_CAT(CLASS,__define)
    /**/

# undef OVERRIDE
# undef METHOD
# undef VAR
    NULL
};

#ifndef USE_BIT_FIELDS
static const size_t W_CAT_INNER(CLASS,__property_offset)[] = {
# define VAR(scope,type,name,...) W_CAT_INNER(VAR_,scope)(name),
# define VAR_public(name) offsetof(struct W_CAT_INNER(CLASS,__private),name)
# define VAR_read(name) VAR_public(name)
# define VAR_private(name) offsetof(struct W_CAT_INNER(CLASS,__private),CLASS.name)
# define OVERRIDE(C,name)
# define METHOD(C,P,type,...)

    /**/
    W_CAT(CLASS,__define)
    /**/

# undef OVERRIDE
# undef METHOD
# undef VAR
# undef VAR_public
# undef VAR_private
# undef VAR_read

    0
};
#endif

static const size_t W_CAT_INNER(CLASS,__property_len)[] = {
# define VAR(scope,type,name,...) sizeof(# name)-1,
# define OVERRIDE(C,name)
# define METHOD(C,P,type,...)

    /**/
    W_CAT(CLASS,__define)
    /**/

# undef OVERRIDE
# undef METHOD
# undef VAR
    0
};

#ifdef BUILD_JSON

# define JSON(t) t
# define VAR(scope,type,...) BOOST_PP_OVERLOAD(VAR_,__VA_ARGS__)(type,__VA_ARGS__)
# define VAR_1(type,name)
# define VAR_2(t,name,spec) \
    int W_CAT_INNER(spec,_to_string)(void* self, char* buffer, size_t size); \
    int W_CAT_INNER(spec,_from_string)(const char* buffer, size_t size, void** self);
# define OVERRIDE(C,name)
# define METHOD(C,P,type,...)

    /**/
    W_CAT(CLASS,__define)
    /**/

# undef JSON
# undef OVERRIDE
# undef METHOD
# undef VAR
# undef VAR_1
# undef VAR_2


struct w_json_class W_CAT_INNER(CLASS,__property_type)[] = {

# define JSON(t) t
# define VAR(scope,type,...) BOOST_PP_OVERLOAD(VAR_,__VA_ARGS__)(type,__VA_ARGS__)
# define VAR_1(type,name) \
    { .to_string = NULL,  \
      .from_string = NULL },
# define VAR_2(t,name,spec) \
    { .to_string = (int (*)(void* self, char* buffer, size_t size)) \
        W_CAT_INNER(spec,_to_string), \
      .from_string = (int (*)(const char* buffer, const char** endptr, void* self)) W_CAT_INNER(spec,_from_string) },
# define OVERRIDE(C,name)
# define METHOD(C,P,type,...)

    /**/
    W_CAT(CLASS,__define)
    /**/

# undef JSON
# undef OVERRIDE
# undef METHOD
# undef VAR
# undef VAR_1
# undef VAR_2

};
#endif

#ifdef SUPER
extern struct W_CAT(SUPER,__class) W_CAT(SUPER,__class_instance);
#endif
struct W_CAT(CLASS,__private);
struct W_CAT(CLASS,__class_private) W_CAT(CLASS,__class_instance) = {
#ifdef SUPER
    .meta.super = &W_CAT(SUPER,__class_instance),
#else
    .meta.super = NULL,
#endif
    .meta.name = BOOST_PP_STRINGIZE(CLASS),
    .meta.size = sizeof(struct W_CAT_INNER(CLASS,__private)),
    .meta.property_name = W_CAT_INNER(CLASS,__property_name),
    .meta.property_len = W_CAT_INNER(CLASS,__property_len),
#ifndef USE_BIT_FIELDS
    .meta.property_offset = W_CAT_INNER(CLASS,__property_offset),
#endif
#ifdef BUILD_JSON
    .meta.property_type = &W_CAT_INNER(CLASS,__property_type)[0],
#endif

    .free = W_CAT(CLASS,_free),
#ifdef BUILD_JSON
    .to_json = (int (*)(struct W_CAT(CLASS,_PRIVATE)* self, char* buffer, size_t size)) W_CAT(CLASS,_to_json),
    .from_json = (int (*)(struct W_CAT(CLASS,_PRIVATE)* self, const char* buffer, const char** endptr)) W_CAT(CLASS,_from_json),
#endif

    /* Expand method interface. */
# define VAR(...)
# define OVERRIDE(C,name) \
    .name = /* kill warning */ (void*) W_CAT_INNER(C,__,name),
# define METHOD(C,P,type,...)          \
    BOOST_PP_OVERLOAD(_METHOD_,__VA_ARGS__)(C,P,type,__VA_ARGS__)
# define _METHOD_1(C,P,type,name)      \
    .name = W_CAT_INNER(C,__,name),
# define _METHOD_2(C,P,type,name,args) \
    .name = W_CAT_INNER(C,__,name),

    /**/
    W_CAT(CLASS,__define)
    /**/

# undef OVERRIDE
# undef METHOD
# undef _METHOD_1
# undef _METHOD_2
# undef VAR
# undef Array
};

void* W_CAT(CLASS,__class_instance_ptr) = &W_CAT(CLASS,__class_instance);

#endif
