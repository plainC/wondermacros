#undef CONSTRUCT
#undef FINALIZE


#undef METHOD
#undef _METHOD
#undef _METHOD_1
#undef _METHOD_2

#define W_CLASS_GENERATE
#define INHERIT(...)
#include <wondermacros/objects/x/class_instance.h>
#undef W_CLASS_GENERATE
#undef INHERIT

#undef CLASS
#undef ABSTRACT
#undef NO_CONSTRUCT
#undef NO_DESTRUCT

