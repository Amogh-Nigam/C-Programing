//Application of Stacks - Postfix Exp Evaluation
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define size 100

struct postfix
{
    float arr[size];
    int top;
};
float compute(int op1, int op2, char ch)
{
    float result = 0;
    switch(ch)
    {
        case '+': result = op1+op2;
                  break;
        case '-': result = op1-op2;
                  break;
        case '*': result = op1*op2;
                  break;
        case '/': result = op2/op1;
                  break;
    }
    return (result);
}
float value(char ch)
{
//    int random = rand()%10;
//    printf("Random number for %c is %d\n",ch,random);
//    return random;
    switch(ch)
    {
        case 'a': return (5);
        case 'b': return (4);
        case 'c': return (4);
        case 'd': return (5);
        case 'e': return (2);
        case 'f': return (3);
        case 'g': return (5);
        case 'h': return (1);
        case 'i': return (4);
        case 'j': return (9);
        case 'k': return (1);
        case 'l': return (5);
        case 'm': return (4);
        case 'n': return (2);
        case 'o': return (5);
        case 'p': return (9);
        case 'q': return (8);
        case 'r': return (7);
        case 's': return (3);
        case 't': return (1);
        case 'u': return (7);
        case 'v': return (1);
        case 'w': return (3);
        case 'x': return (5);
        case 'y': return (4);
        case 'z': return (7);
    }
    return 0;
}
void init(struct postfix *s)
{
    s->top = -1;
}
void push(struct postfix *s, float val)
{
    if (s->top == size-1)
        printf("\nStack is Full !!!\n");
    else
    {
        s->top = s->top + 1;
        s->arr[s->top] = val;
    }
}
float pop(struct postfix *s)
{
    if (s->top == -1)
    {
        return -1;
    }
    else
    {
        float x = s->arr[s->top];
        s->top = s->top - 1;
        return x;
    }
}
int operand(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return 1;
    return 0;
}
int operator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
        return 1;
    return 0;
}
int main()
{
    struct postfix s;
    init(&s);
    char exp[size];
    printf("Enter postfix expression : ");
    scanf("%s", exp);
    int i = 0;
    float res;
    while (exp[i] != '\0')
    {
        if (operand(exp[i]))
        {
            if (i == strlen(exp) - 1)
            {
                printf("Invalid Postfix Expression.\n");
                return 0;
            }
            else
                push(&s, value(exp[i]));
        }
        else if (operator(exp[i]))
        {
            if (i <= 1)
            {
                printf("The Operator (%c) can't be present at %d index.\n", exp[i], i);
                printf("Hence, this expression cannot be evaluated.\n");
                return 0;
            }
            else if (s.top >= 1)
            {
                float op1 = pop(&s);
                float op2 = pop(&s);
                res = compute(op2,op1,exp[i]);
                push(&s, res);
            }
            else
            {
                printf("Invalid postfix expression as it has EXCESS operators.\n");
                return 0;
            }
        }
        else
        {
            printf("This expression contains irrelevant characters for a postfix expression.\n");
            return 0;
        }
        i++;
    }
    res = pop(&s);
    if (s.top == -1 && exp[i] == '\0')
        printf("Final answer is %f\n", res);
    else
        printf("Invalid postfix expression as it has EXCESS operands.\n");
    return 0;
}
//Use of stacks exp like a,b,c are passed to stack then if a operator comes then first two letters are pop out and operation is done as stackBelowTop (operator +,-,/,*) stackTop
