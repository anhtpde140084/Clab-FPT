#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
typedef char string[100];
struct QuesType
{
	char kind[3];
	int point;
	string ques;
	string answer;

	//  Multi choice
	int numchoices;
	string *choicelist;
};

QuesType *ReadFile(string fn, int &N)
{
	FILE *f = fopen(fn, "r");
	if (!f)
	{
		printf("Unknow file!");
		exit(0);
	}

	printf("Loading data from %s...\n", fn);
	fscanf(f, "%d\n", &N);
	QuesType *QBank = (QuesType *)malloc((N) * sizeof(QuesType));

	for (int q = 0; q < N; q++)
	{
		QuesType multichoice;
		fscanf(f, "%s %d\n%[^\n]\n", multichoice.kind, &multichoice.point, multichoice.ques);
		// xu ly MultiChoice
		if (strcmp(multichoice.kind, "MC") == 0)
		{
			fscanf(f, "%d\n", &multichoice.numchoices);
			multichoice.choicelist = (string *)malloc((multichoice.numchoices) * sizeof(string));
			for (int i = 0; i < multichoice.numchoices; i++)
			{
				fscanf(f, "%[^\n]\n", multichoice.choicelist[i]);
			}
		}
		fscanf(f, "%[^\n]\n", multichoice.answer);
		QBank[q] = multichoice;
	}
	printf("Read successful!\n");
	fclose(f);
	return QBank;
}

void printQues(QuesType *QBank, int &N, int &userPoint)
{
	string userAnswer;
	char a = 'A';
	printf("Answer: \n");
	int random;
	int n;
again:
	fflush(stdin);
	printf("How many questions would you like (out of 3)? ");
	scanf("%d", &n);
	if (n > 3)
	{
		printf("Sorry, that is too many.\n");
		goto again;
	}
	else if (n < 1)
	{
		printf("That not valid!\n");
		goto again;
	}
	for (int i = 0; i < n; i++)
	{
		srand(time(0));
		int random = rand() % N;

		printf("%s\n%s\n", QBank[random].kind, QBank[random].ques);
		if (strcmp(QBank[random].kind, "MC") == 0)
		{
			for (int j = 0; j < QBank[random].numchoices; j++)
			{
				printf("%c.%s\n", a++, QBank[random].choicelist[j]);
			}
		}

		printf("Your answer: ");
		fflush(stdin);
		gets(userAnswer);

		if (strcmp(userAnswer, QBank[random].answer) == 0)
		{
			printf("Correct answer is %s\n", QBank[random].answer);
			userPoint += QBank[random].point;
		}
		else if (strcmp(userAnswer, "SKIP") == 0)
		{
			printf("You skip!\n");
			userPoint -= QBank[random].point;
			continue;
		}
		else
		{
			printf("Correct answer is %s\n", QBank[random].answer);
			userPoint -= QBank[random].point;
		}
		a = 'A';
		printf("Your point: %d\n", userPoint);
	}
}

int main()
{
	string fname;
	string lname;
	string fn;
	int userPoint;
	int N;
	QuesType *QBank;
	printf("What is your first name ? ");
	fflush(stdin);
	gets(fname);
	printf("What is your last name ? ");
	fflush(stdin);
	gets(lname);
	printf("What file stores your questions? ");
	fflush(stdin);
	gets(fn);
	QBank = ReadFile(fn, N);
	printQues(QBank, N, userPoint);
	printf("%s %s, your game is over!\nYour final score is %d points \nBetter luck next time!", fname, lname, userPoint);
	return 0;
}

