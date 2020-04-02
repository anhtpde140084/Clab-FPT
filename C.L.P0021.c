#include <conio.h>
#include <stdio.h>
int day_of_year(int b, int a, int c)
{
    int i = 0, daymon = 0, dayday = 0;
    int mth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((c % 4) || (c % 100) && (c % 400))
        mth[2] = mth[2] + 1;

    for (i = 0; i < a; i++)
    {
        daymon += mth[i];
    }
    dayday = b;
    return (daymon + dayday);
}
void day_of_week(int d, int m, int y)
{
    int day = (d += m < 3 ? y-- : y - 2, 23 * m / 9 + d + 4 + y / 4 - y / 100 + y / 400) % 7; 
    switch (day)
    {
    case 0:
        printf("Sunday");
        break;
    case 1:
        printf("Monday");
        break;
    case 2:
        printf("Tuesday");
        break;
    case 3:
        printf("Wednesday");
        break;
    case 4:
        printf("Thursday");
        break;
    case 5:
        printf("Friday");
        break;
    case 6:
        printf("Saturday");
        break;

    }
}
int week_of_year(int day,int month,int year){
    return day_of_year(day,month,year) /7;
}
int main(void)
{   int day, month, year;
    printf("Please enter a date (dd/mm/yyyy): ");
    scanf("%d%d%d",&day,&month,&year);
    printf("Day of year: %d",day_of_year(day,month,year));
    printf("\nDay of week: "); 
    day_of_week(day,month,year);
    printf("\nWeek of year: %d",week_of_year(day,month,year));
    getch();
    return 0;
}