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

#ifndef __W_TEST_H
#define __W_TEST_H

#define W_TEST(name,...)                            \
    {                                               \
        char buf[256];                              \
        sprintf(buf,"[%s:%s] ", # name, __FILE__);  \
        printf("%s ", buf);                         \
        for (int i=strlen(buf); i < 80; i++)        \
            printf(" ");                            \
        __VA_ARGS__                                 \
        printf("Ok.\n");                            \
    }

#define W_TEST_ASSERT(cond,...)                     \
    if (cond) {                                     \
    } else {                                        \
        printf(" ");                                \
        printf(__VA_ARGS__);                        \
        return 1;                                   \
    }

#define W_TEST_GROUP(name)                    \
    printf("\n\nGROUP: %s\n\n", name);

#endif

