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

void inorderIterative(node *root) {
    node *stack[100];
    int top = -1;
    node *curr = root;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%d\t", curr->data);
        curr = curr->right;
    }
}

int main() {
    int choice, val;

    while (1) {
        printf("\n\n====== Binary Search Tree Menu ======\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal (Iterative)\n");
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
                printf("Inorder traversal: ");
                inorderIterative(root);
                break;

            case 3:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

