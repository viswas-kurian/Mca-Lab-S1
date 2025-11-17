#include<stdio.h>
#include<malloc.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node *head = NULL;

void insertBeg(int val){
	node *t=(node *)malloc(sizeof(node));
	t->data=val;
	t->next=NULL;
	
	if(head==NULL){
		head=t;
		t->next=head;
	}
	else{
		node *temp=head;
		node *last=head;
		while(last->next!=head){
			last=last->next;
		}
		head=t;
		t->next=temp;
		last->next=head;
	}
	printf("Inserted %d at the beginning.\n",val);
}

void insertEnd(int val){
	node *t=(node *)malloc(sizeof(node));
	t->data=val;
	t->next=NULL;
	
	if(head==NULL){
		head=t;
		t->next=head;
	}
	else{
		node *temp=head;
		while(temp->next!=head){
			temp=temp->next;
		}
		temp->next=t;
		t->next=head;
	}
}

void deleteElement(){
	if(head==NULL){
		printf("Circular Linked List is Empty\n");
		return;
	}
	
	if(head->next == head){
		printf("Deleted Element is %d\n", head->data);
    	free(head);
    	head = NULL;
    	return;
	}

	node *temp=head;
	node *lastnode=head;
	printf("Deleted Element at first node is %d.\n",temp->data);
	while(lastnode->next!=head){
		lastnode = lastnode->next;
	}
	head=head->next;
	lastnode->next=head;
	free(temp);
}

void disp(){
	if(head==NULL){
		printf("Circular Linked List is Empty\n");
		return;
	}
	
	node *temp=head;
	do{
		printf("%d\t",temp->data);
		temp=temp->next;
	}while(temp!=head);
	printf("\n");
}

int main() {
	int ch, val;
	do {
		printf("\n--- Circular Linked List Menu ---\n");
		printf("1. Insert at Beginning\n");
		printf("2. Insert at End\n");
		printf("3. Delete First Element\n");
		printf("4. Display List\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		
		switch(ch){
			case 1:
				printf("Enter value to insert at beginning: ");
				scanf("%d", &val);
				insertBeg(val);
				break;
			case 2:
				printf("Enter value to insert at end: ");
				scanf("%d", &val);
				insertEnd(val);
				break;
			case 3:
				deleteElement();
				break;
			case 4:
				disp();
				break;
			case 5:
				printf("Exiting...\n");
				break;
			default:
				printf("Invalid choice! Try again.\n");
		}
	} while(ch != 5);
	
	return 0;
}

