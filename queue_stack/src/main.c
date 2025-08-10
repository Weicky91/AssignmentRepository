#include <stdio.h>
#include "../include/stack.h"
#include "../include/queue.h"

int main()
{
    queue q;
    stack s;
    int a = 2;
    float b = 3;
    unsigned int c = 12;
    int get = 0;

    // initial operation
    QueueInit(&q);
    StackInit(&s, 50);

    // data put in q
    for (int i = 0; i < MaxQueueLen; i++)
    {
        QueuePut(&q, i + 1);
    }
    for (int i = 0; i < MaxQueueLen; i++)
    {
        QueueOut(&q, &get);
        printf("%d  ", get);
    }

    // put data in s
    StackPush(&s, &a, sizeof(int));
    StackPush(&s, &b, sizeof(float));
    StackPush(&s, &c, sizeof(unsigned int));

    printf("\n\n");
    printf("data to stack: %d  %f  %d\n",a,b,c);
    a = 0;
    b = 0;
    c = 0;
    // pop  out
    printf("data from stack: ");
    StackPop(&s, &c, sizeof(unsigned int));
    printf("%d  ", c);
    StackPop(&s, &b, sizeof(float));
    printf("%f  ", b);
    StackPop(&s, &a, sizeof(int));
    printf("%d\n", a);
    return 0;
}