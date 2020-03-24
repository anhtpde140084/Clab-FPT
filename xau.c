#include <stdio.h>
#include <string.h>
#include <conio.h>

void replace(char string[], char s1[], char s2[])
{
    int sLen, s1Len, s2Len;
    int i = 0, j, k;
    int count = 0, pos1, posCuoi;
    sLen = strlen(string);
    s1Len = strlen(s1);
    s2Len = strlen(s2);
    for (i = 0; i < sLen; i++)
    {
        count = 0;
        pos1 = i;
        for (j = 0; string[i] == s1[j]; j++, i++)
            if (j == s1Len - 1)
                count = 1;
        posCuoi = i;
        if (count == 0)
            i -= j;
        else
        {
            for (j = pos1; j < posCuoi; j++)
            {
                for (k = pos1; k < sLen; k++)
                    string[k] = string[k + 1];
                sLen--;
                i--;
            }

            for (j = pos1; j < pos1 + s2Len; j++)
            {
                for (k = sLen; k >= j; k--)
                    string[k + 1] = string[k];
                string[j] = s2[j - pos1];
                sLen++;
                i++;
            }
        }
    }
}
main()
{
    char s[100], s1[100], s2[100];
    printf("\nEnter a string: ");
    gets(s);
    printf("\nEnter the s1 string: ");
    gets(s1);
    printf("\nEnter the s2 string: ");
    gets(s2);
    replace(s, s1, s2);
    printf("\nnew string : %s\n", s);
    getch();
    return 0;
}
