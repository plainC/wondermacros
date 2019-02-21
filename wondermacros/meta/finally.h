#ifndef __W_FINALLY_H
#define __W_FINALLY_H

/*
 * finally.h is copyright 2012 Simon Tatham.
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
 * MPP_FINALLY: execute the suffixed statement, and execute the
 * provided 'finally' clause after it finishes. If it terminates by
 * 'break', execute the same 'finally' clause but propagate the break
 * to the containing statement.
 *
 * 'finally' should have the syntactic form of one or more
 * declarations and statements, except that a trailing semicolon may
 * be omitted.
 *
 * The 'finally' argument will be double-expanded. Of course it'll
 * only be executed once in any given run, so that's not a concern for
 * function side effects, but don't do anything fiddly like declaring
 * a static variable to which you return a pointer and then expecting
 * the pointer to be the same no matter which copy of 'finally' it
 * came from.
 *
 * This macro is artificially transparent to 'break': it passes break
 * through, but includes a 'break' statement at the top level, so it
 * must always be contained inside some loop or switch construction.
 */
#define W_FINALLY(labid, finally)                     \
    if (1) {                                            \
        goto W_LABEL(labid, body);                    \
      W_LABEL(labid, break):                          \
        {finally;}                                      \
        break;                                          \
      W_LABEL(labid, finish):                         \
        {finally;}                                      \
    } else                                              \
        while (1)                                       \
            if (1)                                      \
                goto W_LABEL(labid, break);           \
            else                                        \
                while (1)                               \
                    if (1)                              \
                        goto W_LABEL(labid, finish);  \
                    else                                \
                    W_LABEL(labid, body):

#endif

