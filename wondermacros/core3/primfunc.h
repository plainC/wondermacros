#define FOR_ARG0_BEING(T,arg) \
    for (T* arg = W_OBJECT_AS(CAR(args), T); \
        arg && W_OBJECT_IS(arg, T); arg = NULL)

#define FOR_ARG0_AND_ARG1_BEING(T,arg0,arg1) \
    for (T* arg0 = W_OBJECT_AS(CAR(args), T), \
           *arg1 = W_OBJECT_AS(CADR(args), T); \
        arg0 && arg1 && W_OBJECT_IS(arg0, T) && W_OBJECT_IS(arg1, T); \
        arg0 = NULL)

#define FOR_EACH_ARG(T,arg) \
    for (T* arg = W_OBJECT_AS(CAR(args), T); \
        arg && W_OBJECT_IS(arg, T); args = CDR(args), arg = args ? CAR(args):NULL)


FUNC(slot_value,slot-value,
    Object* obj = CAR(args);
    Symbol* sym = CADR(args);
    struct ClassProperty* property = w_oo_lookup_property(obj->klass, sym->name);
    if (!property) {
        printf("Not found\n");
        exit(1);
    }

    return property->klass->_new(NULL, W_REF_VOID_PTR(obj, property->offset));
)


FUNC(class_of,class-of,
    Object* obj = CAR(args);

    return W_NEW(_Class, ._klass = obj->klass);
)


FUNC(class_slots,class-slots,
    _Class* _klass = CAR(args);
    Class* klass = _klass->_klass;

    Object* slots = NULL;
    for (int i=0; klass->properties[i].name; i++) {
        slots = W_NEW(Cons, .car = W_CALL(context->lisp,intern)(klass->properties[i].name, strlen(klass->properties[i].name)), .cdr = slots);
    }
    return slots;
)


FUNC(find_class,find-class,
    Symbol* sym = CAR(args);

    W_HASH_TABLE_FOR_EACH_MATCH(intern_map_t, match, context->lisp->classes, sym->name) {
        _Class* klass = W_NEW(_Class, ._klass = match->value);
        return klass;
    }
    printf("Not found\n");
    return NULL;
)

FUNC(class_name,class-name,
    _Class* klass = CAR(args);
    Symbol* sym = W_CALL(context->lisp,intern)(klass->_klass->name, strlen(klass->_klass->name));

    return sym;
)

FUNC(add,+,
    int sum = 0;
    FOR_EACH_ARG(Int, arg)
        sum += arg->value;

    return W_NEW(Int, .value = sum);
)

FUNC(sub,-,
    int sum;
    FOR_ARG0_BEING(Int, arg)
        sum = arg->value;

    args = CDR(args);
    FOR_EACH_ARG(Int, arg)
        sum -= arg->value;

    return W_NEW(Int, .value = sum);
)

FUNC(inc,inc,
    FOR_ARG0_BEING(Int, arg)
        return W_NEW(Int, .value = arg->value + 1);

    return NULL;
)

FUNC(dec,dec,
    FOR_ARG0_BEING(Int, arg)
        return W_NEW(Int, .value = arg->value - 1);

    return NULL;
)

