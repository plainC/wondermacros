#include "wondermacros/sorting/numeric_cmp.h"

/*
 * By redefining W_COMPARE a different comparison method can be used. Use, for example,
 * strcmp for strings, or, W_NUMERIC_CMP_DESC for descending order for numeric types.
 */
#ifndef W_COMPARE
# define W_COMPARE W_NUMERIC_CMP_ASC /* use numeric ascending order by default */
#endif

