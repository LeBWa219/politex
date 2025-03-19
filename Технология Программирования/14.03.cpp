
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 1
Node* createList() {
    Node* head = 0;
    return head;
}


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == 0) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = 0;
    return newNode;
}


// 2.
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode; 
}

// 2.
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);

    if (head == 0) {
        return newNode; 
    }

    Node* current = head;
    while (current->next != 0) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// 2.
Node* insertAfterValue(Node* head, int value, int data) {
    Node* current = head;

    while (current != 0) {
        if (current->data == value) {
            Node* newNode = createNode(data);
            newNode->next = current->next;
            current->next = newNode;
            return head;
        }
        current = current->next;
    }

   
    printf("Value %d not found in the list.\n", value);
    return head;
}

// 3.
Node* deleteFromBeginning(Node* head) {
    if (head == 0) {
        return 0;
    }

    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// 3.
Node* deleteFromEnd(Node* head) {
    if (head == 0) {
        return 0; 
    }

    if (head->next == 0) {
        free(head);
        return 0;
    }

    Node* current = head;
    Node* previous = 0;

    while (current->next != 0) {
        previous = current;
        current = current->next;
    }

    previous->next = 0;
    free(current);
    return head;
}

// 3.
Node* deleteAfterValue(Node* head, int value) {
    if (head == 0) {
        return 0;
    }

    Node* current = head;

    while (current != 0 && current->data != value) {
        current = current->next;
    }

    if (current == 0 || current->next == 0) {
        printf("Value %d not found or no element after it.\n", value);
        return head; 
    }

    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}


// 4.
Node* sortListAscending(Node* head) {
    if (head == 0 || head->next == 0) {
        return head;
    }

    int swapped;
    Node* current;
    Node* last = 0;

    do {
        swapped = 0;
        current = head;

        while (current->next != last) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);

    return head;
}
// 4.
Node* sortListDescending(Node* head) {
    if (head == 0 || head->next == 0) {
        return head;
    }
    int swapped;
    Node* current;
    Node* last = 0;
    do {
        swapped = 0;
        current = head;
        while (current->next != last) {
            if (current->data < current->next->data) {
                
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
    return head;
}
void printList(Node* head) {
    Node* current = head;
    while (current != 0) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("0\n"); 
}

int main() {
    Node* myList = createList();

    myList = insertAtEnd(myList, 8);
    myList = insertAtEnd(myList, 1);
    myList = insertAtEnd(myList, 7);
    myList = insertAtBeginning(myList, 9);
    printf("creating list:\n");
    printList(myList);
    
    printf("new el after the value:\n");
    myList = insertAfterValue(myList, 3, 2);
    printList(myList);

    myList = deleteFromBeginning(myList);
    printf("delete from beginning:\n");
    printList(myList);

    myList = deleteFromEnd(myList);
    printf("delete from the end:\n");
    printList(myList);

    myList = deleteAfterValue(myList, 2);
    printf("delete after the value:\n");
    printList(myList);

    myList = insertAtEnd(myList, 5);
    myList = insertAtEnd(myList, 1);
    myList = insertAtEnd(myList, 2);
    printList(myList);

    myList = sortListAscending(myList);
    printList(myList);

    myList = sortListDescending(myList);
    printList(myList);

    Node* current = myList;
    while (current != 0) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

