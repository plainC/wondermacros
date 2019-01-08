#ifndef __W_LABEL_H
#define __W_LABEL_H

/***
 *** Name:        W_LABEL
 *** Proto:       W_LABEL(id1,id2)
 ***
 *** Arg:         id1   label one
 *** Arg:         id2   label one
 ***
 *** Description: Use W_LABEL to construct line-unique labels.
 ***/
#define W_LABEL(id1,id2)                                      \
    W_CAT(W_LABEL_ ## id1 ## _ ## id2 ## _, __LINE__)

#endif

