
#include <bits/stdc++.h> 
using namespace std; 
int bookDays(int* A,int n)
{  	
	float R1,R2; 
	int s=0,cot=0,s1=0;
	for (int i = 0; i <=n; i++) { 	
		for (int j = i; j <i+1; j++) {
			s=s+A[i];
			s1=s+A[i];
			R1 = s /(float)(j+1); 
			R2 = s1 /(float)(j+2);	
			if(R1<R2)
			cot+=1;	
		} 	
	}
    return cot;
}
int main() { 
	int A[] = {212,43,512,905,988,349,103,570,986,430,878,634,186,488,959}; 
	int n = sizeof(A)/sizeof(A[0]); 
	cout <<	bookDays(A,n); 
	return 0; 
} 
