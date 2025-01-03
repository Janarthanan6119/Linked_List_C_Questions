#include<stdio.h>
struct Node{
int data;
struct Node *prev;
struct Node *next;
};
struct Node* createNode(int data){
struct Node *newnode = malloc(sizeof(struct Node));
newnode->prev = NULL
newnode->data = data;
newnode->next=NULL;
return newnode;
} ;
void insertAtEnd(striuct Node **headad,int data){
struct Node *newnode = createNode(data);
if(*headad==NULL){
    *headad = newnode;
    return;
}
struct Node *temp = *headad;
while(temp->next!=NULL){
    temp=temp->next;
}
temp->next=newnode;
newnode->prev = temp;
}
void insertAtbegin(struct Node** headad,int data ){
struct Node *newnode = createNode(data);
newnode->next=*head;
//Need to check already node is in the list,if it is not
//the node which we are inserting is a first node
if(*head!=NULL)
    (*head)->prev=newnode;
*head=newnode;
}
void insertAtpos(struct Node **headad,int data,int pos){
struct Node *newnode = createNode(data);
struct Node *temp = *headad;
if(pos==1){
    insertAtbegin(headad,data);
    return;
}
for(int i=1;i<pos-1&&temp!=NULL;i++){
    temp=temp->next;
}
if(temp==NULL){
    printf("Position out of bounds");
    free(newnode);
    return;
}
newnode->next = temp->next;
newnode->prev = temp;
if(temp->next!=NULL){
    temp->next->prev = newnode;
}
temp->next= newnode;
}
void deleteAtEnd(struct Node **head){
struct Node *temp = *head;
if(temp->next==NULL){
    *head=NULL;
    free(temp);
    return;
}
while(temp->next!=NULL){
    temp=temp->next;
}
temp->prev->next=NULL;
free(temp);
}
void deleteAtbegin(struct Node **head){
struct Node *temp = *head;
*head=(*head)->next;
if(*head!=NULL){
(*head)->prev = NULL;
}
free(temp);
}
void deleteAtPos(struct Node **head,int pos){
struct Node *temp = *head;
if(pos==1){
    deleteAtbegin(head);
    return;
}
//to be in the delete pos
for(int i=1;i<pos&&temp!=NULL;i++){
    temp=temp->next;
}
if(temp==NULL){
    printf("Position Out of Bounds");
    return;
}
if(temp->next!=NULL){
    temp->next->prev = temp->prev;
}
if(temp->prev!=NULL){
    temp->prev->next=temp->next;
}
free(temp);
}
void display(struct Node *head){
struct Node *temp = head;
while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
}

}
int main(){
struct Node *head = NULL;
insertAtEnd(&head,10);
insertAtEnd(&head,15);
insertAtEnd(&head,20);
insertAtbegin(&head,5);
insertAtpos(&head,12,3);
deleteAtEnd(&head);
deleteAtBegin(&head);
deleteAtPos(&head,2)
display(head);
}
