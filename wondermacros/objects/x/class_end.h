#undef CONSTRUCT
#undef FINALIZE


#undef METHOD
#undef _METHOD
#undef _METHOD_1
#undef _METHOD_2

#define W_CLASS_GENERATE
#include <wondermacros/objects/x/class_instance.h>
#undef W_CLASS_GENERATE

#undef CLASS
#undef SUPER
#undef ABSTRACT
#undef NO_CONSTRUCT
#undef NO_DESTRUCT
#undef TO_HEADER
#undef INCLUDE_0
#undef INCLUDE_1
#undef INCLUDE_2
#undef INCLUDE_3
