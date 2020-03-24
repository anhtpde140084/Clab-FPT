#include <conio.h>
#include <stdio.h>

void convert(int n)
{
    int i = 1, rem, s = 0;
    do
    {
        rem = n % 2;
        s += (i * rem);
        n /= 2;
        i *= 10;
    } while (n > 0);
    printf("\tThe binary number is: %d", s);
}
int main()
{
    int n,key;
    do
    {
        printf("\nConvert Decimal to Binary program");
        printf("\n\tEnter a positive number: ");
        scanf("%d", &n);
        if (n <= 0)
        {
            printf("Nhap lai: ");
            scanf("%d", &n);
        }
        convert(n);
        printf("\n Press anykey to another convert || Press ESC to exit!\n");
        key=getch();
    } while (key!=27);
    getch();
    return 0;
}