#ifndef  STACK_H_
#define  STACK_H_

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include <stdlib.h> 

//struct declaration
typedef struct Stack//先入后出：类比弹夹(数据修改只会联系上top栈顶)
{
	char* top; //栈顶
	char* base;//栈底
	unsigned int size;  //栈的大小
}stack;



//function declarations
/*
栈的初始化函数
*/
void StackInit(stack* s,unsigned int size);

/*
栈是否空函数
*/
bool StackIsEmpty(stack* s);

/*
栈是否满函数
*/
bool StackIsFull(stack* s);

/*
入栈函数;为了可以传入多种类型的变量，使用void类型解决
*/
bool StackPush(stack* s,void* value,int size);

/*
出栈函数
*/
bool StackPop(stack* s,void* value,int size);

/*
栈内存清空
*/
void StackFree(stack *s);
#endif