#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <dirent.h>
FILE *f, *f1, *f2;
int drawMenu() // menu
{
    int choice;
    printf("\n1) Read file");
    printf("\n2) Copy files");
    printf("\n3) Merge two files");
    printf("\n4) List files in a directory");
    printf("\n5) Delete file");
    printf("\n6) Exit.");
    printf("\n");
    printf("Choice features: ");
    scanf("%d", &choice);
    return choice;
}
void readfile()
{
    char fn[15];
    char ch;
    fflush(stdin);
    printf("Enter the name of file you wish to see: ");
    gets(fn);
    f = fopen(fn, "r");
    if (f == NULL)
    {
        printf("Can't open file !!!\n");
        return;
    }
    printf("\n");
    ch = fgetc(f);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(f);
    }
    fclose(f);
}
void copyfile()
{
    char ch, fn1[100], fn2[100];
    printf("Enter name of file to copy: ");
    gets(fn1);
    f1 = fopen(fn1, "r");
    if (f == NULL)
    {
        printf("Can't open file !!!\n");
        getch();
        return;
    }
    printf("Enter name of target file: ");
    gets(fn2);
    f2 = fopen(fn2, "w");
    ch = fgetc(f1);
    while (ch != EOF)
    {
        fputc(ch, f2);
        printf("\nFile copied successfully!!");
    }
    fclose(f1);
    fclose(f2);
}
void mergeFile()
{
    FILE *fs1, *fs2, *ft;
    char ch, file1[20], file2[20], file3[20];
    printf("Enter name of first file ");
    gets(file1);
    printf("Enter name of second file ");
    gets(file2);
    printf("Enter name of file which will store contents of two files ");
    gets(file3);
    fs1 = fopen(file1, "r");
    fs2 = fopen(file2, "r");
    if (fs1 == NULL || fs2 == NULL)
    {
        perror("Error ");
        printf("Press any key to exit...\n");
        getch();
        return 0;
    }
    ft = fopen(file3, "w");
    if (ft == NULL) // !=ft
    {
        perror("Error ");
        printf("Press any key to exit...\n");
        return 0;
    }
    while ((ch = fgetc(fs1)) != EOF)
        fputc(ch, ft); // end of file
    while ((ch = fgetc(fs2)) != EOF)
        fputc(ch, ft);
    printf("Two files were merged into %s file successfully.\n", file3);
    fclose(fs1);
    fclose(fs2);
    fclose(ft);
}
// su dung thu vien dirent.h de truy cap vao current folder
void list(){
	fflush(stdin);
	DIR *f;
	struct dirent *dir;
	f= opendir(".");
	while ((dir= readdir(f))!= NULL){
		printf("%s\n", dir->d_name); // su dung struct con tro.
	}
	closedir(f);	
}
// dung ham remove de xoa file va khong the truy cap file do nua
void deletedFile()
{
    FILE *F;
    char fn[100];
    int r;
    printf("Enter the name of file you wih to delete: ");
    gets(fn);
    F = fopen(fn, "w+");
    r = remove(fn);
    if (r == 0)
    {
        printf("\n%s file deleted successfully!!!", fn);
    }
    else
    {
        printf("\nCan not delete!!");
    }

}
int main()
{
    int choice;
    do
    {
        choice = drawMenu();
        switch (choice)
        {
        case 1:
            readfile();
            break;
        case 2:
            copyfile();
            break;
        case 3:
            mergeFile();
            break;
        case 4:
            list();
            break;
        case 5:
            deletedFile();
            break;
        default: printf("End program!!");
            getch();
            break;
        }
    } while (choice > 0 && choice < 6);
    getch();
    return 0;
}