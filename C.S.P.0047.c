#include <conio.h>
#include <stdio.h>
#include <string.h>
int n = 0;
typedef struct
{
    char name[100];
} student;
student list[1000];
int drawMenu()
{
    int choice;
    printf("*******************************");
    printf("\n1 - Add a student.");
    printf("\n2 - Remove a student.");
    printf("\n3 - Search a student.");
    printf("\n4 - Print list student in an ascending folder.");
    printf("\n5 - Exit");
    printf("\n******************************\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void add(char data[])
{
    fflush(stdin);
    printf("\nEnter student name: ");
    gets(list[n].name);
    printf("\nThe student name has been added in list !\n");
    n++;
}
void Search(char data[])
{
    char name2[100];
    int check = 0;
    printf("\nEnter student name: ");
    fflush(stdin);
    gets(name2);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(list[i].name, name2) == 0)
        {
            printf("The position is %d \n", i);
        }
    }
}
void xoa(char data[])
{
    char name1[100];
    int check = 0;
    printf("\nEnter student name: ");
    fflush(stdin);
    gets(name1);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(list[i].name, name1) == 0)
            list[i] = list[n - 1];
        n--;
        check = 1;
    }
    if (check == 1)
    {
        printf("\nThe name student has been deleted!\n");
    }
    else
        printf("\n No Data Match.");
}
void printOut(char data[])
{
    if (n == 0)
    {
        printf("\nNot found!");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            printf("%s\n", list[i].name);
        }
    }
}

int main()
{
    char data[100], name[100];
    int choice;
    do
    {
        choice = drawMenu();
        switch (choice)
        {
        case 1:
            add(data);
            break;
        case 2:
            xoa(data);
            break;
        case 3:
            Search(data);
            break;
        case 4:
            printOut(data);
            break;
        default:
            printf("Program excutive!");
            break;
        }

    } while (choice > 0 && choice < 4);
    getch();
    return 0;
}
