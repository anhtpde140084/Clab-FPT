#include <conio.h>
#include <stdio.h>

void Input(int a[], int n)
{
    for (int i = 1; i < n+1; i++)
    {
        printf("Input elements %d = ", i );
        scanf("%d", &a[i]);
    }
}

int odd(int a[], int n)
{
    int s = 0;
    for (int i = 1; i < n+1; i++)
    {
        if (a[i] % 2 != 0)
        {
            s += a[i];
        }
    }
    return s;
}

int even(int a[], int n)
{
    int s = 0;
    for (int i = 1; i < n+1; i++)
    {
        if (a[i] % 2 != 0)
        {
            continue;
        }
        s += a[i];
    }
    return s;
}
int main()
{
    int a[100];
    int n;
    printf("Enter a number of elements: ");
    scanf("%d", &n);
    Input(a, n);
    printf("\nSum of Odd = %d", odd(a, n));
    printf("\nSum of Even = %d", even(a, n));
    printf("\n=======================================");
    getch();
    return 0;
}
