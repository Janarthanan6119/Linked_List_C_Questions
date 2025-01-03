#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node* createNode(int data){
    struct Node *newnode = malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next =NULL;
    return newnode;
}
void insertAtEnd(struct Node **head,int data){
struct Node *newnode = createNode(data);
if(*head==NULL){
    *head=newnode;
    newnode->next = *head;
    return;
}
struct Node *temp = *head;
while(temp->next!=*head){
    temp=temp->next;
}
temp->next = newnode;
newnode->next = *head;

}
void split(struct Node **head,struct Node **h1,struct Node **h2){
struct Node *fast=*head,*slow=*head;
//fast will reach end,slow will reach mid at the end of the loop
while(fast->next!=*head && fast->next->next!=*head){
    slow=slow->next;
    fast=fast->next->next;
}
//Only it will work,if your Length of the List is Even
if(fast->next->next==*head){
    fast = fast->next;
}
*h2=slow->next;
*h1=*head;
slow->next=*h1;
fast->next = *h2;
}
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

}
int main(){
struct Node *head = NULL;
insertAtEnd(&head,10);
insertAtEnd(&head,20);
insertAtEnd(&head,30);
insertAtEnd(&head,40);
insertAtEnd(&head,50);
insertAtEnd(&head,60);
//display(head);
struct Node *h1=NULL,*h2=NULL;
split(&head,&h1,&h2);
display(h1);
printf("\n");
display(h2);
}
