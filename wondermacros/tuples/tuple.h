#ifndef __W_TUPLE_H
#define __W_TUPLE_H

#include <boost/preprocessor/facilities/overload.hpp>
#include <boost/preprocessor/punctuation/remove_parens.hpp>
#include <boost/preprocessor/seq/for_each_i.hpp>
#include <string.h>

#ifndef W_MALLOC_SAFE
#include <unistd.h>
#include <stdio.h>
static inline void*
w_malloc_safe(size_t size)
{
    void* p = malloc(size);
    if (!p) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }
    return p;
}
#define W_MALLOC_SAFE(s) w_malloc_safe(s)
#endif

#define W_TUPLE_TYPE(type_seq) struct { BOOST_PP_SEQ_FOR_EACH_I(_W_TUPLE_TYPE,~,type_seq) }
#define _W_TUPLE_TYPE(z,data,i,elem) elem _ ## i;

#define W_TUPLE_NEW(types,...) \
    memcpy(W_MALLOC_SAFE(sizeof(W_TUPLE_TYPE(types))), \
        &(W_TUPLE_TYPE(types)) { __VA_ARGS__ }, \
        sizeof(W_TUPLE_TYPE(types)))
#define W_TUPLE_ELEM(tuplep,ix) ((tuplep)->_ ## ix)

#endif

