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
    printf("A\n");
    if(*head==NULL){
        *head = newnode;
        return;
    }
    struct Node *temp = *head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    printf("End\n");
}
void duplicates(struct Node *head){
struct Node *current = head,*temp,*prev;
while(current!=NULL && current->next!=NULL){
    prev = current;
    while(prev->next!=NULL){
        if(current->data==prev->next->data){
            temp = prev->next;
            prev->next = prev->next->next;
            free(temp);
        }
        else
            prev = prev->next;
    }
    current=current->next;
}
}
int findlength(struct Node *head){
int len = 0;
struct Node *temp = head;
while(temp!=NULL){
    len++;
    temp=temp->next;
}
return len;
}

struct Node* findinter(struct Node *head,struct Node *head2){
int l1 = findlength(head);
int l2 = findlength(head2);
int diff = abs(l1-l2);
struct Node *longer = (l1>l2)?head:head2;
struct Node *shorter = (l1>l2)?head2:head;
for(int i=0;i<diff;i++)
    longer=longer->next;

while(longer!=NULL && shorter!=NULL){
    if(longer==shorter)
        return longer;
    longer = longer->next;
    shorter=shorter->next;
}
};
struct Node* leftrotate(struct Node *head,int n){
struct Node *current = head;
int len =findlength(head);
int k = n%len;
if(k==0)
    return head;
for(int i=1;i<k;i++)
    current = current->next;
struct Node *newhead = current->next;
current->next = NULL;

struct Node *temp = newhead;
while(temp->next!=NULL)
    temp = temp->next;
temp->next = head;
return newhead;

}
struct Node* rightrotate(struct Node *head,int k){
if(head==NULL || k==0)
    return head;
int len = findlength(head);
k = k%len;
return leftrotate(head,len-k);

}
void swap(struct Node **head,int x,int y){
struct Node *prevX=NULL,*prevY=NULL;
struct Node *curX = *head,*curY=*head;

while(curX!=NULL && curX->data!=x){
    prevX = curX;
    curX = curX->next;
}
while(curY!=NULL && curY->data!=y){
    prevY=curY;
    curY=curY->next;
}
if(curX==NULL || curY==NULL)
    return;
if(prevX!=NULL)
    prevX->next=curY;
else
    *head=curY;
if(prevY!=NULL)
    prevY->next=curX;
else
    *head=curX;
struct Node *temp = curX->next;
curX->next = curY->next;
curY->next = temp;

}
void display(struct Node *head){
    struct Node *temp = head;
    int count=0;
    while(temp!=NULL){
        count++;
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\nCount of the Nodes %d",count);
}
int main()
{
    struct Node *head=NULL;
    insertAtEnd(&head,1);
    insertAtEnd(&head,2);
    insertAtEnd(&head,3);
    insertAtEnd(&head,4);
    insertAtEnd(&head,5);
    //insertAtBegin(&head,2);
    /*struct Node *head2 = NULL;
    insertAtEnd(&head2,1);
    insertAtEnd(&head2,4);
    //duplicates(head);
    struct Node *common = NULL;
    insertAtEnd(&common,5);
    insertAtEnd(&common,6);
    insertAtEnd(&common,7);
    struct Node *temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = common;

    struct Node *temp2 = head2;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next = common;

    struct Node *intersection = findinter(head,head2);
    printf("%d",intersection->data);*/
    //display(head);
    //printf("\n");
    //int k =2;
    //struct Node *left=leftrotate(head,k);
    //struct Node *right =rightrotate(head,k);
    //display(left); //1 2 3 2 1
    //display(right);
    swap(&head,2,4);
    display(head);
}
