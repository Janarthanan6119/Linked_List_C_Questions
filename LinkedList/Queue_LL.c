#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
sturct Node *next;
};
struct Queue{
struct Node *front;
struct Node *rear;
};
struct Queue* createQueue(){
struct Queue *q = malloc(sizeof(struct Queue));
q->front =NULL;
q->rear= NULL;
return q;
};
struct Node* createNode(int data){
struct Node *newnode = malloc(sizeof(struct Node));
newnode->data = data;
newnode->next = NULL;
return newnode;
} ;
void enqueue(struct Queue *q,int data){
struct Node *newnode = createNode(data);
if(q->rear==NULL){
    q->front=q->rear=newnode;
    return;
}
q->rear->next=newnode;
q->rear=newnode;
}
int dequeue(struct Queue *q){
if(q->front==NULL){
    printf("Queue is EMpty");
    return -1;
}
struct Node *temp = q->front;
int data = temp->data;
q->front = q->front->next;
if(q->front ==NULL){
    q->rear = NULL;
    }
free(temp);
return data;
}
int peek(struct Queue *q){
if(q->front==NULL){
    printf("Queue is EMpty");
    return -1;
}
return q->front->data;
}
void display(struct Queue *q){
if(q->front==NULL){
    printf("Queue is EMpty");
    return;
}
struct Node *temp = q->front;
while(temp!=NULL){
    printf("%d",temp->data);
    temp=temp->next;
}

}
int main(){
struct Queue *q = createQueue();
enqueue(q,10);
enqueue(q,15);
int rem = dequeue(q);
printf("%d",rem);
int front = peek(q);

display(q);

}
