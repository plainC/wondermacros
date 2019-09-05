FUNC(class_name,class-name,
    CHECK_ARGC(1);
    CHECK_ARG_TYPE(0, _Class);
    _Class* klass = CAR(args);
    Symbol* sym = W_CALL(context->lisp,intern)(klass->_klass->name, strlen(klass->_klass->name));

    return sym;
)


FUNC(class_of,class-of,
    CHECK_ARGC(1);
    Object* obj = CAR(args);

    return W_NEW(_Class, ._klass = obj->klass);
)


FUNC(class_precedence_list,class-precedence-list,
    CHECK_ARGC(1);
    CHECK_ARG_TYPE(0, _Class);
    Class* klass = ((_Class*) CAR(args))->_klass;
    Cons* list = NULL;
    for (int i=0; klass->superclasses[i]; i++)
        list = CONS(W_NEW(_Class, ._klass = klass->superclasses[i]), list);

    return list;
)


FUNC(class_direct_superclass,class-direct-superclass,
    CHECK_ARGC(1);
    CHECK_ARG_TYPE(0, _Class);
    Class* klass = ((_Class*) CAR(args))->_klass;

    return klass->nbr_superclasses > 1 ? W_NEW(_Class, ._klass = klass->superclasses[klass->nbr_superclasses - 2]) : NULL;
)


FUNC(subtypep,subtypep,
    CHECK_ARGC(2);
    CHECK_ARG_TYPE(0, _Class);
    CHECK_ARG_TYPE(1, Symbol);
    Class* klass = ((_Class*) CAR(args))->_klass;
    Symbol* sym = SYMBOL(CADR(args));

    for (int i=0; klass->superclasses[i]; i++)
        if (strcmp(sym->name, klass->superclasses[i]->name) == 0)
            return context->lisp->t;

    return NULL;
)


FUNC(class_slots,class-slots,
    CHECK_ARGC(1);
    CHECK_ARG_TYPE(0, _Class);
    _Class* _klass = CAR(args);
    Class* klass = _klass->_klass;

    Object* slots = NULL;
    for (int i=0; klass->properties[i].name; i++) {
        slots = W_NEW(Cons, .car = W_CALL(context->lisp,intern)(klass->properties[i].name, strlen(klass->properties[i].name)), .cdr = slots);
    }
    return slots;
)


FUNC(find_class,find-class,
    CHECK_ARGC(1);
    CHECK_ARG_TYPE(0, Symbol);
    Symbol* sym = CAR(args);

    W_HASH_TABLE_FOR_EACH_MATCH(intern_map_t, match, context->lisp->classes, sym->name) {
        _Class* klass = W_NEW(_Class, ._klass = match->value);
        return klass;
    }
    printf("Not found\n");
    return NULL;
)


FUNC(slot_value,slot-value,
    CHECK_ARGC(2);
    CHECK_ARG_TYPE(1, Symbol);
    Object* obj = CAR(args);
    Symbol* sym = CADR(args);
    struct ClassProperty* property = w_oo_lookup_property(obj->klass, sym->name);
    if (!property) {
        printf("Not found\n");
        exit(1);
    }

    return property->klass->_new(NULL, W_REF_VOID_PTR(obj, property->offset));
)
