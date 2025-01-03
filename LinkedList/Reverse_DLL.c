#include <stdio.h>
#include <stdlib.h>

// Node structure for a doubly linked list
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
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
    newNode->prev = temp;
}

void reverse(struct Node **head){
    struct Node *current = *head;
    struct Node *prev = NULL;
    while(current!=NULL){
        prev = current->prev;
        current->prev = current->next;
        current->next=prev;
        *head=current;
        current=current->prev;
    }

}
// Function to display the doubly linked list
void display(struct Node* head) {
   struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    /*struct Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    printf("%d ",temp->data);//5
    temp=temp->prev;
    while(temp->prev!=NULL){
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    */
    }

// Main function
int main() {
    struct Node* head = NULL;

    // Insert elements into the doubly linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Original list: ");
    display(head);
    reverse(&head);
/*
    printf("Reversed list: ");*/
    display(head);

    return 0;
}

