#include <conio.h>
#include <stdio.h>

void getUserChoice()
{

    printf("\n1. Enter an integer array ");
    printf("\n2. Sort array in ascending and display the sorted array on the screen");
    printf("\n3. Enter new integer value");
    printf("\n4. Add new value entered to the sorted array in ascending order and then display new array on the screen");
    printf("\n5. Loop up dulicate elements and remove it from the array. ");
    printf("\n6. Exit.!");
}
void nhap(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("Element[%d] =  ", i);
        scanf("%d", &a[i]);
    }
}
void xuat(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
}
void sort(int a[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%5d", a[i]);
    }
}
void newVal( int n ,int a[] ){
	printf("\nPlease enter new value: ");
	scanf("%d", &a[n++]);
}

void del(int a[], int n)
{
    int i, j, k, x;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                for (k = j; k < n; k++)
                {
                    a[k] = a[k + 1];
                }
                n--;
                j--;
            }
        }
    }
}
int main()
{
    int userChoice;
    int a[100];
    int n, x;
    getUserChoice();
    printf("\nPlease enter size of array: ");
    scanf("%d", &n);
    nhap(a, n);
    printf("\nThe array after sorting: ");
    sort(a, n);
    newVal(n,a);
    xuat(a,n);
    sort(a,n);
    printf("\nNew array: ");
    xuat(a,n);
    del(a, n);
    printf("\nThe array after removeing dupicate elements: \n");
    xuat(a, n);
    printf("\nExit!!");
    getch();
    return 0;
}