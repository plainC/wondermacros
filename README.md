Wondermacros - Generally useful macros for C/C++ programming.

Intro

Writting a C/C++ macro library is hard. There exists just few of them,
typically with a very narrow focus. Our focus is generally useful
programming techniques which is too wide topic to be specific. Thus,
Wondermacros is just a bag of macros of various kinds. We try to be
C99 compliant, though some macros may require C11 struct initialization,
for example (1). The code is free under BSD/MIT style license, see each
file separately.

We try not to reinvent the wheel and build on top of Boost pre-processor
library (2). It can be used in C programming as well, it is not just for
C++, since it does not bring in any code other than pre-processor macros.
So in order to use macros which use Boost macros you need to have Boost
library installed during build time. But this dependency is just a build
time dependency.

We will also incorporate some great macros of others. For instance, some
macros build on Simon Tatham's metaprogramming macros (3) which provide
a general purpose toolkit for building looping macros and other useful
control structures. The original mp.h is included in Wondermacros.

Best Regards,
J.P. Iivonen <wondermacros@yahoo.com>


References

(1) https://en.cppreference.com/w/c/language/struct_initialization
(2) https://www.boost.org/doc/libs/1_67_0/libs/preprocessor/doc/index.html
(3) https://www.chiark.greenend.org.uk/~sgtatham/mp/
