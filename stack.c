#include<stdio.h>
#define MAX 10
int Stack[MAX];
int Top = 0;
void Push()
{
    int number;
    if (Top == MAX)
    {
        printf("OVERFLOW\n");
    }
    else
    {
        printf("Number you want to insert in Stack: ");
        scanf("%d", &number);
        Stack[Top] = number;
        Top++;
    }
}
void Pop()
{
    if (Top == 0)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        Top--;
        printf("Number deleted from Stack\n");
    }
}
void Display()
{
    int i;
    if (Top == 0)
        printf("UNDERFLOW\n");
    else
    {
        printf("Stack Element are :\n");
        for (i = Top-1; i >=0; i--)
        {
            printf(" %d\n", Stack[i]);
        }
    }
}
void main() 
{
    printf("Stack Operation\n\nChoose From te given option:\n1. Push \n2. Pop\n3. Display \n4. Exit\n");
    int ch;
    while (1)
    {
        printf("Your option:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: Push();
            break;
        case 2: Pop();
            break;
        case 3:Display();
            break;
        case 4:
            exit(0);
        default:
            printf("Error\n");
        }
    }
}