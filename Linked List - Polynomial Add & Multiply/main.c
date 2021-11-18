//struct poly Addition & Multiplication Using Linked List
#include<stdio.h>
#include<stdlib.h>

struct poly
{
    float coeff;
    int exp;
    struct poly *next;
};
typedef struct poly Polynomial;

void Input(Polynomial **poly)
{
    int size;
    Polynomial *p, *q;
    printf("\nEnter size of polynomial : ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        p = (Polynomial*)malloc(sizeof(Polynomial));
        p->next = NULL;
        printf("\nDegree of element %d : ",i+1);
        scanf("%d",&p->exp);
        printf("Coeffcient of element %d : ",i+1);
        scanf("%f",&p->coeff);
        if(*poly == NULL)
            *poly = p;
        else
        {
            q = *poly;
            while (q->next != NULL)
                q = q->next;
            q->next=p;
        }
    }
}

void Output(Polynomial *poly)
{
    Polynomial *p = poly;
    if(p == NULL)
        printf("0");
    while (p!=NULL)
    {
        if(p->next == NULL)
            printf("(%.2f)x^%d", p->coeff, p->exp);
        else
            printf("(%.2f)x^%d+", p->coeff, p->exp);
        p = p->next;
    }
}

Polynomial *Addition(Polynomial *poly1, Polynomial *poly2)
{
    Polynomial *poly3 = NULL, *p, *q;
    if(poly1 == NULL)
    {
        poly3 = poly2;
        return poly3;
    }
    if(poly2 == NULL)
    {
        poly3 = poly1;
        return poly3;
    }
    while (poly1 != NULL || poly2 != NULL)
    {
        p = (Polynomial*)malloc(sizeof(Polynomial));
        p->next = NULL;
        if (poly1!=NULL && poly2!=NULL)
        {
            if (poly1->exp == poly2->exp)
            {
                p->coeff = poly1->coeff + poly2->coeff;
                p->exp = poly1->exp;
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
            else if(poly1->exp > poly2->exp)
            {
                p->coeff = poly1->coeff;
                p->exp = poly1->exp;
                poly1 = poly1->next;
            }
            else
            {
                p->coeff = poly2->coeff;
                p->exp = poly2->exp;
                poly2 = poly2->next;
            }
        }
        else
        {
            if(poly2 == NULL)
            {
                p->coeff = poly1->coeff;
                p->exp = poly1->exp;
                poly1 = poly1->next;
            }
            else if(poly1 == NULL)
            {
                p->coeff = poly2->coeff;
                p->exp = poly2->exp;
                poly2 = poly2->next;
            }
        }
        if(poly3 == NULL)
            poly3 = p;
        else
        {
            q = poly3;
            while (q->next != NULL)
                q = q->next;
            q->next = p;
        }
    }
    return poly3;
}

Polynomial *Multiply(Polynomial *poly1, Polynomial *poly2)
{
    struct poly *poly3 = NULL, *p, *q, *l = NULL, *m;
    while(poly1 != NULL)
    {
        p = poly2;
        l = NULL;
        while(p != NULL)
        {
            q = (Polynomial*)malloc(sizeof(Polynomial));
            q->coeff = poly1->coeff * p->coeff;
            q->exp = poly1->exp + p->exp;
            q->next = NULL;
            if(l == NULL)
                l = q;
            else
            {
                m = l;
                while (m->next != NULL)
                    m = m->next;
                m->next = q;
            }
            p = p->next;
        }
            poly3 = Addition(poly3, l);
            poly1 = poly1->next;
        }
    return poly3;
}

int main()
{
    Polynomial *poly1 = NULL, *poly2 = NULL;
    printf("Enter Polynomial 1 : ");
    Input(&poly1);
    printf("\nEnter Polynomial 2 : ");
    Input(&poly2);
    printf("\nPolynomial 1 : \n");
    Output(poly1);
    printf("\n\nPolynomial 2 : \n");
    Output(poly2);
    printf("\n\nAddition of 2 Polynomials : \n");
    Output(Addition(poly1, poly2));
    printf("\n\nMultiplication of 2 Polynomial : \n");
    Output(Multiply(poly1, poly2));
    printf("\n\n");
    return 0;
}

