#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};

typedef struct node node;
node *head = NULL;

void insert(int a){
	node *t;
	if(head==NULL){
		head=(node *)malloc(sizeof(node));
		head->data=a;
		head->next=NULL;
	}
	else{
		t=head;
		while(t->next!=NULL){
			t=t->next;
		}
		t->next=(node *)malloc(sizeof(node));
		t->next->data=a;
		t->next->next=NULL;
	}
}

void disp(){
	node *t;
	for(t=head;t!=NULL;t=t->next){
		printf("%d\t",t->data);
	}
}

int main(){
	insert(100);
	insert(-15);
	insert(300);
	disp();
	return 0;
}
