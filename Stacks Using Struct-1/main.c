//Menu Driven Stacks - Basics
#include <stdio.h>
#define MAXSIZE 500

struct stack
{
    int a[MAXSIZE];
    int top;
};
void init(struct stack *s)
{
    s->top = -1;
}
void push(struct stack *s)
{
    if (s->top == MAXSIZE - 1)
    {
        printf("\tStack Overflow !!!\n\n");
        return;
    }
    s->top++;
    int x;
    printf("\tEnter number to Push in Stack : ");
    scanf("%d", &x);
    s->a[s->top] = x;
    printf("\tValue %d Added Successfully.\n\n", s->a[s->top]);
}
void pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("\tStack is Empty !!! Please Insert Some Values...\n\n");
        return;
    }
    printf("\tDeleted %d Successfully.\n\n", s->a[s->top]);
    s->top--;
}
void display(struct stack s)
{
    if (s.top == -1)
    {
        printf("\tStack is Empty !!! Please Insert Some Values...\n\n");
        return;
    }
    printf("\tElements in Stacks are : \n\n\t\t\t");
    for (int i = s.top; i >= 0; i--)
        printf("%d\n\t\t\t", s.a[i]);
    printf("\n");
}
int main()
{
    int opt;
    struct stack s;
    init(&s);
    do
    {
        printf("\t\t   MENU\n\n");
        printf("1 - Inserting Element in Stack (PUSH)\n");
        printf("2 - Deleting Element from Stack (POP)\n");
        printf("3 - Display Elements of Stack\n");
        printf("4 - Exit from the Program\n");
        printf("\nSelect the Option No. : ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
            {
                push(&s);
                break;
            }
            case 2:
            {
                pop(&s);
                break;
            }
            case 3:
            {
                display(s);
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
    }while(opt != 4);
    return 0;
}

