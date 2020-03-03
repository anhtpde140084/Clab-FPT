#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>

int insideFile(char *a, char *b)
{
    if (strcmp(a, b) == 0)
    {
        system("cls");
        printf("Great, %s is in the dictionary!\n", a);
        return 1;
    }
    return 0;
}
int subStr(char *a, char *b)
{
    int n = strlen(a);
    int m = strlen(b);

    int i = 0;
    for (int j = 0; j < m; j++)
    {
        while (b[j] == a[i])
        {
            i++;
            j++;
            if (i == n)
                return 1;
        }
        i = 0;
    }
    return 0;
}
int subSquence(char *a, char *b)
{
    int n = strlen(a);
    int m = strlen(b);
    if (abs(n - m) > 2)
        return 0;
    int i = 0, j = 0, count = 0;
    while (j < m)
    {
        if (b[j] == a[i])
            i++;
        else
            count++;
        j++;
    }
    if ((i == n) && (count < 5))
        return 1;
    return 0;
}
int permutation(char *a, char *b)
{
    int n = strlen(a);
    int pos[n];
    for (int i = 0; i < n; i++)
        pos[i] = 0;
    int i = 0, j = 0;
    while (i < n)
    {
        for (j = 0; j < n; j++)
            if (a[i] == b[j])
            {
                pos[j] = 1;
                break;
            }
        if (j == n)
            return 0;
        i++;
    }
    for (int i = 0; i < n; i++)
        if (pos[i] == 0)
            return 0;
    return 1;
}
int matchscore(char *a, char *b)
{
    int n = strlen(a);
    int i = 0, count = 0;
    while (i < n)
    {
        if (a[i] == b[i])
            count++;
        i++;
    }
    return (n - count) < 3;
}
void check(FILE *f, char *word)
{
    char *temp = (char *)calloc(30, sizeof(char));
    int time = 1, result;
    printf("Here is the possible words you could have meant:\n");
    while (getc(f) != EOF)
    {
        result = 0;
        if (time == 1)
        {
            rewind(f);
            time++;
        }
        fscanf(f, "%s", temp);
        if (insideFile(word, temp))
            return;
        if (strcmp(temp, word) > 0)
            result += subStr(word, temp) + subSquence(word, temp);
        else if (strcmp(temp, word) < 0)
            result += subStr(temp, word) + subSquence(temp, word);
        if (strlen(temp) == strlen(word))
            result += permutation(word, temp) + matchscore(temp, word);
        if (result > 0)
            printf("%s\n", temp);
    }
}
void FindWord(FILE *f, char *word, char *choice)
{
    printf("Please enter a word you'd like to check \n ");
    fflush(stdin);
    scanf("%s", word);
    check(f, word);
    printf("Would you like to check another word? (yes/no): \n");
    fflush(stdin);
    scanf("%s", choice);
}
int main()
{
    FILE *f = fopen("dictionary.txt", "r");
    char *word = (char *)calloc(30, sizeof(char));
    char *choice = (char *)calloc(30, sizeof(char));
    printf("Welcome to the Spell Checker!\n");
    printf("The dictionary has been loaded.\n");
    while (1)
    {
        FindWord(f, word, choice);
        if (strcmp(choice, "no") == 0)
        {
            printf("End program!!\n");
            system("pause");
            return 1;
        }
        else if (strcmp(choice, "yes") == 0)
        {
            rewind(f);
            continue;
        }
        else
        {
            printf("Wrong format...\n");
            system("pause");
        }
    }
    getch();
    return 0;
}
