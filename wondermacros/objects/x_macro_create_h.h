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
#include <boost/preprocessor/cat.hpp>
#include <wondermacros/meta/cat.h>

#ifndef PREFIX
# define PREFIX
#endif

#ifndef CLASS
# error "Macro CLASS is not defined"
#endif



/* Declare class struct. */
#define PUBLIC_METHOD(type,name,args,...) \
    type (*name) (struct BOOST_PP_CAT(PREFIX,CLASS)* self BOOST_PP_REMOVE_PARENS(args));
#define PRIVATE_METHOD(...)
struct W_CAT(PREFIX,CLASS,__class) {
    struct {
        const char* name;
        size_t size;
    } meta;
#ifdef SUPER
    W_CAT(SUPER,__methods)
#endif
    W_CAT(CLASS,__methods)
};
#undef PUBLIC_METHOD
#undef PRIVATE_METHOD


/* Declare instance struct. */
#define PUBLIC_PROPERTY(type,name,...) type name;
#define PRIVATE_PROPERTY(...)

struct W_CAT(PREFIX,CLASS) {
    struct W_CAT(PREFIX,CLASS,__class)* klass;
#ifdef SUPER
    W_CAT(SUPER,__properties)
#endif
    W_CAT(CLASS,__properties)
};

#undef PUBLIC_PROPERTY
#undef PRIVATE_PROPERTY


/* Forward declare class struct instance. */
extern struct W_CAT(PREFIX,CLASS,__class) W_CAT(PREFIX,CLASS,__class_instance);
