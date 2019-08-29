#include "expand_api.h"


/* Include class definition. */
#include W_STRINGIZE(NAME)
#include "expand_class_struct.h"
#include "expand_object_struct.h"

#include "expand_forward_declares.h"

#include "expand_construct.h"
#include "expand_new.h"
#include "expand_free.h"

#undef NAME
#undef CLASS
#undef HAS_CONSTRUCT
#undef HAS_DESTRUCT
