FUNC(eq,eq,
    CHECK_ARGC(2);
    Object* lhs = CAR(args);
    Object* rhs = CADR(args);

    return lhs == rhs ? context->lisp->t : NULL;
)


FUNC(_null,null,
    CHECK_ARGC(1);
    Object* obj = CAR(args);

    return obj ? NULL : context->lisp->t;
)


FUNC(atom,atom,
    CHECK_ARGC(1);
    Object* obj = CAR(args);
    return obj == NULL || !W_OBJECT_IS(obj, Cons) ? context->lisp->t : NULL;
)


FUNC(consp,consp,
    CHECK_ARGC(1);
    Object* obj = CAR(args);
    return obj == NULL || !W_OBJECT_IS(obj, Cons) ? NULL : context->lisp->t;
)


FUNC(listp,listp,
    CHECK_ARGC(1);
    Object* obj = CAR(args);
    return obj == NULL || W_OBJECT_IS(obj, Cons) ? context->lisp->t : NULL;
)


FUNC(symbolp,symbolp,
    CHECK_ARGC(1);
    Object* obj = CAR(args);
    return obj && W_OBJECT_IS(obj, Symbol) ? context->lisp->t : NULL;
)


FUNC(characterp,characterp,
    CHECK_ARGC(1);
    Object* obj = CAR(args);
    return obj && W_OBJECT_IS(obj, Character) ? context->lisp->t : NULL;
)


FUNC(stringp,stringp,
    CHECK_ARGC(1);
    Object* obj = CAR(args);
    return obj && W_OBJECT_IS(obj, String) ? context->lisp->t : NULL;
)


FUNC(functionp,functionp,
    CHECK_ARGC(1);
    Object* obj = CAR(args);
    return obj && W_OBJECT_IS(obj, PrimFunc) ? context->lisp->t : NULL;
)


FUNC(not,not,
    CHECK_ARGC(1);
    Object* obj = CAR(args);
    return obj ? NULL : context->lisp->t;
)

