
#include <bits/stdc++.h> 
using namespace std; 

void rankify(int* A , int n) { 
	int cot=0;
	float R1,R2; 
	int s=0;
	int s1=0;
	for (int i = 0; i < n; i++) { 
		
		for (int j = i; j <i+1; j++) {
			s=s+A[i];
			s1=s+A[i];
			R1 = s /(float)(j+1); 
			R2 = s1 /(float)(j+2);
			if(R1<R2)
			cot++;		
		} 
	}
		cout << cot<< ' '; 

	} 
int main() { 
	int A[] = {67,816,150,217,801,565,876,475,213,297}; 
	int n = sizeof(A) / sizeof(A[0]); 
	for (int i = 0; i < n; i++) 
	cout << A[i] << ' '; 
	cout << '\n'; 
	
	rankify(A, n); 
	
	return 0; 
} 

// This code is contributed by Gitanjali. 

