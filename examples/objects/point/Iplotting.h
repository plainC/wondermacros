#ifndef __I_PLOTTING_H
#define __I_PLOTTING_H


#define I__plotting__plot(T)         METHOD(T,void,plot,())
#define I__plotting__plot_colored(T) METHOD(T,void,plot_colored,(,const char* color))
#define I__plotting(T) \
    I__plotting__plot(T) \
    I__plotting__plot_colored(T) \
    /* End */

#endif
