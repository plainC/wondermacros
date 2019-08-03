#include "expand_api.h"

/* Include class definition. */
#include W_STRINGIZE(NAME)
#include "expand_class_struct.h"
#include "expand_object_struct.h"

extern struct W_CAT(CLASS,__class) W_CAT(CLASS,__class_instance);
extern struct W_CAT(CLASS,__class) W_CAT(CLASS,__class_instance);
extern struct UnitTest W_CAT(CLASS,__tests)[];

#include "expand_new.h"
#include "expand_free.h"
