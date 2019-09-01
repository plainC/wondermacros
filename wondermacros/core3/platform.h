#ifndef __PLATFORM_H
#define __PLATFORM_H

#include "oo_types.h"

typedef enum read_status {
    W_READ_NOK,
    W_READ_OK,
    W_READ_EATEN,
} w_read_status_t;

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
extern Class wobject_int64__simple_instance;

/* EvalContext types */
struct Symbol;
typedef struct Symbol Symbol;
struct Lisp;
typedef struct Lisp Lisp;

typedef struct intern_map {
    const char* key;
    Symbol* value;
} intern_map_t;

typedef w_read_status_t (*readtable_func)(char** str, size_t* size, Lisp* lisp, Object** ret);
typedef Object* (*prim_func)(Object* args);

/**/


#endif
