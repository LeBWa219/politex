//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <locale>
//
//
//typedef struct Node {
//    int data;
//    struct Node* next;
//} Node;
//
//Node* createNode(int data) {
//    Node* newNode = (Node*)malloc(sizeof(Node));
//    if (newNode == NULL) {
//        perror("Ошибка выделения памяти для нового узла");
//        exit(EXIT_FAILURE);
//    }
//    newNode->data = data;
//    newNode->next = NULL;
//    return newNode;
//}
//
//
//Node* createLinkedList(int arr[], int n) {
//    Node* head = NULL;
//    Node* tail = NULL;
//
//    for (int i = 0; i < n; i++) {
//        Node* newNode = createNode(arr[i]);
//
//        if (head == NULL) {
//            head = newNode;
//            tail = newNode;
//        } else {
//            tail->next = newNode;
//            tail = newNode;
//        }
//    }
//
//    return head;
//}
//
//
//int writeLinkedListToFile(Node* head, const char* filename) {
//    FILE* file = fopen(filename, "w");
//    if (file == NULL) {
//        perror("Ошибка открытия файла для записи");
//        return -1;
//    }
//
//    Node* current = head;
//    while (current != NULL) {
//        fprintf(file, "%d\n", current->data);
//        current = current->next;
//    }
//
//    fclose(file);
//    return 0;  
//}
//
//void freeLinkedList(Node* head) {
//    Node* current = head;
//    Node* next;
//
//    while (current != NULL) {
//        next = current->next;
//        free(current);
//        current = next;
//    }
//}
//
//
//int main() {
//	setlocale(LC_ALL, "rus");
//    int arr[] = {10, 20, 30, 40, 50};
//    int n = sizeof(arr) / sizeof(arr[0]);
//    const char* filename = "linked_list.txt";
//
//    Node* head = createLinkedList(arr, n);
//
//    if (writeLinkedListToFile(head, filename) == 0) {
//        printf("Односвязный список успешно записан в файл %s\n", filename);
//    } else {
//        printf("Ошибка записи односвязного списка в файл.\n");
//    }
//
//    freeLinkedList(head); 
//    head = NULL;
//
//
//    return 0;
//}




//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <locale>
//
//typedef struct Node {
//    int data;
//    struct Node* next;
//} Node;
//
//
//Node* createNode(int data) {
//    Node* newNode = (Node*)malloc(sizeof(Node));
//    if (newNode == NULL) {
//        perror("Ошибка выделения памяти для нового узла");
//        exit(EXIT_FAILURE);
//    }
//    newNode->data = data;
//    newNode->next = NULL;
//    return newNode;
//}
//
//
//Node* readLinkedListFromFile(const char* filename) {
//    FILE* file = fopen(filename, "r");
//    if (file == NULL) {
//        perror("Ошибка открытия файла для чтения");
//        return NULL;
//    }
//
//    Node* head = NULL;
//    Node* tail = NULL;
//    int data;
//
//    while (fscanf(file, "%d", &data) == 1) {
//        Node* newNode = createNode(data);
//
//        if (head == NULL) {
//            head = newNode;
//            tail = newNode;
//        } else {
//            tail->next = newNode;
//            tail = newNode;
//        }
//    }
//
//    fclose(file);
//    return head;
//}
//
//
//int writeLinkedListToFile(Node* head, const char* filename) {
//    FILE* file = fopen(filename, "w");
//    if (file == NULL) {
//        perror("Ошибка открытия файла для записи");
//        return -1;
//    }
//
//    Node* current = head;
//    while (current != NULL) {
//        fprintf(file, "%dn", current->data);
//        current = current->next;
//    }
//
//    fclose(file);
//    return 0;
//}
//
//
//Node* insertAtBeginning(Node* head, int data) {
//    Node* newNode = createNode(data);
//    newNode->next = head;
//    return newNode;
//}
//Node* insertAtEnd(Node* head, int data) {
//    Node* newNode = createNode(data);
//
//    if (head == NULL) {
//        return newNode; 
//    }
//
//    Node* current = head;
//    while (current->next != NULL) {
//        current = current->next;
//    }
//    current->next = newNode;
//    return head;
//}
//
//Node* insertAfterValue(Node* head, int searchValue, int data) {
//    Node* newNode = createNode(data);
//
//    Node* current = head;
//    while (current != NULL) {
//        if (current->data == searchValue) {
//            newNode->next = current->next;
//            current->next = newNode;
//            return head; 
//        }
//        current = current->next;
//    }
//
//    // Если значение не найдено, возвращаем исходный список
//    printf("Элемент со значением %d не найден.n", searchValue);
//    free(newNode); 
//    return head;
//}
//
//// Функция для освобождения памяти, выделенной под список
//void freeLinkedList(Node* head) {
//    Node* current = head;
//    Node* next;
//
//    while (current != NULL) {
//        next = current->next;
//        free(current);
//        current = next;
//    }
//}
//
//
//int main() {
//	setlocale(LC_ALL, "rus");
//    const char* filename = "linked_list.txt";
//    Node* head = readLinkedListFromFile(filename);
//
//    if (head == NULL) {
//        printf("Список пуст или произошла ошибка при чтении из файла.n");
//    }
//
//   
//    head = insertAtBeginning(head, 5);
//    head = insertAtEnd(head, 60);
//    head = insertAfterValue(head, 30, 35);
//
//    if (writeLinkedListToFile(head, filename) == 0) {
//        printf("Обновленный односвязный список успешно записан в файл %sn", filename);
//    } else {
//        printf("Ошибка записи односвязного списка в файл.n");
//    }
//
//    freeLinkedList(head); 
//    head = NULL;
//
//    return 0;
//}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale>

typedef struct Node {
    int data;
    struct Node* next;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Ошибка выделения памяти для нового узла");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


Node* readLinkedListFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Ошибка открытия файла для чтения");
        return NULL;
    }

    Node* head = NULL;
    Node* tail = NULL;
    int data;

    while (fscanf(file, "%d", &data) == 1) {
        Node* newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    fclose(file);
    return head;
}


int writeLinkedListToFile(Node* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Ошибка открытия файла для записи");
        return -1;
    }

    Node* current = head;
    while (current != NULL) {
        fprintf(file, "%dn", current->data);
        current = current->next;
    }

    fclose(file);
    return 0;
}


Node* deleteFromBeginning(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}


Node* deleteFromEnd(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    Node* current = head;
    Node* prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    free(current);
    return head;
}


Node* deleteAfterValue(Node* head, int searchValue) {
    if (head == NULL) {
        return NULL;
    }

    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data == searchValue) {
            Node* temp = current->next;
            current->next = temp->next;

            free(temp);
            return head;
        }
        current = current->next;
    }

    printf("Элемент со значением %d не найден или нет элемента после него.n", searchValue);
    return head;
}



void freeLinkedList(Node* head) {
    Node* current = head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
	setlocale(LC_ALL, "rus");
    const char* filename = "linked_list.txt";
    Node* head = readLinkedListFromFile(filename);

    if (head == NULL) {
        printf("Список пуст или произошла ошибка при чтении из файла.n");
        
    }

    
    head = deleteFromBeginning(head);
    head = deleteFromEnd(head);
    head = deleteAfterValue(head, 30);  

    if (writeLinkedListToFile(head, filename) == 0) {
        printf("Обновленный односвязный список успешно записан в файл %sn", filename);
    } else {
        printf("Ошибка записи односвязного списка в файл.n");
    }

    freeLinkedList(head);
    head = NULL;

    return 0;
}

