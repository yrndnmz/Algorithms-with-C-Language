#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

	struct node{
    int data;
    struct node * next;
    struct node * prev;
} * temp, * p,*newNode;
	struct node *head=NULL;
	struct node *last=NULL;
    void enqueue(int a);
    void show(struct node *temp);
    void Nonrecursive(struct node *temp);
    void Recursive(struct node *temp);

int main(){
    int n, i,choice,num;
    printf("how many nodes ?:");
    scanf("%d", &n);
    for (i = 0; i < n ; i++) { 
    	printf("Enter a value for node->data:");
    	scanf("%d", &num);
        enqueue(num); 
    } 
    show(head);
    printf("\n\n");
	printf("1.Recursive Selection Sort\n2.Nonrecursive Selection Sort");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
	if(choice==1){
		Recursive(head);
		show(head);	
	}
	else{
		Nonrecursive(head);
		show(head);
	}
	return 0;
}
void enqueue(int a){
	
	struct node *newNode;
    newNode= (struct node * ) malloc(sizeof(struct node));
    newNode->data=a;
	if(head==NULL){
		head=newNode;
		last=newNode;
		last->next=NULL;
	}else{
    	last->next=newNode;
    	newNode->next=NULL;
    	last=newNode;
	}
} 
void Recursive(struct node *temp){
	
    struct node*a=NULL, *b;
    if(b==NULL){
		return;
	}
    a=temp;
    b=temp;
    int sortValue;
    while(a->next!=NULL){
		if(a->data > (a->next)->data){
        	sortValue=a->data;
        	a->data=(a->next)->data;
        	(a->next)->data=sortValue;
    	}
        a=a->next;
    }
    b=b->next;
    Recursive(temp);
}

void Nonrecursive(struct node *temp){
  struct node*a=NULL;
  struct node*b=temp;
  int sortValue;
  while(b){
	    int sortValue;
        a=temp;
    	while(a->next!=NULL){
			if(a->data > (a->next)->data){
        		sortValue=a->data;
        		a->data=(a->next)->data;
        		(a->next)->data=sortValue;
    		}
      		a=a->next;
    	}
	b=b->next;
    }
}

void show(struct node *temp){
	while(temp){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
