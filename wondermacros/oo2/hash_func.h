#ifndef __HASH_FUNC_H
#define __HASH_FUNC_H

static inline unsigned long
strhash(const char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

#endif

