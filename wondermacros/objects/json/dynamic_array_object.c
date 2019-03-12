int
json_dynamic_array_object_to_string(struct Object** self, char* buffer, size_t size)
{
    char tmp[4096];
    char* p = tmp;
    *p++ = '[';
    W_DYNAMIC_ARRAY_FOR_EACH(struct Object*, o, self) {
        if (o_ix)
            *p++ = ',';
        int len = W_CALL(o,to_json)(p, 512);
        if (len >= size)
            return -1;
        p += len;
    }
    *p++ = ']';

    return p-tmp;
}

#define SKIP_WS \
    while (isspace(*p)) \
        p++

#define ACCEPT(ch)    \
    if (*p++ == (ch)) \
        {}            \
    else              \
        return 1

#define READ_OBJECT(obj)                     \
    do {                                     \
        obj = new_with(NULL);                \
        if (W_CALL(obj,from_json)(p,endptr)) \
            return 1;                        \
        p = *endptr;                         \
    } while (0)
    

int
json_dynamic_array_object_from_string(const char* buffer, const char** endptr, const char* type_name, struct Object*** self)
{
    const char* p = buffer;
    struct Object* obj;

    char name[strlen(type_name)];
    strncpy(name,type_name,strlen(type_name)-1);
    name[strlen(type_name)-1] = '\0';
    w_object_new_with_func new_with = w_class_lookup_new_by_name(name);

    if (!new_with)
        return 1;

    SKIP_WS;
    ACCEPT('[');
    SKIP_WS;
    *self = NULL;
    while (1) {
        READ_OBJECT(obj);

        W_DYNAMIC_ARRAY_PUSH(*self, obj);
        SKIP_WS;
        if (*p == ']')
            break;
    }

    ACCEPT(']');
    SKIP_WS;
    *endptr = p;

    return 0;
}

#undef SKIP_WS
#undef ACCEPT
#undef READ_INT


