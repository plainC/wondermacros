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

#ifdef BUILD_JSON
# include <wondermacros/objects/json/types.h>
#endif

#ifndef CLASS
# error "Macro CLASS is not defined"
#endif


#undef _EXPAND_CLASS
#undef _PRIVATE

#ifdef W_FORWARD_DECLARE
struct W_CAT(CLASS,__class);
#endif

#ifdef W_CLASS_DECLARE
struct w_json_class;
struct W_CAT(CLASS,__class) {
# define _PRIVATE
# define _EXPAND_CLASS
#endif

#ifdef W_CLASS_GENERATE
struct W_CAT(CLASS,__private);
struct W_CAT(CLASS,__class_private) {
# define _PRIVATE __private
# define _EXPAND_CLASS
#endif

#ifdef _EXPAND_CLASS
    struct {
        const char* name;
        size_t size;
        const char** property_name;
        const size_t* property_len;
        const size_t* property_offset;
#ifdef BUILD_JSON
        const struct w_json_class* property_type;
#else
        void* property_type;
#endif
    } meta;

    /* Add free method. */
    void (*free)(struct W_CAT(CLASS,_PRIVATE)* self);
#ifdef BUILD_JSON
    int (*to_json)(struct W_CAT(CLASS,_PRIVATE)* self, char* buffer, size_t size);
    int (*from_json)(struct W_CAT(CLASS,_PRIVATE)* self, const char* buffer, const char** endptr);
#endif

    /* Expand public method interface. */
# define VAR(...)
# define OVERLOAD(...)
# define public 1
# define private 0
# define METHOD(C,P,type,...)          \
    BOOST_PP_OVERLOAD(_METHOD_,__VA_ARGS__)(C,P,type,__VA_ARGS__)
# define _METHOD_1(C,P,type,name)      \
    BOOST_PP_EXPR_IF(P,type (*name) (struct W_CAT(C,_PRIVATE)* self);)
# define _METHOD_2(C,P,type,name,args) \
    BOOST_PP_EXPR_IF(P,type (*name) (struct W_CAT(C,_PRIVATE)* self, BOOST_PP_REMOVE_PARENS(args));)
    W_CAT_INNER(CLASS,__define)
# undef public
# undef private
# undef METHOD
# undef _METHOD_1
# undef _METHOD_2
    /**/

# ifdef W_CLASS_GENERATE
    /* Expand private method interface. */
#  define public 0
#  define private 1
#  define METHOD(C,P,type,...)          \
    BOOST_PP_OVERLOAD(_METHOD_,__VA_ARGS__)(C,P,type,__VA_ARGS__)
#  define _METHOD_1(C,P,type,name)      \
    BOOST_PP_EXPR_IF(P,type (*name) (struct W_CAT(C,__private)* self);)
#  define _METHOD_2(C,P,type,name,args) \
    BOOST_PP_EXPR_IF(P,type (*name) (struct W_CAT(C,__private)* self, BOOST_PP_REMOVE_PARENS(args));)
    W_CAT_INNER(CLASS,__define)
#  undef public
#  undef private
#  undef METHOD
#  undef _METHOD_1
#  undef _METHOD_2
#  undef OVERLOAD
    /**/

# endif
# undef VAR
};
#endif

#undef _EXPAND_CLASS
