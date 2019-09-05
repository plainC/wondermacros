#undef TEST
#undef METHOD
#undef METHODV

#include "expand_api.h"

#include "expand_tests.h"

/* Include class definition. */
#include W_STRINGIZE(NAME)
#include "expand_class_properties.h"
#include "expand_class_methods.h"
#include "expand_superclasses.h"
#include "expand_class_instance.h"

