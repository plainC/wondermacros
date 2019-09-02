//#define UNITTEST_FILE "tests/Lisp.h"

#include "Object.h"
#include "Writer.h"
#include "Int.h"
#include "Symbol.h"
#include "Cons.h"
#include "String.h"
#include "WhiteSpace.h"
#include "EvalContext.h"
#include "Quote.h"
#include "hash_func.h"
#include "oo_introspection.h"

#include <string.h>

#define W_EQUAL(a,b) (strcmp((const char*) (a), (const char*) (b)) == 0)
#define W_HASH(key,h) (h = strhash(key))
#include <wondermacros/array/hash_table.h>


#define NAME Lisp
#include "x/class_generate.h"


CONSTRUCT
{
    W_DYNAMIC_ARRAY_PUSH(self->readtable[' '], WhiteSpace___read);
    W_DYNAMIC_ARRAY_PUSH(self->readtable['\n'], WhiteSpace___read);
    W_DYNAMIC_ARRAY_PUSH(self->readtable['\r'], WhiteSpace___read);
    W_DYNAMIC_ARRAY_PUSH(self->readtable['\t'], WhiteSpace___read);

    for (int ch = '0'; ch <= '9'; ++ch) {
        W_DYNAMIC_ARRAY_PUSH(self->readtable[ch], Int___read);
    }
    for (char ch = 'A'; ch <= 'Z'; ++ch)
        W_DYNAMIC_ARRAY_PUSH(self->readtable[ch], Symbol___read);
    for (char ch = 'a'; ch <= 'z'; ++ch)
        W_DYNAMIC_ARRAY_PUSH(self->readtable[ch], Symbol___read);

    char table[] = { '*', '+', '-', '/', '<', '=', '>', '?', '_', 0 };
    for (int i=0; table[i]; ++i)
        W_DYNAMIC_ARRAY_PUSH(self->readtable[table[i]], Symbol___read);

    W_DYNAMIC_ARRAY_PUSH(self->readtable['('], Cons___read);
    W_DYNAMIC_ARRAY_PUSH(self->readtable['\"'], String___read);
    W_DYNAMIC_ARRAY_PUSH(self->readtable['\''], Quote___read);

    self->quote = W_NEW(Quote);


    W_HASH_TABLE_PUSH(intern_map_t, self->classes, "Int", &Int__class_instance);
    W_HASH_TABLE_PUSH(intern_map_t, self->classes, "String", &String__class_instance);

}

w_read_status_t
STATIC_METHOD(_read)(const char** str, size_t* size, Lisp* lisp, Object** ret)
{
  again:
    W_DYNAMIC_ARRAY_FOR_EACH(readtable_func, func, lisp->readtable[**str]) {
        w_read_status_t status = func(str, size, lisp, ret);
        if (status == W_READ_OK)
            return W_READ_OK;
        if (status == W_READ_EATEN)
            goto again;
    }
    printf("Error\n");
    return W_READ_NOK;
}

bool
METHOD(register_reader)(int priority, char ch, bool (*accept)(const char*, const char**))
{
    self->readtable[ch] = accept;
}

Symbol*
METHOD(intern)(const char* name, size_t len)
{
    char buf[64];
    strncpy(buf, name, len);
    buf[len] = 0;

    W_HASH_TABLE_FOR_EACH_MATCH(intern_map_t, match, self->interned, buf) {
        return match->value;
    }

    Symbol* sym = W_NEW(Symbol, .name = strndup(name, len));
    W_HASH_TABLE_PUSH(intern_map_t, self->interned, name, sym);

    return sym;
}

Object*
METHODV(read)
{
    char buf[256];
    fgets(buf, 256, stdin);

    char* str = buf;
    size_t len = strlen(buf);
    Object* ret;

    w_read_status_t status = Lisp___read(&str, &len, self, &ret);
    if (status == W_READ_OK)
        return ret;
    else
        printf("ERROR\n");
    return NULL;
}

bool
METHOD(add_class)(Class* klass)
{
    
}

void
METHODV(repl)
{
    Object* o;
    EvalContext* ctxt = W_NEW(EvalContext, .lisp = self);

    do {
        printf("\n> ");
        fflush(stdout);
        o = W_CALLV(self,read);
        if (o)
            o = W_CALL(o,eval)(ctxt);
        if (o)
            W_CALL(o,print)(stdout);
        else
            printf("NIL");
    } while (true);
}



#define NAME Lisp
#include "x/class_vtable.h"

