#ifndef _W_ROUND_UP_POW2
#define _W_ROUND_UP_POW2

/*
    By Sean Eron Anderson
    seander@cs.stanford.edu
    Individually, the code snippets here are in the public domain
    (unless otherwise noted) — feel free to use them however you
    please. The aggregate collection and descriptions are
    © 1997-2005 Sean Eron Anderson. The code and descriptions are
    distributed in the hope that they will be useful, but WITHOUT
    ANY WARRANTY and without even the implied warranty of
    merchantability or fitness for a particular purpose. As of
    May 5, 2005, all the code has been tested thoroughly. Thousands
    of people have read it. Moreover, Professor Randal Bryant, the
    Dean of Computer Science at Carnegie Mellon University, has
    personally tested almost everything with his Uclid code
    verification system. What he hasn't tested, I have checked
    against all possible inputs on a 32-bit machine. To the first
    person to inform me of a legitimate bug in the code, I'll pay a
    bounty of US$10 (by check or Paypal). If directed to a charity,
    I'll pay US$20.

    https://graphics.stanford.edu/%7Eseander/bithacks.html#RoundUpPowerOf2
*/

#include <stdint.h>


static inline uint32_t
w_round_up_pow2_uint32( uint32_t v )
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}


static inline uint64_t
w_round_up_pow2_uint64( uint64_t v )
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v |= v >> 32;
    v++;
    return v;
}

#endif
