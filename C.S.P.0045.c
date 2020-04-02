#include<stdio.h>
#include<string.h>
#include<conio.h>
int main(){
	int n;
	printf("\nEnter the value of n: ");
	scanf("%d",&n);
	char s[n][100], temp[n][100];
	printf("\nEnter %d name: \n",n);
	for(int i=0; i<n; i++){		
		scanf("%s",&s[i]);
	}
	printf("List input name: ");
	for(int j=0; j<n; j++){
		printf("\n%d. ",j+1);
		printf("%s",s[j]);	
	}	
	printf("List sort name: ");
	for(int i=0; i<n-1; i++){
		for(int j=n-1; j>i; j--){
			if(strcmp(s[i],s[j])>0){
				strcpy(temp[i],s[i]);
				strcpy(s[i],s[j]);
				strcpy(s[j],temp[i]);
			}	
		}	
	}	
	for(int i=0; i<n; i++){
		printf("\n%d. ",i+1);
		printf("%s",s[i]);
		}
    getch();
	return 0;
}