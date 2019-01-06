/* (C) is Copyright 2019 J.P. Iivonen <wondermacros@yahoo.com>
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

#ifndef __W_OBJECTS_API_H
#define __W_OBJECTS_API_H

#include <strings.h>

static inline void*
w_object_new(void* (*allocate)(size_t), size_t size, void* klass)
{
    struct {
        void* klass;
    }* self = allocate(size);
    self->klass = klass;
    return self;
}

static inline void*
w_object_new0(void* (*allocate)(size_t), size_t size, void* klass)
{
    struct {
        void* klass;
    }* self = allocate(size);
    bzero(self, size);
    self->klass = klass;
    return self;
}

#define W_CALL(o,method) (((o)->klass->method) (o, W_CALL_CLOSE
#define W_CALL_CLOSE(...) __VA_ARGS__))

#define W_CALL_VOID(o,method) (((o)->klass->method)(o))


#define W_NEW(type) \
    w_object_new(malloc,sizeof(struct type),&W_CAT(type,__class_instance))

#define W_NEW0(type) \
    w_object_new0(malloc,sizeof(struct type),&W_CAT(type,__class_instance))


#define W_OBJECT_IS(o,type) ((o)->klass == &W_CAT(type,__class_instance))
#define W_OBJECT_AS(o,type) ((struct type*)(o))


#endif
