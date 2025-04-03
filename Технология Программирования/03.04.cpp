#include <stdio.h>
#include <stdlib.h>
#include <locale>
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* insert(TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    return root;
}

TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

TreeNode* deleteNode(TreeNode* root, int data) {
    if (root == NULL) return root;
    
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        
        TreeNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void writeNodeToFile(TreeNode* node, FILE* file) {
    if (node != NULL) {
        writeNodeToFile(node->left, file);
        fprintf(file, "%d ", node->data);
        writeNodeToFile(node->right, file);
    }
}

void writeTreeToTextFile(TreeNode* root, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Ошибка открытия файла %s\n", filename);
        return;
    }
    
    writeNodeToFile(root, file);
    fclose(file);
    printf("Дерево записано в текстовый файл %s\n", filename);
}

// Вспомогательная функция для бинарной записи
void writeBinaryNode(TreeNode* node, FILE* file) {
    if (node != NULL) {
        fwrite(&node->data, sizeof(int), 1, file);
        writeBinaryNode(node->left, file);
        writeBinaryNode(node->right, file);
    } else {
        int marker = -1;
        fwrite(&marker, sizeof(int), 1, file);
    }
}

void writeTreeToBinaryFile(TreeNode* root, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Ошибка открытия файла %s\n", filename);
        return;
    }
    
    writeBinaryNode(root, file);
    fclose(file);
    printf("Дерево записано в бинарный файл %s\n", filename);
}

TreeNode* readBinaryNode(FILE* file) {
    int data;
    if (fread(&data, sizeof(int), 1, file) != 1) {
        return NULL;
    }
    
    if (data == -1) {
        return NULL;
    }
    
    TreeNode* node = createNode(data);
    node->left = readBinaryNode(file);
    node->right = readBinaryNode(file);
    return node;
}

TreeNode* readTreeFromBinaryFile(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Ошибка открытия файла %s\n", filename);
        return NULL;
    }
    
    TreeNode* root = readBinaryNode(file);
    fclose(file);
    printf("Дерево прочитано из бинарного файла %s\n", filename);
    return root;
}

void printTree(TreeNode* root) {
    if (root != NULL) {
        printTree(root->left);
        printf("%d ", root->data);
        printTree(root->right);
    }
}

void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
	setlocale(LC_ALL, "rus");
    TreeNode* root = NULL;
    int elements[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(elements) / sizeof(elements[0]);
    
    for (int i = 0; i < n; i++) {
        root = insert(root, elements[i]);
    }
    
    printf("Исходное дерево: ");
    printTree(root);
    printf("\n");
    
    writeTreeToTextFile(root, "tree.txt");
    
    root = insert(root, 55);
    printf("Дерево после вставки 55: ");
    printTree(root);
    printf("\n");
    writeTreeToTextFile(root, "tree.txt");
    
    root = deleteNode(root, 30);
    printf("Дерево после удаления 30: ");
    printTree(root);
    printf("\n");
    writeTreeToTextFile(root, "tree.txt");
    
    writeTreeToBinaryFile(root, "tree.bin");
    
    TreeNode* newRoot = readTreeFromBinaryFile("tree.bin");
    printf("Дерево из бинарного файла: ");
    printTree(newRoot);
    printf("\n");
    
    freeTree(root);
    freeTree(newRoot);
    
    return 0;
}
