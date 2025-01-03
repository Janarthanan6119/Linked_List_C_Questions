
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
void findpair(struct Node *head,int target){
struct Node *left=head,*right=head;
while(right->next!=NULL)
    right=right->next;

int flag=0;
while(left!=right&&left->prev!=right){
    int sum = left->data+right->data;
    if(sum==target){
        printf("Pairs are %d , %d\n",left->data,right->data);
        left=left->next;
        right=right->prev;
        flag=1;
    }
    else if(sum>target){
        right=right->prev;
    }
    else{
        left=left->next;
    }

}
if(flag==0)
    printf("No pairs Found");
}
void display(struct Node* head) {
   struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main() {
    struct Node* head = NULL;

    // Insert elements into the doubly linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    //printf("Original list: ");
    findpair(head,7);
    //display(head);
}
