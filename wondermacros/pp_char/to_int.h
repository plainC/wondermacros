/* (C) Copyright 2019 J.P. Iivonen <wondermacros@yahoo.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef __W_PP_CHAR_TO_INT_H
#define __W_PP_CHAR_TO_INT_H

/***
 *** Name:        W_PP_CHAR_TO_INT
 *** Proto:       W_PP_CHAR_TO_INT(ch)
 *** Arg:         ch   A character to be converted to integer.
 *** Description: Use W_PP_CHAR_TO_INT to convert a single character to an integer.
 *** Notes:       ch must be a valid character to be used in an identifer, i.g. [a-zA-Z_0-9].
 *** Example:     'W_PP_CHAR_TO_INT(a)' expands to 65.
 ***/
#define W_PP_CHAR_TO_INT(ch) _W_PP_CHAR_TO_INT(ch)

#define _W_PP_CHAR_TO_INT(ch) _W_PP_CHAR_TO_INT_ ## ch

#define _W_PP_CHAR_TO_INT_0 48
#define _W_PP_CHAR_TO_INT_1 49
#define _W_PP_CHAR_TO_INT_2 50
#define _W_PP_CHAR_TO_INT_3 51
#define _W_PP_CHAR_TO_INT_4 52
#define _W_PP_CHAR_TO_INT_5 53
#define _W_PP_CHAR_TO_INT_6 54
#define _W_PP_CHAR_TO_INT_7 55
#define _W_PP_CHAR_TO_INT_8 56
#define _W_PP_CHAR_TO_INT_9 57
#define _W_PP_CHAR_TO_INT_A 65
#define _W_PP_CHAR_TO_INT_B 66
#define _W_PP_CHAR_TO_INT_C 67
#define _W_PP_CHAR_TO_INT_D 68
#define _W_PP_CHAR_TO_INT_E 69
#define _W_PP_CHAR_TO_INT_F 70
#define _W_PP_CHAR_TO_INT_G 71
#define _W_PP_CHAR_TO_INT_H 72
#define _W_PP_CHAR_TO_INT_I 73
#define _W_PP_CHAR_TO_INT_J 74
#define _W_PP_CHAR_TO_INT_K 75
#define _W_PP_CHAR_TO_INT_L 76
#define _W_PP_CHAR_TO_INT_M 77
#define _W_PP_CHAR_TO_INT_N 78
#define _W_PP_CHAR_TO_INT_O 79
#define _W_PP_CHAR_TO_INT_P 80
#define _W_PP_CHAR_TO_INT_Q 81
#define _W_PP_CHAR_TO_INT_R 82
#define _W_PP_CHAR_TO_INT_S 83
#define _W_PP_CHAR_TO_INT_T 84
#define _W_PP_CHAR_TO_INT_U 85
#define _W_PP_CHAR_TO_INT_V 86
#define _W_PP_CHAR_TO_INT_W 87
#define _W_PP_CHAR_TO_INT_X 88
#define _W_PP_CHAR_TO_INT_Y 89
#define _W_PP_CHAR_TO_INT_Z 90
#define _W_PP_CHAR_TO_INT__ 95
#define _W_PP_CHAR_TO_INT_a 97
#define _W_PP_CHAR_TO_INT_b 98
#define _W_PP_CHAR_TO_INT_c 99
#define _W_PP_CHAR_TO_INT_d 100
#define _W_PP_CHAR_TO_INT_e 101
#define _W_PP_CHAR_TO_INT_f 102
#define _W_PP_CHAR_TO_INT_g 103
#define _W_PP_CHAR_TO_INT_h 104
#define _W_PP_CHAR_TO_INT_i 105
#define _W_PP_CHAR_TO_INT_j 106
#define _W_PP_CHAR_TO_INT_k 107
#define _W_PP_CHAR_TO_INT_l 108
#define _W_PP_CHAR_TO_INT_m 109
#define _W_PP_CHAR_TO_INT_n 110
#define _W_PP_CHAR_TO_INT_o 111
#define _W_PP_CHAR_TO_INT_p 112
#define _W_PP_CHAR_TO_INT_q 113
#define _W_PP_CHAR_TO_INT_r 114
#define _W_PP_CHAR_TO_INT_s 115
#define _W_PP_CHAR_TO_INT_t 116
#define _W_PP_CHAR_TO_INT_u 117
#define _W_PP_CHAR_TO_INT_v 118
#define _W_PP_CHAR_TO_INT_w 119
#define _W_PP_CHAR_TO_INT_x 120
#define _W_PP_CHAR_TO_INT_y 121
#define _W_PP_CHAR_TO_INT_z 122

#endif

