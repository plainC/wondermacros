### Source code and other examples

The source code of the previous example can be found 
[here](https://github.com/plainC/wondermacros/tree/master/examples/objects/point). There is 
[another example](https://github.com/plainC/wondermacros/tree/master/examples/objects/html) which
implements a simple web content generation classes (HTML elements, HTML attributes, strings and simple string templates).

See also [Web Elements](https://github.com/plainC/web_elements).

```C
int main()
{
    int v=42;
    double e=2.744;
    double* prices = NULL;
    int has_prices = 1;

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
```

