#include<stdio.h>
#include<malloc.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node *head = NULL;

void insertAtBeginning(int val){
	node *t = (node *)malloc(sizeof(node));
	t->data=val;
	t->next=head;
	head=t;
	printf("\nInserted at the beginning.\n");
}

void insertAtEnd(int val){
	node *t = (node *)malloc(sizeof(node));
	t->data=val;
	t->next=NULL;
	
	if(head==NULL){
		head=t;
	}
	else{
		node *temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=t;
	}
	printf("Inserted at the end");
}

void insertAfterElement(int key,int val){
	node *temp=head;
	while(temp!=NULL && temp->data!=key){
		temp=temp->next;
	}
	
	if(temp==NULL){
		printf("Element %d not found!\n.",key);
		return;
	}
	
	node *t = (node *)malloc(sizeof(node));
	t->data=val;
	t->next=temp->next;
	temp->next=t;
	printf("Inserted %d after %d.\n",val,key);
}



void disp(){
	node *t;
	if(head==NULL){
		printf("\nLinked List is Empty\n");
		return;
	}
	for(t=head;t!=NULL;t=t->next){
		printf("%d\t",t->data);
	}
	printf("\n");
}




int main() {
    int ch, val, key;

    do {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert after Element\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertAtBeginning(val);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertAtEnd(val);
                break;
            case 3:
                printf("Enter the element after which to insert: ");
                scanf("%d", &key);
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertAfterElement(key, val);
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





