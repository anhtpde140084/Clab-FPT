#include <stdio.h>
#include <string.h>
#include <conio.h>
int main()
{
    FILE *f;
    char fn[15];
    char ch;
    fflush(stdin);
    printf("File name: ");
    gets(fn);
    f = fopen(fn, "r");
    if (f == NULL)
    {
        printf("Can't open file !!!\n");
        return;
    }
    printf("File content:\n");
    ch = fgetc(f);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(f);
    }
    fclose(f);
    getch();
    return 0;
}