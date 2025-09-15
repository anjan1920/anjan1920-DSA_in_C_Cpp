#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *left, *right;
};

// Tree
struct node *root;



// Function to insert a new node into the BST
struct node *insert(struct node *root, int value) {
    if (root == NULL) {
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Preorder traversal
void preorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Inorder traversal
void inorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Postorder traversal
void postorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    root = NULL;
    
    // Create BST using insert function
    int value;
    printf("Enter root value: ");
    scanf("%d", &value);
    root = insert(root, value);

    printf("Enter values to insert into the BST (-1 to stop): ");
    while (1) {
        scanf("%d", &value);
        if (value == -1) {
            break;
        }
        insert(root, value);
    }

    printf("Printing preorder traversal: ");
    preorder(root);

    printf("\nPrinting inorder traversal: ");
    inorder(root);

    printf("\nPrinting postorder traversal: ");
    postorder(root);

    return 0;
}

