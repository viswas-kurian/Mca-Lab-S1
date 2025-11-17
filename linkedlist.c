#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};

typedef struct node node;
node *head = NULL;

/*void insert(int a){
	node *t = (node *)malloc(sizeof(node));
	t->data=a;
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
}*/

void insert(int a){
	node *t = (node *)malloc(sizeof(node));
	t->data=a;
	t->next=NULL;
	
	if(head==NULL){
		head=t;
	}
	else{
		node *temp=head;
		head=t;
		head->next=temp;
	}
}

void deleteNode(int a){
	
	if(head==NULL){
		printf("Linked List is Empty.\n");
	}
	else if(head->data==a){
		head=head->next;
	}
	
	else{
		node *t = head;
		while(t->next!=NULL && t->next->data!=a){
			t=t->next;
		}
		if(t->next==NULL){
			printf("Element not Found");
		}
		else{
			t->next=t->next->next;
		}
	}
}

void disp(){
	node *t;
	for(t=head;t!=NULL;t=t->next){
		printf("%d\t",t->data);
	}
}

void sort(){
	node *i, *j;
	int temp;
	if(head==NULL || head->next == NULL)
		printf("\nNo elements");
	else{
		for(i=head;i!=NULL;i=i->next){
			for(j=i->next;j!=NULL;j=j->next){
				if(i->data > j->data){
					temp = i->data;
					i->data = j->data;
					j->data = temp;
				}	
			}
		}
		printf("\nList sorted");
	}
}

void count(){
	int count;
	node *temp=head;
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
		count++;
	}
	printf("\nTotal count is: %d",count);
}

void reverse(){
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next;   // store next node
        current->next = prev;   // reverse the link
        prev = current;         // move prev forward
        current = next;         // move current forward
    }

    head = prev;  // update head to new first node
    printf("List reversed successfully.\n");
}

void search(int a){
	node *t = head;
	int pos = 1;
	while(t != NULL){
		if(t->data == a){
			printf("The element found at position %d",pos);
			return;
		}
		t = t->next;
		pos++;
	}
	printf("\nElement %d not found in the list\n",a);
}

void find_replace(a){
	node *t = head;
	int f,r,flag=0;
	printf("Enter the element to find: ");
	scanf("%d",&f);
	printf("Enter the element to replace: ");
	scanf("%d",&r);
	while(t != NULL){
		if(t->data == f){
			t->data = r;
			flag=1;
		}
		t = t->next;
	}
	if(flag==1)
		printf("\nReplaced\n");
	else
		printf("\nElement not found\n");
}

int main(){
	int ch, val;
	printf("LINKED LIST\n");
	printf("-----------\n");
	do{
		printf("\nLinked List Menu");
		printf("\n1. Insert");
		printf("\n2. Delete");
		printf("\n3. Display");
		printf("\n4. Sort");
		printf("\n5. Count");
		printf("\n6. Reverse");
		printf("\n7. Search");
		printf("\n8. Find and Replace");
		printf("\n9. Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
				printf("\nEnter the element to insert: ");
				scanf("%d",&val);
				insert(val);
				break;
				
			case 2:
				printf("\nEnter the element to delete: ");
				scanf("%d",&val);
				deleteNode(val);
				break;
				
			case 3:
				disp();
				break;
				
			case 4:
				sort();
				break;
				
			case 5:
				count();
				break;
				
			case 6:
				reverse();
				break;
				
			case 7:
				printf("\nEnter element to search: ");
				scanf("%d",&val);
				search(val);
				break;
				
			case 8:
				find_replace();
				break;
				
			default:
				printf("\nInvalid choice");
		}
	}while(ch!=9);
	return 0;
}
