#include<stdio.h>
#include<string.h>
char n, op, a, pw[10], id[10], str[10], jhn[6], xy[1000];
void admin()
{
	printf("Do you want to access the student details  //  Book details\n(Write 'S' for student details or 'B' for Book details: ");
	scanf(" %c", &a);
	if (a == 'B')
	{
		FILE* fp1;
		fp1 = fopen("book.txt", "r");
		if (fp1 == NULL)
			printf("File cannot be found\n");
		printf("List of the books: \n");
		while (!feof(fp1))
		{
			fscanf(fp1, " %[^\n]s", xy);
			printf("%s\n", xy);
		}
		fclose(fp1);
		printf("Write 'B' to go back or 'M' to go to the main menu: ");
		scanf(" %c", &op);
		if (op == 'B')
			admin();
		else if (op == 'M')
			main();
	}
	else if (a == 'S')
	{
		FILE* fp2;
		fp2 = fopen("student.txt", "r+");
		if (fp2 == NULL)
			printf("File cann't be found");
		printf("Here are the details of student: \n");
		while (!feof(fp2))
		{
			fscanf(fp2, " %[^\n]s", xy);
			printf("%s\n", xy);
		}
		printf("\n\nWrite 'ADD' to add a new Student details: ");
		scanf(" %s", &str);
		if (strcmp(str, "ADD") == 0)
		{
			char i[10], p[6];
			printf("User ID: ");
			scanf(" %s", &i);
			printf("Password: ");
			scanf(" %s", &p);
			fprintf(fp2, "\nUser ID:%s || Password:%s", i, p);
		}
		fclose(fp2);
		printf("Write 'B' to go back or 'M' to go to the main menu: ");
		scanf(" %c", &op);
		if (op == 'B')
			admin();
		else if (op == 'M')
			main();
	}
}
void student()
{
	printf("Write 'B' to borrow a book  //  'R' to return a book\n\n\n\n");
	printf("UNDER CONSTRUCTION\n\n");
	printf("Write 'B' to go back or 'M' to go to the main menu: ");
	scanf(" %c", &op);
	if (op == 'B')
		student();
	else if (op == 'M')
		main();
}
int main()
{
	printf("\nLogin using Librarian Credintials // Student Credential\nWrite L OR S\n(L=Librarian | S=Student): ");
	scanf(" %c", &n);
	if (n == 'L')
	{
		printf("Enter the Login ID & Password\n");
		printf("Login ID: ");
		scanf(" %s", &id);
		printf("Password: ");
		scanf(" %s", &pw);
		if (strcmp(id, "jhucamp") == 0 && strcmp(pw,"zee4567")==0)
		{
			admin();
		}
		else
			printf("Wrong User ID or Password");
	}
	else if (n == 'S')
	{
		printf("Enter the Login ID & Password\n");
		printf("Login ID: ");
		scanf(" %s", &id);
		printf("Password: ");
		scanf(" %s", &pw);
		FILE* fp;
		fp = fopen("student.txt", "r+");
		if (fp == NULL)
			printf("File cannot be found\n");
		while (!feof(fp))
		{
			fseek(fp, 10, SEEK_CUR);
			fscanf(fp, " %s", str);
			fseek(fp, 13, SEEK_CUR);
			fscanf(fp, " %s", jhn);
			if (strcmp(str, id) == 0 && strcmp(jhn,pw)==0)
			{
				student();
			}
		}
		fclose(fp);
	}
	else
		printf("Please choose from the given option..!!");
	return 0;
}