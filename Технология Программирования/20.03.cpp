#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root; 
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}
Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else { 
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = findMin(root->right);


        root->data = temp->data;


        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void printTree(Node* root) {
    if (root != NULL) {
        printf("(");
        printTree(root->left);
        printf("%d", root->data);
        printTree(root->right);
        printf(")");
    } else {
        printf("NULL");
    }
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}


int main() {
    Node* root = NULL;

    // Пример использования
    root = insertNode(root, 7);
    root = insertNode(root, 14);
    root = insertNode(root, 2);
    root = insertNode(root, 6);
    root = insertNode(root, 4);
    root = insertNode(root, 16);
    root = insertNode(root, 11);

    printf("Isxodnoe derevo: ");
    printTree(root);
    printf("\n");

    printf("Sortirovannoe derevo: ");
    inorderTraversal(root);
    printf("\n");

    root = insertNode(root, 12);
    root = insertNode(root, 13);

    printf("derevo posle vstavki 12, 13: ");
    printTree(root);
    printf("\n");

    root = deleteNode(root, 14); 

    printf("derevo posle ydaleniya 14: ");
    printTree(root);
    printf("\n");

    printf("sortirovannoe derevo posle ydaleniya 14: ");
    inorderTraversal(root);
    printf("\n");

    freeTree(root);

    return 0;
}

