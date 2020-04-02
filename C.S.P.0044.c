#include <conio.h>
#include <stdio.h>
int drawMenu()
{
    int choice;
    printf("\n1-Add a value");
    printf("\n2-Search a value: ");
    printf("\n3-Print out the array");
    printf("\n4-Print out values in a range of inputted min and max values, inclusively.");
    printf("\n5-Sort the array in ascending order");
    printf("\n6-Quit\n");
    scanf("%d", &choice);
    return choice;
}
void add(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}
void printout(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}
void search(int *a, int n)
{
    int x;
    printf("Enter value you want to search: ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++)
    {
        if (x == a[i])
        {
            printf("%d co vi tri la %d", x, i);
        }
    }
}
void opt4()
{
    int min, max;
    printf("Enter min number: ");
    scanf("%d", &min);
    printf("Enter max number: ");
    scanf("%d", &max);
    printf("The element between min and max is: ");
    for (int i = min; i <= max; i++)
    {
        printf("%d\t", i);
    }
}
void sort(int *a, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printout(a, n);
}
int main()
{
    int opt;
    int a[1000];
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d",&n);
    do
    {
        opt = drawMenu();
        switch (opt)
        {
        case 1:
            add(a, n);
            break;
        case 2:
            search(a, n);
            break;
        case 3:
            printout(a, n);
            break;
        case 4:
         opt4();
         break;
         case 5: 
         sort(a,n);
         break;
        default:
            break;
        }
    } while (opt > 0 && opt < 7);

    getch();
    return 0;
}