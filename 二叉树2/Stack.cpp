// 1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Stack.h"
#include "type.h"



#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
//不可有分号！
/*int init_st( sqstack *S );
int Push( sqstack *S, Bitnode* target ) ;
Bitnode*  Pop( sqstack* S, Bitnode* target );
int gettop( sqstack S, Bitnode* target );*/


int init_st( sqstack *S )
{
	S->base=( Bitnode* )malloc( sizeof( Bitnode )*STACK_INIT_SIZE );//分配内存空间（？）
	if( !S->base )
	{
		exit( 1 );
	}
	S->top=S->base;
	S->stacksize=STACK_INIT_SIZE;
	return 1;
}

int Push( sqstack *S, Bitnode* target )//入栈，最终仍使用地址，为使空指针入栈 失败！
{
	if( (S->top-S->base)>=S->stacksize )//重新分配内存空间
	{
		S->base=( Bitnode* )realloc( S->base,( STACK_INIT_SIZE+STACKINCREMENT )* sizeof( Bitnode ));
		if( !S->base )
		{
			exit( 1 );
		}
		S->top=S->base+S->stacksize;
		S->stacksize+= STACKINCREMENT;
	}
	*(S->top++)=*target;
	//S->top++;//注意！！！
	return 1;
}

Bitnode* Pop( sqstack* S, Bitnode* target )//出栈
{
	Bitnode *output=(Bitnode *)malloc( sizeof( Bitnode ));
	if( (S->top)==(S->base) )//判断栈是否为空
	{
		exit( 1 );
	}
	//target=(Bitnode *)malloc( sizeof( Bitnode ));//取消了内存？并不是！
	*output = *(--S->top)  ;//注意！出现问题，无法正常直接赋值给TARGET!!!
	//target=output;
	return output;
}

int gettop( sqstack* S, Bitnode* target )//取栈顶元素
{
	if( S->top==S->base )//判断栈是否为空
	{
		return -1;
	}
	*target = (*( S->top-1 ));//"--"有问题！
	return 1;
}
