#ifndef __PLATFORM_H
#define __PLATFORM_H

#include "oo_types.h"

enum bcode {
    W_INSTR_NOP,
    W_INSTR_PUSH,
    W_INSTR_RET,
    W_INSTR_NEW,
    W_INSTR_LOAD_BYTE,
};

typedef uint8_t instr_t;

enum bin_op {
    BIN_OP_ADD,
    BIN_OP_SUB,
};
typedef enum bin_op bin_op_t;

extern Class wobject_cstring__simple_instance;
extern Class wobject_int__simple_instance;

/* EvalContext types */
struct Symbol;
typedef struct Symbol Symbol;
struct Lisp;
typedef struct Lisp Lisp;

typedef struct intern_map {
    const char* key;
    Symbol* value;
} intern_map_t;

typedef Object* (*readtable_func)(char** str, size_t* size, Lisp* lisp);

/**/


#endif
