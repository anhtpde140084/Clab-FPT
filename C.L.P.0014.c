#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
int tongtien = 1000;
int drawMenu() // menu
{
    int choice;
    printf("Welcome to the Casino. Here are your choices: ");
    printf("\n1. Buy chips ");
    printf("\n2. Sell chips ");
    printf("\n3. Play Craps ");
    printf("\n4. Play Arup's Game of Dice ");
    printf("\n5. Status Report ");
    printf("\n6. Quit \n");
    scanf("%d", &choice);
    return choice;
}
int main()
{
    int money, chips;
    int xu, sum;
    char roll;
    int k;
    int choice;
    do
    {   hoilai: // dung goto de hoi lai choices
        choice = drawMenu();
        
        switch (choice)
        {
        case 1:
            printf("How much cash do you want to spend for chips?\n");
            scanf("%d", &money);
            if (money < 10 || money > 1000)
            {
                printf("Sorry, you do not have that much money. No chips bought.\n\n");
                goto hoilai;
            }
            else
            {
                printf("You have %d to play games\n", money);
                chips = money / 11;
                tongtien -= money;
            }
            break;
        case 2: // quy doi tien
            money = chips * 10;
            chips = 0;
            printf("You got %d$.", money);
            tongtien -= money;
            break;
        case 3:
            printf("\nHow many chips would you want to bet?\n");
            scanf("%d", &xu);
            if ((xu == 0) || (xu > chips))
            {
                printf("\nSorry that is not allowed. No game played.\n");
            }
            else
                printf("\nPress 'r' and hit enter for your first roll.\n");
        hoilai2: 
            fflush(stdin);
            scanf("%c", &roll);
            if (roll != 'r')
            {
                break;
            }
            sum = 2 + rand() % 11;
            printf("You roll: %d", sum);
            if (sum == 7)
            {
                printf("\n You win.");
                chips += xu;
                goto thoat; // goto 'thoat' o phia duoi func
            }
            else if (sum == 11)
            {
                printf("\n You win.");
                chips += xu;
                goto thoat;// goto 'thoat' o phia duoi func
            }
            else if ((sum == 2) || (sum == 3) || (sum == 12))
            {
                printf("\n You lose.");
                chips -= xu;
                goto thoat;// goto 'thoat' o phia duoi func
            }
            int k = sum;
        check:
            printf("\nPress 'r' and hit enter for your next roll.\n");
            fflush(stdin);
            scanf("%c", &roll);
            if (roll != 'r')
            {
                break;
            }
            sum = 2 + rand() % 11;
            printf("You roll: %d", sum);
            if (sum == 7)
            {
                printf("\n You lose.");
                chips -= xu;
                goto thoat;
            }
            else if (sum == k)
            {
                printf("\n You win.");
                chips += xu;
                goto thoat;
            }
            else
                goto check;
        thoat:
            break;
        case 4:
            printf("\nHow many chips would you want to bet?\n");
            scanf("%d", &xu);
            if ((xu == 0) || (xu > chips))
            {
                printf("\nSorry that is not allowed. No game played.");
            }
            else
                printf("\nPress 'r' and hit enter for your first roll.\n");
        hoilai3:
            fflush(stdin);
            scanf("%c", &roll);
            if (roll != 'r')
            {
                break;
            }
            sum = 2 + rand() % 11;
            printf("You roll: %d", sum);
            if ((sum == 11) || (sum == 12))
            {
                printf("\n You win.");
                chips += xu;
                goto exit;
            }
            else if (sum == 2)
            {
                printf("\n You lose.");
                chips -= xu;
                goto exit;
            }
            k = sum;
        check1:
            printf("\nPress 'r' and hit enter for your next roll.\n");
            fflush(stdin);
            scanf("%c", &roll);
            if (roll != 'r')
            {
                break;
            }
            sum = 2 + rand() % 11;
            printf("You roll: %d", sum);
            if (sum <= k)
            {
                printf("\n You lose.");
                chips -= xu;
                goto exit;
            }
            else if (sum > k)
            {
                printf("\n You win.");
                chips += xu;
                goto exit;
            }
            else
            {
                goto check1;
            }
        exit:
            break;
            case 5: printf("\nYou currently have %d$ left and %d chips.\n",money+5,chips);
				break;
        default: printf("Program excutive!!");
            break;
        }
    } while (choice > 0 && choice < 6);

    getch();
    return 0;
}