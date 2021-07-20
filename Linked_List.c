#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* link;
};
struct node* head = NULL;
void add()
{
	struct node*temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data: ");
	scanf("%d", &temp->data);
	temp->link = NULL;
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		struct node* ptr;
		ptr = head;
		while (ptr->link != NULL)
		{
			ptr = ptr->link;
		}
		ptr->link = temp;
	}
}
void dlt()
{
	int n;
	printf("Enter the position of data which you want to delete: ");
	scanf("%d", &n);
	if (n == 1)
	{
		struct node* ptr = head;
		head = head->link;
		ptr->link = NULL;
		free(ptr);
	}
	else
	{
		struct node* ptr,*q;
		ptr = head;
		for (int i = 1; i < n-1; i++)
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
	printf("Enter the position where you want to insert: ");
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
		head = temp;
	}
	else
	{
		struct node* q,*p;
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
		struct node* temp=malloc(sizeof(struct node));
		if (head == NULL)
		{
			printf("List is empty\n");
		}
		else
		{
			printf("DATA-->\n");
			temp = head;
			while (temp != NULL)
			{
				printf("%d\n",temp->data);
				temp = temp ->link;
			}
		}
}
void length()
{
	int count = 0;
	struct node* p;
	p = head;
	while (p != NULL)
	{
		printf("%d ", p);
		count++;
		p = p->link;
	}
	printf("Length: %d\n", count);
}
void reverse()
{
	struct node* p, * q = NULL;
	while (head != NULL)
	{
		p = head->link;
		head->link = q;
		q = head;
		head = p;
	}
	head = q;
}
void search()
{
	int n;
	printf("Enter the data you want to search: ");
	scanf("%d", &n);
	struct node* ptr = head;
	int m = 0, count = 0;
	while (ptr != NULL)
	{
		count++;
		if (ptr->data == n)
		{
			printf("Data found at %d\n", count);
			m = 1;
		}
		ptr = ptr->link;
	}
	if (m == 0)
		printf("NO DATA FOUND..!!\n");
}
void main()
{
	printf("-------------------LINKED_LIST---------------------\n");
	printf("1-INSERTION\n2-DELETION\n3-ADD_IN_START/BETWEEN\n4-TRAVERSE\n5-LENGTH\n6-REVERSE\n7-Search\n8-EXIT\n\n");
	int x;
	while (1)
	{
	printf("Enter the operation you want to perform: ");
	scanf("%d", &x);
	
		switch (x)
		{
		case 1: add();
			break;
		case 2: dlt ();
			break;
		case 3: add_between();
			break;
		case 4: traverse();
			break;
		case 5: length();
			break;
		case 6: reverse();
			break;
		case 7:search();
			break;
		case 8: printf("Exiting...........\n");
			exit(1);
		default: printf("CHOOSE FROM THE GIVEN OPTION..!!\n");
			break;
		}
	}
}
