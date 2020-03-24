#include <stdio.h>
#include <conio.h>
const MAX = 100;

void input(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter element[%d] = ", i);
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
int findSmallest(int arr[], int n){
    int min = arr[0];
    int i;
    for ( i = 1; i < n; i++)
    {
        if (min > arr[i]) min = arr[i];
        
    }
    return min;
}
int main()
{
    int arr[MAX];
    int n;
    printf("\nPlease enter size of array: ");
    scanf("%d", &n);
    input(arr, n);
    ascending(arr, n);
    printf("The array sorted in ascending: ");
    print(arr, n);
    descending(arr, n);
    printf("\nThe array sorted in descending: ");
    print(arr, n);
    printf("\n Smallest is %d",findSmallest(arr,n));
    getch();
    return 0;
}