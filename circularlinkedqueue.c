#include<stdio.h>
#include<malloc.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node *front = NULL;
node *rear = NULL;

void enqueue(int val){
	node *t = (node *)malloc(sizeof(node));
	t->data=val;
	t->next=NULL;
	
	if(front==NULL && rear==NULL){
		front=rear=t;
		t->next=front;
	}
	
	else{
		rear->next=t;
		rear=t;
		rear->next=front;
	}
	printf("Inserted in Circular Linked Queue Sucessfully.\n");
}


void dequeue(){
	
	if(front==NULL && rear==NULL){
		printf("Circular Linked Queue is Empty.\n");
		return;
	}
	
	if(front->next==front){
		printf("%d is dequeued.\n",front->data);
		free(front);
		front=rear=NULL;
		return;
	}
	
	node *temp=front;
	printf("%d is dequeued.\n",temp->data);
	front=front->next;
	rear->next=front;
	free(temp);
}


void disp(){
	if(front==NULL && rear==NULL){
		printf("Circular Linked Queue is Empty.\n");
		return;
	}
	
	node *temp=front;
	do{
		printf("%d\t",temp->data);
		temp=temp->next;
	}while(temp!=front);
	printf("\n");
}


int main() {
    int ch, val;

    do {
        printf("\n--- Circular Linked Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                disp();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(ch != 4);

    return 0;
}



