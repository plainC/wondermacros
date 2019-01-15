/* (C) Copyright 2017 J.P. Iivonen <wondermacros@yahoo.com>
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

#ifndef __W_TO_CHAR_H
#define __W_TO_CHAR_H

/***
 *** Name:        W_TO_CHAR
 *** Proto:       W_TO_CHAR(ch)
 *** Arg:         ch   A character to be converted to ASCII.
 *** Description: Use W_TO_CHAR to convert a single character to a C character.
 *** Notes:       ch must be a valid character to be used in an identifer, i.g. [a-zA-Z_0-9].
 *** Example:     'char str[] = { W_TO_CHAR(a), W_TO_CHAR(b), 0 };' expands to
 ***              'char str[] = { 'a', 'b', 0 };'
 ***/
#define W_TO_CHAR(ch) _W_TO_CHAR(ch)

#define _W_TO_CHAR(ch) _W_TO_CHAR_ ## ch

#define _W_TO_CHAR_0 '0'
#define _W_TO_CHAR_1 '1'
#define _W_TO_CHAR_2 '2'
#define _W_TO_CHAR_3 '3'
#define _W_TO_CHAR_4 '4'
#define _W_TO_CHAR_5 '5'
#define _W_TO_CHAR_6 '6'
#define _W_TO_CHAR_7 '7'
#define _W_TO_CHAR_8 '8'
#define _W_TO_CHAR_9 '9'
#define _W_TO_CHAR_A 'A'
#define _W_TO_CHAR_B 'B'
#define _W_TO_CHAR_C 'C'
#define _W_TO_CHAR_D 'D'
#define _W_TO_CHAR_E 'E'
#define _W_TO_CHAR_F 'F'
#define _W_TO_CHAR_G 'G'
#define _W_TO_CHAR_H 'H'
#define _W_TO_CHAR_I 'I'
#define _W_TO_CHAR_J 'J'
#define _W_TO_CHAR_K 'K'
#define _W_TO_CHAR_L 'L'
#define _W_TO_CHAR_M 'M'
#define _W_TO_CHAR_N 'N'
#define _W_TO_CHAR_O 'O'
#define _W_TO_CHAR_P 'P'
#define _W_TO_CHAR_Q 'Q'
#define _W_TO_CHAR_R 'R'
#define _W_TO_CHAR_S 'S'
#define _W_TO_CHAR_T 'T'
#define _W_TO_CHAR_U 'U'
#define _W_TO_CHAR_V 'V'
#define _W_TO_CHAR_W 'W'
#define _W_TO_CHAR_X 'X'
#define _W_TO_CHAR_Y 'Y'
#define _W_TO_CHAR_Z 'Z'
#define _W_TO_CHAR__ '_'
#define _W_TO_CHAR_a 'a'
#define _W_TO_CHAR_b 'b'
#define _W_TO_CHAR_c 'c'
#define _W_TO_CHAR_d 'd'
#define _W_TO_CHAR_e 'e'
#define _W_TO_CHAR_f 'f'
#define _W_TO_CHAR_g 'g'
#define _W_TO_CHAR_h 'h'
#define _W_TO_CHAR_i 'i'
#define _W_TO_CHAR_j 'j'
#define _W_TO_CHAR_k 'k'
#define _W_TO_CHAR_l 'l'
#define _W_TO_CHAR_m 'm'
#define _W_TO_CHAR_n 'n'
#define _W_TO_CHAR_o 'o'
#define _W_TO_CHAR_p 'p'
#define _W_TO_CHAR_q 'q'
#define _W_TO_CHAR_r 'r'
#define _W_TO_CHAR_s 's'
#define _W_TO_CHAR_t 't'
#define _W_TO_CHAR_u 'u'
#define _W_TO_CHAR_v 'v'
#define _W_TO_CHAR_w 'w'
#define _W_TO_CHAR_x 'x'
#define _W_TO_CHAR_y 'y'

#endif

