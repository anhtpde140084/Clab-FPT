
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
void prinOut(int a[], char s[], int n)
{
    for (int i = 0; i < n; i++)
        printf("\n------%3c: %3d", s[i], a[i]);
}
int main()
{
    char s[50];
    char str[26];
    int a[26];
    int n;
    printf("Enter a string: ");
    gets(s);
    strlwr(s);
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]))
            putchar(s[i]);
        else
        {
            return 0;
        }
        if (s[i] != ' ')
        {
            int kiemtra = 1;
            for (int j = 0; j < strlen(s); j++)
            {
                if (s[i] == str[j])
                    a[j]++;
            }

            if (kiemtra)
            {
                s[n] = str[i];
                s[n + 1] = '\0';
                a[n] = 1;
                a[n + 1] = '\0';
                n++;
            }
        }
    }

    prinOut(a, s, n);
    getch();
    return 0;
}
