#include "wondermacros/sorting/numeric_cmp.h"

/*
 * By redefining COMPARE a different comparison method can be used. Use, for example,
 * strcmp for strings, or, W_NUMERIC_CMP_DESC for descending order for numeric types.
 */
#ifndef COMPARE
# define COMPARE W_NUMERIC_CMP_ASC /* use numeric ascending order by default */
#endif

