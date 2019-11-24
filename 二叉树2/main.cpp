// 2：二叉树.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Stack.h"
#include "type.h"

#define MAX_TREE_SIZE 100

Bitnode* CreateBitTree( Bitnode *T );
int InorderTraverse( Bitnode *T );
int Levelorder( Bitnode *T );

int main( void )
{
	Bitnode *root=(Bitnode *)malloc( sizeof( Bitnode ));//要分配空间，随然看上去没必要。否则报错 
	printf( "Please input:\n" );
	root=CreateBitTree( root );//Giving value with "=" !!
	InorderTraverse( root );
	printf("\n");
	Levelorder( root );
	printf("\n");
	system( "pause" );
	return 0;
}
//返回值为地址比较好 ，此处未完成！ 
Bitnode* CreateBitTree( Bitnode *T )//创建二叉树
{
	char input;
	scanf( "%c",&input );
	if( input == ' ' )
	{
		T=0 ;
	}
	else
	{
		if( !( T=( Bitnode * )malloc( sizeof( Bitnode ) ) ) )//分配失败报错
		{
			exit( 1 );
		}
		T->data=input;
		T->lchild=CreateBitTree( T->lchild );
		T->rchild=CreateBitTree( T->rchild );//先序遍历会优先遍历完左子树
	}
	return T;
}

/*int InorderTraverse( Bitnode *T )//空进栈版本，暂时无法使用
{
	sqstack *S;
	Bitnode *test=(Bitnode *)malloc( sizeof( Bitnode )),*output=(Bitnode *)malloc( sizeof( Bitnode ));
	S=( sqstack * )malloc( sizeof( sqstack ) );
	init_st( S );
	Push( S,T );
	while( gettop( S,test ) != -1 )
	{
		while( gettop( S,output ) && output )//output为空？！栈不愿意使空指针进入！故判断左子树data 注意此处gettop无问题
		{
			Push( S , output->lchild );
		}
		Pop( S,output );
		if( gettop( S,test ) != -1 )
		{
			Pop( S,output );
			printf( "%c\n",output->data );
			if( !output->data )
			{
				return -1;
			}
			Push( S,output->rchild );
		}
	}
	return 1;
}*/

int InorderTraverse( Bitnode *T )
{
	sqstack *S;
	Bitnode *P=T;
	Bitnode *test=(Bitnode *)malloc( sizeof( Bitnode )),*output=(Bitnode *)malloc( sizeof( Bitnode ));
	S=( sqstack * )malloc( sizeof( sqstack ) );
	init_st( S );
	while( gettop( S,test ) != -1 || P )//注意判断符号
	{
		if( P )
		{
			Push( S, P );
			P=P->lchild;
		}
		else
		{
			P=Pop( S,output );//注意，第一次时P并没有空间,似乎没有赋值成功 //此处地址可能在与函数文件交换时丢失
			printf( "%c",P->data );
			if( !P->data )
			{
				return -1;
			}
			P=P->rchild;
		}
	}
	free( S );
	free( test );
	free( output );
	return 1;
}

int Levelorder( Bitnode *T )
{
	sqstack *S;
	Bitnode *P=T;
	Bitnode *test=(Bitnode *)malloc( sizeof( Bitnode )),*output=(Bitnode *)malloc( sizeof( Bitnode ));
	S=( sqstack * )malloc( sizeof( sqstack ) );
	init_st( S );//初始栈
	Push( S, P );
	output=Pop( S,output );//此处地址可能在与函数文件交换时丢失//此处用于第一次判断
	Push( S, output );
	while( gettop( S,test ) != -1 && output )//注意判断符号！！不是||
	{
		output=Pop( S,output );//此处地址可能丢失？
		printf("%c",output->data);
		if( ( output->rchild )!= 0 )
		{
			Push( S,output->rchild );
		}
		if( ( output->lchild )!= 0 )
		{
			Push( S,output->lchild );
		}
	}
	free( S );//没有执行此处？？？
	free( test );
	free( output );
	return 1;
}
