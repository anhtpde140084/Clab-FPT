#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//source: 

FILE *fin;
typedef char string[100];
//struct
typedef struct
{
    char kind[3];
    int point;
    string ques;
    string answer;
    //  Multi choice
    int numchoices;
    string *choicelist;
} question;

// read file
question *readfile(string fn, int &N)
{
    fin = fopen(fn, "r");
    if (fn == NULL)
    {
        printf("Error!! Can not found this file Name ");
        getch();
        return 0;
    }
    fscanf(fin, "%d\n", &N);
    question *cauhoi = (question *)malloc((N) * sizeof(question));
    for (int i = 0; i < N; i++)
    {
        question p;
        fscanf(fin, "%s %d\n%[^\n]\n", p.kind, &p.point, p.ques);
        if (strcmp(p.kind, "MC") == 0)
        {
            fscanf(fin, "%d\n", &p.numchoices);
            p.choicelist = (string *)malloc((p.numchoices) * sizeof(string));
            for (int i = 0; i < p.numchoices; i++)
            {
                fscanf(fin, "%[^\n]\n", p.choicelist[i]);
            }
        }
        fscanf(fin, "%[^\n]\n", p.answer);
        cauhoi[i] = p;
    }
    fclose(fin);
    return cauhoi;
}
// in danh sach cau hoi
void printOut(question *cauhoi, int &N, int &cout)
{
    string choice;
    question p;
    char a = 'A';
    int random;
    int n;
check: // khai bao goto buoc nhay
    fflush(stdin);
    printf("How many questions would you like (out of 3)? "); //*
    scanf("%d", &n);                                          //*
    if (n > 3)
    {
        printf("Sorry, that is too many.\n");
        goto check; // nhay ve *
    }
    else if (n < 1)
    {
        printf("That not valid!\n");
        goto check; // nhay ve *
    }
    for (int i = 0; i < n; i++)
    {
        srand(time(0));
        int random = rand() % N;
        printf("%s\n%s\n", cauhoi[random].kind, cauhoi[random].ques);
        if (strcmp(cauhoi[random].kind, "MC") == 0)
        {
            for (int j = 0; j < cauhoi[random].numchoices; j++)
            {
                printf("%c.%s\n", a++, cauhoi[random].choicelist[j]);
            }
        }
        fflush(stdin);
        gets(choice);
        if (strcmp(choice, cauhoi[random].answer) == 0)
        {
            printf("Correct answer is %s\n", cauhoi[random].answer);
            cout += cauhoi[random].point;
        }
        else if (strcmp(choice, "SKIP") == 0)
        {
            printf("You skip!\n");
            cout -= cauhoi[random].point;
            continue;
        }
        else
        {
            printf("Correct answer is %s\n", cauhoi[random].answer);
            cout -= cauhoi[random].point;
        }
        a = 'A';
        printf("Your point: %d\n", cout);
    }
}

int main()
{
    string firstName;
    string lastName;
    string fileName;
    int userPoint;
    int N;
    question *p;
    printf("What is your first name ?\n ");
    fflush(stdin);
    gets(firstName);
    printf("What is your last name ?\n ");
    fflush(stdin);
    gets(lastName);
    printf("What file stores your questions?\n ");
    fflush(stdin);
    gets(fileName);
    p = readfile(fileName, N);
    printOut(p, N, userPoint);
    printf("%s %s, your game is over!\nYour final score is %d points \nBetter luck next time!", firstName, lastName, userPoint);
    getch();
    return 0;
}

