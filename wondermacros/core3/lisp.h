#ifndef __LISP_EXT_H
#define __LISP_EXT_H

#define CAR(l) (((Cons*)(l))->car)
#define CDR(l) (((Cons*)(l))->cdr)
#define CADR(l) (CAR(CDR(l)))

#endif

