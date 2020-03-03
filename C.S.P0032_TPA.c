#include <conio.h>
#include <stdio.h>

int main()
{
        int key;
    do
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
        printf("\nPress ESC to exit or Enter to continous!\n");
        key = getch();
        printf("-----------------------------\n");

    } while (key != 27);

    getch();
    return 0;
}