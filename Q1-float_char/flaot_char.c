/*
函数内容：两个float类型的值59.622f与92.6327f存入一个长度为4的char数组中
          再从该数组中提取出两个float类型的值，使用你能想到的方法，缩小提取出的小数和原来数字之间的差距
窗口输出：
*/
#include<stdio.h>
#include<string.h>

void storefloats(char *array, float a, float b) 
{
    // 将 a 的低 2 字节存储到数组中
    memcpy(array, (char *)&a + 2, 2);
    // 将 b 的低 2 字节存储到数组中
    memcpy(array + 2, (char *)&b + 2, 2);
}
void extract(char *array, float* a, float* b) 
{
	// 从数组中提取 a 的低 2 字节
    memcpy((char *)a + 2, array, 2);
    // 从数组中提取 b 的低 2 字节
    memcpy((char *)b + 2, array + 2, 2);
}

int main() {
    char array[4];
    float a=59.622f,b=2.6327f; 

    storefloats(array, a, b);

    // 打印数组内容
    printf("存储情况：\n");
    for (int i = 0; i < 4; i++) {
        printf("%02X ", (unsigned char)array[i]);
    }
    printf("\n\n");
    
    
    float a1,a2;
    extract(array,&a1,&a2);
    printf("精度损失情况（Δ提取-原数据）：\n%.3f ,%.3f", a1-a,a2-b);
    printf("\n");
    
    return -300;
}