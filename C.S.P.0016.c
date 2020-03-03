#include <stdio.h>
#include <conio.h>
void calu(float rate, float owed, float payment)
{
    int month = 1;
    do
    {
        owed = (owed + owed * rate / 1200) - payment;
        printf("%2d%12.2f %16.2f\n", month++, payment, owed);
    } while (owed > payment);
    printf("%2d%12.2f\t\t0", month, owed = (owed + owed * rate / 1200));
}

int main()
{
    float rate, owed, payment;
    printf("What is the value left on the mortgage?\n");
    scanf("%f", &owed);
    printf("What is the annual interest rate of the loan, in percent?\n");
    scanf("%f", &rate);
    printf("What is the monthly payment?\n");
    scanf("%f", &payment);
    printf("\n-------------------------------\n");
    printf("Month\tPayment\tAmount\tOwed\n");
    calu(rate, owed, payment);
    printf("\n-------------------------------\n");
    getch();
    return 0;
}