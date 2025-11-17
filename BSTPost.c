#include <stdio.h>
#include <malloc.h>

typedef struct node {
    int data;
    struct node *left, *right;
} node;

node *root = NULL;

node* insert(node *root, int val) {
    if (root == NULL) {
        node *t = (node *)malloc(sizeof(node));
        t->data = val;
        t->left = t->right = NULL;
        return t;
    }
    else if (val < root->data) {
        root->left = insert(root->left, val);
    }
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

void postorderIterative(node *root) {
	
	node *stack1[100],*stack2[100];
	int top1=-1,top2=-1;
	
	stack1[++top1]=root;
	
	while(top1!=-1){
		node *curr = stack1[top1--];
		stack2[++top2]=curr;
		
		if(curr->left){
			stack1[++top1]=curr->left;
		}
		if(curr->right){
			stack1[++top1]=curr->right;
		}
	}
	while(top2!=-1){
		printf("%d\t",stack2[top2--]->data);
	}
	
}

int main() {
    int choice, val;

    while (1) {
        printf("\n\n===== Binary Search Tree Menu =====\n");
        printf("1. Insert\n");
        printf("2. Postorder Traversal (Iterative)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;

            case 2:
                printf("Postorder traversal: ");
                postorderIterative(root);
                printf("\n");
                break;

            case 3:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
