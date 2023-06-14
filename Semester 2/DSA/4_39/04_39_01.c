#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* left;
    int data;
    struct Node* right;
} Node;

Node* createTree() {
    Node* root;
    int choice;

    root = (Node*)malloc(sizeof(Node));
    printf("Enter the data of the root node: ");
    scanf("%d", &root->data);

    printf("Add left child of %d? (0/1): ", root->data);
    scanf("%d", &choice);

    if (choice == 1)
        root->left = createTree();
    else
        root->left = NULL;

    printf("Add right child of %d? (0/1): ", root->data);
    scanf("%d", &choice);

    if (choice == 1)
        root->right = createTree();
    else
        root->right = NULL;

    return root;
}

void preorder(Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    Node* root = NULL;
    int choice, data;

    while (1) {
        printf("1. Create Binary Tree\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                root = createTree();
                printf("Binary tree created!\n");
                break;
            case 2:
                if (root == NULL) {
                    printf("Tree is empty -- cannot traverse\n");
                    break;
                }
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                if (root == NULL) {
                    printf("Tree is empty -- cannot traverse\n");
                    break;
                }
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                if (root == NULL) {
                    printf("Tree is empty -- cannot traverse\n");
                    break;
                }
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
                exit(0);
        }
    }

    return 0;
}
