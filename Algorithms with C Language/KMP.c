#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void KMPSearch(int A[],int n,int B[],int m){
	int i = 0; 
    int j = 0; 
    while (i < n) { 
        if (A[i] == B[j]) { 
            j++; 
            i++; 
        } 
  
        if (j == m) { 
            printf("Found pattern at index %d \n", i - j); 
            j = 0;
        } 
       //hala textimin uzunluðunu geçmediyse ilk ifteki ai bj eþit deðilse 
        else if (i < n && A[i] != B[j]) {  
           
            if (j != 0) 
                j = 0;
            else
                i = i + 1; 
        } 
    } 
} 
int main(){
	int a,b,n,m;
	printf("Enter the length of A string : ");
	scanf("%d",&n);
	int A[n];
	printf("Enter the length of B string : ");
	scanf("%d",&m);
	int B[m];
	srand(time(NULL));
	for(a=0; a<n; a++){
		A[a]=rand() % 2;
	}
	printf("A= ");
	for(a=0; a<n; a++){
		printf("%d",A[a]);
	}
	printf("\n");
	for(b=0; b<m; b++){
		B[b]=rand() % 2;
	}
	printf("B= ");
	for(b=0; b<m; b++){
		printf("%d",B[b]);
	}
	printf("\n");
	KMPSearch(A,n,B,m);
	return 0;	
}



