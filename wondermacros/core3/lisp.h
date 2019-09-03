#ifndef __LISP_EXT_H
#define __LISP_EXT_H

#include <wondermacros/meta/id.h>

#define CAR(l) (((Cons*)(l))->car)
#define CDR(l) (((Cons*)(l))->cdr)
#define CADR(l) (CAR(CDR(l)))
#define CDDR(l) (CDR(CDR(l)))

#define REVERSE(list)                    \
    do {                                 \
        Cons* W_ID(prev) = NULL;         \
        Cons* W_ID(cur) = (list);        \
        Cons* W_ID(next);                \
        while (W_ID(cur)) {              \
            W_ID(next) = W_ID(cur)->cdr; \
            W_ID(cur)->cdr = W_ID(prev); \
            W_ID(prev) = W_ID(cur);      \
            W_ID(cur) = W_ID(next);      \
        }                                \
        list = W_ID(prev); \
    } while (0);

#define CONS(a,b) W_NEW(Cons, .car = (a), .cdr = (b))

#define STRING(s) (W_OBJECT_AS(s,String)->cstr)
#define INT(v) (W_OBJECT_AS(v,Int)->value)

#define MKSTRING(b) W_NEW(String, .cstr = (b))
#define MKINT(v) W_NEW(Int, .value = (v))
#define MKCHAR(ch) W_NEW(Character, .value = (ch))

#endif

