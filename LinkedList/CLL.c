#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *next;
};
struct Node* createNode(int data){
struct Node *newnode = malloc(sizeof(struct Node));
newnode->data = data;
newnode->next = NULL;
return newnode;
};
void insertAtEnd(struct Node **tail,int data){
struct Node *newnode = createNode(data);
if(*tail==NULL){
    *tail=newnode;
    newnode->next = newnode;
}
else{
    newnode->next=(*tail)->next;
    (*tail)->next = newnode;
    *tail=newnode;
}
}
void insertAtBegin(struct Node** tail,int data){
struct Node *newnode = createNode(data); //2 NULL
if(*tail==NULL){
    *tail=newnode;
    newnode->next = newnode;
}
newnode->next = (*tail)->next;
(*tail)->next = newnode;
}
void insertAtPos(struct Node** tail,int data,int pos){
struct Node *newnode = createNode(data);//20 NULL
if(pos==1){
        insertAtBegin(tail,data);
    return;
}
struct Node *temp = (*tail)->next;
for(int i=1;i<pos-1;i++){
    if(temp==*tail){
        printf("Position Out of Bounds");
        return;
    }
    temp = temp->next;
}
newnode->next = temp->next;
temp->next = newnode;
if(temp==*tail)
    *tail = newnode;
}
void deleteAtEnd(struct Node **tail){
struct Node *head = (*tail)->next;
if(*tail==head){
    *tail=NULL;
    free(head);
    return;
}
struct Node *temp = head;
while(temp->next!=*tail){
    temp=temp->next;
}
temp->next = (*tail)->next;
free(*tail);
*tail=temp;
}
void deleteAtBegin(struct Node **tail){
struct Node *head = (*tail)->next;
if(*tail==head){
    *tail==NULL;
}
else{
(*tail)->next = head->next;
free(head);
}
}
void deleteAtPos(struct Node **tail,int pos){

struct Node *temp = (*tail)->next;
for(int i=1;i<pos-1;i++){
    if(temp->next==*tail){
        printf("Position Out of Bounds");
        return;
        }
    temp = temp->next;
}
struct Node *delNode = temp->next;
temp->next = delNode->next;
if(delNode == *tail)
    *tail = temp;
free(delNode);
}
void display(struct Node *tail){
struct Node *temp = tail->next;
do{
    printf("%d ",temp->data);
    temp = temp->next;
}while(temp!=tail->next);
}
int main(){
    struct Node *tail = NULL;
    insertAtEnd(&tail,10);
    insertAtEnd(&tail,15);
    insertAtBegin(&tail,5);
    insertAtPos(&tail,12,3);
    insertAtPos(&tail,18,6);
    deleteAtEnd(&tail);
    deleteAtBegin(&tail);
    deleteAtPos(&tail,3);
    display(tail);
}
