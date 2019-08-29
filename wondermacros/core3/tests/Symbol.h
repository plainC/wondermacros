TEST(symbol,
        "Create a Test object and set a dynamic int array property 'd'.")
({
    Symbol* sym = W_NEW(Symbol, .name="i");
    Symbol* sym2 = W_NEW(Symbol, .name="i");
    printf("%s\n", (char*) sym->name);

    printf("%d\n", (int) W_CALL(sym,equal)((Object*) sym2));

    Writer* writer = W_NEW(Writer);
    Symbol__to_json((Object**) &sym,writer);
    W_CALLV(sym,free);
})

