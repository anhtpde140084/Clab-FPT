#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

FILE *f;
int productCount = 0;
int idNumber[100];
char name[100][30];
double cost[100];
char category[100];
int menu()
{
    int choice;
    printf("Please make one of the following selections\n");
    printf("1. Add new item\n2. Delete item\n");
    printf("3. Change the cost of an item\n");
    printf("4. Search for item\n");
    printf("5. Display inventory details\n");
    printf("6. Quit\nYour choice ?: ");
    scanf("%d", &choice);
    return choice;
}

int findata(int id)
{
    for (int i = 0; i < 100; i++)
        if (id == idNumber[i])
            return i;
    return -1;
}
void updateFile()
{
    fclose(f);
    int a = remove("items.txt");
    f = fopen("items.txt", "w+");
    for (int i = 0; i < productCount; i++)
        fprintf(f, "%-8d%-10s%-8.2lf\t%c\n", idNumber[i], name[i], cost[i], category[i]);
}
void getInputFile()
{
    char *filename = (char *)calloc(30, sizeof(char));
    printf("Welcome to the store!\n");
    printf("Input the file to load: ");
    scanf("%s", filename);
    f = fopen("items.txt", "r+");
    while (1)
    {
        char etc = fgetc(f);
        if (etc == EOF)
            break;
        fseek(f, -1, SEEK_CUR);
        fscanf(f, "%d", &idNumber[productCount]);
        fscanf(f, "%s", name[productCount]);
        fscanf(f, "%lf", &cost[productCount]);
        fscanf(f, "\t%c\n", &category[productCount++]);
    }
    printf("%s have been load successfully to the database!\n", filename);
    rewind(f);
}
void add()
{
    printf("What is the ID number of the item to add? \n");
    int id;
    scanf("%d", &id);
    if (findata(id) >= 0)
    {
        printf("ID already exist, ADD FAILURE!\n");
        return;
    }
    idNumber[productCount] = id;
    printf("What is the name of the item to be added? \n ");
    scanf("%s", name[productCount]);
    printf("What is the cost of the item to be added?\n ");
    scanf("%lf", &cost[productCount]);
    fflush(stdin);
    printf("What is the product category of the item to be added?\n ");
    scanf("%c", &category[productCount++]);
    updateFile(f);
    printf("%s has been added into the database!\n",name[productCount]);
}
void delete ()
{
    int id;
    printf("What is the name of the item to delete?\n ");
    scanf("%d", &id);
    int pos = findata(id);
    if (pos < 0)
    {
        printf("ID not found, DELETE FAILURE!\n");
        return;
    }
    for (int i = pos; i < productCount - 1; i++)
    {
        idNumber[i] = idNumber[i + 1];
        strcpy(name[i], name[i + 1]);
        cost[i] = cost[i + 1];
        category[i] = category[i + 1];
    }
    productCount--;
    updateFile(f);
    printf("%s have been deleted from the database.\n",id);
}
void changeCost()
{
    int id;
    double newcost;
    printf("What is the ID number of the item in question?\n ");
    scanf("%d", &id);
    int pos = findata(id);
    if (pos < 0)
    {
        printf("ID not found, FAILURE!\n");
        return;
    }
    printf("You are going to change cost the product name \"%s\", Type the new cost: ", name[pos]);
    scanf("%lf", &newcost);
    cost[pos] = newcost;
    updateFile(f);
    printf("UPDATE SUCCESS!\n");
}
void display()
{
    printf("%10s\t%10s\t%-15s\t%s\n", "ID", "Name", "Cost", "Category");
    for (int i = 0; i < productCount; i++)
        printf("%10d\t%10s\t%-15lf\t%c\n", idNumber[i], name[i], cost[i], category[i]);
}

void search()
{
    int id, pos;
    printf("What item would you like to search for? \n ");
    scanf("%d", &id);
    pos = findata(id);
    if (pos >= 0)
    {
        printf("_________________Product infomation_________________\n");
        printf("%10s\t%10s\t%-15s\t%s\n", "ID", "Name", "Cost", "Category");
        printf("%10d\t%10s\t%-15lf\t%c\n", idNumber[pos], name[pos], cost[pos], category[pos]);
    }
    else
        printf("Not found product with specified ID!\n");
}
int main()
{
    FILE *f;
    getInputFile();
    int choice = 0;
    while (choice != 6)
    {
        system("cls");
        choice = menu();
        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            delete ();
            break;
        case 3:
            changeCost();
            break;
        case 4:
            search();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Program terminal!\n");
            break;
        default:
            printf("Choice agian!\n");
            break;
        }
        system("pause");
    }
    return 0;
}
