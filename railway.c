#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct node{
	char name[50];
	int age;
	int seatno;
	struct node *next;
}node;

node *head=NULL;

node* createNode(char name[],int age,int seatno){
	node *t = (node *)malloc(sizeof(node));
	strcpy(t->name,name);
	t->age=age;
	t->seatno=seatno;
	t->next=NULL;
	return t;
}

void insert(char name[],int age,int seatno){
	node *t = createNode(name,age,seatno);
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
	printf("Passenger Booked Successfully.\n");
}

void delete1(int seatno){
	node *temp=head;
	node *prev = NULL;
	if(head==NULL){
		printf("No Passengers to Delete.\n");
		return;
	}
	
	if(head->seatno==seatno){
		head=head->next;
		free(temp);
		printf("Delete Passenger with seatno %d.\n",seatno);
		return;
	}
	else{
		while(temp!=NULL && temp->seatno!=seatno){
			prev=temp;
			temp=temp->next;
		}
		if(temp==NULL){
			printf("Seat %d not found",seatno);
			free(temp);
		}
		prev->next=temp->next;
		free(temp);
		printf("Passenger with seat %d cancelled.",seatno);
	}
}



void disp(){
	if(head==NULL){
		printf("List is Empty.\n");
	}
	else{
		node *temp=head;
		printf("\nThe Passenger List is: \n");
		printf("\nSeat No\tName\tAge\t\n");
		while(temp!=NULL){
			printf("%d\t%s\t%d\n",temp->seatno,temp->name,temp->age);
			temp=temp->next;
		}
	}
}


int main(){
    int choice, age, seatno;
    char name[50];

    do {
        printf("\n===== Train Reservation System =====\n");
        printf("1. Book Ticket\n");
        printf("2. Cancel Ticket\n");
        printf("3. Display Passengers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter name: ");
                scanf(" %[^\n]s", name);  // read full line with spaces
                printf("Enter age: ");
                scanf("%d", &age);
                printf("Enter seat number: ");
                scanf("%d", &seatno);
                insert(name, age, seatno);
                break;

            case 2:
                printf("Enter seat number to cancel: ");
                scanf("%d", &seatno);
                delete1(seatno);
                break;

            case 3:
                disp();
                break;

            case 4:
                printf("Exiting system...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 4);

    return 0;
}
