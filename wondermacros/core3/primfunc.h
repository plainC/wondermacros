#define block(...) do { __VA_ARGS__ } while (0)

#define exception(...) \
    block(printf(__VA_ARGS__); return NULL; )


#define FOR_EACH_ARG(T,arg) \
    for (T* arg = W_OBJECT_AS(CAR(args), T); \
        arg && W_OBJECT_IS(arg, T); args = CDR(args), arg = args ? CAR(args):NULL)

#define CHECK_ARGC(n) W_CAT(_CHECK_ARGC_,n)
#define _CHECK_ARGC_0 \
    block(if (args != NULL) exception("%s does not except arguments",_fn_);)
#define _CHECK_ARGC_1 \
    block(if (args == NULL || CDR(args) != NULL) \
          exception("%s expects one argument",_fn_);)
#define _CHECK_ARGC_2 \
    block(if (args == NULL || CDR(args) == NULL || CDDR(args) != NULL) \
          exception("%s expects two argument",_fn_);)

#define CHECK_MIN_ARGC(n) W_CAT(_CHECK_MIN_ARGC_,n)
#define _CHECK_MIN_ARGC_1 \
    block(if (args == NULL) \
          exception("%s expects at least one argument",_fn_);)

#define CHECK_ARG_TYPE(n,T) W_CAT(_CHECK_ARG_TYPE_,n)(T)
#define _CHECK_ARG_TYPE_0(T) \
    block(if (!W_OBJECT_IS(CAR(args),T)) \
          exception("%s: first argument is expected to be %s",_fn_,#T);)
#define _CHECK_ARG_TYPE_1(T) \
    block(if (!W_OBJECT_IS(CADR(args),T)) \
          exception("%s: second argument is expected to be %s",_fn_,#T);)

#define CHECK(cond,...) \
    block(if (!(cond)) exception(__VA_ARGS__);)

#include "primfunc-clos.h"
#include "primfunc-logical.h"


FUNC(add,+,
    CHECK_MIN_ARGC(1);
    int sum = 0;
    FOR_EACH_ARG(Int, arg)
        sum += arg->value;

    return W_NEW(Int, .value = sum);
)


FUNC(cons,cons,
    CHECK_ARGC(2);
    return CONS(CAR(args),CADR(args));
)


FUNC(length,length,
    CHECK_ARGC(1);
    CHECK_ARG_TYPE(0, String);
    return MKINT(strlen(STRING(CAR(args))));
)

FUNC(string_equal,string-equal,
    CHECK_ARGC(2);
    CHECK_ARG_TYPE(0, String);
    CHECK_ARG_TYPE(1, String);
    int len_l = strlen(STRING(CAR(args)));
    int len_r = strlen(STRING(CADR(args)));
    if (len_l != len_r)
        return NULL;
    const char* l = STRING(CAR(args));
    const char* r = STRING(CADR(args));
    while (*l && tolower(*l) == tolower(*r)) {
        ++l;
        ++r;
    }
    return *l ? NULL : context->lisp->t;
)

FUNC(string_not_equal,string-not-equal,
    CHECK_ARGC(2);
    CHECK_ARG_TYPE(0, String);
    CHECK_ARG_TYPE(1, String);
    int len_l = strlen(STRING(CAR(args)));
    int len_r = strlen(STRING(CADR(args)));
    if (len_l != len_r)
        return context->lisp->t;
    const char* l = STRING(CAR(args));
    const char* r = STRING(CADR(args));
    while (*l && tolower(*l) == tolower(*r)) {
        ++l;
        ++r;
    }
    return *l ? context->lisp->t : NULL;
)

FUNC(string_upcase,string-upcase,
    CHECK_ARGC(1);
    CHECK_ARG_TYPE(0, String);
    int len = strlen(STRING(CAR(args)));
    char* buf = malloc(len+1);
    const char* p = STRING(CAR(args));
    for (int i=0; i < len; p++,i++)
        buf[i] = toupper(*p);

    return MKSTRING(buf);
)


FUNC(string_downcase,string-downcase,
    CHECK_ARGC(1);
    CHECK_ARG_TYPE(0, String);
    int len = strlen(STRING(CAR(args)));
    char* buf = malloc(len+1);
    const char* p = STRING(CAR(args));
    for (int i=0; i < len; p++,i++)
        buf[i] = tolower(*p);

    return MKSTRING(buf);
)


FUNC(string_capitalize,string-capitalize,
    CHECK_ARGC(1);
    CHECK_ARG_TYPE(0, String);
    int len = strlen(STRING(CAR(args)));
    char* buf = malloc(len+1);
    const char* p = STRING(CAR(args));
    bool first = true;
    for (int i=0; i < len; p++,i++) {
        buf[i] = first ? toupper(*p) : tolower(*p);
        if (isspace(*p))
            first = true;
        else if (first)
            first = false;
    }

    return MKSTRING(buf);
)


FUNC(_char,char,
    CHECK_ARGC(2);
    CHECK_ARG_TYPE(0, String);
    CHECK_ARG_TYPE(1, Int);

    const char* s = STRING(CAR(args));
    int ix = INT(CADR(args));

    CHECK(ix >= 0, "index should be positive");
    CHECK(ix < strlen(s), "index should be less than the length");

    return MKCHAR(STRING(CAR(args))[INT(CADR(args))]);
)

