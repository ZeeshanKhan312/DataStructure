#include<stdio.h>
#define MAX 5
int size = 0;
int queue[MAX];
int front = 0;
int rare = -1;
int num;
void enque()
{
	if (size < MAX )
	{
		printf("Enter the Number:");
		scanf("%d", &num);
		rare = (rare + 1) % MAX;
		queue[rare] = num;
		size++;
	}
	else
		printf("OVERFLOW\n");
}
int deque()
{
	printf("Number Deleted\n");
	front = (front + 1) % MAX;
	size--;
}
void display()
{
	int i;
	printf("Queue List:\n");
	if (front <= rare)
	{
		for (i = front; i <= rare; i++)
		{
			printf("%d\n", queue[i]);
		}
	}
	else 
	{
		for (i = front; i < MAX ; i++)
		{
			printf("%d\n", queue[i]);
		}
		for (i = 0; i <= rare; i++)
		{
			printf("%d\n", queue[i]);
		}
	}
}
void main()
{
	printf("----------------------C_QUEUE APPLICATION-------------------\n");
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