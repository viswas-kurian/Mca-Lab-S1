#include<stdio.h>
#include<malloc.h>

typedef struct node{
	int coeff;
	int pow;
	struct node *next;
}node;

node *head1=NULL;
node *head2=NULL;
node *headProd=NULL;

node* createNode(int coeff,int pow){
	node *t= (node *)malloc(sizeof(node));
	t->coeff=coeff;
	t->pow=pow;
	t->next=NULL;
	return t;
}

void insert1(int coeff,int pow){
	node *t = createNode(coeff,pow);
	if(head1==NULL){
		head1=t;
	}
	
	else{
		node *temp = head1;
		while(temp->next!=NULL){
			temp = temp->next;
		}
	temp->next=t;
	}	
}

void insert2(int coeff,int pow){
	node *t = createNode(coeff,pow);
	if(head2==NULL){
		head2=t;
	}
	
	else{
		node *temp = head2;
		while(temp->next!=NULL){
			temp = temp->next;
		}
	temp->next=t;
	}	
}

void insertProd(int coeff,int pow){
	if (coeff==0) return;
	
	node *temp=headProd;
	node *prev=NULL;
	
	while(temp!=NULL){
		if(temp->pow==pow){
			temp->coeff+=coeff;
			return;
		}
		prev = temp;
		temp=temp->next;
	}
	node *newNode=createNode(coeff,pow);
	if(headProd==NULL){
		headProd=newNode;
	}
	else{
		prev->next=newNode;
	}
}

void disp(node *head){
	node *temp=head;
	while(temp!=NULL){
		printf("%dx^%d",temp->coeff,temp->pow);
		if(temp->next!=NULL){
			printf(" + ");
		}
		temp=temp->next;
	}
	printf("\n");
}


void mulPoly(){
	node *p1=head1;
	while(p1!=NULL){
		node *p2=head2;
		while(p2!=NULL){
			insertProd(p1->coeff * p2->coeff,p1->pow + p2->pow);
			p2=p2->next;
		}
		p1=p1->next;
	}
}

int main(){
	int n,coeff,pow,i;
	
	printf("Enter number of terms in Polynomial 1: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter coefficient and power: ");
        scanf("%d%d", &coeff, &pow);
        insert1(coeff, pow);
    }
    
    printf("Enter number of terms in Polynomial 2: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter coefficient and power: ");
        scanf("%d%d", &coeff, &pow);
        insert2(coeff, pow);
    }
    
    
    printf("\nPolynomial 1: ");
    disp(head1);
    
    printf("\nPolynomial 2: ");
    disp(head2);
    
    mulPoly();
    
    printf("\nSum: ");
    disp(headProd);
    
    return 0;
}


