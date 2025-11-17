#include<stdio.h>
#include<malloc.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node *head = NULL;

void deleteBeginning(){
	if(head==NULL){
		printf("List is empty!Nothing to Delete");
		return;
	}
	node *temp=head;
	head=head->next;
	printf("%d Deleted from beginning.\n",temp->data);
	free(temp);
}

void deleteEnd(){
	if(head==NULL){
		printf("List is empty!Nothing to Delete");
		return;
	}
	if(head->next==NULL){
		printf("Deleted %d from end.\n",head->data);
		free(head);
		head=NULL;
		return;
	}
	
	node *temp=head;
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	printf("Deleted %d from end.\n", temp->next->data);
	free(temp->next);
	temp->next=NULL;
}



void deleteElement(int key){
	if(head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    
    if(head->data==key){
    	node *temp=head;
    	head=head->next;
    	printf("Deleted %d from the list\n",temp->data);
    	free(temp);
    	return;
	}
	
	node *temp=head;
	while(temp->next!=NULL && temp->next->data!=key){
		temp=temp->next;
	}
	
	if(temp->next==NULL){
		printf("Element %d not found in the list.\n",key);
		return;
	}
	node *del = temp->next;
	temp->next = del->next;
	printf("Deleted %d from the list.\n",key);
	free(del);
}

void insertAtEnd(int val){
    node *t = (node*)malloc(sizeof(node));
    t->data = val;
    t->next = NULL;

    if(head == NULL){
        head = t;
    } else {
        node *temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = t;
    }
}

void disp() {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }
    node *t;
    for(t = head; t != NULL; t = t->next) {
        printf("%d\t", t->data);
    }
    printf("\n");
}




int main() {
    /*int ch, val;

    do {
        printf("\n--- Linked List Deletion Menu ---\n");
        printf("1. Delete from Beginning\n");
        printf("2. Delete from End\n");
        printf("3. Delete a Specific Element\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                deleteBeginning();
                break;
            case 2:
                deleteEnd();
                break;
            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &val);
                deleteElement(val);
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
    } while(ch != 5);*/
    insertAtEnd(10);
	insertAtEnd(20);
	insertAtEnd(30);
	disp(); // 10 20 30
	deleteBeginning();
	disp(); // 20 30
	deleteEnd();
	disp(); // 20
	deleteElement(20);
	disp(); // empty list

    return 0;
}
