<<<<<<< HEAD
#include <stdio.h>
#include <string.h>
#include <conio.h>
 
int main() {
	char s[30], esc;
	int i, L;
	do{
		printf("Please enter string: ");
		gets(s);
        printf("The old string: %s\n",s);
        printf("The reversed string: ");
		L=strlen(s);
		for(i=L-1;i>=0;i--) {
			if(s[i]==' '){
				s[i]='\0';
				printf("%s ", &s[i]+1);
			}
		}
		printf("%s ", s);
		printf("\nPress enter to continue another reverse, ESC to exit :>!");
		esc=getch();
	} while(esc!=27);
	return 0;
}
=======
#include <stdio.h>
#include <string.h>
#include <conio.h>
 
int main() {
	char s[30], esc;
	int i, L;
	do{
		printf("Please enter string: "); // enter string
		gets(s);
		printf("The old string: %s\n",s);
		printf("The reversed string: ");
		L=strlen(s);
		// reverse string
		for(i=L-1;i>=0;i--) {
			if(s[i]==' '){
				s[i]='\0';
				printf("%s ", &s[i]+1);
			}
		}
		//outcome
		printf("%s ", s);
		printf("\nPress enter to continue another reverse, ESC to exit :>!");
		esc=getch();
	} while(esc!=27);
	return 0;
}
>>>>>>> 1270a740864df7137ede6b0d00260f857d1ffc42
