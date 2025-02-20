#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;          
    struct Node* next; 
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head; 
    *head = newNode;       
}


void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
   
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void insertAtIndex(struct Node** head, int data, int index) {
    if (index < 0) {
        printf("Invalid index\n");
        return;
    }

    struct Node* newNode = createNode(data);

    if (index == 0) {
       
        insertAtBeginning(head, data);
        return;
    }

    struct Node* temp = *head;
    int i = 0;

   
    while (temp != NULL && i < index - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Index out of bounds\n");
        return;
    }

    
    newNode->next = temp->next;
    temp->next = newNode;
}


void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; 

    
    insertAtBeginning(&head, 1); 
    insertAtEnd(&head, 2);        
    insertAtEnd(&head, 3);        
    insertAtIndex(&head, 4, 2);
    insertAtIndex(&head, 5, 0);    
    
    printf("Linked List: ");
    displayList(head);

    return 0;
}
