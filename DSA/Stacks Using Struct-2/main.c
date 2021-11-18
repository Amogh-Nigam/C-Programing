//Application of Stacks - Parenthesis Balance
#include <stdio.h>
#include <string.h>
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
void push(struct stack *s, int ch)
{
    s->top++;
    s->a[s->top] = ch;
}
int pop(struct stack *s)
{
    if (s->top == -1)
        return 0;
    int ch;
    ch = s->a[s->top];
    s->top--;
    return ch;
}
int MatchingPair(char c1, char c2)
{
    if (c1 == '(' && c2 == ')')
        return 1;
    else if (c1 == '{' && c2 == '}')
        return 1;
    else if (c1 == '[' && c2 == ']')
        return 1;
    else
        return 0;
}
int check(char arr[])
{
    struct stack s;
    init(&s);
    int i = 0;
    while(arr[i])
    {
        if (arr[i] == '{' || arr[i] == '(' || arr[i] == '[')
            push(&s, arr[i]);
        else if (arr[i] == '}' || arr[i] == ')' || arr[i] == ']')
        {
            if (s.top == -1)
                return 0;
            else if (!MatchingPair(pop(&s), arr[i]))
                return 0;
        }
        else
        {
            printf("\tInvalid Input !!!\n\tPlease Try Again...\n\n");
            return 2;
            break;
        }
        i++;
    }
    if (s.top == -1)
        return 1;
    else
        return 0;
}
int main()
{
    int opt;
    char arr[MAXSIZE];
    do
    {
        strcpy(arr,"");
        printf("\t\t   MENU\n\n");
        printf("1 - To Check Balance of Parenthesis\n");
        printf("2 - Exit from the Program\n");
        printf("\nSelect the Option No. : ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
            {
                printf("\tEnter the String of Parenthesis : \n");
                scanf("%s", arr);                      //INPUT IS STRICTLY PARENTHESIS
                int flag = check(arr);
                if (flag == 1)
                    printf("\tParenthesis are Balanced\n\n");
                else if (flag == 0)
                    printf("\tParenthesis are NOT Balanced\n\n");
                break;
            }
            case 2:
            {
                printf("\tExit Successful.\n");
                break;
            }
            default:
            {
                printf("\tInvalid Option !!!\n\tPlease Try Again...\n\n");
                break;
            }
        }
    }while(opt != 2);
    return 0;
}
