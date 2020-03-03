#include <stdio.h>
#include <string.h>
#include <conio.h>
int out(char a[], int b[], int n, int max)
{
    int i;
    printf("\n Times of appearance for each character: ");
    printf("\n");
    for (i = 0; i < n; i++)
        printf("%3c", a[i]);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%3d", b[i]);
    printf("\n============================================");
    printf("\nCharacters that appears the most: ");
    printf("\n");
    for (i = 0; i < n; i++)
        if (b[i] == max)
            printf("%3c", a[i]);
    printf("\n");
    for (i = 0; i < n; i++)
        if (b[i] == max)
            printf("%3d", b[i]);
}
int main()
{
    char chuoi[100];
    int key;
    int dem = 0;
    char a[50];
    int b[50];
    int n;
    int max;
    do
    {
        printf("\n\n");
        printf("  PLEASE ENTER STRING:  ");
        gets(chuoi);
        for (int i = 0; i < strlen(chuoi); i++)
        {
            if (chuoi[i] != ' ')
            {
                int check = 1;
                for (int j = 0; j < strlen(chuoi); j++)
                {
                    if (a[j] == chuoi[i])
                    {
                        b[j] = b[j] + 1;
                        if (max > b[j])
                            max = b[j];
                        check = 0;
                    }
                }
                if (check)
                {
                    a[n] = chuoi[i];
                    a[n + 1] = '\0';
                    b[n] = 1;
                    b[n + 1] = '\0';
                    n++;
                }
            }
        }

        out(a, b, n, max);
        key = getch();
    } while (key != 27);
    getch();
    return 0;
}
