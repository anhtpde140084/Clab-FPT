#include <stdio.h>
#include <string.h>
 
int main()
{
  	char str[100];
  	int i;
  	
  	int freq[26] = {0}; 
 
  	printf("\n Please Enter any String :  ");
  	gets(str);
  	
  	for(i = 0; str[i] != '\0'; i++)
  	{
  		if(str[i] >= 'a' && str[i] <= 'z')
  		{
  			freq[str[i] - 'a']++;
		}
  		else if(str[i] >= 'A' && str[i] <= 'Z')
  		{
  			freq[str[i] - 'A']++;
		}
	}
  		
  	for(i = 0; i < 26; i++)
  	{
		if(freq[i] != 0)
		{
			printf("Character '%c' Occurs %d Times \n", i+'a', freq[i]);
		}
	}
	getch();
  	return 0;
}