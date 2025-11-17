#include<stdio.h>
#include<malloc.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node *front=NULL;
node *rear=NULL;

void linkedEnqueue(int val){
	node *t=(node *)malloc(sizeof(node));
	t->data = val;
	t->next = NULL;
	
	if(front==NULL && rear==NULL){
		front=rear=t;
	}
	else{
		rear->next=t;
		rear=t;	
	}
	printf("Enqueued %d to the Linked List.\n",val);
}

void linkedDequeue(){
	if(front==NULL && rear==NULL){
		printf("The Queue is Empty.\n");
		return;
	}
	
	node *temp=front;
	printf("\n%d is Popped.\n",temp->data);
	front=front->next;
	free(temp);
}

void disp(){
	node *temp=front;
	printf("\nThe Elements in the queue are: \n");
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}


int main(){
	linkedEnqueue(20);
	linkedEnqueue(45);
	linkedEnqueue(55);
	linkedEnqueue(60);
	disp();
	linkedDequeue();
	disp();
	
}







