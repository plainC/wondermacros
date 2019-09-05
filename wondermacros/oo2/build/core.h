#ifndef __CORE_H
#define __CORE_H

#include "platform.h"


/* Classes */

/* Class Variant */
struct Variant;
struct Variant__class;
typedef struct Variant Variant;
typedef struct Variant__class Variant__class;
extern struct Variant__class Variant__class_instance;
/* Class Writer */
struct Writer;
struct Writer__class;
typedef struct Writer Writer;
typedef struct Writer__class Writer__class;
extern struct Writer__class Writer__class_instance;
/* Class Reader */
struct Reader;
struct Reader__class;
typedef struct Reader Reader;
typedef struct Reader__class Reader__class;
extern struct Reader__class Reader__class_instance;
/* Class Object */
struct Object;
struct Object__class;
typedef struct Object Object;
typedef struct Object__class Object__class;
extern struct Object__class Object__class_instance;
/* Class Symbol */
struct Symbol;
struct Symbol__class;
typedef struct Symbol Symbol;
typedef struct Symbol__class Symbol__class;
extern struct Symbol__class Symbol__class_instance;
/* Class SpecialForm */
struct SpecialForm;
struct SpecialForm__class;
typedef struct SpecialForm SpecialForm;
typedef struct SpecialForm__class SpecialForm__class;
extern struct SpecialForm__class SpecialForm__class_instance;
/* Class Quote */
struct Quote;
struct Quote__class;
typedef struct Quote Quote;
typedef struct Quote__class Quote__class;
extern struct Quote__class Quote__class_instance;
/* Class PrimFunc */
struct PrimFunc;
struct PrimFunc__class;
typedef struct PrimFunc PrimFunc;
typedef struct PrimFunc__class PrimFunc__class;
extern struct PrimFunc__class PrimFunc__class_instance;
/* Class Lisp */
struct Lisp;
struct Lisp__class;
typedef struct Lisp Lisp;
typedef struct Lisp__class Lisp__class;
extern struct Lisp__class Lisp__class_instance;
/* Class Number */
struct Number;
struct Number__class;
typedef struct Number Number;
typedef struct Number__class Number__class;
extern struct Number__class Number__class_instance;
/* Class Int */
struct Int;
struct Int__class;
typedef struct Int Int;
typedef struct Int__class Int__class;
extern struct Int__class Int__class_instance;
/* Class Float */
struct Float;
struct Float__class;
typedef struct Float Float;
typedef struct Float__class Float__class;
extern struct Float__class Float__class_instance;
/* Class Ratio */
struct Ratio;
struct Ratio__class;
typedef struct Ratio Ratio;
typedef struct Ratio__class Ratio__class;
extern struct Ratio__class Ratio__class_instance;
/* Class True */
struct True;
struct True__class;
typedef struct True True;
typedef struct True__class True__class;
extern struct True__class True__class_instance;
/* Class Character */
struct Character;
struct Character__class;
typedef struct Character Character;
typedef struct Character__class Character__class;
extern struct Character__class Character__class_instance;
/* Class Nil */
struct Nil;
struct Nil__class;
typedef struct Nil Nil;
typedef struct Nil__class Nil__class;
extern struct Nil__class Nil__class_instance;
/* Class _Class */
struct _Class;
struct _Class__class;
typedef struct _Class _Class;
typedef struct _Class__class _Class__class;
extern struct _Class__class _Class__class_instance;
/* Class WhiteSpace */
struct WhiteSpace;
struct WhiteSpace__class;
typedef struct WhiteSpace WhiteSpace;
typedef struct WhiteSpace__class WhiteSpace__class;
extern struct WhiteSpace__class WhiteSpace__class_instance;
/* Class Cons */
struct Cons;
struct Cons__class;
typedef struct Cons Cons;
typedef struct Cons__class Cons__class;
extern struct Cons__class Cons__class_instance;
/* Class EvalContext */
struct EvalContext;
struct EvalContext__class;
typedef struct EvalContext EvalContext;
typedef struct EvalContext__class EvalContext__class;
extern struct EvalContext__class EvalContext__class_instance;
/* Class BinOp */
struct BinOp;
struct BinOp__class;
typedef struct BinOp BinOp;
typedef struct BinOp__class BinOp__class;
extern struct BinOp__class BinOp__class_instance;
/* Class String */
struct String;
struct String__class;
typedef struct String String;
typedef struct String__class String__class;
extern struct String__class String__class_instance;
/* Class StringRef */
struct StringRef;
struct StringRef__class;
typedef struct StringRef StringRef;
typedef struct StringRef__class StringRef__class;
extern struct StringRef__class StringRef__class_instance;
/* Class Test */
struct Test;
struct Test__class;
typedef struct Test Test;
typedef struct Test__class Test__class;
extern struct Test__class Test__class_instance;


/* Simple types */
extern struct ClassSimple wobject_bool__class_instance;
extern struct ClassSimple wobject_int__class_instance;
extern struct ClassSimple wobject_int64__class_instance;
extern struct ClassSimple wobject_cstring__class_instance;
extern struct ClassSimple wobject_cstring__class_instance;


#endif /* __CORE_H */
