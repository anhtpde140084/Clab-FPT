#include <stdio.h>
#include <conio.h>
#include <string.h>

void TimeOnce(char str[])
{
    int count = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        for (int j = 0; j < strlen(str); j++)
        {
            if (str[i] == str[j])
            {
                count++;
            }
        }

        if (count == 1)
        {
            printf("%c    ", str[i]);
        }
        count = 0;
    }
}

int main()
{
    char key;
    char s[50];
    do
    {
        printf("Enter the string: ");
        gets(s);
        printf("Found characters: ");
        TimeOnce(s);
        fflush(stdin);
        printf("\n ===================================================");
        printf("\n");
        printf("Press ESC to Exit");
        key = getch();
    } while (key != 27);
}