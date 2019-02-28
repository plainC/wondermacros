#ifndef __W_OBJECT_H
#define __W_OBJECT_H

#ifndef LOWERCASE_OBJECT
# ifdef USE_T_TYPE_SUFFIX
#  define CLASS Object_t
#  define Object_t__define
# else
#  define CLASS Object
#  define Object__define
# endif
#else
# ifdef USE_T_TYPE_SUFFIX
#  define CLASS object_t
#  define object_t__define
# else
#  define CLASS object
#  define object__define
# endif
#endif

#include <wondermacros/objects/x/class_declare.h>

#endif

