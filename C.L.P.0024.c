#include <conio.h>
#include <stdio.h>
#include <string.h>
typedef struct
{
    char new[100];
    char mean[100];
} diction;
diction list[1000];
int n = 0;
FILE *f, *f1;
int drawMenu()
{
    int choice;
    printf("==============DICTIONARY===============");
    printf("\n1. Create a new word");
    printf("\n2. Update an exiting word");
    printf("\n3. Look up meaning");
    printf("\n4. Exit");
    printf("\n Please choice (1-4): ");
    scanf("%d", &choice);
    return choice;
}
void add()
{
    char add[30];
    printf("\nEnter a new word: ");
    fflush(stdin);
    gets(add);
    f = fopen("index.txt", "a");
    strcpy(list[n].new, add);
    fprintf(f, "%s\n", list[n].new);
    printf("\n");
    fclose(f);
    f = fopen("meaning.txt", "a");
    fflush(stdin);
    printf("Meaning: ");
    gets(list[n].mean);
    fprintf(f, "%s\n", list[n].mean);
    n++;
    fclose(f);
}
void update()
{
    char add[30];
    printf("\nEnter a word to update: ");
    fflush(stdin);
    gets(add);
    for (int i = 0; i <= n; i++)
    {   
        if ((strcmp(add, list[i].new) == 0))
        {   f = fopen("meaning.txt", "w+");
            printf("Meaning update: ");
            gets(list[i].mean);
            fprintf(f, "%s\n", list[i].mean);
            rewind(f);
        }
        else    
        break;
       }
    fclose(f);
}
void lookup()
{
    char look[10];
        char nhap[10];
				printf("\nEnter a word to look up: ");
				fflush(stdin);
				gets(look);	
				for(int i=0; i<=n; i++){
				if((strcmp(look,list[i].new)==0)){	
					f= fopen("meaning.txt","r");
						fgets(&list[i].mean,60,f);
						printf("Meaning: %s",list[i].mean);	
                        rewind(f);
					}
				}
					fclose(f);
}
int main()
{   int choice;
    do
    {
        choice = drawMenu();
        switch (choice)
        {
        case 1:
            printf("You choice 1 \n");
            add();
            break;
        case 2:
            printf("You choice 2 \n");
            update();
            break;
        case 3:
            printf("You choice 3 \n");
            lookup();
            break;
        default:
            printf("\nProgram exit!");
            break;
        }

    } while (choice >0 && choice <4);

    getch();
    return 0;
}