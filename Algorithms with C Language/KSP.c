#include<stdio.h>
int max(int a, int b) { return (a > b)? a : b; }

int Knapsack(int W[], int V[], int n, int K){
    
    if(K==0||n==0)
        return 0;
        
   
    if(W[n-1]>K) // weight kyý geçiyorsa bir önceki elemana bak.
        return Knapsack(W,V,n-1,K);
 
    
    return max(Knapsack(W,V,n-1,K),V[n-1]+Knapsack(W,V,n-1,K-W[n-1])); //aldýðým elemanla baþka hangi elemanlarý alýrým. aldýðým V + kalanlarýn içinden V
}
int main(){
    int i, W[5], V[5], K;
    
    printf("Enter size of knapsack between 5 and 25:\n");
    scanf("%d", &K);
    
    printf("Enter value of 5 items between 1 and 25:\n");
    for(i = 0;i < 5; ++i){
    	scanf("%d", &V[i]);
    }
    printf("Enter weight of 5 items between 1 and %d:\n", K);
    for(i = 0;i < 5; ++i){
    	scanf("%d", &W[i]);
    }
 
    printf("The total value is %d", Knapsack(W, V, 5,K));
    return 0;
}
