#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char account[30];
    char PIN[30];
    char ID[30];
    char BL[30];
    char MoneyType[30];
    double sum;
} ATM;
ATM list[100];
int n = 0;
FILE *f;
int drawMenu()
{
    int choice;
    printf("1. Withdraw money.");
    printf("\n2. Transfer money.");
    printf("\n3. Exit \n");
    scanf("%d", &choice);
    return choice;
}
void login()
{
    int userChoice;
    char userIF[30];
    char pin[30];
    printf("User(ID): ");
    fflush(stdin);
    gets(userIF);
    printf("Pin: ");
    fflush(stdin);
    gets(pin);
    for (int i = 0; i <= n; i++)
    {
        if (strcmp(list[i].ID, userIF) == 0 && strcmp(list[i].PIN, pin) == 0)
        {
            do
            {
                userChoice = drawMenu();
                switch (userChoice)
                {
                case 1:
                    f = fopen("ruttien.txt", "w+");
                    double money;
                    printf("\nHow much many you want to withDraw? ");
                    scanf("%lf", &money);
                    fprintf(f, "%lf", list[i].sum - money);
                    printf("\nYou have left %0.lf\n", list[i].sum - money);
                    f = fopen("infor.txt", "a+");
                    fprintf(f, "%0.lf", list[i].sum - money);
                    fclose(f);
                    break;
                case 2:
                    f = fopen("transfer.txt", "w+");
                    char a[100];
                    printf("\nEnter ID account you want to transfer: ");
                    fflush(stdin);
                    gets(a);
                    printf("\nEnter money you want to transfer: ");
                    scanf("%0.lf", &money);
                    fputs(a, f);
                    fprintf(f, "%0.lf", money);
                    printf("\n You have transfered for %s - %0.lf VND", a, money);
                    f = fopen("infor.txt", "w+");
                    fprintf(f, "%0.lf", list[i].sum - money);
                    fclose(f);
                    break;
                case 3:
                    exit(0);
                    break;
                default:

                    printf("\nSign out!");
                    break;
                }
            } while (userChoice > 0 && userChoice < 4);
        }
        else
            printf("\nWrong password or Account do not exist.\n");
        break;
    }
}
void regiter()
{
    FILE *fo = fopen("infor.txt", "a");
    printf("ID: ");
    fflush(stdin);
    gets(list[n].ID);
    printf("\nPIN: ");
    fflush(stdin);
    gets(list[n].PIN);
    printf("\nType of Money(USA, VND): ");
    fflush(stdin);
    gets(list[n].BL);
    printf("\nCurently you have: ");
    fflush(stdin);
    gets(list[n].MoneyType);
    printf("\nEnter your Amount of Money VND: ");
    scanf("%0.lf", &list[n].sum);
    fprintf(fo, "%s\n", list[n].ID);
    fprintf(fo, "%s\n", list[n].PIN);
    fprintf(fo, "%s\n", list[n].BL);
    fclose(fo);
    fo = fopen("ruttien.txt", "a");
    fprintf(fo, "%.0lf\n", list[n].sum);
    fclose(fo);
    fo = fopen("transfer.txt", "a");
    fprintf(fo, "%s\n", list[n].MoneyType);
    fclose(fo);
    n++;
}
int drawMenu2()
{
    int opt;
    printf("============ ATM Agribank ==========");
    printf("\n1. Login");
    printf("\n2. Register account");
    printf("\n3. Exit\n");
    scanf("%d", &opt);
    return opt;
}
int main()
{
    int opt;
    do
    {
        opt = drawMenu2();
        switch (opt)
        {
        case 1:
            login();
            break;
        case 2:
            regiter();
            break;
        default:
            printf("==========Hope you have a good day!===================\n");
        }
    } while (opt!=3);
    printf("\nExited.\n");
    getch();
    return 0;
}