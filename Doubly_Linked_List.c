#include<stdio.h>
#include<stdlib.h>
struct node {
	struct node *prev;
	int data;
	struct node* next;
};
struct node* head = NULL;
void add()
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the Data: ");
	scanf("%d", &temp->data);
	temp->prev = NULL;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
	}
	else 
	{
		struct node* ptr;
		ptr = head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
		temp->prev = ptr;
	}
}
void dlt()
{
	int n;
	printf("Enter the position of data to delete:");
	scanf("%d", &n);
	struct node* p, * q;
	if (n == 1)
	{
		p = head;
		head = head->next;
		head->prev = NULL;
		p->next = NULL;
		free(p);
	}
	else
	{
		struct node* ptr;
		p = head;
		for (int i = 1; i < n - 1; i++)
		{
			p = p->next;
		}
		ptr = p->next;
		q = p->next->next;
		if (q == NULL)
		{
			p->next = q;
		}
		else
		{
			p->next = q;
			q->prev = p;
		}
		ptr->next = NULL;
		ptr->prev = NULL;
		free(ptr);
	}
}
void add_between()
{
	int n;
	printf("Enter the position of data to add:");
	scanf("%d", &n);
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the Data: ");
	scanf("%d", &temp->data);
	temp->prev = NULL;
	temp->next = NULL;
	if (n == 1)
	{
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	else
	{
		struct node* p, * q;
		p = head;
		for (int i = 1; i < n - 1; i++)
		{
			p = p->next;
		}
		q = p->next;
		p->next = temp;
		q->prev = temp;
		temp->next = q;
		temp->prev = p;
	}
}
void traverse()
{
	if (head == NULL)
		printf("Linked List is empty\n");
	else
	{
		struct node* ptr = head;
		printf("DATA-->\n");
		while (ptr != NULL)
		{
			printf("%d\n", ptr->data);
			ptr = ptr->next;
		}
	}
}
void length()
{
	struct node* ptr = head;
	int count = 0;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;	
	}
	printf("Length of Doubly Linked List: %d\n", count);
}
void reverse()
{
	struct node* ptr = head;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	printf("DATA after reversing-->\n");
	while (ptr != NULL)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->prev;
	}
}
void search()
{
	int n;
	printf("Enter the Data to search: ");
	scanf("%d", &n);
	struct node* ptr;
	ptr = head;
	int count = 0,m=0;
	while (ptr != NULL)
	{
		count++;
		if (ptr->data == n)
		{
			printf("Data fount at %d  line\n",count);
			m++;
		}
		ptr = ptr->next;
	}
	if (m == 0)
		printf("NO DATA FOUND..!!\n");
}
void main()
{
	printf("----------------DOUBLY LINKED LIST---------------\n");
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
		case 2: dlt();
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