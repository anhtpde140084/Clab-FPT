#include <conio.h>
#include <stdio.h>
#include <string.h>

FILE *f;

struct Grocery
{   int n;
    int idNumber[20];
    char nameProduct[100];
    float cost[100];
    char category[100];
};
void updateFile(struct Grocery n){
    fclose(f);
    int n =0;
    int a = remove("items.txt");
    f = fopen("items.txt", "w+");
    for (int i = 0; i < n; i++)
    {
        
    }
    
}
void add(struct Grocery a, int n)
{
    char key[20];
    int a;
    printf("What is the ID number of the items to add? \n");
    scanf("%s", a.idNumber);
    printf("What is the name of the item to be added? \n ");
    scanf("%s", a.nameProduct);
    printf("What is the cost of the item to be added?\n ");
    scanf("%lf", &a.cost);
    fflush(stdin);
    printf("What is the product category of the item to be added?\n ");
    scanf("%c", &a.category);
    updateFile(f);
    printf("%s has been added into the database!\n", a.nameProduct);
}
