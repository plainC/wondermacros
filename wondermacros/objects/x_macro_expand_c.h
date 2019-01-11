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
#include <wondermacros/meta/cat.h>

#ifndef PREFIX
# define PREFIX
#endif

#ifndef CLASS
# error "Macro CLASS is not defined"
#endif


struct W_CAT(PREFIX,CLASS,__private);


/* Declare private class struct. */
#define METHOD(C,type,name,args,...) \
    type (*name) (struct BOOST_PP_CAT(BOOST_PP_CAT(PREFIX,CLASS),__private)* self \
        BOOST_PP_REMOVE_PARENS(args));
struct W_CAT(PREFIX,CLASS,__class_private) {
    struct {
        const char* name;
        size_t size;
    } meta;

    W_CAT(CLASS,__inherited_interfaces)

    W_CAT(CLASS,__public_methods)
#if BOOST_PP_NOT(W_CAT(CLASS,__is_abstract))
    W_CAT(CLASS,__private_methods)
#endif

    void (*free)(struct W_CAT(PREFIX,CLASS)* self);
};
#undef METHOD



/* Forward declare methods. */
#ifdef SUPER

# define METHOD(C,type,name,args,...) \
    type BOOST_PP_CAT(BOOST_PP_CAT(SUPER,__),name) (struct BOOST_PP_CAT(BOOST_PP_CAT(PREFIX,CLASS),__private)* self \
        BOOST_PP_REMOVE_PARENS(args));

W_CAT(SUPER,__public_methods)

# undef METHOD
#endif

#define METHOD(C,type,name,args,...) \
    type BOOST_PP_CAT(BOOST_PP_CAT(CLASS,__),name) (struct BOOST_PP_CAT(BOOST_PP_CAT(PREFIX,CLASS),__private)* self \
        BOOST_PP_REMOVE_PARENS(args));
W_CAT(CLASS,__public_methods)
#if BOOST_PP_NOT(W_CAT(CLASS,__is_abstract))
W_CAT(CLASS,__private_methods)
#endif

#undef METHOD

#ifdef SUPER
# define METHOD(C,type,name,args,...) \
    type BOOST_PP_CAT(BOOST_PP_CAT(CLASS,__),name) (struct BOOST_PP_CAT(BOOST_PP_CAT(PREFIX,CLASS),__private)* self \
        BOOST_PP_REMOVE_PARENS(args));
    W_CAT(CLASS,__override_methods)
# undef METHOD
#endif

void W_CAT(CLASS,__,free)(struct W_CAT(PREFIX,CLASS)* self);


/* Initialize class struct instance. */

#if BOOST_PP_NOT(BOOST_PP_CAT(CLASS,__is_abstract))

struct W_CAT(PREFIX,CLASS,__class) W_CAT(PREFIX,CLASS,__class_instance) = {
    .meta.name = BOOST_PP_STRINGIZE(CLASS),
    .meta.size = sizeof(struct W_CAT(PREFIX,CLASS,__private)),

# define METHOD(C,type,name,args,...) \
    .name = (type (*)(struct BOOST_PP_CAT(PREFIX,CLASS)* self BOOST_PP_REMOVE_PARENS(args))) BOOST_PP_CAT(BOOST_PP_CAT(C,__),name),
    W_CAT(CLASS,__override_methods)
# undef METHOD

#endif


# define METHOD(C,type,name,args,...) \
    .name = (type (*)(struct BOOST_PP_CAT(PREFIX,CLASS)* self BOOST_PP_REMOVE_PARENS(args))) BOOST_PP_CAT(BOOST_PP_CAT(C,__),name),

    W_CAT(CLASS,__public_methods)
#if BOOST_PP_NOT(W_CAT(CLASS,__is_abstract))
    W_CAT(CLASS,__private_methods)
#endif

   .free = W_CAT(CLASS,_free),
};
# undef METHOD




/* Define method macros to provide signatures. */
#define METHOD(C,type,name,args,...) \
type W_CAT(CLASS,__,name) (struct W_CAT(PREFIX,CLASS,__private)* self BOOST_PP_REMOVE_PARENS(args))


/* Constructor. */
#define CONSTRUCT                                                                                      \
void W_CAT(CLASS,___construct) (struct W_CAT(PREFIX,CLASS,__private)* self);                           \
struct W_CAT(PREFIX,CLASS)*                                                                            \
W_CAT(PREFIX,CLASS,_new)()                                                                             \
{                                                                                                      \
    struct W_CAT(PREFIX,CLASS,__private)* self = malloc(sizeof(struct W_CAT(PREFIX,CLASS,__private))); \
    bzero(self, sizeof(struct W_CAT(PREFIX,CLASS,__private)));                                         \
    self->klass = (struct W_CAT(PREFIX,CLASS,__class_private)*)&W_CAT(PREFIX,CLASS,__class_instance);  \
    W_CAT(CLASS,___construct)(self);                                                                   \
    return (struct W_CAT(PREFIX,CLASS)*) self;                                                         \
}                                                                                                      \
                                                                                                       \
struct W_CAT(PREFIX,CLASS)*                                                                            \
W_CAT(PREFIX,CLASS,_new_with)(const struct W_CAT(PREFIX,CLASS,__private)* clone)                       \
{                                                                                                      \
    struct W_CAT(PREFIX,CLASS,__private)* self = malloc(sizeof(struct W_CAT(PREFIX,CLASS,__private))); \
    *self = *clone;                                                                                    \
    self->klass = (struct W_CAT(PREFIX,CLASS,__class_private)*)&W_CAT(PREFIX,CLASS,__class_instance);  \
    W_CAT(CLASS,___construct)(self);                                                                   \
    return (struct W_CAT(PREFIX,CLASS)*) self;                                                         \
}                                                                                                      \
                                                                                                       \
void W_CAT(CLASS,___construct) (struct W_CAT(PREFIX,CLASS,__private)* self)



/* Destructor. */
#define FINALIZE                                                                                       \
void W_CAT(CLASS,___finalize) (struct W_CAT(PREFIX,CLASS,__private)* self);                            \
void W_CAT(CLASS,_free)(struct W_CAT(PREFIX,CLASS)* self)                                       \
{                                                                                                      \
    W_CAT(CLASS,___finalize)((struct W_CAT(PREFIX,CLASS,__private)*) self);                            \
    free(self);                                                                                        \
}                                                                                                      \
                                                                                                       \
void W_CAT(CLASS,___finalize) (struct W_CAT(PREFIX,CLASS,__private)* self)



