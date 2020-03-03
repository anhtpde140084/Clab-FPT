#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct Memcached
{
    char key[30];
    char variable[100];
    int soday;
};
//typedef struct MEMCACHED Memcached- test khai bao typedef.

void nhap(struct Memcached a[], int n) 
{
    int i;
    for (int i = 0; i < n; i++)
    {
        printf("Enter your key: ");
        gets(a[i].key);
        fflush(stdin);
        printf("Enter your variable: ");
        gets(a[i].variable);
        fflush(stdin);
        printf("Enter expire time: ");
        scanf("%d", &a[i].soday);
        printf("\nStore data succeed with key' %s ' , using on-the-fly compression expire time is %d seconds.!!\n\n", a[i].key, a[i].soday);
    }
}
void xuat(struct Memcached a[], int n) 
{
    int i;
    for (int i = 0; i < n; i++)
    {
        printf("\nYou data is: %s \n", a[i].variable);
        printf("\n");
    }
}
void timVal(struct Memcached a[], int n, char key[20])
{

    int i;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(key, a[i].key) == 0)
        {
            xuat(a[i].key, n);
        }
        else
        {
            printf("\n NOT FOUND!!!\n");
        }
    }
}

void xoa(struct Memcached a[], int n)
{
    int pos;
    char key[30];
    fflush(stdin);
    printf("Enter your key: ");
    scanf("%s",&key);
        for (int i = 0; i < n; i++)
        {
            strcpy(a[i].key, a[i + 1].key);
            strcpy(a[i].variable, a[i + 1].variable);
            a[i].soday = a[i + 1].soday;
        }
        n--;
        printf("\nDelete Success!\n\n");
    }

int getChoice()
{
    int choice;
    printf("=============  Mamcache  ==============");
    printf("\n**     1) Store data                 **");
    printf("\n**     2) Retrieve item              **");
    printf("\n**     3) Delete item                **");
    printf("\n**     4) Flush all existing items   **");
    printf("\n**     5) Exit the program.          **");
    printf("\n*------------------------------------**");
    printf("\n      Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}
int main()
{   char key[30];
    int i, userChoice;
    struct Memcached a[30];
    int n = 1;
    do
    {
        userChoice = getChoice();
        switch (userChoice)
        {
        case 1:
            fflush(stdin);
            nhap(a, n);
            break;
        case 2:
            
            printf("Enter your key: ");
            scanf("%s", &key);
            timVal(a, n, key);
            break;
        case 3:
            xoa(a, n);
            break;
        case 4:
            printf("Success!!!!\n");
            break;
        default:
            printf("Chocie again !\n");
            break;
        }

    } while (userChoice > 0 && userChoice < 4);
    getch();
    return 0;
}
