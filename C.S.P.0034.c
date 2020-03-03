#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void Reverse(char s[])
{
    printf("String before reverse : %s\n", s);

    printf("String reversed: %s", strrev(s));
}
void Convert(char s[])
{
    for (int i = 0; i <= strlen(s); i++)
    {
        if (islower(s[i]))
            putchar(toupper(s[i]));
        else
            putchar(tolower(s[i]));
    }
}
int main()
{
    char s[50];
    int key;
    do{
    printf("Enter a string: ");
    gets(s);
    Reverse(s);
    printf("\nAfter convert: ");
    Convert(s);
    printf("------------------------------------\n");
    printf("--------Press ESC to exit or ENTER to continous!!!\n");
    key=getch();
    }
    while(key !=27);
    getch();
    return 0;
}