#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void check(int a)
{
    int b = sqrt(a);
    if (b * b == a)
    {
        printf("%d is a square number %d = %d x %d \n", a, a, b, b);
        system("pause");
    }

    else
    {
        printf("%d is not a square number ", a);
    }
}
int main()
{
    int n;

    while (n);
    {   
        system("cls");
        printf("Check Square Number Program\n");
        printf("Enter a positive integer n = ");
        scanf("%d", &n);
        if (n < 0)
        {
            printf("\nPlease enter a positive integer!");
            printf("\n=========================================");
        }
        else
        {
            check(n);
        }

    } 

    getch();
    return 0;
}