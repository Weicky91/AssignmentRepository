#include"../include/stack.h"

//function declarations
/*
栈的初始化函数
*/
void StackInit(stack* s,unsigned int size)
{
	s->base=(char*)malloc(size*sizeof(char));//分配设置字节的大小内存
	s->top=s->base;
	s->size=size;//字节数量
}

/*
栈是否空函数
*/
bool StackIsEmpty(stack* s)
{
	return(s->base==s->top);
}

/*
栈是否满函数
*/
bool StackIsFull(stack* s)
{
	return((s->base-s->top)>=s->size);//当这两个指针中间大小内存大于等于size，就是满了（本身说好了分给size大小的内存）
}

/*
入栈函数
*/
bool StackPush(stack* s,void* value,int size)
{
	if(StackIsFull(s))return false;
	//这里先腾出预备存储的数据大小，然后将地址往低位移动，为了后面memcpy数据内容提出空间（base所在的地址就是数据上限）-物理上限
	s->top-=size;//地址向上生长
	memcpy(s->top,value,size);
}

/*
出栈函数
*/
bool StackPop(stack* s,void* value,int size)
{
	//是不是足够出栈，而不是有没有数据，要考虑到里面剩余字节数是否足够支持输出
	if(s->base-s->top<size)return false;
	//数据主流是小端模式，从内存地位读到高位，所以直接从top指针出往高位（base方向）进行字节copy，传递给value
	memcpy(value,s->top,size);
	s->top+=size;//地址朝base方向走
}

/*
栈内存清空
*/
void StackFree(stack *s)
{
	free(s->base);
	s->base=NULL;
	s->top=NULL;
}