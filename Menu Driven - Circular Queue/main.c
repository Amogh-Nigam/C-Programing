//Menu Driven - Circular Queue Using Array
#include <stdio.h>
#define SIZE 50

struct queue
{
    int a[SIZE];
    int front;
    int rear;
};
void init(struct queue *s)
{
    s->front = 0;
    s->rear = 0;
}
void insert(struct queue *s)
{
    if((s->rear + 1) % SIZE == s->front)
    {
        printf("\tQueue is full !!! \n\n");
        return;
    }
    else
    {
        int x;
        printf("\tEnter number to Insert in Queue : ");
        scanf("%d", &x);
        s->a[s->rear] = x;
        printf("\tValue %d Added Successfully.\n\n", s->a[s->rear]);
        s->rear = (s->rear + 1) % SIZE;
    }
}
void delete(struct queue *s)
{
    if(s->rear == s->front)
    {
        printf("\tQueue is Empty !!! Please Insert Some Values...\n\n");
        return;
    }
    printf("\tDeleted %d Successfully.\n\n", s->a[s->front]);
    s->front = (s->front + 1) % SIZE;
}
void display(struct queue s)
{
    if (s.front == s.rear)
    {
        printf("\tQueue is Empty !!! Please Insert Some Values...\n\n");
        return;
    }
    int i = s.front;
    printf("\tElements in Queue are : \n\n\t\t\t");
    while(i != s.rear)
    {
        printf("%d\n\t\t\t", s.a[i]);
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
int main()
{
    int opt;
    struct queue q;
    init(&q);
    do
    {
        printf("\t\t   MENU\n\n");
        printf("1 - Inserting Element in Queue\n");
        printf("2 - Deleting Element from Queue\n");
        printf("3 - Display Elements of Queue\n");
        printf("4 - Exit from the Program\n");
        printf("\nSelect the Option No. : ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
            {
                insert(&q);
                break;
            }
            case 2:
            {
                delete(&q);
                break;
            }
            case 3:
            {
                display(q);
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
