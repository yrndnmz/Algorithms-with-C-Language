#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

	struct node{
    int data;
    struct node * next;
} * temp;
	struct node *head=NULL;
	struct node *last=NULL;
    void push(int a);
    void show(struct node *temp);
    void Nonrecursive(struct node *temp);
    void Recursive(struct node *temp);

int main(){
    int n, i,choice,num ;
    printf("How many nodes ?:");
    scanf("%d", &n);
    for (i = 0; i < n ; i++) { 
    	printf("Enter a value for node->data:");
    	scanf("%d", & num);
        push(num); 
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
void push(int a){
	
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
	if(temp==NULL){
		return;
	}
	struct node*a=NULL,*b=NULL;
  	int sortValue;
  	
    a=temp;
    b=temp->next;
    
    while(b!=NULL){	
      if(b->data<a->data){
        a=b;
      }
      	b=b->next;
    }
    if(a!=temp){
      sortValue=a->data;
      a->data=temp->data;
      temp->data=sortValue;
    }
	Recursive(temp->next);
}

void Nonrecursive(struct node *temp){
	struct node*a=NULL,*b=NULL;
  	int sortValue;

  while(temp){
    a=temp;
    b=temp->next;
    
    while(b){
    	
      if(b->data<a->data){
        a=b;
      }
      	b=b->next;
    }

    if(a!=temp){
      sortValue=a->data;
      a->data=temp->data;
      temp->data=sortValue;
    }
    temp=temp->next;
  }
}

void show(struct node *temp){
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}











