#include <stdio.h>
#include <conio.h>

int getUserChoice()
{
    int choice;
    printf("\n1 - Quadratic equation");
    printf("\n2 - Bank deposit problem");
    printf("\n3 -Quit");
    printf("\nSelect an option:  ");
    scanf("%d", &choice);
    return choice;
}
void quadratic(float a, float b, float c)
{
    float x1, x2;
    float delta = b * b - 4 * a * c;
    if (delta < 0)
    {
        printf("Phuong trinh vo nghiem!! ");
    }
    else if (delta == 0)
    {
        printf("Phuong trinh co kiep kep x1 = x2 = %f", -b / (2 * a));
    }
    else
    {
        delta = sqrt(delta);
        x1 = (-b + delta) / (2 * a);
        x2 = (-b - delta) / (2 * a);
        printf("phuong trinh co 2 nghiem phan biet: \n");
        printf("x1 = %f", x1);
        printf("x2 = %f", x2);
    }
}
void bank()
{
    double deposit, rate;
    int time;
    do
    {
        printf("Enter deposit: ");
        scanf("%lf", &deposit);
    } while (deposit < 0);

    do
    {
        printf("Enter rate: ");
        scanf("%lf", &rate);
    } while (rate > 0.2);

    do
    {
        printf("Enter time (by month) to send: ");
        scanf("%d", &time);
    } while (time < 0);

    printf("Total amount received: %.5lf\n", deposit * rate * time);
}
int main()
{
    float a, b, c;
    int userChoice;
    do
    {
        userChoice = getUserChoice();
        switch (userChoice)
        {
        case 1:
            printf("Enter a, b, c: ");
            scanf("%f%f%f", &a, &b, &c);
            quadratic(a, b, c);
            printf("\n===========================");
            break;
        case 2:
            bank();
            break;
        }
    } while (userChoice > 0 && userChoice < 3);
    getch();
    return 0;
}