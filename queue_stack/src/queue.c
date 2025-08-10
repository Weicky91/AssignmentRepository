#include"../include/queue.h"
/*函数实现*/
//队列初始化函数
void QueueInit(queue* q)
{
	q->front=0;  //初始化指针
	q->rear=0;
	
	for(int i=0;i<MaxQueueLen;i++)
	{
		q->data[i]=0;//初始队列数据
	}
}


//队列是否满函数
/*
关于队列是否满了，主要看此时rear是不是指向了最大的存储位上，因此通过（rear+1）%MaxQueueLen==0来判断
因此：true：队列已满
      false：队列未满
*/
bool QueueIsFull(queue* q)
{
	if(((q->rear+1)%MaxQueueLen)==q->front)return true;//判断尾指针位置
	else{return false;}
}


//队列是否空函数
/*
队列空的意味着初始rear和front都是0；
*/
bool QueueIsEmpty(queue* q)
{
	if(q->rear==q->front)return true;//判断头尾指针位置
	else{
		return false;
	}
}


//队列输入函数
bool QueuePut(queue* q,int value)
{
	//判断是否满了，满了就不存了
	if(QueueIsFull(q))return false;
	
	//没满则队列
	q->data[q->rear]=value;
	q->rear=(q->rear+1)%MaxQueueLen;//进行下一次数据输入的指针位置
}


//队列输出函数
bool QueueOut(queue* q,int *value)
{
	//先判断队列是不是空的，空的直接返回
	if(QueueIsEmpty(q))return false;
	
	//将数值赋予
	*value=q->data[q->front];
	q->front=(q->front+1)%MaxQueueLen;//为了读取并输出下一次数据的指针位置
}
