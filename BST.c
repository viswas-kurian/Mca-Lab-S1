#include<stdio.h>
#include<malloc.h>

typedef struct node{
	int data;
	struct node *left,*right;
}node;

node *root = NULL;

node* insert(node *root,int val){
	if(root==NULL){
		node *t= (node *)malloc(sizeof(node));
		t->data=val;
		t->left=NULL;
		t->right=NULL;
		return t;
	}
	
	else if(val<root->data){
		root->left=insert(root->left,val);
	}
	else if(val>root->data){
		root->right=insert(root->right,val);
	}
	return root;
}



void inorder(node *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
	
}

void preorder(node *root){
	if(root!=NULL){
		printf("%d\t",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
	
void postorder(node *root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->data);
	}
}

int main() {
    node *root = NULL;   // start with an empty tree
    int choice, val;

    while (1) {
        printf("\n\n1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Inorder: ");
                inorder(root);
                break;
            case 3:
                printf("Preorder: ");
                preorder(root);
                break;
            case 4:
                printf("Postorder: ");
                postorder(root);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
