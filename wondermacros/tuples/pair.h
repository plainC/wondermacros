#ifndef __W_PAIR_H
#define __W_PAIR_H

#ifndef W_MALLOC_SAFE
static inline void*
w_malloc_safe(size_t size)
{
    void* p = malloc(size);
    if (!p) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }
    return p;
}
#define W_MALLOC_SAFE(s) w_malloc_safe(s)
#endif

#define W_PAIR_TYPE(T0,T1) struct { T0 _0; T1 _1; }
#define W_PAIR_NEW(T0,T1,...) (*((W_PAIR_TYPE(T0,T1)* W_MALLOC_SAFE(sizeof(W_PAIR_TYPE(T0,T1)))) = (W_PAIR_TYPE(T0,T1)) { __VA_ARGS__ })
#define W_PAIR_ELEM(pairp,ix) ((pairp)->_ ## ix)

#endif

