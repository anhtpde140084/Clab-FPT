#include <stdio.h>
#include <string.h>
#include <conio.h>
// dung struct long nhau || Struct nhúng
struct day
{
    struct plane
    {
        char noidi[100];
        char noiden[100];
        int seat;
    } list[100];
} date[10];

int n = 0;
// menu
int getchoice()
{
    int choice;
    printf("================ PLANE BOOK ================");
    printf("\nWhich of the following choices do you want? \n");
    printf("1) Make a reservation\n");
    printf("2) Print out a listing of all flights\n");
    printf("3) Quit\n");;
    scanf("%d", &choice);
    return choice;
}
// kiem tra ngay di ngay ve
int checkDay(int di, int ve)
{
    if (di < 0 || di > 9)
        return 0;
    if (ve < 0 || ve > 9)
        return 0;
    if (ve == di)
        return 1;
    return 2;
}
// kiem tra noi di va noi den trong tham chieu struct && file
int checkPlace(char noidi[100], char noiden[100])
{
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(noidi, date[0].list[i].noidi) == 0)
        {
            if (strcmp(noiden, date[0].list[i].noiden) == 0)
                return 1;
        }
    }
    return 0;
}
int checkSeat(char noidi[100], char noiden[100], int di, int ve, int seat, int listdi[], int listve[])
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(noidi, date[0].list[i].noidi) == 0)
        {
            if (strcmp(noiden, date[0].list[i].noiden) == 0)
            {
                listdi = i;
                if (date[di].list[i].seat - seat < 0)
                    return 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (strcmp(noiden, date[0].list[i].noidi) == 0)
        {
            if (strcmp(noidi, date[0].list[i].noiden) == 0)
            {
                listve = i;
                if (date[ve].list[i].seat - seat < 0)
                    return 0;
            }
        }
    }
    return 1;
}
void book()
{
    char tenKH[100], noidi[100], noiden[100];
    int listdi, listve, ngaydi, ngayve, seat;
    printf("What is your name?\n");
    scanf("%s",&tenKH);
    printf("From which city do you want to fly?\n");
    scanf("%s", &noidi);
    printf("what is your destination city?\n");
    scanf("%s",&noiden);
    printf("which day do you want to leave?\n");
    scanf("%d", &ngaydi);
    printf("which day do you want to come back?\n");
    scanf("%d", &ngayve);
    printf("How many seats do you want?\n");
    scanf("%d", &seat);
    if (checkPlace(noidi, noiden) == 0)
    {
        printf("Sorry, that reservation could not be made.\n");
        printf("We don't have flights to and from %s and %s.\n", noidi, noiden);
        return;
    }
    if (checkDay(ngaydi, ngayve) == 0)
    {
        printf("Sorry, that reservation could not be made.\n");
        printf("The day of flight are invalid.\n");
        return;
    }
    else if (checkDay(ngaydi, ngayve) == 1)
    {
        printf("Sorry, that reservation could not be made.\n");
        printf("You must come back on a later date than you leave.\n");
        return;
    }
    if (checkSeat(noidi, noiden, ngaydi, ngayve, seat, listdi, listve) == 0)
    {
        printf("Sorry, that reservation could not be made.\n");
        printf("Not enough seats are available.\n");
        return;
    }
    date[ngaydi].list[listdi].seat -= seat;
    date[ngayve].list[listve].seat -= seat;
    printf("Thanks, your reservation has been made.\n");
}

int main()
{
    int userChoice;
    char fn[100];
    char noidi[100], noiden[100];
    int seat;
    printf("Enter the name of file with the flight data: \n");
    gets(fn);
    printf("\n");
    FILE *f = fopen(fn, "r");
    if (f == NULL)
    {
        printf("Error!!! Can not found this file name. ");
        getch();
        return 0;
    } // read end of file
    while (fscanf(f, "%s %s %d", &noidi, &noiden, &seat) != EOF)
    {
        strcpy(date[0].list[n].noidi, noidi);
        strcpy(date[0].list[n].noiden, noiden);
        date[0].list[n].seat = seat;
        n++;
    }
    do
    {
        userChoice = getchoice();
        switch (userChoice)
        {
        case 1:
            book();
            printf("\n=====================================\n");
            break;
        case 2:
            printf("Here is the information for each flight on each day:\n\n");
            for (int i = 0; i <=6; i++)
            {
                printf("Day %d\n", i);

                for (int j = 0; j < n; j++)
                {
                    printf("From: %s To: %s Available Seats: %d\n", date[i].list[j].noidi, date[i].list[j].noiden, date[i].list[j].seat);
                }
            }
            printf("\n=====================================\n");
            break;
        case 3:
            printf("Program excuted !\n");
            printf("Exit!!");
            return 0;
            break;
        default:
            printf("Chocie again !\n");
            break;
        }

    } while (userChoice > 0 && userChoice < 4);

    getch();
    return 0;
}
