//Stack Using LL
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a stack node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Push operation: Add an element to the top of the stack
void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed to the stack.\n", data);
}

// Pop operation: Remove an element from the top of the stack
int pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Stack underflow! Cannot pop from an empty stack.\n");
        return -1; // Indicates stack is empty
    }
    struct Node* temp = *top;
    int poppedData = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedData;
}

// Peek operation: View the top element of the stack without removing it
int peek(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty! No top element to display.\n");
        return -1; // Indicates stack is empty
    }
    return top->data;
}

// Display the stack elements
void display(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate stack operations
int main() {
    struct Node* stack = NULL; // Initialize the stack (top pointer)

    // Perform stack operations
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("After pushing elements:\n");
    display(stack);

    printf("Top element is: %d\n", peek(stack));

    printf("Popped element: %d\n", pop(&stack));
    printf("After popping an element:\n");
    display(stack);

    printf("Popped element: %d\n", pop(&stack));
    printf("After popping another element:\n");
    display(stack);

    return 0;
}
