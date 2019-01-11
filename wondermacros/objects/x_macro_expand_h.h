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


#ifndef PREFIX
# define PREFIX
#endif

#ifndef CLASS
# error "Macro CLASS is not defined"
#endif



/* Declare class struct. */
#define METHOD(C,type,name,args,...) \
    type (*name) (struct BOOST_PP_CAT(PREFIX,CLASS)* self BOOST_PP_REMOVE_PARENS(args));
struct W_CAT(PREFIX,CLASS,__class) {
    struct {
        const char* name;
        size_t size;
    } meta;

    W_CAT(CLASS,__inherited_interfaces)

    W_CAT(CLASS,__public_methods)

    void (*free)(struct W_CAT(PREFIX,CLASS)* self);
};
#undef METHOD



/* Declare instance struct. */
#define PROPERTY(type,name,...) type name;

struct W_CAT(PREFIX,CLASS) {
    struct W_CAT(PREFIX,CLASS,__class)* klass;

    W_CAT(CLASS,__public_properties)
};

#undef PROPERTY


/* Declare private instance struct. */
#define PROPERTY(type,name,...) type name;

struct W_CAT(PREFIX,CLASS,__private) {
    struct W_CAT(PREFIX,CLASS,__class_private)* klass;

    W_CAT(CLASS,__public_properties)
#if BOOST_PP_NOT(W_CAT(CLASS,__is_abstract))
    W_CAT(CLASS,__private_properties)
#endif
};

#undef PROPERTY


/* Forward declare class struct instance. */
extern struct W_CAT(PREFIX,CLASS,__class) W_CAT(PREFIX,CLASS,__class_instance);

/* Forward declare constructor and destructor. */
struct W_CAT(PREFIX,CLASS)* W_CAT(PREFIX,CLASS,_new)();
struct W_CAT(PREFIX,CLASS)* W_CAT(PREFIX,CLASS,_new_with)(const struct W_CAT(PREFIX,CLASS,__private)* clone);
void W_CAT(PREFIX,CLASS,_free)(struct W_CAT(PREFIX,CLASS)* self);

