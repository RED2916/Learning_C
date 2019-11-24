#ifndef _STACK_H_
#define _STACK_H_

#include "type.h"

int init_st( sqstack* S );
int Push( sqstack* S, Bitnode* target ) ;
Bitnode*  Pop( sqstack* S, Bitnode* target );
int gettop( sqstack* S, Bitnode* target );

#endif
