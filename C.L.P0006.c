#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void openpuz(char s[]){
	char line[50], gline[50], g, alr[20];
	int ktr=0, status=0, dem=0, fault=0;
	FILE *op;
	op=fopen(s,"r");
	again:
	while(!feof(op)) 
	{	
		fscanf(op,"%s",line);	
		int len = strlen(line);
		for(int i=0; i<len; i++){
		gline[i]='-';
	}
	printf("\n%s",gline);
	check:
	printf("\nPlease enter your guess:\n");
	getchar();
	scanf("%c",&g);
	for(int j=0; j<len; j++)
		{
		if((g==line[j]) && (alr[j]!= g))
			{
			gline[j]=line[j];		
			dem++;
			ktr=1;
			alr[j]=g;
			}
		}
		if (ktr!=1){			
			printf("\nYou're wrong.\n"); 
			fault++;
			 printf("\nYou currently have %d incorrect guesses.\n", fault);
			}
			ktr=0;
		if(fault==5){
		   	 printf("\nGamover!"); 
		   	 printf("\nThe correct word is %s",line);
		   	 printf("\nThanks for playing!");
		   	 break;
		}else{
		printf("%s",gline);
		}
		if(dem==len){
			printf("\nChucMung!");
			fault=0;
			goto again;
		}else{
			goto check;	
		}
	}
	fclose(op);
}
int main(){
	char s[100], opt;
	int fault=0;
	printf("What is the file store the puzzle words? \n");
	gets(s);
	printf("\nWould you like to play hangman? (Y/N)\t");
	scanf("%c",&opt);
	switch(opt){
		case 'n': 	printf("\nExited.");
		 	 		printf("\nThanks for playing!");
					break;
		case 'y':   printf("\nYou currently have %d incorrect guesses.", fault);
					printf("\nHere is your puzzle: \n");
					openpuz(s);
					break;
		default: 
					printf("\nPlease choose the right option.");	
					printf("\nPress Enter to continue or ESC to exit.");			
	}
	getch();
	return 0;
}