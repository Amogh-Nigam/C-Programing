//Non Recursive Merge Sort
#include <stdio.h>

void Merge_ND_Sort(int a[], int f1, int m1, int l1)
{
    int i = f1, j = m1 + 1, k = f1;
    int b[100];
    while (i <= m1 && j <= l1)
    {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    for ( ; i <= m1; i++ )
    {
        b[k++] = a[i];
    }
    for (; j <= l1; j++)
    {
        b[k++] = a[j];
    }
    for (i = f1; i <= l1; i++)
    {
        a[i] = b[i];
    }
}
void Separate(int a[], int n)
{
    for (int len = 1; len < n; len = len * 2)
    {
        for (int i = 0; i<n; i = i + 2*len)
        {
            int f1 = i;
            int l1 =  i + ((2 * len) - 1);
            int m1 = (f1+l1)/2;
            if (l1 >= n)
                l1 = n-1;
            Merge_ND_Sort(a, f1, m1, l1);
        }
    }
}

int main()
{
    int n;
    printf("Enter the size of Array to be sorted : ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the array elements :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    Separate(a, n);
    printf("\nSorted array is : ");
    for (int i = 0; i < n; i++)
        printf("%d  ", a[i]);
    printf("\n\n");
    return 0;
}
