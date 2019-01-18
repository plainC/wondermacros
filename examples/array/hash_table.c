#include <wondermacros/array/hash_table.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    struct hash_uint {
        unsigned key;
        unsigned value;
    };

    struct hash_uint* table = NULL;

    W_HASH_TABLE_INIT(table,1);

    for (unsigned int i=0; i < 50000; i++)
        W_HASH_TABLE_PUSH(struct hash_uint, table, i, i);


    W_HASH_TABLE_FOR_EACH_MATCH(struct hash_uint, map, table, 2)
        printf("%u -> %d\n", map->key, map->value);

    int matched;
    W_HASH_TABLE_REMOVE(table, 2, matched);
    printf("Removed: %d\n", matched);

    W_HASH_TABLE_FOR_EACH_MATCH(struct hash_uint, map, table, 2)
        printf("%u -> %d\n", map->key, map->value);

    W_HASH_TABLE_FREE(table);
}
