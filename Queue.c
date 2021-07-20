#include<stdio.h>
#define MAX 3
int queue[MAX];
int front = 0;
int rare = -1;
void enque()
{
	if (rare < MAX-1 )
	{
		rare++;
		printf("Enter the Number:");
		scanf("%d", &queue[rare]);
	}
	else
		printf("OVERFLOW\n");
}
int deque()
{
	if (rare == -1)
		printf("Underflow\n");
	else
	{
		printf("Number Deleted\n");
		for (int i = 0; i < rare; i++)
		{
			queue[i] = queue[i + 1];
		}
		rare--;
	}
}
void display()
{
	printf("Queue List:\n");
	if (rare == -1)
		printf("Underflow\n");
	else
	{
		for (int i = 0; i <= rare; i++)
		{
			printf("%d\n", queue[i]);
		}
	}
}
void main()
{
	printf("----------------------QUEUE APPLICATION-------------------\n");
	printf("Operation available to perform:\nEnqueue-1\nDequeue-2\nGetRare-3\nGetFront-4\nDisplay-5\nExit-6\n");
	int ch;
	while (1)
	{	
		printf("Choose from the given option: ");
		scanf("%d", &ch);
		switch (ch) 
		{
		case 1:enque();
			break;
		case 2: deque();
			break;
		case 3:
			printf("GetRare=%d\n", queue[rare]);
			break;
		case 4:
			printf("GetFront=%d\n", queue[front]);
			break;
		case 5:
			display();
			break;
		case 6:
			printf("exiting......");
			exit(0);
		}
	}
}