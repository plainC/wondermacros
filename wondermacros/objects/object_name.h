#undef CLASS
#undef Object_t__define
#undef Object__define
#undef object_t__define
#undef object__define

#ifndef LOWERCASE_OBJECT
# ifdef USE_T_TYPE_SUFFIX
#  define CLASS Object
#  define Object__define
#  define OBJECT_T Object_t
#  define CLASS_T Object__class_t
# else
#  define CLASS Object
#  define Object__define
#  define OBJECT_T struct Object
#  define CLASS_T struct Object__class
# endif
#else
# ifdef USE_T_TYPE_SUFFIX
#  define CLASS object
#  define object__define
#  define OBJECT_T object_t
#  define CLASS_T object__class_t
# else
#  define CLASS object
#  define object__define
#  define OBJECT_T struct object
#  define CLASS_T struct object__class
# endif
#endif
