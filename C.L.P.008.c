#include <conio.h>
#include <stdio.h>
#include <string.h>

int notAllow(char mess[][100], int sotu, char tucam[][100], int SLtucam)
{
    for (int i = 0; i < sotu; i++)
    {
        for (int j = 0; j < SLtucam; j++)
        {
            if (strcasecmp(mess[i], tucam[j]) == 0)
            {
                return 1;
            }
        } /* code */
    }
    return 0;
}

int chinhta(char word[100], char dic[][100], int SLtudien)
{
    for (int i = 0; i < SLtudien; i++)
    {
        if (strcasecmp(word, dic[i]) == 0)
        {
            return 0;
        }
    }
    return 1;
}

int sai3tu(char mess[][100], int sotu, char dic[][100], int SLtudien)
{
    int count = 0;
    for (int i = 0; i < sotu; i++)
    {
        if (chinhta(mess[i], dic, SLtudien) == 1)
        {
            count++;
            if (count > 2)
            {
                return 1;
            }
        }
    }
    return 0;
}

int Messenger(char mess[][100], int sotu)
{
    int count = 0;
    for (int i = 0; i < sotu; i++)
    {
        switch (count)
        {
        case 0:
            if (strcasecmp(mess[i], "I") == 0)
            {
                count++;
            }
            break;
        case 1:
            if (strcasecmp(mess[i], "love") == 0)
            {
                count++;
            }
            else
            {
                count = 0;
            }

            break;
        case 2:
            if (strcasecmp(mess[i], "you") == 0)
            {
                return 1;
            }
            else
            {
                count = 0;
            }
            break;
        default:
            break;
        }
    }
    return 0;
}

int Cam(int Time, char mess[][100], int SoTu, char TuDien[][100], int SLTuDien, char TuCam[][100], int SLTuCam) {
    if (Time> 6) {
        return 0;
    }
    if (notAllow(mess, SoTu, TuCam, SLTuCam) == 1) {
        return 1;
    }
    if (sai3tu(mess, SoTu, TuDien, SLTuDien) == 1) {
        return 1;
    }
    if (Messenger(mess, SoTu) == 1) {
        return 1;
    }
    return 0;
}

int main(){
    int SLTuDien;
    int SLTuCam;
    int SLmess;
    int SoTu;
    FILE *f=fopen("textmsg.txt","r");
    if (f==NULL) printf("File is not exist");
    else
    {
        fscanf(f, "%d", &SLTuDien);
        char TuDien[SLTuDien][100];
        for (int i = 0; i < SLTuDien; i++) {
            fscanf(f, "%s", TuDien[i]);
        }
        fscanf(f, "%d", &SLTuCam);
        char TuCam[SLTuCam][100];
        for (int i = 0; i < SLTuCam; i++) {
            fscanf(f, "%s", TuCam[i]);
        }
        fscanf(f, "%d", &SLmess);
        int hour;
        int Time;
        int minute;
        char am_pm[2];
        for (int i = 0; i < SLmess; i++) {
            fscanf(f, "%d:%d", &hour, &minute);
            fscanf(f, "%s", am_pm);
            if(strcasecmp(am_pm, "AM") == 0) Time = hour;
			else Time = hour + 12;

            fscanf(f, "%d", &SoTu);
            char mess[SoTu][100];
            for (int j = 0; j < SoTu; j++) {
                fscanf(f, "%s", mess[j]);
            }
            printf("\nMessage #%d:", i + 1);
            if (Cam(Time, mess, SoTu, TuDien, SLTuDien, TuCam, SLTuCam) == 1) printf(" FAILED TO SEND!");
            else {
                for (int j = 0; j < SoTu; j++) {
                    printf(" %s", mess[j]);
                }
            }
        }
        fclose(f);
    }
    getch();
    return 0;
} 