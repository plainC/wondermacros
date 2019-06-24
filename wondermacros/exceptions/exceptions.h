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
#ifndef __W_EXCEPTIONS_H__
#define __W_EXCEPTIONS_H__


#include <wondermacros/exceptions/default_policy.h>

#include <setjmp.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include <wondermacros/array/get_size.h>
#include <wondermacros/meta/id.h>
#include <wondermacros/meta/declare.h>
#include <wondermacros/meta/after.h>
#include <wondermacros/meta/before.h>
#include <wondermacros/meta/finally.h>
#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/comparison/greater.hpp>
#include <boost/preprocessor/variadic/size.hpp>

#ifndef EXTERN
# define EXTERN extern
#endif


#ifndef W_EXCEPTION_ERROR_MESSAGE_LENGTH
# define W_EXCEPTION_ERROR_MESSAGE_LENGTH 128
#endif

#define W_EXCEPTION_TYPE                                \
    struct {                                            \
        int status;                                     \
        jmp_buf buf;                                    \
        int line;                                       \
        const char* func;                               \
        const char* file;                               \
        int _errno;                                     \
        char message[W_EXCEPTION_ERROR_MESSAGE_LENGTH]; \
    }

/***
 *** Name:        W_EXCEPTION_STACK_DECLARE
 *** Proto:       W_EXCEPTION_STACK_DECLARE(size)
 *** Arg:         size      the size of the exception stack, e.g. 64
 *** Description: Use W_EXCEPTION_STACK_DECLARE to declare an exception stack. Use it in the global scope (outside any function) in a C file. Use also in a header with extern prefix and with emphty size argument.
 ***/
#define W_EXCEPTION_STACK_DECLARE(size)                 \
    W_EXCEPTION_TYPE w_exception_stack[size],           \
        *w_exception_ptr = w_exception_stack            \

/***
 *** Name:        W_EXCEPTION_RESET_LAST
 *** Proto:       W_EXCEPTION_RESET_LAST
 *** Description: Use W_EXCEPTION_RESET_LAST to clear all data related to last exception. with extern prefix and with emphty size argument.
 ***/
#define W_EXCEPTION_RESET_LAST                          \
    (*(w_exception_ptr+1)).status =                     \
        (*(w_exception_ptr+1))._errno =                 \
        (*(w_exception_ptr+1)).line =                   \
        (*(w_exception_ptr+1)).message[0] = 0,          \
    (*(w_exception_ptr+1)).func =                       \
        (*(w_exception_ptr+1)).file = NULL 

/***
 *** Name:        W_TRY
 *** Proto:       W_TRY
 *** Description: Use W_TRY to run code which may cause exceptions. Use W_THROW to throw an exception inside W_TRY block. Use W_CATCH or W_CATCH_ALL to catch exceptions after W_TRY block.
 *** Notes:       Exception stack must be declared using W_EXCEPTION_STACK_DECLARE.
 ***/
#define W_TRY                                           \
    W_DECLARE(0, int W_ID(done))                        \
    W_BEFORE(1,                                         \
        if (w_exception_ptr+1 == &w_exception_stack     \
            [W_ARRAY_GET_SIZE(w_exception_stack)]) {    \
            fprintf(stderr, "FATAL ERROR: "             \
                "Exception stack overflow. "            \
                "Too many nested W_TRYs.\n");           \
            exit(1);                                    \
        }                                               \
        errno = 0;                                      \
        W_EXCEPTION_RESET_LAST;                         \
        ++w_exception_ptr;                              \
        if (setjmp((*w_exception_ptr).buf))             \
            W_ID(done) = 1;                             \
        else                                            \
            W_ID(done) = 0;                             \
    )                                                   \
    W_FINALLY(2,                                        \
        --w_exception_ptr;                              \
        W_ID(done) = 1;                                 \
    )                                                   \
    for ( ; !W_ID(done); ++W_ID(done))                  \

/***
 *** Name:        W_THROW
 *** Proto:       W_THROW(err[,...])
 *** Arg:         err   an integer other than zero
 *** Description: Use W_THROW to throw an exception inside W_TRY block.
 ***/
#define W_THROW(...)                                    \
    do {                                                \
        BOOST_PP_IF(                                    \
            BOOST_PP_GREATER(                           \
                BOOST_PP_VARIADIC_SIZE(__VA_ARGS__),1), \
            _W_THROW_VA(__VA_ARGS__),                   \
            _W_THROW_1(__VA_ARGS__)                     \
        )                                               \
    } while (0)

#define _W_THROW_1(err,...)                             \
    (*w_exception_ptr).status = (err);                  \
    (*w_exception_ptr).line = __LINE__;                 \
    (*w_exception_ptr).func = __func__;                 \
    (*w_exception_ptr).file = __FILE__;                 \
    (*w_exception_ptr)._errno = errno;                  \
    longjmp((*w_exception_ptr).buf, 0);                 \

#define _W_THROW_VA(err,...)                            \
    snprintf((*w_exception_ptr).message,                \
        W_EXCEPTION_ERROR_MESSAGE_LENGTH, __VA_ARGS__); \
    _W_THROW_1(err)                                     \

/***
 *** Name:        W_CATCH
 *** Proto:       W_CATCH(err)
 *** Arg:         err   an integer other than zero
 *** Description: Use W_CATCH to catch exceptions of a given error class. It will clear the last exception from memory so another catch following will not trigger.
 ***/
#define W_CATCH(err)                                    \
    for (int W_ID(catch)=1; W_ID(catch) &&              \
        (*(w_exception_ptr+1)).status == (err);         \
        W_EXCEPTION_RESET_LAST,W_ID(catch)=0)           \

/***
 *** Name:        W_CATCH_ALL
 *** Proto:       W_CATCH_ALL
 *** Description: Use W_CATCH_ALL to catch exceptions of all kinds. It will clear the last exception from memory so another catch following will not trigger.
 ***/
#define W_CATCH_ALL                                     \
    for (int W_ID(catch)=1; W_ID(catch) &&              \
        (*(w_exception_ptr+1)).status;                  \
        W_EXCEPTION_RESET_LAST,W_ID(catch)=0)           \

/***
 *** Name:        W_EXCEPTION_FPRINTF
 *** Proto:       W_EXCEPTION_FPRINTF(out)
 *** Description: Use W_EXCEPTION_FPRINTF to print an error message of latest exception into a file (e.g. stderr).
 ***/
#define W_EXCEPTION_FPRINTF(out)                        \
    if ((*(w_exception_ptr+1)).status)                  \
        fprintf(out, "[%s:%d:%s][%d%s%s] %s\n",         \
            (*(w_exception_ptr+1)).file,                \
            (*(w_exception_ptr+1)).line,                \
            (*(w_exception_ptr+1)).func,                \
            (*(w_exception_ptr+1))._errno,              \
            (*(w_exception_ptr+1))._errno ? ":" : "",   \
            (*(w_exception_ptr+1))._errno ?             \
                strerror((*(w_exception_ptr+1))._errno):\
                "",                                     \
            (*(w_exception_ptr+1)).message              \
        );                                              \
    else                                                \
        fprintf(out, "[no exceptions in the stack]\n")

#endif
