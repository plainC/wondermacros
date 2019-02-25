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
#include <wondermacros/meta/id.h>
#include <wondermacros/meta/cat_inner.h>
#include <wondermacros/configs/default_allocation.h>
#include <stddef.h>


#ifndef CLASS
# error "Macro CLASS is not defined"
#endif

#ifndef ABSTRACT


#define WRITE_CH(ch)                                  \
    if (!--size)                                      \
        return 1;                                     \
    else                                              \
        *buffer++ = (ch)

#define WRITE_STR(str,len)                            \
    do {                                              \
        if (size <= (len))                            \
            return 1;                                 \
        for (int W_ID(i)=0; W_ID(i)<(len); W_ID(i)++) \
            *buffer++ = (str)[W_ID(i)];               \
        size -= (len);                                \
    } while (0)

int
W_CAT(CLASS,_to_json)(struct CLASS* _self, char* buffer, size_t size)
#ifdef W_CLASS_DECLARE
;
#endif
#ifdef W_CLASS_GENERATE
{
    struct W_CAT(CLASS,__private)* self = (struct W_CAT(CLASS,__private)*) _self;

    WRITE_STR("{ ",2);
    for (int i=0; self->klass->meta.property_name[i]; i++) {
        /* Add comma if not the first. */
        if (i > 0)
            WRITE_STR(", ",2);

        /* Write the name of the property. */
        WRITE_CH('\"');
        WRITE_STR(self->klass->meta.property_name[i],self->klass->meta.property_len[i]);
        WRITE_STR("\":",2);

        /* Serialize the value of the property. */
        int len = self->klass->meta.property_type[i].to_string(W_REF_VOID_PTR(self, self->klass->meta.property_offset[i]), buffer, size);
        buffer += len;
        size -= len;
    }
    WRITE_STR(" }",2);
    WRITE_CH(0);

    return 0;
}
#undef WRITE_CH
#undef WRITE_STR

#endif

#endif

