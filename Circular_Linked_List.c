#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* link;
};
struct node* head = NULL;
void add()
{
	struct node* temp = malloc(sizeof(struct node));
	printf("Enter the data: ");
	scanf("%d", &temp->data);
	temp->link = NULL;
	if (head == NULL)
	{
		head=temp;
		head->link = head;
	}
	else
	{
		struct node* ptr;
		ptr = head;
		do 
		{
			ptr = ptr->link;		
		} while (ptr->link != head);
		ptr->link = temp;
		temp->link = head;
	}
}
void dlt()
{
	int n;
	printf("Enter the No. to dlt: ");
	scanf("%d", &n);
	if (head == NULL)
	{
		printf("List is Empty\n");
	}
	else if (n == 1)
	{
		struct node* ptr, * q;
		ptr = head;
		head = head->link;
		q = head;
		ptr->link = NULL;
		do
		{
			q = q->link;
		} while (q->link != ptr);
		q->link = head;
		free(ptr);
	}
	else
	{
		struct node* ptr, * q;
		ptr = head;
		for (int i = 1; i < n - 1; i++)
		{
			ptr = ptr->link;
		}
		q = ptr->link;
		ptr->link = ptr->link->link;
		q->link = NULL;
		free(q);
	}
}
void add_between()
{
	int n;
	printf("Enter the place where you want to insert: ");
	scanf("%d", &n);
	struct node* temp = malloc(sizeof(struct node));
	printf("Enter the data: ");
	scanf("%d", &temp->data);
	temp->link = NULL;
	if (head == NULL)
		printf("Liked List is empty\n");
	else if (n == 1)
	{
		temp->link = head;
		struct node* ptr;
		ptr = head;
		do
		{
			ptr = ptr->link;
		} while (ptr->link != head);
		ptr->link = temp;
		head = temp;
	}
	else
	{
		struct node* q, * p;
		q = head;
		for (int i = 1; i < n - 1; i++)
		{
			q = q->link;
		}
		p = q->link;
		q->link = temp;
		temp->link = p;
	}
}
void traverse()
{
	struct node* temp;
	if (head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		printf("DATA-->\n");
		temp = head;
		do
		{
			printf("%d\n", temp->data);
			temp = temp->link;
		} while (temp != head);
	}
}
void length()
{
	struct node* temp ;
	if (head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		temp = head;
		int count = 0;
		do
		{
			temp = temp->link;
			count++;
		} while (temp != head);
		printf("Length of Circular LInked List: %d\n", count);
	}
}
void search()
{
	struct node* temp;
	int n,m=0,count=1;
	printf("Enter the number to search:");
	scanf("%d", &n);
		temp = head;
		do
		{
			if (temp->data == n)
			{
				printf("Data found at %d\n", count);
				m = 1;
			}
			temp = temp->link;
			count++;
		} while (temp != head);
		if (m == 0)
			printf("NO DATA FOUND..!!");
}
void main()
{
	int x;
	printf("-------------------CIRCULR_LINKED_LIST---------------------\n1-INSERTION\n2-DELETION\n3-ADD_IN_START/BETWEEN\n4-TRAVERSE\n5-LENGTH\n6-SEARCH\n7-EXIT\n\n");
	while (1)
	{
		printf("Enter the operation you want to perform: ");
		scanf("%d", &x);
		switch (x)
		{
		case 1: add();
			break;
		case 2: dlt();
			break;
		case 3:add_between();
			break;
		case 4: traverse();
			break;
		case 5:length();
			break;
		case 6:search();
			break;
		case 7: printf("Exiting...........\n");
			exit(1);
		default: printf("CHOOSE FROM THE GIVEN OPTION..!!\n");
			break;
		}
	}
}