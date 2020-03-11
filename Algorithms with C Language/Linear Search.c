#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

/* Structure of a node */
struct node {
    int data;          // Data 
    struct node *next; // Address 
}*newNode, *head;
void createList(int n);
void reclinearsearch(int item);

int main()
{
    int i,n, data, item;
    printf("Enter the total number of nodes: "); //Create a linked list
    scanf("%d", &n);
    createList(n);
    printf("Enter the value to search in the list: "); 
    scanf("%d", &item);
    reclinearsearch(item);
    return 0;
}

void createList(int n) //Create a list of n nodes
{
    struct node *newNode, *temp;
    int data, i;
    head = (struct node *)malloc(sizeof(struct node));
    
    if(head == NULL) //unable to allocate memory
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter the data of node 1: "); //Input data of node from the user
        scanf("%d", &data);

        head->data = data; // Link data field with data
        head->next = NULL; // Link address field to NULL

        temp = head;

        for(i=2; i<=n; i++) //Create n nodes and adds to linked list
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            if(newNode == NULL) //memory is not allocated for newNode
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data; // Link data field of newNode with data
                newNode->next = NULL; // Link address field of newNode with NULL

                temp->next = newNode; // Link previous node i.e. temp to the newNode
                temp = temp->next; 
            }
        }
    }
}

void reclinearsearch(int item)
{
	int count=1,x;
	newNode=head;
	while(newNode->next!=NULL)
	{
		if(newNode->data==item){
			while(head!=NULL){
				for(count=1;count<=head->data;count++){
    				if(head->data%count==0){
    					printf("%d ",count);
					}
				}
				head=head->next;
				printf("\n");
			}
			x=1;
			break;
		}
		else{
			count++;
			newNode=newNode->next;
		}		
	}
	if(x!=1){
		printf("Searching value didn't find");
	}
}
 
