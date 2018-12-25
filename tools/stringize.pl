#!/usr/bin/perl

$copyright= <<'END_COPYRIGHT';
/* (C) Copyright 2018 J.P. Iivonen <wondermacros@yahoo.com>
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
END_COPYRIGHT

print "$copyright\n";
print "#include <boost/preprocessor/facilities/overload.hpp>\n\n";

my $max = 8;
if (defined $ARGV[0]) {
    $max = $ARGV[0];
}

print "#define W_STRINGIZE(...) BOOST_PP_OVERLOAD(_W_STRINGIZE_,__VA_ARGS__)(__VA_ARGS__)\n\n";
for ($i=1; $i<=$max; $i++) {
    print "#define _W_STRINGIZE_$i(";
    for ($n=1; $n<=$i; $n++) {
        if ($n > 1) {
            print ",";
        }
        print "_$n";
    }
    print ") ";
    for ($n=1; $n<=$i; $n++) {
        print " # ";
        print "_$n";
    }
    print "\n";
}

