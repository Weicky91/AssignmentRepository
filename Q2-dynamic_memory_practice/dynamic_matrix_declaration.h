#ifndef matrix_dynamic_
#define matrix_dynamic_

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

typedef struct MPara
{
	int row;
	int column;
	float** data;
}*Matrix;

//functions
/*矩阵生成函数，通过输入行列生成对应大小内存*/
Matrix CreateM(int row,int column);

/*矩阵转置函数*/
Matrix TransM(Matrix M);

/*矩阵相乘函数*/
Matrix MultiM(Matrix M1,Matrix M2);

/*释放矩阵函数*/
void FreeM(Matrix m);

/*矩阵打印函数*/
void PrintM(Matrix M);
#endif

