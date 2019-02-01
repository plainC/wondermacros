#ifndef __FSM_TOOLS_H
#define __FSM_TOOLS_H


#define FSM_GO_NEXT_STATE(self,...)                         \
    BOOST_PP_OVERLOAD(_FSM_GO_NEXT_STATE_,__VA_ARGS__)(self,__VA_ARGS__)

#define _FSM_GO_NEXT_STATE_2(self,target,action)            \
    DO_FSM_GO_NEXT_STATE(self,/*none*/,target,action)
#define _FSM_GO_NEXT_STATE_3(self,start,target,action)      \
    DO_FSM_GO_NEXT_STATE(self,W_CAT(FSM,__,start,__exit)(self);,target,action)

#define DO_FSM_GO_NEXT_STATE(self,exit_start,target,action)   \
    W_WRAP(FSM_GO_NEXT_STATE,                                 \
        exit_start                                            \
        self->state = W_CAT(FSM,__,target);                   \
        { action }                                            \
        W_CAT(FSM,__,target,__entry)(self);                   \
        if (W_CAT(FSM,__,target,__meta_auto_transition))      \
            W_CAT(FSM,__,target,__meta_auto_transition(self)); \
    )

#endif

