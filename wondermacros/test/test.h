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

#undef W_TEST

/***
 *** Name:        W_TEST
 *** Proto:       W_TEST(name,...)
 *** Arg:         name         name of the test case
 *** Arg:         ...          statements to be executed
 *** Description: Use W_TEST to add a unit test directly into a header file.  It is used with the unit test X-Macro.
 ***/
#define W_TEST(name,...)                            \
    {                                               \
        char buf[256];                              \
        sprintf(buf,"[%s:%s] ", # name, __FILE__);  \
        printf("%s ", buf);                         \
        for (size_t i=strlen(buf); i < 80; i++)     \
            printf(" ");                            \
        __VA_ARGS__                                 \
        printf("Ok.\n");                            \
    }

/***
 *** Name:        W_TEST_ASSERT
 *** Proto:       W_TEST_ASSERT(cond,...)
 *** Arg:         cond         a condition expression, should evaluate to non-zero if test ok
 *** Arg:         ...          format and arguments for error reporting
 *** Description: Use W_TEST_ASSERT to run a test in a unit test.
 ***/
#define W_TEST_ASSERT(cond,...)                     \
    if (cond) {                                     \
    } else {                                        \
        printf(" ");                                \
        printf(__VA_ARGS__);                        \
        printf("\n");                               \
        return 1;                                   \
    }

/***
 *** Name:        W_TEST_GROUP
 *** Proto:       W_TEST_GROUP(name)
 *** Arg:         name         a test group name
 *** Description: Use W_TEST_GROUP to group tests in unit testing.
 ***/
#define W_TEST_GROUP(name)                    \
    printf("\n\nGROUP: %s\n\n", # name);

#endif
