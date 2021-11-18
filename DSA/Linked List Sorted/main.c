//Linked List Sorted
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *next;
};
struct node *start = NULL;
void display(void)
{
    struct node *ptr = start;
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

void Insert_Sort(void)
{
    int x;
    printf("\nEnter the Element to be Inserted : ");
    scanf("%d", &x);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->value = x;
    ptr->next = NULL;
    printf("\tElement has been Inserted\n\n");
    if (!start)
    {
        start = ptr;
        return;
    }
    if (start->value >= x)
    {
        ptr->next = start;
        start = ptr;
        return;
    }
    if (start->value < x && start->next == NULL)
    {
        start->next = ptr;
        return;
    }
    struct node *p = start;
    struct node *q = NULL;
    while (p && p->value < x)
    {
        q = p;
        p = p->next;
    }
    if (!p)
    {
        q->next = ptr;
        return;
    }
    q->next = ptr;
    ptr->next = p;
}

void Search_Node(void)
{
    int x;
    struct node *ptr = start;
    if (!ptr)
    {
        printf("\tList is Empty !!!\n\n");
        return;
    }
    printf("\nEnter the Element to be Searched : ");
    scanf("%d", &x);
    while (ptr)
    {
        if (ptr->value > x)
            break;
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
    struct node *ptr = start;
    struct node *q = NULL;
    if (!ptr)
    {
        printf("\tList is Empty !!!\n\n");
        return;
    }
    printf("\nEnter the Element to be Deleted : ");
    scanf("%d", &x);
    if (start->value == x)
    {
        start = start->next;
        free(ptr);
    }
    while (ptr && ptr->value < x)
    {
        q = ptr;
        ptr = ptr->next;
    }
    if (!ptr)
    {
        printf("\tElement not Present in List !!!\n\n");
        return;
    }
    if(ptr->value > x)
    {
        printf("\tElement not Present in List !!!\n\n");
        return;
    }
    q->next = ptr->next;
    printf("Element Deleted from the List !!!\n\n");
    free(ptr);
}

int main()
{
    int opt;
    while (1)
    {
        printf("\t\t   MENU\n\n");
        printf("1 - Display Linked List\n");
        printf("2 - Insert in Sorted List\n");
        printf("3 - Search in Linked List\n");
        printf("4 - Deleting of a Node\n");
        printf("5 - Exit from the Program\n");
        printf("\nSelect the Option No. : ");
        scanf("%d", &opt);
        switch (opt)
        {
            case 1:
                display();
                break;
            case 2:
                Insert_Sort();
                break;
            case 3:
                Search_Node();
                break;
            case 4:
                Delete_Node();
                break;
            case 5:
                printf("\tExit Successful.\n");
                exit(0);
            default:
                printf("\tInvalid Option!!!\n\tPlease Try Again...\n\n");
                continue;
        }
    }
    return 0;
}

