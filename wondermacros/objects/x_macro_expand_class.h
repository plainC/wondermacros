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
struct W_CAT(PREFIX,CLASS,__class_private) {
#else
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


/* Expand interfaces. */
#define METHOD(C,type,...) BOOST_PP_OVERLOAD(_METHOD_,__VA_ARGS__)(C,type,__VA_ARGS__)
#define _METHOD_1(C,type,name) type (*name) (struct C* self);
#define _METHOD_2(C,type,name,args) type (*name) (struct C* self, BOOST_PP_REMOVE_PARENS(args));

#define BEGIN(I)
#define END
O_CAT(CLASS,__interfaces)(CLASS)
#undef METHOD
#undef _METHOD_1
#undef _METHOD_2
#undef BEGIN
#undef END

#ifdef X_PRIVATE
# if BOOST_PP_NOT(W_CAT(CLASS,__is_abstract))
    W_CAT(CLASS,__private_methods)
# endif
#endif

    void (*free)(struct W_CAT(PREFIX,CLASS)* self);
};
#undef METHOD
