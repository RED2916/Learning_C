#ifndef _TYPE_H_
#define _TYPE_H_

typedef struct Bitnode{
	char data;
	Bitnode *lchild,*rchild;
};

typedef struct sqstack{
	Bitnode *base;
	Bitnode *top;
	int stacksize;
};

#endif
