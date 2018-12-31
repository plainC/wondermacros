/*
 * mp.h: header file providing macros for 'metaprogramming' custom
 * loop constructions in standard C.
 *
 * Accompanies the article on the web at
 *   https://www.chiark.greenend.org.uk/~sgtatham/mp/
 */

#ifndef __W_BEFORE_H
#define __W_BEFORE_H

/*
 * mp.h is copyright 2012 Simon Tatham.
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
 * NONINFRINGEMENT.  IN NO EVENT SHALL SIMON TATHAM BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */


#include <wondermacros/meta/cat.h>
#include <wondermacros/meta/label.h>


/*
 * Macros beginning with 'MPP_' and 'MPS_' are building blocks
 * intended for metaprogrammers to make useful control constructions
 * from.
 *
 * The prefixes distinguish their syntactic role. MPP_ macros are
 * statement _prefixes_; you would typically build a custom control
 * structure by defining a macro expanding to a sequence of them. MPS_
 * macros are actual statements, which you might use in the various
 * parameters of MPP_ macros that are expected to be statement-shaped.
 */

/*
 * Safety considerations:
 *
 *  - All of these macros are C89-safe, except for MPP_DECLARE if you
 *    pass an actual declaration and not just an assignment, since
 *    that one relies on the C99 (and C++) extension of being able to
 *    write a declaration in the initialisation clause of a for
 *    statement.
 *
 *  - None of these macros uses switch, so case labels from a switch
 *    outside the whole lot may be written inside the suffixed
 *    statement/block.
 *
 *  - All of these constructions use 'goto' with labels constructed
 *    programmatically, using __LINE__ to make them unique between
 *    multiple invocations of the same loop macro. So don't put two
 *    loop macros defined using these building blocks on the same
 *    source line.
 *
 *  - All of these constructions can be prefixed to something that is
 *    syntactically a single C statement, and generate something that
 *    is also a single C statement. So they're if-else safe - you can
 *    use an unbraced one of these constructs followed by an unbraced
 *    statement within the then-clause of an outer if, and the else
 *    will still bind to what it looks as if it ought to.
 *
 *  - Controlling what happens if the user writes a 'break' in the
 *    suffixed statement is unavoidably rather fiddly. The macros
 *    below fall into a few categories:
 *
 *     + naturally transparent to 'break' (MPP_BEFORE, MPP_IF). Macros
 *       of this type will not affect the semantics of 'break' in the
 *       suffixed statement at all - it will terminate the next
 *       innermost loop or switch outside the construction.
 *
 *     + artificially transparent to 'break', by means of deliberately
 *       catching and 'rethrowing' it. (MPP_BREAK_{THROW,CATCH};
 *       MPP_BREAK_HANDLER; MPP_FINALLY.) These macros will propagate
 *       a break outwards to the next containing loop, but in order to
 *       do so they require that there _be_ a next containing loop,
 *       since their expansion can't avoid including a break statement
 *       which they themselves do not wrap in a loop. So you should
 *       only use these when you know there is a containing loop (e.g.
 *       because MPP_WHILE or MPP_DO_WHILE precedes them in your
 *       construction).
 *
 *     + loop constructions. (MPP_WHILE and MPP_DO_WHILE). These
 *       macros give 'break' the obvious semantics of terminating the
 *       loop they define.
 *
 *     + break-unsafe macros, which have to include a C looping
 *       construction to do something not essentially loopy, and hence
 *       have the unfortunate side effect of causing 'break' to only
 *       terminate the suffixed statement itself. On the other hand,
 *       they can be used in contexts where there is no surrounding
 *       loop at all (which is why I don't just fix them to contain a
 *       built-in MPP_BREAK_{THROW,CATCH}).
 *
 *    If you are using these macros to build a looping construct, then
 *    you will probably include an MPP_WHILE or MPP_DO_WHILE in your
 *    stack, and you'll want 'break' to terminate that. So you just
 *    need to be sure that break is correctly propagated from the
 *    suffixed statement back to that loop, which you can do by
 *    sticking to the break-transparent macros where possible and
 *    using MPP_BREAK_{THROW,CATCH} to bypass any break-unsafe macro
 *    such as MPP_DECLARE that you might need to use. Having done
 *    that, 'break' will do what the user expects.
 *
 *    But if you're using the macros to wrap some context around a
 *    statement you still intend to be executed only once, there will
 *    be unavoidable side effects on 'break': you can't use the
 *    artificially break-unsafe macros because the user might use your
 *    construction in a context with no surrounding loop at all, so
 *    you must stick to the naturally break-transparent and the
 *    break-unsafe, and there aren't enough of the former to be really
 *    useful. So you must just live with 'break' acquiring unhelpful
 *    behaviour inside such a macro.
 *
 *  - Almost none of these macros is transparent to 'continue'. The
 *    naturally break-transparent MPP_BEFORE is, but none of the rest
 *    can possibly be, because as soon as you include any loop
 *    construction in the stuff being prefixed to a statement, you
 *    introduce the invariant that 'continue' is equivalent to jumping
 *    to the end of the suffixed statement or block. This is not too
 *    bad if you're defining a custom loop construction (it was quite
 *    likely the behaviour you wanted for continue anyway), but if you
 *    were trying to use MPP_DECLARE and/or MPP_BEFORE_AND_AFTER to
 *    wrap a statement in some context but still only execute it once,
 *    you'd have to be aware of that limitation.
 *
 *  - MPP_FINALLY and MPP_BREAK_HANDLER can only catch non-local exits
 *    from the block _by break_. They are not true C++ try/finally, so
 *    they can't catch other kinds of exit such as return, goto,
 *    longjmp or exit.
 *
 *  - Finally, it almost goes without saying, but don't forget that
 *    snippets of code you use as parameters to these macros must
 *    avoid using commas not contained inside parentheses, or else the
 *    C preprocessor will consider the comma to end that macro
 *    parameter and start the next one. If there is any reason you
 *    really need an unbracketed comma, you can work around this by
 *    one of two methods:
 *     - define a macro that expands to a comma ('#define COMMA ,')
 *       and then use that macro in place of commas in your macro
 *       argument. It won't be expanded to an actual comma until after
 *       the argument-separation has finished.
 *     - if you're allowed to use C99, define a variadic macro that
 *       expands to its unmodified input argument list ('#define
 *       WRAP(...) __VA_ARGS__') and then enclose comma-using code in
 *       WRAP(). Again, this will protect the commas for just long
 *       enough.
 */

/*
 * MPP_BEFORE: run the code given in the argument 'before' and then
 * the suffixed statement.
 *
 * 'before' should have the syntactic form of one or more declarations
 * and statements, except that a trailing semicolon may be omitted.
 * Any declarations will be in scope only within 'before', not within
 * the suffixed statement.
 *
 * This macro, unusually among the collection, is naturally
 * transparent to 'break' and also transparent to 'continue'.
 */
#define W_BEFORE(labid,before)                  \
    if (1) {                                    \
        before;                                 \
        goto W_LABEL(labid, body);              \
    } else                                      \
    W_LABEL(labid, body):

#endif

