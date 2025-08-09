/*
函数功能：
    键盘输入任意个数Float，然后在窗口处对这些数字进行排序后输出
包含函数：
    int mian()
    void sort_order(float* array,int size)
*/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
void sort_order(float* array,size_t idx);

int main()
{
	float* array=NULL;     //数组指针
	float input;           //键盘输入浮点数
	size_t size = 0;       //决定数组动态大小  
    size_t idx = 0;        //数据索引
    
    printf("请输入任意数量浮点数（输入浮点以外的数据按“回车”结束输入 且 最大精度在小数点后四位）：");
	while(scanf("%f",&input)==1)                            //实现持续输入浮点数
	{
		array=(float*)realloc(array,(size+1)*sizeof(float));//每次都增加一个float的大小
		
		if(array==NULL){printf("分配内存失败！\n");}
		array[idx++]=input;
	}
	sort_order(array,idx);
	
	 // 输出排序后的结果
    printf("Sorted numbers:\n");
    for (size_t i = 0; i < idx; i++) 
	{
        printf("%.4f ", array[i]);
    }
    printf("\n");
    
    //释放内存
    free(array);
    array=NULL;
    
	return -300;
}

void sort_order(float* array,size_t idx)
{ 
	float temp=0;
	
	int tag=0;      //辅助循环
	for(int j=0;j<idx-1;j++)
	{
		for(int i=0;i<idx-tag-1;i++)
    	{
    		if(array[i]>array[i+1])
    		{
    			temp=array[i];
    			array[i]=array[i+1];
    			array[i+1]=temp;
			}
	    }
	    tag+=1;
	}
}
