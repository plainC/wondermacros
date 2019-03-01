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

#ifndef WDEBUG_EXPAND
# include <stddef.h>
# include <ctype.h>
#endif


#ifndef CLASS
# error "Macro CLASS is not defined"
#endif

#ifndef ABSTRACT


#define WRITE_CH(ch)                                  \
    if (!--size)                                      \
        return -1;                                     \
    else                                              \
        *buffer++ = (ch)

#define WRITE_STR(str,len)                            \
    do {                                              \
        if (size <= (len))                            \
            return -1;                                 \
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
    const char* orig = buffer;
    struct W_CAT(CLASS,__private)* self = (struct W_CAT(CLASS,__private)*) _self;

    if (!self) {
        WRITE_STR("null",4);
        return 4;
    }

    WRITE_STR("{ ",2);
    int count = 0;

    for (int i=0; self->klass->meta.property_name[i]; i++) {

        if (! self->klass->meta.property_type[i].to_string)
            continue;

        /* Add comma if not the first. */
        if (count > 0)
            WRITE_STR(", ",2);

        /* Write the name of the property. */
        WRITE_CH('\"');
        WRITE_STR(self->klass->meta.property_name[i],self->klass->meta.property_len[i]);
        WRITE_STR("\":",2);

        /* Serialize the value of the property. */
        int len = self->klass->meta.property_type[i].to_string(W_REF_VOID_PTR(self, self->klass->meta.property_offset[i]), buffer, size);
        if (len < 0)
            return -1;
        buffer += len;
        size -= len;
        ++count;
    }
    WRITE_STR(" }",2);
    *buffer='\0';

    return buffer-orig;
}
#undef WRITE_CH
#undef WRITE_STR

#endif

/**/

#define SKIP_WS \
    while (isspace(*p)) \
        ++p
#define SKIP_UNTIL(ch) \
    while (*p != ch) \
        ++p

#define ACCEPT(ch) \
    if (*p++ == ch) \
        {} \
    else \
        return 1

#define LOOKUP_PROPERTY(index,self,name,len) \
    do { \
        (index) = -1; \
        for (int W_ID(i) = 0; (self)->klass->meta.property_name[W_ID(i)]; W_ID(i)++) \
            if (strncmp((self)->klass->meta.property_name[W_ID(i)],(name),(len))==0) { \
                (index) = W_ID(i); \
                break; \
            } \
    } while (0)

int
W_CAT(CLASS,_from_json)(struct CLASS* _self, const char* buffer, const char** endptr)
#ifdef W_CLASS_DECLARE
;
#endif
#ifdef W_CLASS_GENERATE
{
    struct W_CAT(CLASS,__private)* self = (struct W_CAT(CLASS,__private)*) _self;

    const char* p = buffer;
    const char* str;
    int index = (-1);

    if (self == NULL)
        return 1;

    SKIP_WS;
    if (*p == ',') {
        ACCEPT(',');
        SKIP_WS;
    }
    if (strncmp(p, "null",4)==0) {
        p+=4;
        SKIP_WS;
        *endptr = p; //FIXME: set self=NULL and free the allocation
        return 0;
    }
    ACCEPT('{');
    SKIP_WS;
    while (*p != '}') {
        if (index != (-1)) {
            ACCEPT(',');
            SKIP_WS;
        }
        ACCEPT('\"');
        str = p;
        SKIP_UNTIL('\"');
        LOOKUP_PROPERTY(index, self, str, p-str);

        if (index == (-1))
            return 1;

        ACCEPT('\"');
        SKIP_WS;
        ACCEPT(':');
        SKIP_WS;

        if (!self->klass->meta.property_type[index].from_string)
            return 1;

        if (self->klass->meta.property_type[index].from_string(p, endptr, W_REF_VOID_PTR(self, self->klass->meta.property_offset[index])))
            return 1;

        p = *endptr;        
        SKIP_WS;
    }
    ACCEPT('}');

    *endptr = p;

    return 0;
}

#endif

#endif

#undef WRITE_CH
#undef WRITE_STR
#undef SKIP_WS
#undef ACCEPT
#undef SKIP_UNTIL
#undef LOOKUP_PROPERTY

