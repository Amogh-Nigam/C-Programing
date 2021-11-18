//Application of Stacks - String in Palindrome
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXSIZE 50

struct stack
{
    char a[MAXSIZE];
    int top;
};
void init(struct stack *s)
{
    s->top = -1;
}
void push(struct stack *s, char ch)
{
    if (s->top == MAXSIZE - 1)
    {
        printf("\tStack Overflow !!! -> Increase MAXSIZE\n\n");
        return;
    }
    s->top++;
    s->a[s->top] = ch;
}
char pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("\tStack is Empty !!! Please Insert Some Values...\n\n");
        return 0;
    }
    char ch;
    ch = s->a[s->top];
    s->top--;
    return ch;
}
int check(char arr[], int l)
{
    struct stack s;
    init(&s);
    int i = 0;
    for( ; i < l/2 ; i++ )
        push(&s, arr[i]);
    if(l % 2 != 0)
        i = i + 1;
    while (i < l)
    {
        if( pop(&s) != arr[i] )
            return 0;
        i++;
    }
    if (s.top == -1)
        return 1;
    else
        return 0;
}
int main()
{
    int opt, l = 0, flag;
    char arr[MAXSIZE];
    do
    {
        strcpy(arr,"");
        printf("\t\t   MENU\n\n");
        printf("1 - To Check String in Palindrome using STACKS\n");
        printf("2 - Exit from the Program\n");
        printf("\nSelect the Option No. : ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
            {
                printf("\tEnter the String : \n");
                scanf("%s", arr);
                int i = 0;
                l = strlen(arr);
                while(i < l)
                {
                    arr[i]=tolower(arr[i]);
                    i++;
                }
                flag = check(arr, l);
                if(flag)
                    printf("\tString in Palindrome\n\n");
                else
                    printf("\tString NOT in Palindrome\n\n");
                break;
            }
            case 2:
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
    }while(opt != 2);
    return 0;
}
