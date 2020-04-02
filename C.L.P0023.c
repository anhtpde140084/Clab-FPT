#include <conio.h>
#include <stdio.h>
#include <string.h>

int menu()
{
    int choice;
    printf("1. strcat\n");
    printf("2. strcmp\n");
    printf("3. strcpy\n");
    printf("4. strncpy\n");
    printf("5. strnset\n");
    printf("6. strstr\n");
    printf("7. strchr\n");
    printf("Enter your choice: \n");
    scanf("%d", &choice);
    return choice;
}
void mystrcat()
{
    char str1[30], str2[30];
    printf("Nhap chuoi 1: ");
    gets(str1);
    printf("Nhap chuoi 2: ");
    gets(str2);
    printf("Chuoi sau khi noi la: %s %s", str1, str2);
}

void myStrcmp()
{
    char str1[30], str2[30];
    printf("Nhap chuoi 1: ");
    gets(str1);
    printf("Nhap chuoi 2: ");
    gets(str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if ((len1 - len2) > 0)
        printf("Chuoi 2 ngan hon chuoi 1");
    if ((len1 - len2) < 0)
        printf("Chuoi 1 ngan hon chuoi 2");
    if (len1 - len2 == 0)
        printf("chuoi 1 bang chuoi 2");
}
void mycopy()
{
    char source[30], target[30];
    int j = 0;
    printf("Nhap chuoi: ");
    gets(source);
    do
    {
        target[j] = source[j];
        j++;
    } while (source[j] != 0);
    printf("Chuoi sau khi copy la: ");
    printf("%s", target);
}
void mystrncpy()
{
    char str1[30], str2[30];
    int n;
    printf("Nhap chuoi : ");
    gets(str1);
    printf("Nhap so ky tu muon copy: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        str2[i] = str1[i];
    }
    str1[n] = '\0';
    printf("Sau khi copy ky tu: ");
    printf(str2);
}
void mystrset()
{
    char str[30], kytu;
    int n;
    printf("Nhap chuoi: ");
    gets(str);
    printf("Nhap ky tu: ");
    scanf("%c", &kytu);
    printf("Nhap so luong muon thay the: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        str[i] = kytu;
    }
    printf(str);
}
void mystrstr()
{
    char str1[100], str2[100];
    int kt, vitri;
    printf("Nhap chuoi 1: ");
    gets(str1);
    printf("Nhap chuoi con can tim: ");
    gets(str2);
    for (int i = 0; i < strlen(str1); i++)
    {
        kt = 1;
        if (str1[i] == str2[0])
        {
            for (int j = i; j < strlen(str2); j++)
            {
                if (str1[j] != str2[j])
                {
                    kt = 0;
                    break;
                }
            }
            if (kt == 1)
            {
                vitri = i;
                printf("Ket qua: ");
                for (int k = vitri; k < strlen(str1); k++)
                {
                    printf("%c", str1[k]);
                }
                return;
            }
        }
    }
    printf("Ket qua: ");
    printf("(Null)");
}

void mystrchr()
{
    char str1[100], kytu;
    int kt, vitri;
    printf("Nhap chuoi 1: ");
    gets(str1);
    printf("Nhap ky tu: ");
    scanf("%c", &kytu);
    for (int i = 0; i < strlen(str1); i++)
    {
        if (str1[i] == kytu)
        {
            for (int j = i; j < strlen(str1); j++)
            {
                printf("%c", str1[j]);
            }
            return;
        }
    }
    printf("Ket qua: ");
    printf("(Null)");
}
int main()
{
    int choice;
    do
    {
        choice = menu();
        switch (choice)
        {
        case 1:
            mystrcat();
            break;
        case 2:
            myStrcmp();
            ;
            break;
        case 3:
            mycopy();
            break;
        case 4:
            mystrncpy();
            break;
        case 5:
            mystrset();
            break;
        case 6:
            mystrstr();
            break;
        case 7:
            mystrchr();
            break;

        default:
            break;
        }
    } while (choice != 8);

    // mystrcat();
    // myStrcmp();
    //mycopy();
    // mystrncpy();
    mystrset();
    getch();
    return 0;
}
