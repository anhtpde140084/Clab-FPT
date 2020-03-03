#include <stdio.h>
#include <conio.h>

int getUserChoice()
{
    int choice;
    printf("\n1 - Calculating Fuel Economy");
    printf("\n2 - Calculating Distance Traveled");
    printf("\n3 - Revised Fuel Economy Calculation");
    printf("\nChoice feature: ");
    scanf("%d", &choice);
    return choice;
}

void fuel()
{
    int minutes;
    float speed, gas;
    printf("How many minutes did you drive? \n");
    scanf("%d", &minutes);
    printf("What was the average speed of the car during that time? \n");
    scanf("%f", &speed);
    printf("How many gallons of gas did your car use? \n");
    scanf("%f", &gas);
    printf("Your car everaged %.2f miles per gallon.", (speed / 60) * minutes / gas);
}
void distance()
{
    float radius;
    int revol;
    printf("What is the radius of your tires, in inches?\n");
    scanf("%f", &radius);
    printf("How many revolutions did your car's tires make?\n");
    scanf("%d", &revol);
    printf("Your car traveled %.2f miles.", 3.14 * 2 * radius * revol * 0.000015783);
    ;
}
void revised()
{
    float radius, gas;
    int revol;
    printf("What is the radius of your tires, in inches?\n");
    scanf("%f", &radius);
    printf("How many revolutions did your car's tires make?\n");
    scanf("%d", &revol);
    printf("How many gallons of gas did your car use?\n");
    scanf("%f", &gas);
    printf("Your car averaged %.2f miles per gallon.", 3.141592654 * 2 * radius * revol * 0.000015783 / gas);
}
int main()
{
    int userChoice;
    do
    {
        userChoice = getUserChoice();
        switch (userChoice)
        {
        case 1:
            fuel();
            break;
        case 2:
            distance();
            break;
        case 3:
            revised();
            break;
        }
    } while (userChoice > 0 && userChoice < 3);
    getch();
    return 0;
}