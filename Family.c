#include <stdio.h>
#include<string.h>
#pragma pack(1)
typedef struct family family;
struct family {
	char* name;
	char* hobby;
	char* work;
	int age;
};
void main()
{
	family s[20];
	s[0].name = "Zeeshan Khan";
	s[0].age = 19;
	s[0].hobby = "It's Confidential";
	s[0].work = "Currently pursuing Engineering";
	s[1].name = "Raiyaan Khan";
	s[1].age = 9;
	s[1].hobby = "Playing Video Games";
	s[1].work = "Studying in Grade 4th";
	s[2].name = "Fiza Khan";
	s[2].age = 17;
	s[2].hobby = "Using Snapchat filters";
	s[2].work = "Has passed 12th";
	s[3].name = "Daniyal Khan";
	s[3].age = 8;
	s[3].hobby = "Talking about Spider Man or other super heros";
	s[3].work = "Studing in 3rd Grade";
	s[4].name = "Aleeza Khan";
	s[4].age = 4;
	s[4].hobby = "Singing Nursery Rhymes";
	s[4].work = "Does study from home";
	s[5].name = "Nasima Khanam";
	s[5].age = 40;
	s[5].hobby = "Cooking Delicious Food";
	s[5].work = "House wife";
	s[6].name = "Kalimur Rahman";
	s[6].age = 50;
	s[6].hobby = "News Dekhna";
	s[6].work = "Scientific officer";
	s[7].name = "Shahid Khan";
	s[7].age = 38;
	s[7].hobby = "Playing Guitaar";
	s[7].work = "IT Engineer";
	s[8].name = "Heena Khan";
	s[8].age = 34;
	s[8].work = "House wife";
	s[8].hobby = "I'm not much sure";
	s[9].name = "Junaid Khan";
	s[9].age = 32;
	s[9].hobby = "acha khana khaana aur dusron ko khilaana";
	s[9].work = "IT Engineer";
	s[10].name = "Sumbul Nisha";
	s[10].age = 28;
	s[10].hobby = "I'm not much sure";
	s[10].work = "House wife";
	s[11].name = "Sajid Khan";
	s[11].age = 30;
	s[11].hobby = "Pahle shooping karna tha abhi ka pata nahi";
	s[11].work = "Software Engineer";
	s[12].name = "Sabrin Khan";
	s[12].age = 23;
	s[12].hobby = "I'm not much sure";
	s[12].work = "House wife";
	s[13].name = "Farzana Khan";
	s[13].age = 34;
	s[13].hobby = "Bhabhi ji ghar par hai  dekhna";
	s[13].work = "Ammi Abbu  ke dawai ka khayal rakhna";
	s[14].name = "Safiulla Khan";
	s[14].age = 72; 
	s[14].hobby = "Puri Duniya ka tension lena";
	s[14].work = "Retired BSF officer";
	s[15].name = "Ayesha Khatoon";
	s[15].age = 62;
	s[15].hobby = "Cooking Delicious Food";
	s[15].work = "House wife";
	char b[20];
	printf("Enter the Person name you want to know about: ");
	scanf(" %[^\n]s", b);
	printf("\n");
	int i;
	for (i = 0; i <= 15; i++)
	{
		if (strcmp(b, s[i].name) == 0)
		{
			printf("Information available about the Person: \n");
			printf("Name= %s\nAge= %d\nHobby= %s\nWork=%s\n", s[i].name, s[i].age, s[i].hobby,s[i].work);
			if (i == 0)
				system("17456.jpg");
			else if (i == 1)
				system("172610.jpg");
			else if (i == 2)
				system("IMG_4538.JPG");
			else if (i == 3)
				system("IMG_4435.JPG");
			else if (i == 4)
				system("IMG_5308.jpg");
			else if (i == 5)
				system("IMG_201905.jpg");
			else if (i == 6)
				system("4653465.jpg");
			else if (i == 7)
				system("IMG_5300.jpg");
			else if (i == 8)
				system("DU5A5332.JPG");
			else if (i == 9)
				system("3326568796.jpg");
			else if (i == 10)
				system("DU5A5481.JPG");
			else if (i == 11)
				system("200484553.jpg");
			else if (i == 12)
				system("DU5A5247.JPG");
			else if (i == 13)
				system("IMG_5301.jpg");
			else if (i == 14)
				system("IMG_5298.jpg");
			else if (i == 15)
				system("IMG_5299.jpg");
			break;
		} 
		else if (i == 15)
		{
			printf("No Record found\n");
			break;
		}
	}
	printf("\n");
	char ch;
	printf("Do you Want to know about someone else if yes write 'y': ");
	scanf(" %c", &ch);
	printf("\n");
	if (ch == 'y')
	{
		main();
	}
}
