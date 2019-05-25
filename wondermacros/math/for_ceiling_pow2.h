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

#ifndef __W_FOR_CEILING_POW2_H
#define __W_FOR_CEILING_POW2_H

/***
 *** Name:        W_FOR_CEILING_POW2
 *** Proto:       W_FOR_CEILING_POW2(T,pow2,a)
 *** Arg:         T          an unsigned type name (e.g. `unsigned` or `uint64_t`)
 *** Arg:         pow2       a free variable name to be assigned
 *** Arg:         a          a value
 *** Description: Use W_FOR_CEILING_POW2 to round up to next power of two.
 ***/
#define W_FOR_CEILING_POW2(T,pow2,a)         \
    W_DECLARE(ceiling_pow2a, T pow2 = (a)-1) \
    W_BEFORE(ceiling_pow2b,                  \
        for (size_t W_ID(shift)=1; W_ID(shift) <= (sizeof(T)<<2); W_ID(shift) <<= 1) \
            pow2 |= pow2 >> W_ID(shift);     \
        ++pow2;                              \
    )


/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif

W_TEST(W_FOR_CEILING_POW2,
    for (size_t i=0; i < 1024; i++)
        W_FOR_CEILING_POW2(unsigned,p, i) {
            int t = p;
            t = t - ((t >> 1) & 0x55555555);
            t = (t & 0x33333333) + ((t >> 2) & 0x33333333);
            t = (((t + (t >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
            W_TEST_ASSERT(i==0 || (t == 1 && p >= i), "%d failed (%d)", i, t);
        }
)

#endif

