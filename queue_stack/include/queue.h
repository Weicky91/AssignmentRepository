#ifndef  QUEUE_H_
#define  QUEUE_H_

#define MaxQueueLen 50

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
/*通过%MaxQueueLen 取模可以实现循环队列，并且不会无线增大内存空间*/
typedef struct Queue
{
	unsigned char front;
	unsigned char rear;
	int data[MaxQueueLen];
}queue;

/*函数实现*/
//队列初始化函数
void QueueInit(queue* q);
//队列是否满函数
bool QueueIsFull(queue* q);
//队列是否空函数
bool QueueIsEmpty(queue* q);
//队列输入函数
bool QueuePut(queue* q,int value);
//队列输出函数
bool QueueOut(queue* q,int *value);

#endif