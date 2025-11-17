#include<stdio.h>
#include<malloc.h>

typedef struct node{
	int coeff;
	int pow;
	struct node *next;
}node;

node *head1=NULL;
node *head2=NULL;
node *headSum=NULL;

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

void insertSum(int coeff,int pow){
	node *t= createNode(coeff,pow);
	if(headSum==NULL){
		headSum=t;
	}
	else{
		node *temp=headSum;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=t;
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


void addPoly(){
	node *p1=head1;
	node *p2=head2;
	
	while(p1!=NULL && p2!=NULL){
		if(p1->pow == p2->pow){
			insertSum(p1->coeff + p2->coeff,p1->pow);
			p1=p1->next;
			p2=p2->next;
		}
		else if(p1->pow>p2->pow){
			insertSum(p1->coeff,p1->pow);
			p1 = p1->next;
		}
		else if(p2->pow>p1->pow){
			insertSum(p2->coeff,p2->pow);
			p2 = p2->next;
		}
	}
	while(p1!=NULL){
		insertSum(p1->coeff,p1->pow);
		p1 = p1->next;
	}
	while(p2!=NULL){
		insertSum(p2->coeff,p2->pow);
		p2 = p2->next;
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
    
    addPoly();
    
    printf("\nSum: ");
    disp(headSum);
    
    return 0;
}


