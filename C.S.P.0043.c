#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void add(int a[], int i){
	printf("\nEnter a value: ");
	scanf("%d",&a[i]);
	i++;
}
void index(int a[], int i){
	int id, kt=0;
	printf("\nEnter a value: ");
	scanf("%d",&id);
	for(int i=0; i<sizeof(a);i++){
		if(id==a[i]){
			printf("\nIts index is: %d\t",i);
			kt=1;
		}
	}
	if(kt==0){
		printf("\nNo Data Found.");
	}
}
void rem(int a[], int i){
	int pos;
	printf("\nInput an integer you wanna remove: ");
	scanf("%d",&pos);
	for(int k=0; k<i; k++){
		if(pos==a[k]){ 
			a[k]=a[k+1];
			i--;
		break;
		}
	}
}
void Revall(int a[], int i){
	int pos;
	int k;
	printf("\nInput an integer you wanna remove: ");
	scanf("%d",&pos);
	for(k=0; k<i; k++){
		if(pos==a[k]){ 
			i--;
			a[k]=a[k+1];
			k=0;
		}	
	}
}
void Printo(int a[],int i){
	printf("\nValues in array: ");
	for(int j=0; j<i; j++){
		printf("\t%d",a[j]);
	}
}
void Sorta(int a[], int i){
	int temp=0;
	for(int g=0; g<i;g++){
		for(int j=i;j>g;j--){
			if(a[j]<a[j-1]){
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}
		}
	}
	for(int h=0; h<i; h++){
		printf("\t%d",a[h]);
	}
}
void Sortd(int a[], int i){
	int temp=0;
	for(int g=0; g<i; g++){
		for(int j=i; j>g; j--){
			if(a[j]>a[j-1]){
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}
		}
	}
	for(int l=1; l<i+1; l++){
		printf("\t%d",a[l]);
	}
}
int main(){
	int opt;
	int i=0;
	int a[100];
	do{
	printf("\n1. Add a value");
	printf("\n2. Search a value");
	printf("\n3. Remove the first existence of a value");
	printf("\n4. Remove all existences of a value");
	printf("\n5. Print out the array ");
	printf("\n6. Sort the array in ascending order (positions of elements are preserved)");
	printf("\n7. Sort the array in descending order (positions of elements are preserved)");
	printf("\n8. Quit\n");
	scanf("%d",&opt);
	switch(opt){
		case 1: add(a,i);
				break;
		case 2: index(a,i);
				break;
		case 3: rem(a,i);
				break;
		case 4: Revall(a,i);
				break;
		case 5: Printo(a,i);
				break;
		case 6: Sorta(a,i);
				break;
		case 7: Sortd(a,i);
				break;
        default: printf("\nExited.\n");
        break;
		}
	}while(opt>0&&opt<8);
	
    getch();
	return 0;
}