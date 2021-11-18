//Application of Stacks - Infix To Postfix
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 500
// size of infix exp

struct stack
{
    char arr[size];
    int top;
};
void init(struct stack *s)
{
    s->top = -1;
}
int operand(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return 1;
    return 0;
}
int operator(char ch)
{
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '%' || ch == '^' || ch == '(')
        return 1;
    return 0;
}
int operator_only(char ch)
{
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '^' || ch == '%')
        return 1;
    return 0;
}
//Function to check the IN-STACKS PRIORITY
int isp(char ch)
{
    switch(ch)
    {
        case '+':
        case '-': return (1);
        case '*':
        case '/':
        case '%': return (2);
        case '(': return (0);
        case '^': return (3);
        default : break;
    }
    return 0;
}
//Function to check the IN-COMING PRIORITY
int icp(char ch)
{
    switch(ch)
    {
        case '+':
        case '-': return (1);
        case '*':
        case '/':
        case '%': return (2);
        case '(': return (5);
        case '^': return (4);
        default : break;
    }
    return 0;
}
void push (struct stack *s, char ch)
{
    if (s->top == size-1)
        printf("\nStack is Full !!!\n");
    else
    {
        s->top = s->top + 1;
        s->arr[s->top] = ch;
    }
}
char pop (struct stack *s)
{
    char ch = s->arr[s->top];
    s->top = s->top - 1;
    return ch;
}
int main()
{
    /*
    ACCEPTED LETTERS : A to Z and a to z
    ACCEPTED OPERATORS : +, -, *, /, %, ^
    SAMPLE INPUT: (a-b)*(c^d-f)+(g/h)-i%j$
    NOTE : INPUT CHARACTERS MUST BE ENDED WITH '$'
    */
    char exp[size], postfix[size];
    printf("Enter your infix expression ( ENDING WITH '$' SIGN ) : ");
    scanf("%s", exp);
    unsigned long int l = strlen(exp);
    if (exp[l-1] != '$')
    {
        printf("Invalid Postfix Expression it doesn't contains $ character IN THE END.\n");
        return 0;
    }
    struct stack s;
    init(&s);
    int flag = 0;
    for(int i = 0; i != '$'; i++ )
    {
        if (exp[i] == '(')
        {
            push(&s, exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (s.top == -1)
            {
                flag = 1;
                break;
            }
            else
                s.top = s.top - 1;
        }
    }
    if(flag == 1 || s.top != -1)
    {
        printf("Invalid Infix Expression Parenthesis Not Balanced\n");
        exit(0);
    }
    init(&s);
    push(&s, '$');
    int i = 0, j = 0, oprand = 0, oprator = 0;
    //Converting the Infix expression into Postfix Expression WITH ERROR HANDLING
    while (exp[i] != '$')
    {
        if (operand(exp[i]))
        {
            if (operand(exp[i+1]))
            {
                printf("Invalid Infix Expression operator missing after \"%c\" at index %d\n", exp[i], i+1);
            }
            oprand++;
            postfix[j] = exp[i];
            j++;
        }
        else if (exp[i] == ')')
        {
            while (s.arr[s.top] != '(' && s.top != -1)
            {
                postfix[j] = pop(&s);
                j++;
            }
            if( s.arr[s.top] == '(' )
                pop(&s);
        }
        else if (operator(exp[i]))
        {
            if (operator_only(exp[i]))
            {
                if (operator_only(exp[i+1]) || i == 0 || i == l - 1)
                {
                    printf("Invalid Infix Expression operator (%c) should not be at index %d\n", exp[i], i+1);
                    exit(0);
                }
                oprator++;
            }
            while (isp(s.arr[s.top]) >= icp(exp[i]))
            {
                postfix[j++] = pop(&s);
            }
            push(&s, exp[i]);
        }
        else
        {
            printf("Invalid Infix Expression as it contains Miscellaneous Characters --> (%c)\n",exp[i]);
            exit(0);
        }
        i++;
    }
    if( oprand != oprator + 1 )
    {
        if( oprand > oprator + 1 )
        {
            printf("Invalid Infix Expressionas as it has EXCESS operands\n");
            exit(0);
        }
        else
        {
            printf("Invalid Infix Expressionas as it has EXCESS operators\n");
            exit(0);
        }
    }
    while (s.top != -1)
    {
        postfix[j] = pop(&s);
        j++;
    }
    postfix[j] = '\0';
    printf("Postfix Expression of the input is : %s\n", postfix);
    exit(0);
}

