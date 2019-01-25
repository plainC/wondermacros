#include <wondermacros/array/for_each.h>

#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <wondermacros/objects/api.h>
#endif

#include "html.h"
#include "html_elem.h"
#include "html_attr.h"


int main()
{
    struct html_elem* doc = W_NEW(html_elem, .tag = html_elem_tag_html, .attrs = NULL, .next = NULL);
    char buffer[1024];
    int pos=0;

    W_CALL(doc,append_child)(W_NEW(html_attr, .tag = html_attr_tag_hidden, .value = "true"));
    W_CALL(doc,to_string)(buffer, 1024, &pos);
    printf("%s\n", buffer);
}
