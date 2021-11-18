//Merging Sorted Array
#include <stdio.h>

int main()
{
    int s1,s2,s3,i=0,j=0,k=0;
    printf("Enter the size of Array 1 : ");
    scanf("%d",&s1);
    printf("Enter the size of Array 2 : ");
    scanf("%d",&s2);
    s3=s1+s2;
    printf("\nEnter the sorted array elements (Both Ascending Arrays)\nArray 1 :\n");
    int a[s1],b[s2],c[s3];
    for(int i=0;i<s1;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Array 2 :\n");
    for(int i=0;i<s2;i++)
    {
        scanf("%d",&b[i]);
    }
    while(i<s1 && j<s2)
    {
        if(a[i] < b[j])
            c[k++]=a[i++];
        else
            c[k++]=b[j++];
    }
    while(i<s1)
    {
        c[k++]=a[i++];
    }
    while(j<s2)
    {
        c[k++]=b[j++];
    }
    printf("After Merging and Sorting...\n");
    for(int i=0 ; i<s3 ; i++)
    {
        printf(" %d ",c[i]);
    }
    printf("\n");
    return 0;
}
