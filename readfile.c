#include <stdio.h>
#include<conio.h>
#include <stdlib.h> // For exit() function
int main()
{
    char c[1000];
    FILE *fptr;
 
    if ((fptr = fopen("program.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);         
    }
 
    // reads text until newline 
    printf("Find the sentences in file: ");
    fscanf(fptr,"%[^\n]", c);
 
    printf("Data from the file:\n%s", c);
    fclose(fptr);
    getch();
    return 0;
}