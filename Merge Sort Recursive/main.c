//Recursive Merge Sort
#include <stdio.h>

void mergeNDsort(int a[], int f1, int m1, int l1)
{
    int i, j, k;
    int n1 = m1 - f1 + 1;
    int n2 = l1 - m1;
    int a1[n1], a2[n2];
    for (i = 0; i < n1; i++)
    {
        a1[i] = a[f1 + i];
    }
    for (j = 0; j < n2; j++)
    {
        a2[j] = a[m1 + 1 + j];
    }
    i = 0;
    j = 0;
    k = f1;
    while (i < n1 && j < n2)
    {
        if (a1[i] <= a2[j])
            a[k++] = a1[i++];
        else
            a[k++] = a2[j++];
    }
    while (i < n1)
        a[k++] = a1[i++];
    while (j < n2)
        a[k++] = a2[j++];
}

void separate(int a[], int f1, int l1)
{
    if(f1 < l1)
    {
        int m1 = f1 + (l1-f1)/2;
        separate(a,f1,m1);
        separate(a,m1+1,l1);
        mergeNDsort(a,f1,m1,l1);
    }
}

int main()
{
    int s;
    printf("Enter the size of Array to be sorted : ");
    scanf("%d",&s);
    printf("\nEnter the array elements :\n");
    int a[s];
    for(int i=0; i < s; i++)
    {
        scanf("%d",&a[i]);
    }
    separate(a,0 ,s - 1);
    printf("\nThe array after Merge Sorting is :\n");
    for (int i = 0; i<s; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
