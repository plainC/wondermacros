//#define UNITTEST_FILE "tests/Lisp.h"

#include "Object.h"
#include "Writer.h"
#include "Int.h"
#include "Symbol.h"
#include "Cons.h"

#include <string.h>

#define NAME Lisp
#include "x/class_generate.h"

static Object* read_(char** str, size_t* size, Lisp* lisp);

static Object*
read_number(char** str, size_t* size, Lisp* lisp)
{
    char* endptr;
    int64_t val = strtoll(*str, &endptr, 10);

    *size -= endptr - *str;
    *str = endptr;

    return W_NEW(Int, .value = val);
}

static Object*
read_symbol(char** str, size_t* size, Lisp* lisp)
{
    int pos;
    for (pos = 0; lisp->readtable[(*str)[pos]] == read_symbol
            || lisp->readtable[(*str)[pos]] == read_number; ++pos)
        ;

    char* s = strndup(*str, pos);
    *str += pos;
    *size -= pos;

    return W_NEW(Symbol, .name = s); 
}

static Object*
read_ws(char** str, size_t* size, Lisp* lisp)
{
    while (lisp->readtable[**str] == read_ws)
        *str += 1, *size -= 1;

    return NULL;
}

static Object*
read_cons(char** str, size_t* size, Lisp* lisp)
{
    /* Eat '(' */
    *str += 1;
    *size -= 1;
    read_ws(str, size, lisp);

    Cons* list = NULL;
    Cons* last;
    do {
        Cons* new_item = W_NEW(Cons, .car = read_(str, size, lisp), .cdr = NULL);

        if (!list)
            list = last = new_item;
        else {
            last->cdr = new_item;
            last = new_item;
        }
        read_ws(str, size, lisp);
    } while (**str != ')');

    /* Eat ')' */
    *str += 1;
    *size -= 1;

    return list;
}

CONSTRUCT
{
    for (int ch = 0; ch < 256; ++ch)
        self->readtable[ch] = read_symbol;

    self->readtable[' '] = read_ws;
    self->readtable['\n'] = read_ws;

    for (char ch = '0'; ch <= '9'; ++ch)
        self->readtable[ch] = read_number;

    self->readtable['('] = read_cons;
}

static Object*
read_(char** str, size_t* size, Lisp* lisp)
{
    read_ws(str, size, lisp);
    return lisp->readtable[**str](str, size, lisp);
}

Object*
METHODV(read)
{
    char buf[256];
    fgets(buf, 256, stdin);

    char* str = buf;
    size_t len = strlen(buf);

    return read_(&str, &len, self);
}

void
METHODV(repl)
{
    Object* o;
    do {
        printf("\n> ");
        fflush(stdout);
        o = W_CALLV(self,read);
        W_CALL(o,print)(stdout);
    } while (true);
}



#define NAME Lisp
#include "x/class_vtable.h"

