#define W_CLASS_DECLARE

#ifdef TO_HEADER
TO_HEADER
#endif

#ifdef INCLUDE_0
# include INCLUDE_0
#endif

#ifdef INCLUDE_1
# include INCLUDE_1
#endif

#ifdef INCLUDE_2
# include INCLUDE_2
#endif

#ifdef INCLUDE_3
# include INCLUDE_3
#endif

#define INHERIT(...)
#include <wondermacros/objects/x/class.h>
#include <wondermacros/objects/x/object_instance.h>
#include <wondermacros/objects/x/method_typedefs.h>
#include <wondermacros/objects/x/new.h>
#include <wondermacros/objects/x/dup.h>
#include <wondermacros/objects/x/free.h>
#ifdef BUILD_JSON
# include <wondermacros/objects/x/to_json.h>
#endif
#include <wondermacros/objects/x/method_forward_declares.h>
#undef INHERIT

extern void* W_CAT(CLASS,__class_instance_ptr);

#undef W_CLASS_DECLARE

#undef CLASS
#undef ABSTRACT
#undef NO_CONSTRUCT
#undef NO_DESTRUCT
#undef TO_HEADER
#undef INCLUDE_0
#undef INCLUDE_1
#undef INCLUDE_2
#undef INCLUDE_3

