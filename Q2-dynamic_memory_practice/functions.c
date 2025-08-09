#include"dynamic_matrix_declaration.h"
/*矩阵生成函数，通过输入行列生成对应大小内存*/
Matrix CreateM(int row,int column)
{
	Matrix m=(Matrix)malloc(sizeof(struct MPara));
	if(!m)return NULL;
	
	m->row=row;
	m->column=column;
	
	/*通过输入的行和列*(sizeof)float确定矩阵大小*/
	/*先给行生成row个一级指针“float**” */
	m->data=(float**)malloc(row*sizeof(float*));
	if(!m->data){free(m);return NULL;}
	
	/*给列生成column个二级指针“float*”*/
	for(int i=0;i<row;i++)
	{
		m->data[i]=(float*)calloc(column,sizeof(float));
		if(!m->data[i])
		{
			//逐级释放
		    while(i--)free(m->data[i]);
		    
		    free(m->data);
		    free(m);
		    //NULL——内存分配失败
		    return NULL;
		}
	}
	
	return m;
}
	


/*矩阵转置函数*/
Matrix TransM(Matrix M)
{
	Matrix MT=CreateM(M->column,M->row);
	for(int i=0;i<M->row;i++)
	{
		for(int j=0;j<M->column;j++)
		{
			MT->data[j][i]=M->data[i][j];
		}
	}
	
	return MT;
}

/*矩阵相乘函数*/
Matrix MultiM(Matrix M1,Matrix M2)
{
	if(M1->column!=M2->row)return NULL;
	
	Matrix C=CreateM(M1->row,M2->column);	
	
	float data=0;
	for(int i=0;i<M1->row;i++)
	{
		for(int j=0;j<M2->column;j++)
		{
			for(int p=0;p<M1->column;p++)
			{
				data+=M1->data[i][p]*M2->data[p][j];
			}
			C->data[i][j]=data;
			data=0;
		}
	}
	
	return C;
}

/*释放矩阵函数*/
void FreeM(Matrix m)
{
	if(!m)return;
	for(int i=0;i<m->row;i++){free(m->data[i]);m->data[i]=NULL;}
	
	free(m->data);m->data=NULL;
	free(m);

}

/*矩阵打印函数*/
void PrintM(Matrix M)
{
	for(int i=0;i<M->row;i++)
	{
		for(int j=0;j<M->column;j++)
		{
			printf("%.2f   ",M->data[i][j]);
		}
		printf("\n");
	}
}