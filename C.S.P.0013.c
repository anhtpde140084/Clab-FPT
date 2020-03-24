#include <conio.h>
#include <stdio.h>
#include <math.h>
void enter(double a[], int *n)
{
    printf("Please enter numbers: \n");
    double num = 0;
    while (1)
    {
        scanf("%lf", &num);
        if (num == -999)
            break;
        if( num <0 || num >100)
            printf("Nhap lai: \n");
        a[*n] = num;
        *n = *n + 1;
    }
}
void xoaMin(double a[], int *n)
{
    double min = a[0];
    for (int i = 0; i < *n; i++)
        if (min > a[i])
            min = a[i];
    for (int i = 0; i < *n; i++)
    {
        if (a[i] == min)
        {
            for (int j = i; j < *n; j++)
            {
                a[j] = a[j + 1];
            }
            *n = *n - 1;
            break;
        }
    }
    printf("The data has been adjusted by removing the minimum %.2lf\n", min);
}
void xoaMax(double a[], int *n)
{
    double max = a[0];
    for (int i = 0; i < *n; i++)
        if (max < a[i])
            max = a[i];
    for (int i = 0; i < *n; i++)
        if (a[i] == max)
        {
            for (int j = i; j < *n - 1; j++)
                a[j] = a[j + 1];
            *n = *n - 1;
            break;
        }
    printf("The data has been adjusted by removing the maximum %.2lf\n", max);
}
double calAv(double a[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return sum / n;
}
double calDiv(double a[], int n, double mean)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += pow(a[i] - mean, 2);
    return sqrt(sum / n);
}
int kCach(int n, int a, int b)
{
    return ((n >= a) && (n <= b) ? 1 : 0);
}
void Histogram(double a[], int n)
{
    int dau = 0;
    int cuoi = 4;
    while (cuoi < 100)
    {
        printf("%2d-%2d|", dau, cuoi);
        for (int i = 0; i < n; i++)
            if (kCach(a[i], dau, cuoi))
                printf("*");
        printf("\n");
        dau = cuoi + 1;
        cuoi = dau + 4;
    }
    printf("%5d|", dau);
    for (int i = 0; i < n; i++)
        if (a[i] == 100)
            printf("*");
    printf("\n");
}

int main()
{
    double *a = (double *)calloc(100, sizeof(double));
    int n = 0;
    enter(a, &n);
    xoaMin(a, &n);
    xoaMax(a, &n);
    double mean = calAv(a, n);
    printf("The adjusted mean is %.2lf\n", mean);
    printf("The adjusted standard devitation is %.2lf\n", calDiv(a, n, mean));
    printf("Here is a histogram of the adjusted data:\n");
    Histogram(a, n);
    getch();
    return 0;
}