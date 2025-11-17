#include<stdio.h>
#include<malloc.h>

typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
}node;

node *head=NULL;

void insertBeg(int val){
	node *t=(node *)malloc(sizeof(node));
	t->data=val;
	t->next=NULL;
	t->prev=NULL;
	
	if(head==NULL){
		head=t;
	}
	else{
		node *temp=head;
		head=t;
		head->next=temp;
		temp->prev=t;
	}
}

void insertatEnd(int val){
	node *t=(node *)malloc(sizeof(node));
	t->data=val;
	t->next=NULL;
	t->prev=NULL;
	
	
	if(head==NULL){
		head=t;
	}
	
	else{
		node *temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=t;
		t->prev=temp;
	}
	
}

void deleteBeg(){
	if(head==NULL){
		printf("The Double Linked list is Empty.");
		return;
	}
	
	node *temp=head;
	printf("The First node %d is deleted.\n",temp->data);
	if(head->next==NULL){
		head=NULL;
	}
	else{
		head=head->next;
		head->prev=NULL;
	}
	free(temp);
}


void deleteEnd(){
	if(head==NULL){
		printf("The Double Linked list is Empty.");
		return;
	}
	
	node *temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	
	if(temp->prev!=NULL){
		temp->prev->next=NULL;
	}
	else{
		head=NULL;
	}
	printf("%d is deleted at the end",temp->data);
	free(temp);
}



void dispForward(){
	if(head==NULL){
		printf("The Double Linked list is Empty.");
		return;
	}
	
	node *temp=head;
	printf("\nForward: ");
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}


void dispBackward(){
	if(head==NULL){
		printf("The Double Linked list is Empty.");
		return;
	}
	
	node *temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	printf("\nBackwards: ");
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->prev;
	}
	printf("\n");
}

int main() {
    int ch, val;

    do {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display Forward\n");
        printf("6. Display Backward\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &val);
                insertBeg(val);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &val);
                insertatEnd(val);
                break;
            case 3:
                deleteBeg();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                dispForward();
                break;
            case 6:
                dispBackward();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(ch != 7);

    return 0;
}

