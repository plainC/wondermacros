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

/* Do not include this file directly. */


#ifdef X_PRIVATE
# define METHOD(C,type,name,args,...) \
    type (*name) (struct BOOST_PP_CAT(BOOST_PP_CAT(PREFIX,CLASS),__private)* self \
        BOOST_PP_REMOVE_PARENS(args));
struct W_CAT(PREFIX,CLASS,__class_private) {
#else
# define METHOD(C,type,name,args,...) \
    type (*name) (struct BOOST_PP_CAT(PREFIX,CLASS)* self \
        BOOST_PP_REMOVE_PARENS(args));
struct W_CAT(PREFIX,CLASS,__class) {
#endif
    void* start[0];
    struct {
        const char* name;
        size_t size;
        const char** method;
        const char** property;
        int (*get_method_offset)(const char* name);
        int (*get_property_offset)(const char* name);
    } meta;
    void* vftb[0];
    W_CAT(CLASS,__inherited_interfaces)

    W_CAT(CLASS,__public_methods)
#ifdef X_PRIVATE
# if BOOST_PP_NOT(W_CAT(CLASS,__is_abstract))
    W_CAT(CLASS,__private_methods)
# endif
#endif
    void (*free)(struct W_CAT(PREFIX,CLASS)* self);
};
#undef METHOD
