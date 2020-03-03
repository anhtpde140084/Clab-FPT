#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int check(int n)
{

    int a, b, c;
    a = n % 10;
    n /= 10;
    b = n % 10;
    n /= 10;
    c = n;
    printf("The slot machine show %d%d%d", c, b, a);
    if ((a == b) && (b == c))
        return 2;
    if ((a == b) || (a == c) || (b == c))
        return 1;
    return 0;
}
void playGame(float *money)
{
    int n = 100 + rand() % (999 + 1 - 100);
    int win = check(n);

    switch (win)
    {
    case 0:
        printf("\nSorry you don't win anything.");
        break;
    case 1:
        printf("\nyou win 50 cents!");
        *money += 0.5;
        break;
    case 2:
        printf("\nYou win the big prize, $10.00!");
        *money += 10;
        break;
    }
}
int getUserChoice(float *money)
{
    int choice;
    printf("\n\n================Simple Slot Machine=======================");
    printf("\n You have $%.2f", *money);
    printf("\n Choose one of the following menu option: ");
    printf("\n1. Play the slot machine");
    printf("\n2. Save game");
    printf("\n3. Cash out ");
    printf("\n================= Please Choice! (1,2,3) ==================================\n");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    int userChoice, stop = 0;
    float money;
    srand(time(NULL));
    FILE *f = fopen("CLP003.txt", "w+");
    fprintf(f, "10");
    rewind(f);
    fscanf(f, "%f", &money);

    while (stop == 0)
    {    
        if ((int)money == 0)
        {
            printf("Sorry, you out of money, exitting...\n");
            system("pause");
            break;
        }
        userChoice = getUserChoice(&money);
        switch (userChoice)
        {
        case 1:
            money -= 0.25;
            playGame(&money);
            break;
        case 2:
            printf("Your money have saved with %.2f! \n", money);
            stop == 0;
            rewind(f);
            fprintf(f, "%.2f", money);
            break;
        case 3:
            printf("Thank you for playing, you end with %.2f !\n", money);
            stop = 1;
            rewind(f);
            fprintf(f, "0");
            break;
        default:
            printf("Choice again !\n");
            break;
        }
    }

    system("pause");
    return 0;
}