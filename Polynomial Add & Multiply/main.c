//Polynomial Addition & Multiplication
#include<stdio.h>
#include<stdlib.h>

struct poly
{
    float coeff;
    int exp;
};
typedef struct poly Polynomial;

void Input(Polynomial poly[],int *size)
{
    printf("\nEnter size of polynomial : ");
    scanf("%d",size);
    for (int i = 0; i < *size; i++)
    {
        printf("\nDegree of element %d : ",i+1);
        scanf("%d",&poly[i].exp);
        printf("Coeffcient of element %d : ",i+1);
        scanf("%f",&poly[i].coeff);
    }
}

void Output(Polynomial poly[],int size)
{
    for (int i = 0; i < size; i++)
    {
        if(poly[i].coeff == 0)
            i++;
        else
            printf("(%.2f)",poly[i].coeff);
        if(poly[i].exp == 0)
            printf("");
        else if(size - i != 1)
            printf("x^%d+",poly[i].exp);
        else
            printf("x^%d",poly[i].exp);
    }
}

void Addition(Polynomial poly1[], Polynomial poly2[], Polynomial result[], int size1, int size2, int *size3)
{
    int i = 0, j = 0, k = 0;
    *size3 = 0;
    while (i < size1 || j < size2)
    {
        if (poly1[i].exp == poly2[j].exp)
        {
            result[k].coeff = poly1[i].coeff + poly2[j].coeff;
            result[k].exp = poly1[i].exp;
            (*size3)++;
            i++;
            j++;
            k++;
        }
        else if(poly1[i].exp > poly2[j].exp)
        {
            result[k].coeff = poly1[i].coeff;
            result[k].exp = poly1[i].exp;
            (*size3)++;
            i++;
            k++;
        }
        else
        {
            result[k].coeff = poly2[j].coeff;
            result[k].exp = poly2[j].exp;
            (*size3)++;
            j++;
            k++;
        }
    }
}

void multiply(Polynomial poly1[], Polynomial poly2[], Polynomial result[], int size1, int size2, int *size3)
{
    Polynomial poly3[10], poly4[100];
    int m = 0;
    for(int i = 0; i < 100; i++)
    {
        result[i].coeff = 0;
        result[i].exp = 0;
        poly4[i].coeff = 0;
        poly4[i].exp = 0;
    }
    for(int i = 0; i < size1; i++)
    {
        int k = -1, l = 0;
        for(l = 0; l < m; l++)
        {
            poly4[l].coeff = result[l].coeff;
            poly4[l].exp = result[l].exp;
        }
        for(int j = 0; j < size2; j++)
        {
            poly3[++k].exp = poly1[i].exp + poly2[j].exp;
            poly3[k].coeff= poly1[i].coeff * poly2[j].coeff;
        }
        Addition(poly3,poly4,result,k+1,l,&m);
    }
    *size3=m;
}

int main()
{
    Polynomial poly1[10], poly2[10], result[100];
    int size1, size2, size3;
    printf("Enter Polynomial 1 : ");
    Input(poly1,&size1);
    printf("\nEnter Polynomial 2 : ");
    Input(poly2,&size2);
    Addition(poly1, poly2, result, size1, size2, &size3);
    printf("\nPolynomial 1 : \n");
    Output(poly1, size1);
    printf("\n\nPolynomial 2 : \n");
    Output(poly2, size2);
    printf("\n\nAddition of 2 Polynomials : \n");
    Output(result, size3);
    multiply(poly1, poly2, result, size1, size2, &size3);
    printf("\n\nMultiplication of 2 Polynomial : \n");
    Output(result, size3);
    printf("\n\n");
    return 0;
}
