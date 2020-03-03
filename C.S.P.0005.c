#include <stdio.h>

int main()
{
    int n, i, key;
    do
    {

        printf("Please enter a number (1-9): ");
        scanf("%d", &n);
        printf("Multiplication table for %d number: \n", n);
        for (i = 1; i <= 9; ++i)
        {
            printf("%d * %d = %d \n", n, i, n * i);
        }
        printf("-----------------------------\n");
        printf("\nPress ESC to exit or Enter to continous!\n");
        key = getch();
    } while (key != 27);
    

    return 0;
}