#include<stdio.h>
#include<malloc.h>

typedef struct node{
	int data;
	struct node *next;
}node;


node *top = NULL;

void linkedPush(int val){
	node *t=(node *)malloc(sizeof(node));
	t->data=val;
	t->next=NULL;
	
	if(top==NULL){
		top=t;
	}
	else{
		node *temp=top;
		top=t;
		t->next=temp;
	}
	printf("Element %d Pushed into Stack.\n",val);
}

void linkedPop(){
	if(top==NULL){
		printf("Linked Stack is Empty.");
		return;
	}
	node *temp=top;
	printf("\nPopped Element is %d.\n",temp->data);
	top=top->next;
	free(temp);
}

void disp(){
	if(top==NULL){
		printf("Linked Stack is Empty.");
		return;
	}
	node *temp=top;
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	
}


int main(){
	linkedPush(20);
	linkedPush(30);
	linkedPush(40);
	disp();
	linkedPop();
	disp();
	
	return 0;
	
}
