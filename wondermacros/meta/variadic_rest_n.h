#ifndef __W_VARIADIC_REST_N_H
#define __W_VARIADIC_REST_N_H

#define W_VARIADIC_REST_N(n,...) W_CAT(_W_VARIADIC_REST_,n)(__VA_ARGS__)
#define _W_VARIADIC_REST_0(_0,...) __VA_ARGS__
#define _W_VARIADIC_REST_1(_0,_1,...) __VA_ARGS__
#define _W_VARIADIC_REST_2(_0,_1,_2,...) __VA_ARGS__
#define _W_VARIADIC_REST_3(_0,_1,_2,_3,...) __VA_ARGS__

#endif
