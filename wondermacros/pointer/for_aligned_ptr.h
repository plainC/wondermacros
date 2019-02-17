/* (C) Copyright 2019 J.P. Iivonen <wondermacros@yahoo.com>
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

#ifndef __W_FOR_ALIGNED_PTR_H
#define __W_FOR_ALIGNED_PTR_H

#include <wondermacros/meta/declare.h>
#include <stdint.h>

/***
 *** Name:        W_FOR_ALIGNED_PTR
 *** Proto:       W_FOR_ALIGNED_PTR(T,alignedp,origp,pow2)
 *** Arg:         T          a type name (must be pointer type, e.g. `void*`)
 *** Arg:         alignedp   a free identifier name for the aligned pointer
 *** Arg:         origp      a pointer to be aligned
 *** Arg:         pow2       alignment (power of 2)
 *** Description: Use W_FOR_ALIGNED_PTR to get a properly alinged pointer.
 ***/
#define W_FOR_ALIGNED_PTR(T,alignedp,origp,pow2)                    \
    W_DECLARE(aligned_a,                                            \
        T alignedp = (T) (((uintptr_t) (origp) + ((1<<(pow2))-1)) & \
            ~(uintptr_t) ((1 << (pow2))-1))                         \
    )

/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif

W_TEST(W_FOR_ALIGNED_PTR,
     unsigned correct[] = {
         0x12345671,0x12345672,0x12345674,0x12345678,0x12345680,0x12345680,
         0x12345680,0x12345680,0x12345700,0x12345800,0x12345800,0x12345800,
         0x12346000,0x12346000,0x12348000,0x12348000
    };

    void* p = (void*) 0x12345671;
    for (int i=0; i<16; i++)
        W_FOR_ALIGNED_PTR(void*,ap,p,i)
            W_TEST_ASSERT(correct[i] == (uintptr_t) ap, "%d failed", i);
)

#endif
