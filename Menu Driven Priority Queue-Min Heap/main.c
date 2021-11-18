//Menu Driven Priority Queue Using MIN Heap
#include <stdio.h>
#define SIZE 500

int a[SIZE], n = 0;

void display (int a[], int *n)
{
    printf("Priority Queue(MIN-HEAP) contains : ");
    for (int i = 0; i < *n; i++)
        printf("%d ", a[i]);
}

void insert (int a[], int *n, int x)
{
    a[*n] = x;
    *n = *n+1;
    int i = (*n)-1;
    while (i > 0)
    {
        int parent = (i-1)/2;
        if (a[i] < a[parent])
        {
            int temp = a[i];
            a[i] = a[parent];
            a[parent] = temp;
            i = parent;
        }
        else
        break;
    }
}

int delete (int a[], int *n)
{
    int x = a[0];
    a[0] = a[*n-1];
    *n = *n-1;
    int i = 0;
    while (1)
    {
        int left = 2*i+1;
        int right = 2*i+2;
        int index = i;
        if (left < *n && a[left] < a[index])
            index = left;
        if (right < *n && a[right] < a[index])
            index = right;
        if (index == i)
            break;
        else
        {
            int temp = a[i];
            a[i] = a[index];
            a[index] = temp;
            i = index;
        }
    }
    return x;
}

int main ()
{
    int choice = 0;
    int x, ele;
    do
    {
        printf("\t\t   MENU Min-Heap\n\n");
        printf("1 - Inserting Element in Priority Queue\n");
        printf("2 - Deleting Element from Priority Queue\n");
        printf("3 - Display Elements of Priority Queue\n");
        printf("4 - Exit from the Program\n");
        printf("\nSelect the Option No. : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("\tEnter number to Insert in Priority Queue : ");
                scanf("%d", &x);
                insert (a, &n, x);
                printf("\tValue %d Added Successfully.\n\n", x);
                break;
            }
            case 2:
            {
                if (n == 0)
                {
                    printf("\tPriority Queue is Empty !!! Please Insert Some Values...\n\n");
                }
                ele = delete (a, &n);
                printf("\tElement Deleted is : %d\n\n", ele);
                break;
            }
            case 3:
            {
                if (n == 0)
                {
                    printf("\tPriority Queue is Empty !!! Please Insert Some Values...\n\n");
                }
                display (a, &n);
                printf("\n\n");
                break;
            }
            case 4:
            {
                printf("\tExit Successful.\n");
                break;
            }
            default:
            {
                printf("\tInvalid Option!!!\n\tPlease Try Again...\n\n");
                break;
            }
        }
    }while(choice != 4);
}
