//Sparse Matrix Addition
#include<stdio.h>
#include<stdlib.h>

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
//        printf("Number of Elements in Matrix %c is Greater Than %d X %d !!!\n", ch, a[0].row, a[0].column); if(a[0].value > a[0].row * a[0].column)
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

void Add_Sparse_Matrix(struct sparse a[], struct sparse b[])
{
    struct sparse c[10];
    int k = 1, l = 1, m = 1;
    c[0].row = a[0].row;
    c[0].column = a[0].column;
    c[0].value = 0;
    for (int i = 0; i < c[0].row; i++)
    {
        for (int j = 0; j < c[0].column; j++)
        {
            if(i == a[k].row && j == a[k].column && i == b[l].row && j == b[l].column)
            {
                c[m].row = i;
                c[m].column = j;
                c[m].value = a[k].value + b[l].value;
                k++;
                l++;
                m++;
                c[0].value++;
            }
            else if(i == a[k].row && j == a[k].column)
            {
                c[m].row = i;
                c[m].column = j;
                c[m].value = a[k].value;
                k++;
                m++;
                c[0].value++;
            }
            else if (i == b[l].row && j == b[l].column)
            {
                c[m].row = i;
                c[m].column = j;
                c[m].value = b[l].value;
                l++;
                m++;
                c[0].value++;
            }
        }
    }
        printf("\nMatrix C After Addition of Matrix A and Matrix B\n");
        Output(c);
}

int main()
{
    printf("Pl Fill as Described \n\t--> First fill all non-zero Elements in Row No. 0 then of Row No. 1 and then of Row No. 2 etc ... <--\n");
    struct sparse a[100] ,b[100];
    printf("\t>> For Matrix A <<");
    Input(a,'A');
    Output(a);
    printf("\n\t>> For Matrix B <<");
    Input(b,'B');
    Output(b);
    if(a[0].row != b[0].row || a[0].column != b[0].column)
    {
        printf("\nAddition Not Possible as Matrix A and Matrix B have DIFFERENT No. of Rows and Columns\n");
        exit(0);
    }
    Add_Sparse_Matrix(a,b);
    return 0;
}

