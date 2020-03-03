#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
int getUserChoice()
{
    int choice;
    printf("\n1. Convert binary to decimal number");
    printf("\n2. Convert octal number to decimal number");
    printf("\n3. Convert hexadecimal number to decimal number");
    printf("\n4. Exit");
    printf("\n Please choose number(1-4): ");
    scanf("%d", &choice);
}
void display(int decimal)
{
        printf("Decimal number is %d", decimal);
        printf("\nPress Enter to continue !");
        printf("\n-----------------------------------------------!\n");
}

void op1()
{
    int number, binary, decimal = 0, base = 1, digit;
    printf("Enter binary number: ");
    scanf("%d", &number);
    while (number > 0)
    {
        binary = number;
        digit = number % 10;
        decimal += digit * base;
        number /= 10;
        base *= 2;
    }
    printf("The binary number is %d\n", binary);
    display(decimal);
}
void op2()
{
    long int octal, decimal = 0;
    int i = 0;

    printf("Enter any octal number: ");
    scanf("%ld", &octal);
    while (octal != 0)
    {
        decimal = decimal + (octal % 10) * pow(8, i++);
        octal = octal / 10;
    }

    printf("The octal number is %ld\n", octal);
    display(decimal);
}
void op3()
{
    
    char s[10000];
    scanf("%s", s);
    int n = strlen(s);
    int dec = 0, temp;
    for (int i = 0; i < n; i++)
    {
        switch (s[i])
        {
        case 'A':
            temp = 10;
            break;
        case 'B':
            temp = 11;
            break;
        case 'C':
            temp = 12;
            break;
        case 'D':
            temp = 13;
            break;
        case 'E':
            temp = 14;
            break;
        case 'F':
            temp = 15;
            break;
        default:
            temp = (int)s[i] - 48;
            break;
        }
        dec = dec * 16 + temp;
    }
    display(dec);
}
int main()
{
    int userChoice;
    do
    {
        userChoice = getUserChoice();
        switch (userChoice)
        {
        case 1:
            op1();
            system("pause");
            break;
        case 2:
            op2();
            system("pause");
            break;
        case 3:
            printf("Enter a HEX number: ");
            op3();
            system("pause");
        case 4:
            printf("Program is completed");
            system("pause");
            break;
        default:
            printf("Again!");
        }
    } while (userChoice > 0 && userChoice < 5);

    system("pause");
}