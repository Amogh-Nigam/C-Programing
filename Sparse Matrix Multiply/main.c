//Sparse Matrix Multiplication
#include<stdio.h>
#include<stdlib.h>
#define SIZE 150

struct sparse
{
    int row;
    int column;
    int value;
};

void Input(struct sparse a[], char ch)
{
    printf("\nEnter size of m & n for mxn Matrix %c" ,ch);
    printf("\nEnter Number of Rows 'm' : ");
    scanf("%d", &a[0].row);
    printf("Enter Number of Columns 'n' : ");
    scanf("%d",&a[0].column);
    printf("How many non-zero values in the Matrix (MAX = %d) : ",(int)(0.33 * a[0].row * a[0].column));
    scanf("%d",&a[0].value);
    if(a[0].value > 0.33 * a[0].row * a[0].column)
    {
        printf("\nNumber of NON ZERO NUMBERS are more than 33 %% of the Matrix thus if Sparse Matrix Method is used it --> WON'T SAVE SPACE <--");
        printf("\n\t EXITING THE PROGRAM !!!\n\n");
        exit(0);
    }
    for (int i = 1; i <= a[0].value; i++)
    {
        printf("\nRow value : ");
        scanf("%d",&a[i].row);
        printf("Column value : ");
        scanf("%d",&a[i].column);
        printf("Element value : ");
        scanf("%d",&a[i].value);
        if(a[i].row >= a[0].row || a[i].column >= a[0].column)
        {
            printf("\nWrong Entry !!! \n--> Value of Row/Column EXCEED Total No. of Rows/Columns <--\nTry Again ...\n");
            i = i - 1;
            continue;
        }
        if(i > 1)
        {
            if(a[i-1].row > a[i].row)
            {
                printf("\nWrong Entry !!! Pl Fill as Described \nNOTE : LAST 2 INPUT DECLINED\n Try Again ...\n");
                i = i - 2;
                continue;
            }
        }
    }
}

void Output(struct sparse a[])
{
    int k = 1;
    printf("\nMatrix : \n");
    for (int i = 0; i < a[0].row; i++)
    {
        for (int j = 0; j < a[0].column; j++)
        {
            if(k <= a[0].value)
            {
                if(i == a[k].row && j == a[k].column)
                {
                    printf("%d\t",a[k].value);
                    k++;
                }
                else
                    printf("%d\t",0);
            }
            else
                    printf("%d\t",0);
        }
        printf("\n");
    }
 }

void transpose(struct sparse b[], struct sparse x[])
{
    int c[b[0].column], d[b[0].column];
    for (int i = 0; i <= b[0].column - 1; i++)
    {
        c[i] = 0;
    }
    for (int i = 1; i <= b[0].value; i++)
    {
        c[b[i].column] = c[b[i].column] + 1;
    }
    d[0] = c[0];
    for (int i = 1; i <= b[0].column - 1; i++)
    {
        d[i] = d[i - 1] + c[i - 1];
    }
    x[0].row = b[0].column;
    x[0].column = b[0].row;
    x[0].value = b[0].value;
    for (int i = 1; i <= b[0].value; i++)
    {
        x[d[b[i].column]].row = b[i].column;
        x[d[b[i].column]].column = b[i].row;
        x[d[b[i].column]].value = b[i].value;
        d[b[i].column] = d[b[i].column] + 1;
    }
}

void Multiply_Sparse_Matrix(struct sparse a[], struct sparse b[])
{
    struct sparse c[SIZE];
    int l=1,n=1,sum=0;
    c[0].row=a[0].row;
    c[0].column=b[0].row;
    c[0].value=0;
    for (int i=0; i<c[0].row; i++)
    {
        for (int j=0;j<c[0].column; j++)
        {
            sum=0;
            for (int k=0; k<b[0].column; k++)
            {
                if(i==a[l].row && j==b[k+1].row && a[l].column==b[k+1].column)
                {
                    sum=sum+(a[l].value*b[k+1].value);
                }
            }
                if(sum!=0)
                {
                    c[n].row=i;
                    c[n].column=j;
                    c[n].value=sum;
                    c[0].value++;
                    n++;
                }
        }
            l++;
    }
    printf("\nMatrix C After Multiplication of Matrix A and Matrix B\n");
    Output(c);
}

int main()
{
    printf("Number of NON ZERO NUMBERS should not be more than 33 %% of the Matrix else Sparse Matrix Method --> WON'T SAVE SPACE <--\n");
    printf("Pl Fill as Described \n\t--> First fill all non-zero Elements in Row No. 0 then of Row No. 1 and then of Row No. 2 etc ... <--\n");
    struct sparse a[SIZE], b[SIZE], d[SIZE];
    printf("\t>> For Matrix A <<");
    Input(a,'A');
    Output(a);
    printf("\n\t>> For Matrix B <<");
    Input(b,'B');
    Output(b);
    if(a[0].column != b[0].row)
    {
        printf("\nMultiplication Not Possible as Matrix A and Matrix B have DIFFERENT No. of Rows and Columns\n");
        printf("\n\t EXITING THE PROGRAM !!!\n\n");
        exit(0);
    }
    transpose(b, d);
    Multiply_Sparse_Matrix(a, d);
    return 0;
}
