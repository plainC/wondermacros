#ifndef __HTML_API_H
#define __HTML_API_H


#include <boost/preprocessor/variadic/elem.hpp>
#include <boost/preprocessor/variadic/size.hpp>
#include <boost/preprocessor/arithmetic/dec.hpp>
#include <boost/preprocessor/control/expr_if.hpp>
#include <boost/preprocessor/comparison/equal.hpp>

#include <stdarg.h>
#include <stdlib.h>
#include <wondermacros/meta/variadic_rest_n.h>
#include <wondermacros/array/dynamic_array.h>

#include "html_elem.h"

static inline struct html_elem*
html_append_children(struct html_elem* self, struct html** elems)
{
    for (int i=0; elems[i]; i++) {
        W_CALL(self,append_child)(elems[i]);
    }

    return self;
}

static inline struct html**
html_dynamic_array_build(int nbr_of_elems, ...)
{
    struct html** array = NULL;
    va_list ap;
    va_start(ap, nbr_of_elems);
    for (int i=0; i < nbr_of_elems; i++)
        W_DYNAMIC_ARRAY_PUSH(array, va_arg(ap, struct html*));
    va_end(ap);
    return array;
}

#define PTR_STR(p) W_NEW(ptr_string, .value=(p))
#define PTR_INT(p) W_NEW(ptr_int, .value=(p))
#define PTR_DOUBLE(p) W_NEW(ptr_double, .value=(p))
#define COND(c,elem) W_NEW(cond, .name = (c), .child = elem)
#define INT_VAR(n) W_NEW(var_int, .name = n)
#define DOUBLE_VAR(...) W_NEW(var_double, .name = __VA_ARGS__)
#define ARRAY(...) W_NEW(array, .name = __VA_ARGS__)
#define TREE(...) W_NEW(tree, .name = __VA_ARGS__)

#define DOCTYPE _("<!DOCTYPE html>")
#define DOC(...) \
    W_NEW(dom_list, .docs = (void*) html_dynamic_array_build(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__),__VA_ARGS__))


#define html_build(...)                                                              \
    (void*) html_append_children(                                                            \
        W_NEW(html_elem,                                                             \
            .tag = W_CAT(html_elem_tag_,BOOST_PP_VARIADIC_ELEM(0,__VA_ARGS__)),      \
            .attrs = NULL,                                                           \
            .next = NULL),                                                           \
        (struct html*[BOOST_PP_VARIADIC_SIZE(__VA_ARGS__)]) \
            {W_VARIADIC_REST_N(0,__VA_ARGS__)} )

#define _(str) W_NEW(dom_string, .value = str)

#define htmlA(...) html_build(a,__VA_ARGS__)
#define htmlABBR(...) html_build(abbr,__VA_ARGS__)
#define htmlADDRESS(...) html_build(address,__VA_ARGS__)
#define htmlAREA(...) html_build(area,__VA_ARGS__)
#define htmlARTICLE(...) html_build(article,__VA_ARGS__)
#define htmlASIDE(...) html_build(aside,__VA_ARGS__)
#define htmlAPPLET(...) html_build(applet,__VA_ARGS__)
#define htmlAUDIO(...) html_build(audio,__VA_ARGS__)
#define htmlB(...) html_build(b,__VA_ARGS__)
#define htmlBASE(...) html_build(base,__VA_ARGS__)
#define htmlBASEFONT(...) html_build(basefont,__VA_ARGS__)
#define htmlBDI(...) html_build(bdi,__VA_ARGS__)
#define htmlBDO(...) html_build(bdo,__VA_ARGS__)
#define htmlBLOCKQUOTE(...) html_build(blockquote,__VA_ARGS__)
#define htmlBODY(...) html_build(body,__VA_ARGS__)
#define htmlBR(...) html_build(br,__VA_ARGS__)
#define htmlBUTTON(...) html_build(button,__VA_ARGS__)
#define htmlCANVAS(...) html_build(canvas,__VA_ARGS__)
#define htmlCAPTION(...) html_build(caption,__VA_ARGS__)
#define htmlCENTER(...) html_build(center,__VA_ARGS__)
#define htmlCITE(...) html_build(cite,__VA_ARGS__)
#define htmlCODE(...) html_build(code,__VA_ARGS__)
#define htmlCOL(...) html_build(col,__VA_ARGS__)
#define htmlCOLGROUP(...) html_build(colgroup,__VA_ARGS__)
#define htmlDATA(...) html_build(data,__VA_ARGS__)
#define htmlDATALIST(...) html_build(datalist,__VA_ARGS__)
#define htmlDD(...) html_build(dd,__VA_ARGS__)
#define htmlDEL(...) html_build(del,__VA_ARGS__)
#define htmlDETAILS(...) html_build(details,__VA_ARGS__)
#define htmlDFN(...) html_build(dfn,__VA_ARGS__)
#define htmlDIALOG(...) html_build(dialog,__VA_ARGS__)
#define htmlDIR(...) html_build(dir,__VA_ARGS__)
#define htmlDIV(...) html_build(div,__VA_ARGS__)
#define htmlDL(...) html_build(dl,__VA_ARGS__)
#define htmlDT(...) html_build(dt,__VA_ARGS__)
#define htmlEM(...) html_build(em,__VA_ARGS__)
#define htmlEMBED(...) html_build(embed,__VA_ARGS__)
#define htmlFIELDSET(...) html_build(fieldset,__VA_ARGS__)
#define htmlFIGCAPTION(...) html_build(figcaption,__VA_ARGS__)
#define htmlFIGURE(...) html_build(figure,__VA_ARGS__)
#define htmlFONT(...) html_build(font,__VA_ARGS__)
#define htmlFOOTER(...) html_build(footer,__VA_ARGS__)
#define htmlform(...) html_build(form,__VA_ARGS__)
#define htmlH1(...) html_build(h1,__VA_ARGS__)
#define htmlH2(...) html_build(h2,__VA_ARGS__)
#define htmlH3(...) html_build(h3,__VA_ARGS__)
#define htmlH4(...) html_build(h4,__VA_ARGS__)
#define htmlH5(...) html_build(h5,__VA_ARGS__)
#define htmlH6(...) html_build(h6,__VA_ARGS__)
#define htmlHEAD(...) html_build(head,__VA_ARGS__)
#define htmlHEADER(...) html_build(header,__VA_ARGS__)
#define htmlHGROUP(...) html_build(hgroup,__VA_ARGS__)
#define htmlHR(...) html_build(hr,__VA_ARGS__)
#define htmlHTML(...) html_build(html,__VA_ARGS__)
#define htmlI(...) html_build(i,__VA_ARGS__)
#define htmlIFRAME(...) html_build(iframe,__VA_ARGS__)
#define htmlIMG(...) html_build(img,__VA_ARGS__)
#define htmlINPUT(...) html_build(input,__VA_ARGS__)
#define htmlINS(...) html_build(ins,__VA_ARGS__)
#define htmlKDB(...) html_build(kbd,__VA_ARGS__)
#define htmlLABEL(...) html_build(label,__VA_ARGS__)
#define htmlLEGEND(...) html_build(legend,__VA_ARGS__)
#define htmlLI(...) html_build(li,__VA_ARGS__)
#define htmlLINK(...) html_build(link,__VA_ARGS__)
#define htmlLSINDEX(...) html_build(lsindex,__VA_ARGS__)
#define htmlMAIN(...) html_build(main,__VA_ARGS__)
#define htmlMAP(...) html_build(map,__VA_ARGS__)
#define htmlMARK(...) html_build(mark,__VA_ARGS__)
#define htmlMENU(...) html_build(menu,__VA_ARGS__)
#define htmlMETA(...) html_build(meta,__VA_ARGS__)
#define htmlMETER(...) html_build(meter,__VA_ARGS__)
#define htmlNAV(...) html_build(nav,__VA_ARGS__)
#define htmlNOFRAMES(...) html_build(noframes,__VA_ARGS__)
#define htmlNOSCRIPT(...) html_build(noscript,__VA_ARGS__)
#define htmlOBJECT(...) html_build(object,__VA_ARGS__)
#define htmlOL(...) html_build(ol,__VA_ARGS__)
#define htmlOPTGROUP(...) html_build(optgroup,__VA_ARGS__)
#define htmlOPTION(...) html_build(option,__VA_ARGS__)
#define htmlOUTPUT(...) html_build(output,__VA_ARGS__)
#define htmlP(...) html_build(p,__VA_ARGS__)
#define htmlPARAM(...) html_build(param,__VA_ARGS__)
#define htmlPICTURE(...) html_build(picture,__VA_ARGS__)
#define htmlPRE(...) html_build(pre,__VA_ARGS__)
#define htmlPROGRESS(...) html_build(progress,__VA_ARGS__)
#define htmlQ(...) html_build(q,__VA_ARGS__)
#define htmlRP(...) html_build(rp,__VA_ARGS__)
#define htmlRT(...) html_build(rt,__VA_ARGS__)
#define htmlRTC(...) html_build(rtc,__VA_ARGS__)
#define htmlRUBY(...) html_build(ruby,__VA_ARGS__)
#define htmlS(...) html_build(s,__VA_ARGS__)
#define htmlSAMP(...) html_build(samp,__VA_ARGS__)
#define htmlSCRIPT(...) html_build(script,__VA_ARGS__)
#define htmlSECTION(...) html_build(section,__VA_ARGS__)
#define htmlSELECT(...) html_build(select,__VA_ARGS__)
#define htmlSLOT(...) html_build(slot,__VA_ARGS__)
#define htmlSMALL(...) html_build(small,__VA_ARGS__)
#define htmlSOURCE(...) html_build(source,__VA_ARGS__)
#define htmlSPAN(...) html_build(span,__VA_ARGS__)
#define htmlSTRIKE(...) html_build(strike,__VA_ARGS__)
#define htmlSTRONG(...) html_build(strong,__VA_ARGS__)
#define htmlSTYLE(...) html_build(style,__VA_ARGS__)
#define htmlSUB(...) html_build(sub,__VA_ARGS__)
#define htmlSUMMARY(...) html_build(summary,__VA_ARGS__)
#define htmlSUP(...) html_build(sup,__VA_ARGS__)
#define htmlTABLE(...) html_build(table,__VA_ARGS__)
#define htmlTBODY(...) html_build(tbody,__VA_ARGS__)
#define htmlTD(...) html_build(td,__VA_ARGS__)
#define htmlTEMPLATE(...) html_build(template,__VA_ARGS__)
#define htmlTEXTAREA(...) html_build(textarea,__VA_ARGS__)
#define htmlTFOOT(...) html_build(tfoot,__VA_ARGS__)
#define htmlTH(...) html_build(th,__VA_ARGS__)
#define htmlTHEAD(...) html_build(thead,__VA_ARGS__)
#define htmlTIME(...) html_build(time,__VA_ARGS__)
#define htmlTITLE(...) html_build(title,__VA_ARGS__)
#define htmlTR(...) html_build(tr,__VA_ARGS__)
#define htmlTRACK(...) html_build(track,__VA_ARGS__)
#define htmlU(...) html_build(u,__VA_ARGS__)
#define htmlUL(...) html_build(ul,__VA_ARGS__)
#define htmlVAR(...) html_build(var,__VA_ARGS__)
#define htmlVIDEO(...) html_build(video,__VA_ARGS__)
#define htmlWBR(...) html_build(wbr,__VA_ARGS__)


#define attr_build(Tag,Value) \
    W_NEW(html_attr, .tag = W_CAT(html_attr_tag_,Tag), .value = Value)

#define attrACCEPT(v) attr_build(accept,v)
#define attrACCEPT_CHARSET(v) attr_build(accept_charset,v)
#define attrACCESSKEY(v) attr_build(accesskey,v)
#define attrACTION(v) attr_build(action,v)
#define attrALIGN(v) attr_build(align,v)
#define attrALLOW(v) attr_build(allow,v)
#define attrALT(v) attr_build(alt,v)
#define attrASYNC(v) attr_build(async,v)
#define attrAUTOCAPITALIZE(v) attr_build(autocapitalize,v)
#define attrAUTOCOMPLETE(v) attr_build(autocomplete,v)
#define attrAUTOFOCUS(v) attr_build(autofocus,v)
#define attrAUTOPLAY(v) attr_build(autoplay,v)
#define attrBGCOLOR(v) attr_build(bgcolor,v)
#define attrBORDER(v) attr_build(border,v)
#define attrBUFFERED(v) attr_build(buffered,v)
#define attrCHALLENGE(v) attr_build(challenge,v)
#define attrCHARSET(v) attr_build(charset,v)
#define attrCHECKED(v) attr_build(checked,v)
#define attrCITE(v) attr_build(cite,v)
#define attrCLASS(v) attr_build(class,v)
#define attrCODE(v) attr_build(code,v)
#define attrCODEBASE(v) attr_build(codebase,v)
#define attrCOLOR(v) attr_build(color,v)
#define attrCOLS(v) attr_build(cols,v)
#define attrCOLSPAN(v) attr_build(colspan,v)
#define attrCONTENT(v) attr_build(content,v)
#define attrCONTENTEDITABLE(v) attr_build(contenteditable,v)
#define attrCONTEXTMENU(v) attr_build(contextmenu,v)
#define attrCONTROLS(v) attr_build(controls,v)
#define attrCOORDS(v) attr_build(coords,v)
#define attrCROSSORIGIN(v) attr_build(crossorigin,v)
#define attrCSP(v) attr_build(csp,v)
#define attrDATA(v) attr_build(data,v)
#define attrDATA_(v) attr_build(data_,v)
#define attrDATETIME(v) attr_build(datetime,v)
#define attrDECODING(v) attr_build(decoding,v)
#define attrDEFAULT(v) attr_build(default,v)
#define attrDEFER(v) attr_build(defer,v)
#define attrDIR(v) attr_build(dir,v)
#define attrDIRNAME(v) attr_build(dirname,v)
#define attrDISABLED(v) attr_build(disabled,v)
#define attrDOWNLOAD(v) attr_build(download,v)
#define attrDRAGGABLE(v) attr_build(draggable,v)
#define attrDROPZONE(v) attr_build(dropzone,v)
#define attrENCTYPE(v) attr_build(enctype,v)
#define attrFOR(v) attr_build(for,v)
#define attrFORM(v) attr_build(form,v)
#define attrFORMACTION(v) attr_build(formaction,v)
#define attrHEADERS(v) attr_build(headers,v)
#define attrHEIGHT(v) attr_build(height,v)
#define attrHIDDEN(v) attr_build(hidden,v)
#define attrHIGH(v) attr_build(high,v)
#define attrHREF(v) attr_build(href,v)
#define attrHREFLANG(v) attr_build(hreflang,v)
#define attrHTTP_EQUIV(v) attr_build(http_equiv,v)
#define attrICON(v) attr_build(icon,v)
#define attrID(v) attr_build(id,v)
#define attrIMPORTANCE(v) attr_build(importance,v)
#define attrINTEGRITY(v) attr_build(integrity,v)
#define attrISMAP(v) attr_build(ismap,v)
#define attrITEMPROP(v) attr_build(itemprop,v)
#define attrKEYTYPE(v) attr_build(keytype,v)
#define attrKIND(v) attr_build(kind,v)
#define attrLABEL(v) attr_build(label,v)
#define attrLANG(v) attr_build(lang,v)
#define attrLANGUAGE(v) attr_build(language,v)
#define attrLAZYLOAD(v) attr_build(lazyload,v)
#define attrLIST(v) attr_build(list,v)
#define attrLOOP(v) attr_build(loop,v)
#define attrLOW(v) attr_build(low,v)
#define attrMANIFEST(v) attr_build(manifest,v)
#define attrMAX(v) attr_build(max,v)
#define attrMAXLENGTH(v) attr_build(maxlength,v)
#define attrMINLENGTH(v) attr_build(minlength,v)
#define attrMEDIA(v) attr_build(media,v)
#define attrMETHOD(v) attr_build(method,v)
#define attrMIN(v) attr_build(min,v)
#define attrMULTIPLE(v) attr_build(multiple,v)
#define attrMUTED(v) attr_build(muted,v)
#define attrNAME(v) attr_build(name,v)
#define attrNOVALIDATE(v) attr_build(novalidate,v)
#define attrOPEN(v) attr_build(open,v)
#define attrOPTIMUM(v) attr_build(optimum,v)
#define attrPATTERN(v) attr_build(pattern,v)
#define attrPING(v) attr_build(ping,v)
#define attrPLACEHOLDER(v) attr_build(placeholder,v)
#define attrPOSTER(v) attr_build(poster,v)
#define attrPRELOAD(v) attr_build(preload,v)
#define attrRADIOGROUP(v) attr_build(radiogroup,v)
#define attrREADONLY(v) attr_build(readonly,v)
#define attrREFERRERPOLICY(v) attr_build(referrerpolicy,v)
#define attrREL(v) attr_build(rel,v)
#define attrREQUIRED(v) attr_build(required,v)
#define attrREVERSED(v) attr_build(reversed,v)
#define attrROWS(v) attr_build(rows,v)
#define attrROWSPAN(v) attr_build(rowspan,v)
#define attrSANDBOX(v) attr_build(sandbox,v)
#define attrSCOPE(v) attr_build(scope,v)
#define attrSCOPED(v) attr_build(scoped,v)
#define attrSELECTED(v) attr_build(selected,v)
#define attrSHAPE(v) attr_build(shape,v)
#define attrSIZE(v) attr_build(size,v)
#define attrSIZEZ(v) attr_build(sizes,v)
#define attrSLOT(v) attr_build(slot,v)
#define attrSPAN(v) attr_build(span,v)
#define attrSPELLCHECK(v) attr_build(spellcheck,v)
#define attrSRC(v) attr_build(src,v)
#define attrSRCDOC(v) attr_build(srcdoc,v)
#define attrSRCLANG(v) attr_build(srclang,v)
#define attrSRCSET(v) attr_build(srcset,v)
#define attrSTART(v) attr_build(start,v)
#define attrSTEP(v) attr_build(step,v)
#define attrSTYLE(v) attr_build(style,v)
#define attrSUMMARY(v) attr_build(summary,v)
#define attrTABINDEX(v) attr_build(tabindex,v)
#define attrTARGET(v) attr_build(target,v)
#define attrTITLE(v) attr_build(title,v)
#define attrTRANSLATE(v) attr_build(translate,v)
#define attrTYPE(v) attr_build(type,v)
#define attrUSEMAP(v) attr_build(usemap,v)
#define attrVALUE(v) attr_build(value,v)
#define attrWIDTH(v) attr_build(width,v)

#define cssTYPE_SELECTOR(e) W_NEW(css_selector, .elem = e)
#define css(s,d) W_NEW(css_elem, .selector = s, .declarations = d)

#define javascript(s) W_NEW(js_elem, .script = s)

#endif
