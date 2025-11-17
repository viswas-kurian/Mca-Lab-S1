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

void preorderIterative(node *root) {
    node *stack[100];
    int top = -1;
    stack[++top]=root;
    
    while(top!=-1){
    	node *curr= stack[top--];
    	printf("%d\t",curr->data);
    	
    	if(curr->right){
    		stack[++top]=curr->right;
		}
		if(curr->left){
			stack[++top]=curr->left;
		}
	}
}

int main() {
    int choice, val;

    while (1) {
        printf("\n\n===== Binary Search Tree Menu =====\n");
        printf("1. Insert\n");
        printf("2. Preorder Traversal (Iterative)\n");
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
                printf("Preorder traversal: ");
                preorderIterative(root);
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


