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
#undef X_PRIVATE
#define X_PRIVATE
#include <wondermacros/objects/x_macro_expand_class.h>



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


/* Generate 'get method offset' function. */
int
W_CAT(CLASS,___get_method_offset)(const char* name)
{
    for (int i=0; i < W_CAT(CLASS,_NBR_OF_METHODS); i++)
        if (strcmp(W_CAT(PREFIX,CLASS,__class_instance).meta.method[i], name) == 0)
            return i*sizeof(void*);

    return -1;
}


extern const char* W_CAT(CLASS,___properties)[W_CAT(CLASS,_NBR_OF_PROPERTIES)+1];
extern const char* W_CAT(CLASS,___methods)[W_CAT(CLASS,_NBR_OF_METHODS)+1];
extern const int W_CAT(CLASS,___property_size)[W_CAT(CLASS,_NBR_OF_PROPERTIES)+1];



/* Generate 'get property offset' function. */
int
W_CAT(CLASS,___get_property_offset)(const char* name)
{
    int size = 0;
    for (int i=0; i < W_CAT(CLASS,_NBR_OF_PROPERTIES); size += W_CAT(CLASS,___property_size)[i++])
        if (strcmp(W_CAT(PREFIX,CLASS,__class_instance).meta.property[i], name) == 0)
            return size;

    return -1;
}

/* Initialize class struct instance. */

#if BOOST_PP_NOT(BOOST_PP_CAT(CLASS,__is_abstract))

struct W_CAT(PREFIX,CLASS,__class) W_CAT(PREFIX,CLASS,__class_instance) = {
    .meta.name = BOOST_PP_STRINGIZE(CLASS),
    .meta.size = sizeof(struct W_CAT(PREFIX,CLASS,__private)),
    .meta.method = W_CAT(CLASS,___methods),
    .meta.property = W_CAT(CLASS,___properties),
    .meta.get_method_offset = W_CAT(CLASS,___get_method_offset),
    .meta.get_property_offset = W_CAT(CLASS,___get_property_offset),
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



const char* W_CAT(CLASS,___properties)[] = {
# define PROPERTY(type,name,...) # name,
    W_CAT(CLASS,__public_properties)
# undef PROPERTY
    NULL
};
const int W_CAT(CLASS,___property_size)[] = {
# define PROPERTY(type,name,...) sizeof(type),
    W_CAT(CLASS,__public_properties)
# undef PROPERTY
    -1
};
const char* W_CAT(CLASS,___methods)[] = {
# define METHOD(C,type,name,args,...) # name,
    W_CAT(CLASS,__inherited_interfaces)
    W_CAT(CLASS,__public_methods)
    "free",
# undef METHOD
    NULL
};
 




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



