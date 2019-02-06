#include <wondermacros/array/for_each.h>

#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <wondermacros/objects/api.h>
# include <wondermacros/array/dynamic_array.h>
#endif

#include "model.h"

#include "html.h"
#include "html_elem.h"
#include "html_attr.h"
#include "html_api.h"
#include "dom_string.h"
#include "dom_list.h"
#include "css_selector.h"
#include "css_elem.h"
#include "js_elem.h"
#include "ptr_string.h"
#include "ptr_int.h"
#include "ptr_double.h"
#include "cond.h"
#include "array.h"
#include "tree.h"

#include "var_int.h"
#include "var_double.h"


int main()
{
    char* script =
        "var x, y, z;"
        "x = 1;"
        "y = 8;"
        "z = x + y;"
        ""
        "document.getElementById(\"demo\").innerHTML ="
        "\"The value of z is \" + z + \".\";";

    int v=42;
    double e=2.744;
    double* prices = NULL;
    int has_prices = 0;

    W_DYNAMIC_ARRAY_PUSH(prices, 2.12, 3.14, 6.32, 4.24, 7.44);

    struct model* model = W_NEW(model);
    W_CALL(model,bind_ptr)("has_prices",0,&has_prices);
    W_CALL(model,bind_ptr)("a",0,&v);
    W_CALL(model,bind_ptr)("e",1,&e);
    W_CALL(model,bind_ptr)("prices",1,prices);


    struct html_elem* doc = DOC(
        DOCTYPE,
        htmlHTML( attrID(_("FooPoro")), attrLANG(_("fi-FI")), attrDIR(_("LTR")), attrCLASS(_("Public")),
            htmlHEAD(
                htmlMETA(attrCHARSET(_("utf-8"))),
                htmlMETA(attrHTTP_EQUIV(_("X-UA-Compatible")), attrCONTENT(_("IE=Edge,chrome=1"))),
                htmlMETA(attrNAME(_("viewport")), attrCONTENT(_("width=device-width, initial-scale=1"))),
                htmlBASE(attrHREF(_("https://local.com/"))),
                htmlTITLE(_("First page"))
            ),
            htmlBODY(
                css(cssTYPE_SELECTOR("p"),"width:9;"),
            ),
            INT_VAR("a"), DOUBLE_VAR("e", .format="%.2%%"), COND("has_prices", ARRAY("prices", htmlLI(htmlB(DOUBLE_VAR("@elem", .format="$%.2f")))))
        )
    );


    char buffer[1024];
    int pos=0;

    struct view_context context;
    context.buffer = buffer;
    context.size = 1024;
    context.pos = 0;

    W_CALL(doc,to_string)(model, &context);
    printf("%s\n", buffer);
}
