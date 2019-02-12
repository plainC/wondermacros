/* (C) is Copyright 2018,2019 J.P. Iivonen <wondermacros@yahoo.com>
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

#ifndef __W_HASH_TABLE_H
#define __W_HASH_TABLE_H

#include <wondermacros/pointer/hidden_of.h>
#include <wondermacros/meta/id.h>
#include <wondermacros/meta/wrap.h>
#include <wondermacros/meta/declare.h>
#include <wondermacros/meta/before.h>
#include <wondermacros/debug/debug.h>
#include <stdint.h>
#include <wondermacros/configs/default_allocation.h>
#include <wondermacros/array/dynamic_stack.h>


#ifndef W_EQUAL
# define W_EQUAL(a,b) ((a)==(b))
#endif

#ifndef W_HASH
# define W_HASH(key,x)                   \
    do {                                 \
        x = (key);                       \
        x = ((x >> 16) ^ x) * 0x45d9f3b; \
        x = ((x >> 16) ^ x) * 0x45d9f3b; \
        x = (x >> 16) ^ x;               \
    } while (0)
#endif

#ifndef W_PROBE_NEXT
# define W_PROBE_NEXT(hash,slot) W_HASH_TABLE_LINEAR_PROBE_NEXT(hash,slot)
#endif

#ifndef W_IS_MULTIMAP
# define W_IS_MULTIMAP 0
#endif


#ifndef W_HASH_TABLE_HASH_TO_SLOT
# define W_HASH_TABLE_HASH_TO_SLOT(hash_key,table_size_pow2)                       \
    (((hash_key) * 11400714819323198485LLU) >> (64-(table_size_pow2)))

#endif

#ifndef WDEBUG_EXPAND
#define W_HASH_TABLE_HEADER_TYPE                                                   \
    struct {                                                                       \
        int alloc_size; /* power of two */                                         \
        int nbr_of_elems;                                                          \
    }
#endif


#define W_HASH_TABLE_ALLOC_SIZE(H) \
    (1 << W_HIDDEN_OF(H, W_HASH_TABLE_HEADER_TYPE, alloc_size))

#define W_HASH_TABLE_SIZE(H)                                                       \
    W_HIDDEN_OF(H, W_HASH_TABLE_HEADER_TYPE, nbr_of_elems)


#define W_HASH_TABLE_ELEM_SIZE(H)                                                  \
    (sizeof((H)[0]))

/***
 *** Name:        W_HASH_TABLE_INIT
 *** Proto:       W_HASH_TABLE_INIT(H,pow2_size)
 *** Arg:         H          a pointer to a hash table.
 *** Arg:         pow2_size  size of the hash table (an exponent of power two)
 *** Description: Use W_HASH_TABLE_FREE to free a hash table.
 ***/
#define W_HASH_TABLE_INIT(H,pow2_size)                                             \
    W_WRAP(W_HASH_TABLE_INIT,                                                      \
        (H) = W_MALLOC0(                                                           \
            sizeof(W_HASH_TABLE_HEADER_TYPE)                                       \
            + W_HASH_TABLE_BITMAP_SIZE(pow2_size)                                  \
            + W_HASH_TABLE_ELEM_SIZE(H) * (1 << (pow2_size))                       \
        );                                                                         \
        if ((H) == NULL)                                                           \
            W_ERROR_ALLOCATION;                                                    \
        (H) = W_REF_VOID_PTR(H, sizeof(W_HASH_TABLE_HEADER_TYPE)                   \
            + W_HASH_TABLE_BITMAP_SIZE(pow2_size));                                \
        W_HIDDEN_OF(H, W_HASH_TABLE_HEADER_TYPE, alloc_size) = (pow2_size);        \
        W_HIDDEN_OF(H, W_HASH_TABLE_HEADER_TYPE, nbr_of_elems) = 0;                \
    )

#define W_HASH_TABLE_BITMAP_SIZE(pow2_size)                                        \
    (1+((1 << (pow2_size)) >> 3))

#define W_HASH_TABLE_BITMAP(H)                                                     \
    ((uint32_t*) W_REF_VOID_PTR(H,                                                 \
        - sizeof(W_HASH_TABLE_HEADER_TYPE)                                         \
        - W_HASH_TABLE_BITMAP_SIZE(W_HIDDEN_OF(H, W_HASH_TABLE_HEADER_TYPE, alloc_size))))

#define W_HASH_TABLE_SET_SLOT(H,slot)                                              \
    (W_HASH_TABLE_BITMAP(H)[(slot) >> 5]) |= (1U << ((slot) & 31))
#define W_HASH_TABLE_RESET_SLOT(H,slot)                                            \
    (W_HASH_TABLE_BITMAP(H)[(slot) >> 5]) &= (~(1U << ((slot) & 31)))
#define W_HASH_TABLE_GET_SLOT(H,slot)                                              \
    ( (W_HASH_TABLE_BITMAP(H)[(slot) >> 5]) & (1U << ((slot) & 31)) )


#define W_HASH_TABLE_LINEAR_PROBE_NEXT(hash,slot)                                  \
    (((slot) + 1) & ((1 << W_HIDDEN_OF(hash, W_HASH_TABLE_HEADER_TYPE, alloc_size))-1))

/***
 *** Name:        W_HASH_TABLE_PUSH
 *** Proto:       W_HASH_TABLE_PUSH(T,H,Key,Value)
 *** Arg:         T        type name of a hash mapping
 *** Arg:         H        a pointer to a hash table.
 *** Arg:         Key      a key to be mapped
 *** Arg:         Value    a value to be mapped
 *** Description: Use W_HASH_TABLE_FREE to free a hash table.
 ***/
#define W_HASH_TABLE_PUSH(T,H,Key,Value)                                           \
    _W_HASH_TABLE_PUSH(H,Key,Value, W_HASH_TABLE_GROW(T,H);)

#define _W_HASH_TABLE_PUSH(H,Key,Value,rehashing)                                  \
    W_WRAP(_W_HASH_TABLE_PUSH,                                                     \
        if ((H) == NULL)                                                           \
            W_HASH_TABLE_INIT(H,3);                                                \
        else if (W_HASH_TABLE_SIZE(H) > (0.75 * W_HASH_TABLE_ALLOC_SIZE(H)))       \
            { rehashing }                                                          \
        int W_ID(pow2_size) = W_HIDDEN_OF(H, W_HASH_TABLE_HEADER_TYPE, alloc_size);\
        int W_ID(slot);                                                            \
        int W_ID(count) = 1;                                                       \
        /* (i) use hash function. */                                               \
        W_HASH(Key,W_ID(slot));                                                    \
        /* (ii) get a slot in the table based on the size of the table. */         \
        W_ID(slot) = W_HASH_TABLE_HASH_TO_SLOT(W_ID(slot), W_ID(pow2_size));       \
        /* (iii) get a slot that is actually free, use probing. */                 \
        while (W_HASH_TABLE_GET_SLOT(H, W_ID(slot))) {                             \
            if (W_EQUAL(Key, (H)[W_ID(slot)].key)) {                               \
                W_ID(count) = 0;                                                   \
                break;                                                             \
            }                                                                      \
            W_ID(slot) = W_PROBE_NEXT(H,W_ID(slot));                               \
        }                                                                          \
        (H)[W_ID(slot)].key = (Key);                                               \
        (H)[W_ID(slot)].value = (Value);                                           \
        W_HASH_TABLE_SET_SLOT(H, W_ID(slot));                                      \
        W_HIDDEN_OF(H, W_HASH_TABLE_HEADER_TYPE, nbr_of_elems) += W_ID(count);     \
    )

#define W_HASH_TABLE_GROW(T,H)                                                     \
    W_WRAP(W_HASH_TABLE_GROW,                                                      \
        void* W_ID(old_start) = W_HASH_TABLE_BITMAP(H);                            \
        int W_ID(new_size) = W_HIDDEN_OF(H, W_HASH_TABLE_HEADER_TYPE,alloc_size)+1;\
        W_DEBUG("HASH table grow: 2^%d\n", W_ID(new_size));                        \
        void* W_ID(old_H) = (H);                                                   \
        W_HASH_TABLE_INIT(H, W_ID(new_size));                                      \
        W_HASH_TABLE_REHASH(T,H, W_ID(old_H));                                     \
        W_FREE(W_ID(old_start));                                                   \
    )

#define W_HASH_TABLE_REHASH(T,H,old_H)                                             \
    W_WRAP(W_HASH_TABLE_REHASH,                                                    \
        for (int i=0; i<W_HASH_TABLE_ALLOC_SIZE(old_H); i++) {                     \
            if (W_HASH_TABLE_GET_SLOT(old_H,i)) {                                  \
                _W_HASH_TABLE_PUSH(H, ((T*) (old_H))[i].key,                       \
                     ((T*) (old_H))[i].value, /* Cannot happen to me */);          \
            }                                                                      \
        }                                                                          \
    )

/***
 *** Name:        W_HASH_TABLE_FOR_EACH_MATCH
 *** Proto:       W_HASH_TABLE_FOR_EACH_MATCH(T,match,H,Key)
 *** Arg:         T        type name of a hash mapping
 *** Arg:         match    a free variable
 *** Arg:         H        a pointer to a hash table.
 *** Arg:         Key      key to be matched
 *** Description: Use W_HASH_TABLE_FREE to free a hash table.
 ***/
#define W_HASH_TABLE_FOR_EACH_MATCH(T,match,H,Key)                                 \
    W_DECLARE(1, T* match)                                                         \
    W_DECLARE(2, int W_ID(slot))                                                   \
    W_BEFORE(3,                                                                    \
        W_HASH(Key, W_ID(slot));                                                   \
        W_ID(slot) = W_HASH_TABLE_HASH_TO_SLOT(W_ID(slot),                         \
             W_HIDDEN_OF(H, W_HASH_TABLE_HEADER_TYPE, alloc_size));                \
    )                                                                              \
    for ( ;                                                                        \
        W_HASH_TABLE_GET_SLOT(H, W_ID(slot)) && (match=&(H)[W_ID(slot)],1);        \
        W_ID(slot) = W_PROBE_NEXT(H, W_ID(slot))                                   \
    )                                                                              \
        for ( ; match && W_EQUAL(Key, match->key); match = NULL)


/***
 *** Name:        W_HASH_TABLE_FREE
 *** Proto:       W_HASH_TABLE_FREE(H)
 *** Arg:         H  a pointer to a hash table.
 *** Description: Use W_HASH_TABLE_FREE to free a hash table.
 ***/
#define W_HASH_TABLE_FREE(H)                                                       \
    if ((H) == NULL) {} else W_FREE(W_HASH_TABLE_BITMAP(H))


/***
 *** Name:        W_HASH_TABLE_REMOVE
 *** Proto:       W_HASH_TABLE_REMOVE(H,Key,matched)
 *** Arg:         H        a pointer to a hash table.
 *** Arg:         Key      key to be removed
 *** Arg:         matched  integer variable to be set if a mapping is removed
 *** Description: Use W_HASH_TABLE_FREE to free a hash table.
 ***/
#define W_HASH_TABLE_REMOVE(H,Key,matched)                                         \
    W_WRAP(W_HASH_TABLE_REMOVE,                                                    \
        int W_ID(slot);                                                            \
        W_HASH(Key, W_ID(slot));                                                   \
        W_ID(slot) = W_HASH_TABLE_HASH_TO_SLOT(W_ID(slot),                         \
             W_HIDDEN_OF(H, W_HASH_TABLE_HEADER_TYPE, alloc_size));                \
        (matched) = 0;                                                             \
        while (W_HASH_TABLE_GET_SLOT(H, W_ID(slot))) {                             \
            if (W_EQUAL(Key, (H)[W_ID(slot)].key)) {                               \
                (matched)++;                                                       \
                int W_ID(prev) = W_ID(slot);                                       \
                W_ID(slot) = W_PROBE_NEXT(H,W_ID(slot));                           \
                while (W_HASH_TABLE_GET_SLOT(H, W_ID(slot))) {                     \
                    (H)[W_ID(prev)] = (H)[W_ID(slot)];                             \
                    W_ID(slot) = W_PROBE_NEXT(H,W_ID(slot));                       \
                }                                                                  \
                W_HASH_TABLE_RESET_SLOT(H,W_ID(prev));                             \
            } else                                                                 \
                W_ID(slot) = W_PROBE_NEXT(H,W_ID(slot));                           \
        }                                                                          \
    )

#endif

