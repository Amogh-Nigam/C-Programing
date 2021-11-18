//Menu Driven Operation on Arrays
#include <stdio.h>

int MAXSIZE = 500;
//Bubble Sort
void sort(int arr[], int size)
{
    for(int i = 0 ; i <= size-2 ; i++)
    {
        for(int j = 0 ; j <= size-i-2; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j] ;
                arr[j] = arr[j+1] ;
                arr[j+1] = temp ;
            }
        }
    }
}
//binary search
int search(int arr[], int size, int num)
{
    int low = 0 ;
    int high = size-1 ;
    while(low <= high)
    {
        int mid = (low + high)/2 ;
        if(num > arr[mid])
            low = mid + 1 ;
        else if(num < arr[mid])
            high = mid - 1 ;
        else
        {
            return (mid);
            break ;
        }
    }
    return (-1);
}
int count = 0;
void insert(int arr[], int size)
{
    int num;
    for(; count < size; count++)
    {
        printf("\t");
        scanf("%d",&num);
        arr[count]=num;
    }
    sort(arr,size);
}
void delete(int arr[], int pos, int size)
{
    while(pos < size-1)
    {
        arr[pos]=arr[pos+1];
        pos++;
    }
}
void display(int arr[], int size)
{
    if(size!=0)
    {
        printf("\tDisplaying Sorted Array : ");
        for(int i = 0; i < size ; i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n\n");
    }
    else
        printf("\tArray is Empty !!! Please Insert Some Values...\n\n");
}
int main()
{
    int opt, size=0, arr[MAXSIZE];
    do
    {
        int num, pos = -1;
        printf("\t\t   MENU\n\n");
        printf("1 - Insert Elements in Array\n");
        printf("2 - Delete Element from Array\n");
        printf("3 - Search Element in Array\n");
        printf("4 - Display Sorted Array\n");
        printf("5 - Exit from the Program\n");
        printf("\nSelect the Option No. : ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
            {
                if(size == MAXSIZE)
                    printf("\tArray Full !!!\n\n");
                else
                {
                    printf("\tEnter the Number of Elements to be Inserted (MAX -> %d) : ",(MAXSIZE-size));
                    int s;
                    scanf("%d", &s);
                    size += s;
                    if(size <= MAXSIZE)
                    {
                        printf("\tEnter the New Elements of the Array : \n");
                        insert(arr,size);
                    }
                    else if(s > (MAXSIZE-size))
                    {
                        printf("\tInserting greater than MAXSIZE !!! Try Again...\n\n");
                        size-=s;
                    }
                }
                break;
            }
            case 2:
            {
                if( size == 0 )
                {
                    printf("\tArray is Empty !!! Please Insert Some Values...\n\n");
                    break;
                }
                printf("\tEnter the Elements to be Deleted : ");
                scanf("%d",&num);
                pos = search(arr,size,num);
                if(pos != -1)
                {
                    delete(arr,pos,size);
                    printf("\tElement %d Deleted Successfully.\n\n",num);
                    size--;
                }
                else
                    printf("\tElement %d not Found in the Array.\n\n",num);
                
                break;
            }
            case 3:
            {
                if( size == 0 )
                {
                    printf("\tArray is Empty !!! Please Insert Some Values...\n\n");
                    break;
                }
                printf("\tEnter the Elements to be Searched : ");
                scanf("%d",&num);
                pos = search(arr,size,num);
                if(pos != -1)
                {
                    printf("\tElement %d found at index %d position %d IN THE SORTED ARRAY.\n\n",num,pos,pos+1);
                }
                else
                    printf("\tElement %d not Found in the Array.\n\n",num);
                break;
            }
            case 4:
            {
                display(arr,size);
                break;
            }
            case 5:
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
    }while(opt != 5);
    return 0;
}
