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
#include <boost/preprocessor/cat.hpp>
#include <wondermacros/meta/cat.h>

#define O_CAT(a,b) _O_CAT(a,b)
#define _O_CAT(a,b) a ## b

#ifndef CLASS
# error "Macro CLASS is not defined"
#endif


/* Expand method types. */
#define METHOD(C,type,...) BOOST_PP_OVERLOAD(_METHOD_,__VA_ARGS__)(C,type,__VA_ARGS__)
#define _METHOD_1(C,type,name) typedef type (*W_CAT(M__,C,__,name)) (struct C* self);
#define _METHOD_2(C,type,name,args) typedef type (*W_CAT(M__,C,__,name)) (struct C* self, BOOST_PP_REMOVE_PARENS(args));
#define BEGIN(_)
#define END
O_CAT(CLASS,__interfaces)
#undef METHOD
#undef _METHOD_1
#undef _METHOD_2
#undef BEGIN
#undef END



/* Declare public class struct. */
#undef X_PRIVATE
#include <wondermacros/objects/x_macro_expand_class.h>



/* Declare instance struct. */
#define PROPERTY(type,name,...) type name;

struct CLASS {
    struct W_CAT(CLASS,__class)* klass;

    W_CAT(CLASS,__public_properties)
};

#undef PROPERTY


/* Declare private instance struct. */
#define PROPERTY(type,name,...) type name;

struct W_CAT(CLASS,__private) {
    struct W_CAT(CLASS,__class_private)* klass;

    W_CAT(CLASS,__public_properties)
#if BOOST_PP_NOT(W_CAT(CLASS,__is_abstract))
    W_CAT(CLASS,__private_properties)
#endif
};

#undef PROPERTY


/* Forward declare class struct instance. */
extern struct W_CAT(CLASS,__class) W_CAT(CLASS,__class_instance);

/* Forward declare constructor and destructor. */
struct CLASS* W_CAT(CLASS,_new)();
struct CLASS* W_CAT(CLASS,_new_with)(const struct W_CAT(CLASS,__private)* clone);
void W_CAT(CLASS,_free)(struct CLASS* self);

