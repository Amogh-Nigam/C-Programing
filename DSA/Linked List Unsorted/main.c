//Linked List Unsorted 
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

void Insert_Front(void)
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
    ptr->next = start;
    start = ptr;
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
    if (!start)
    {
        start = ptr;
        return;
    }
    struct node *q = start;
    while (q->next != NULL)
        q = q->next;
    q->next = ptr;
}

void Insert_Position(void)
{
    int x, pos;
    printf("\nEnter the Element after which New Element to be Inserted : ");
    scanf("%d", &pos);
    printf("Enter the New Element to be Inserted : ");
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
    struct node *q = start;
    while (q->next != NULL && q->value != pos)
        q = q->next;
    ptr->next = q->next;
    q->next = ptr;
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
    while (ptr && ptr->value != x)
    {
        q = ptr;
        ptr = ptr->next;
    }
    if (!ptr)
    {
        printf("\tElement not Present in List !!!\n\n");
        return;
    }
    else
        printf("Element Deleted from the List !!!\n\n");
    q->next = ptr->next;
    free(ptr);
}

int main()
{
    int opt;
    while (1)
    {
        printf("\t\t   MENU\n\n");
        printf("1 - Display Linked List\n");
        printf("2 - Insert at Starting\n");
        printf("3 - Insert at End\n");
        printf("4 - Insert after given Node\n");
        printf("5 - Search in Linked List\n");
        printf("6 - Deleting of a Node\n");
        printf("7 - Exit from the Program\n");
        printf("\nSelect the Option No. : ");
        scanf("%d", &opt);
        switch (opt)
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
                Insert_Position();
                break;
            case 5:
                Search_Node();
                break;
            case 6:
                Delete_Node();
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

