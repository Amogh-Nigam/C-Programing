//Linked List with Headnode
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *next;
};
struct headnode
{
    struct node *start;
    struct node *end;
    int count;
};
struct headnode h;

void display(void)
{
    struct node *ptr = h.start;
    if (!ptr)
    {
        printf("\tList is Empty !!!\n\n");
        return;
    }
    printf("\nList elements are : ");
    while (ptr)
    {
        printf("%d ", ptr->value);
        ptr = ptr->next;
    }
    printf("\n\n");
}

void Insert_Front(void)
{
    int x;
    printf("\nEnter the Element to be Inserted : ");
    scanf("%d", &x);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->value = x;
    ptr->next = NULL;
    printf("\tElement has been Inserted\n\n");
    if (!h.start)
    {
        h.start = ptr;
        h.end = ptr;
        h.count = 1;
        return;
    }
    ptr->next = h.start;
    h.start = ptr;
    h.count++;
}

void Insert_End(void)
{
    int x;
    printf("\nEnter the Element to be Inserted : ");
    scanf("%d", &x);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->value = x;
    ptr->next = NULL;
    printf("\tElement has been Inserted\n\n");
    if (!h.start)
    {
        h.start = ptr;
        h.end = ptr;
        h.count = 1;
        return;
    }
    struct node *q = h.start;
    while (q->next)
        q = q->next;
    q->next = ptr;
    h.end = ptr;
    h.count++;
}

void Search_Node(void)
{
    int x;
    struct node *ptr = h.start;
    if (!ptr)
    {
        printf("\tList is Empty !!!\n\n");
        return;
    }
    printf("\nEnter the Element to be Searched : ");
    scanf("%d", &x);
    while (ptr)
    {
        if (ptr->value == x)
        {
            printf("Element Found in List !!!\n\n");
            return;
        }
        ptr = ptr->next;
    }
    printf("\tElement not Found !!!\n\n");
}

void Delete_Node(void)
{
    int x;
    struct node *ptr = h.start;
    struct node *q = NULL;
    if (!ptr)
    {
        printf("\tList is Empty !!!\n\n");
        return;
    }
    printf("\nEnter the Element to be Deleted : ");
    scanf("%d", &x);
    while(ptr && ptr->value!=x)
    {
        q = ptr;
        ptr = ptr->next;
    }
    if(!ptr)
    {
        printf("\tElement not Present in List !!!\n\n");
        return;
    }
    if(!q)
        h.start = ptr->next;
    else
        q->next = ptr->next;
    if(h.end == ptr)
        h.end = q;
    free(ptr);
    printf("Element Deleted from the List !!!\n\n");
    h.count--;
}

void Count_Node(void)
{
    printf("Number of Nodes : %d\n\n", h.count);
}

int main()
{
    h.start = NULL;
    h.end = NULL;
    h.count = 0;
    int choice;
    while (1)
    {
        printf("\t   MENU Head Node\n\n");
        printf("1 - Display Linked List\n");
        printf("2 - Insert at Starting\n");
        printf("3 - Insert at End\n");
        printf("4 - Search in Linked List\n");
        printf("5 - Deleting of a Node\n");
        printf("6 - Display Count of Node\n");
        printf("7 - Exit from the Program\n");
        printf("\nSelect the Option No. : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                display();
                break;
            case 2:
                Insert_Front();
                break;
            case 3:
                Insert_End();
                break;
            case 4:
                Search_Node();
                break;
            case 5:
                Delete_Node();
                break;
            case 6:
                Count_Node();
                break;
            case 7:
                printf("\tExit Successful.\n");
                exit(0);
            default:
                printf("\tInvalid Option!!!\n\tPlease Try Again...\n\n");
                continue;
        }
    }
    return 0;
}

