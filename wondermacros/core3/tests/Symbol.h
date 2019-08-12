TEST(symbol,
        "Create a Test object and set a dynamic int array property 'd'.")
({
    Symbol* sym = W_NEW(Symbol, .name="i");
    Symbol* sym2 = W_NEW(Symbol, .name="i");
    printf("%s\n", sym->name);

    printf("%d\n", W_CALL(sym,equal)(sym2));

    Writer* writer = W_NEW(Writer);
    printf("writer=%p\n", writer);
    W_CALL(writer,put_char)('@');
    W_CALL(writer,put_char)('\n');
    W_CALL(sym,to_json)(writer);
    W_CALLV(sym,free);
})

