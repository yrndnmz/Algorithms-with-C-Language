#include<stdio.h>
#include<time.h>
 
int ary[50][50],visited[50],n,cost=0;
 
void mincost(int city){
	int i,ncity;
	visited[city]=1;
	printf("%d--->",city+1);
	ncity=least(city);
 
	if(ncity==450){
		ncity=0;
		printf("%d",ncity+1);
		cost+=ary[city][ncity];
		return;
	}
	mincost(ncity);
}
 
int least(int c){
	
	int i,nc=450;
	int min=450,kmin;
 
	for(i=0;i < n;i++){
		if((ary[c][i]!=0)&&(visited[i]==0)) //orda ba�lant� varsa ve o �ehre gidilmemi�se
			if(ary[c][i]+ary[i][c] < min){ //o �ehre gidi� geli� toplam� minden k���kse
				min=ary[i][0]+ary[c][i];
				kmin=ary[c][i]; //o �ehre olan uzakl�k
				nc=i; //se�ti�im citynin de�eri
			}
	}
	if(min!=450)
		cost+=kmin;
	return nc;
}
 
int main(){
	int i,j;
    srand(time(NULL));
	printf("Please Enter the number of villages between 3 and 50: ");
	scanf("%d",&n);
	for(i=0;i < n;i++){
		for( j=0;j < n;j++)
        ary[i][j]=rand()%9+1;
		visited[i]=0; //hen�z ziyaret edilen �ehir yok
	}
 
	printf("\n\nThe cost list is:");
	for( i=0;i < n;i++){
		printf("\n");
		for(j=0;j < n;j++)
			printf("\t%d",ary[i][j]);
	}
 
	printf("\n\nThe Path is:\n");
	mincost(0); //0 g�nderiyorum ��nk� ba�lang�� de�eri
 
	printf("\n\nMinimum cost is %d\n ",cost);
	return 0;
}
