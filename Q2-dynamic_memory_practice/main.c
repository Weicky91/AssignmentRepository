#include"dynamic_matrix_declaration.h"
//printf("\n");
int main() {
	Matrix C;
	int row=0;
	int column=0;
	
    printf("please put in the row and column:\n ");
    printf("row: ");
    scanf("%d", &row);

    printf("column: ");
    scanf("%d", &column);
    
	C=CreateM(row,column);
	
	printf("now put in data (row is prior to coumn):\n");
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			scanf("%f",&C->data[i][j]);
		}
	}
	
	Matrix CT=TransM(C);
	
	Matrix CCT=MultiM(C,CT);
	
	printf("转置矩阵：\n");
	PrintM(CT);
	printf("\n");printf("\n");
	
	printf("两个矩阵相乘：\n");
	PrintM(CCT);
	printf("\n");
	
	return 0;
}