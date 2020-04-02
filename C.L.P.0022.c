#include <conio.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char stCode[10];
    char stName[30];
    char DOB[30];
    float point;
} sv;
void nhap(sv a[], int n)
{
    printf("Enter new student:");
    for (int i = 0; i < n; i++)
    {   fflush(stdin);
        printf("\nStudent code: ");
        gets(a[i].stCode);
        printf("Student name: ");
        gets(a[i].stName);
        printf("Date of birth: ");
        gets(a[i].DOB);
        printf("Learning point: ");
        scanf("%d",&a[i].point);
    }
}
void xuat(sv sv){
    printf("\nStudent code: %s", sv.stCode);
    printf("\nStudent name: %s", sv.stName);
    printf("\nDate of birth : %s", sv.DOB);
    printf("\nLearning point: %f", sv.point);
}
void xuatSV(sv a[], int n){
    printf("Student list:\n ");
    printf("---------------------------");
    for (int i = 0; i <n; i++)
    {
        xuat(a[i]);
    }
    printf("\n-------------------------");
    
}
void timkiem(sv a[], int n){
    char st[30];
    fflush(stdin);
    printf("Please enter student name: ");
    gets(st);
    printf("If found then display student information name %s\n", st);
    for (int i = 0; i < n; i++)
    {
        if(strcmp(st,a[i].stName)==0)
         {
             xuatSV(a,n);
         }
    }
}
int menu(){
    int choice;
    printf("\n1- Enter student list.");
    printf("\n2- Look up student.");
    printf("\n3- Display student list.");
    printf("\n4- Exit\n");
    scanf("%d",&choice);
    return choice;
}
int main()
{   int n, choice;
    printf("Enter number of student: ");
    scanf("%d",&n);
    sv a[n];
    do
    {
        choice = menu();
        switch (choice)
        {
        case 1: nhap(a,n);
            printf("\nPress enter to continue, ESC to return the main menu");
            break;
        case 2:
         timkiem(a,n);
            break;
        case 3: xuatSV(a,n);
            break;
        case 4: printf("Exit");
            break;
        default: printf("\nComplete!");
            break;
        }
    } while (choice!=4);
    getch();
    return 0;
}
