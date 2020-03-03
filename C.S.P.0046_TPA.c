#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int getUserChoice()
{
    int choice;
    printf("1 -The first primes\n");
    printf("2 -FIB elements\n");
    printf("3 -Sum of digits\n");
    printf("4 -Exit\n");
    printf("Your choice (1/2/3/4)? : ");
    scanf("%d", &choice);
    return choice;
}
int checkPrime(int n)
{
    for (int i = 1; i <= n / 2; i++)
        if ((n % i == 0) && (i != 1))
            return 0;
    return 1;
}
void primeNumbers()
{
    int i = 1, n;
    printf("Number of primes? : ");
    scanf("%d", &n);
    while (n)
        if (checkPrime(++i) == 1)
        {
            printf("%d ", i);
            n--;
        }
}
void infoTrue()
{
    printf("This is a FIB number!\n");
}
void FIB()
{
    int n, a = 1, b = 1, c = 2;
    printf("Enter number to check: ");
    scanf("%d", &n);
    if (n <= 3)
    {
        infoTrue();
        return;
    }
    while (c < n)
    {
        a = b;
        b = c;
        c = a + b;
        if (c == n)
        {
            infoTrue();
            return;
        }
    }
    printf("This is not FIB number! \n");
}
void sumDigit()
{
    int n, t, sum = 0, r;
    printf("Sum Digit Program \n");
    printf("Enter an integer n= ");
    scanf("%d", &n);

    t = abs(n);

    while (t != 0)
    {
        r = t % 10;
        sum = sum + r;
        t = t / 10;
    }

    printf("Sum of digits of %d = %d\n", n, sum);
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
            primeNumbers();
            printf("\n=====================================\n");
            break;
        case 2:
            FIB();
            printf("\n=====================================\n");
            break;
        case 3:
            sumDigit();
            printf("\n=====================================\n");
            break;
        case 4:
            printf("Program excuted !\n");
            break;
        default:
            printf("Chocie again !\n");
            break;
        }

    } while (userChoice > 0 && userChoice < 4);
    getch();
    return 0;
}
