#include <stdio.h>
#include <conio.h>
const MAX = 100;

void input(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n Enter element[%d] = ", i);
        scanf("%d", &a[i]);
    }
}
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%5d", a[i]);
    }
}
void ascending(int a[], int n)
{
    int t;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

void descending(int a[], int n)
{
    int t;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

int main()
{
    int arr[MAX];
    int n;
    printf("\n Please enter size of array: ");
    scanf("%d", &n);
    input(arr, n);
    ascending(arr, n);
    printf("\nThe array sorted in ascending: \n");
    print(arr, n);
    descending(arr, n);
    printf("\nThe array sorted in descending: \n");
    print(arr, n);
    getch();
    return 0;
}