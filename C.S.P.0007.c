#include <stdio.h>
#include <conio.h>
#include <string.h>

char *lSpace(char names[])
{
    int i = 0;
    while (names[i] == ' ')
        i++;
    if (i > 0)
        strcpy(&names[0], &names[i]);
    return names;
}
char *rSpace(char names[])
{
    int i = strlen(names) - 1;
    while (names[i] == ' ')
        i--;
    names[i + 1] = '\0';
    return names;
}
char *Space(char names[])
{
    rSpace(lSpace(names));
    char *ptr = strstr(names, "  ");
    while (ptr != NULL)
    {
        strcpy(ptr, ptr + 1);
        ptr = strstr(names, "  ");
    }
    return names;
}
int main()
{   char names[31];
    int key;
    do
    {   printf("Enter string: ");
        gets(names);
        Space(names);
        printf("After extra blanks are remove: ");
        puts(names);
        key = getch();
    } while (key != 27);
    getch();
    return 0;
}