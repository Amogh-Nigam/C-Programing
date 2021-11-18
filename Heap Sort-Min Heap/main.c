//Heap Sort Using Min Heap
#include <stdio.h>
#define SIZE 500

int a[SIZE], n = 0;

void Heapification (int a[], int n, int i)
{
    if (i >= n)
        return;
    int left = 2*i+1;
    int right = 2*i+2;
    int index = i;
    if (left < n && a[left] < a[index])
        index = left;
    if (right < n && a[right] < a[index])
        index = right;
    if (i == index)
        return;
    if (i != index)
    {
        int temp = a[i];
        a[i] = a[index];
        a[index] = temp;
        i = index;
    }
    Heapification (a, n, i);
}
void makeheap (int a[], int n)
{
    for (int i = n/2-1; i >= 0; i--)
    {
        Heapification (a, n, i);
    }
}
void HeapSort (int a[], int n)
{
    makeheap (a, n);
    int size = n;
    for (int i = 1; i <= n-1; i++)
    {
        int temp = a[0];
        a[0] = a[size-1];
        a[size-1] = temp;
        size--;
        Heapification (a, size, 0);
    }
}

int main ()
{
    printf("Enter the size of Array to be sorted : ");
    scanf("%d", &n);
    printf("\nEnter the array elements :\n");
    for(int i=0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    HeapSort (a, n);
    printf("\nThe array(Descending Order) after Heap Sort is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

