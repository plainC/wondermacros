/*
 * mp.h: header file providing macros for 'metaprogramming' custom
 * loop constructions in standard C.
 *
 * Accompanies the article on the web at
 *   https://www.chiark.greenend.org.uk/~sgtatham/mp/
 */

#ifndef __W_AFTER_H
#define __W_AFTER_H

/*
 * mp.h is copyright 2012 Simon Tatham.
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
 * NONINFRINGEMENT.  IN NO EVENT SHALL SIMON TATHAM BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */


#include <wondermacros/meta/cat.h>
#include <wondermacros/meta/label.h>

/*
 * MPP_AFTER: run the suffixed statement, and then the code given in
 * the argument 'after'.
 *
 * 'after' should have the syntactic form of one or more declarations
 * and statements, except that a trailing semicolon may be omitted.
 * Any declaration in 'after' will be in scope only within 'after'.
 *
 * This macro is break-unsafe - it causes a 'break' to terminate the
 * suffixed statement only. If you need different behaviour, you can
 * use MPP_BREAK_CATCH and MPP_BREAK_THROW to pass a break past it -
 * but beware that in that case the 'after' clause will not be
 * executed, so MPP_FINALLY or MPP_BREAK_HANDLER may be useful too.
 */
#define W_AFTER(labid,after)                  \
    if (1)                                      \
        goto W_LABEL(labid, body);            \
    else                                        \
        while (1)                               \
            if (1) {                            \
                after;                          \
                break;                          \
            } else                              \
            W_LABEL(labid, body):


/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif

W_TEST(W_AFTER,
    int identifier = 1;
    W_AFTER(1,
        identifier = 2;
    ) W_TEST_ASSERT(identifier == 1, "Value mismatch");
    W_TEST_ASSERT(identifier == 2, "Value mismatch");
)

#endif

