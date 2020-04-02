#include<conio.h>
#include<stdio.h>

int main(){
    int a[100], i=0, n=0, max;
	printf("Enter the elements of array: \n");
	for(i=0; i<100; i++){
	scanf("%d",&a[i]);
	n++;
	if (a[i]==0){
		break;
	}}
	printf("\nArray elements: \n");
	for(int j=0; j<n; j++){
		if(a[j]!=0)
			printf("%d\t",a[j]);
	}max=a[0];
	for(i=0; i<n; i++){	
		if(max<a[i]) {
		max=a[i];
		}
	}
	printf("\nThe maximum element in the array: ");
    printf("\nThe max is %d", max);
	printf("\nEven elements: \n");
	for(i=0; i<n; i++){
		if((a[i]%2==0) && (a[i]!=0)) printf("%d\t",a[i]);
	}
	
    getch();
    return 0;
}