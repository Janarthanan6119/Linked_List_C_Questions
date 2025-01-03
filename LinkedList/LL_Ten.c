//Coding for First 9 QUestionss
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
void insertAtBegin(struct Node **head,int data){
    struct Node *newnode = createNode(data);
    if(*head==NULL){
        *head = newnode;
        return;
    }
    //struct Node *temp = *head;
    newnode->next = *head;
    *head =newnode;
}
//2 5 10 15
//   12
void insertAtPos(struct Node **head,int data,int pos){
    struct Node *newnode = createNode(data);
    struct Node *temp = *head;
    if(pos==1){
        insertAtBegin(head,data);
        return;
    }

    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Position Out of Range");
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;


}
void deleteAtEnd(struct Node **head){
    struct Node *temp = *head;
    if((*head)->next==NULL){
        free(*head);
        *head=NULL;
        return;
    }
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    //printf("%d\n",temp->data);
    temp->next = NULL;
}
void deleteAtBegin(struct Node **head){
    struct Node *temp = *head;
    if(temp->next==NULL){
        free(head);
        *head=NULL;
        return;
    }
    *head=(*head)->next;
    free(temp);
}
void deleteAtpos(struct Node **head,int pos){
    struct Node *temp = *head;
    for(int i=1;i<pos-1;i++){
        temp = temp->next;
    }
    temp->next=temp->next->next;
    struct Node *del = temp->next;
    free(del);
}
int search(struct Node *head,int value){
    struct Node *temp=head;
    while(temp!=NULL){
        if(temp->data==value){
            return 1;

    }
        temp=temp->next;
    }
    return 0;
}
void reverse(struct Node **head){
    struct Node *temp = *head;
    struct Node *prev = NULL;
    struct Node *next = NULL;
    while(temp!=NULL){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    *head=prev;
}
struct Node* mergelist(struct Node *h1,struct Node *h2){
struct Node dummy;
dummy.next=NULL;
struct Node *tail = &dummy;
 while(h1!=NULL && h2!=NULL){
     if(h1->data<=h2->data){
         tail->next=h1;
         h1=h1->next;
     }
     else{
         tail->next=h2;
         h2 = h2->next;
     }
     tail = tail->next;
 }
 if(h1!=NULL)
    tail->next = h1;
 else if(h2!=NULL)
    tail->next = h2;

 return dummy.next;
}
//2 1 3
void bubbleSort(struct Node *head){
    struct Node *current;
    int flag;
    struct Node *last = NULL;
    do{
        flag=0;
        current = head;
        while(current->next!=last){
            if(current->data > current->next->data){
                int temp = current->next->data;//1
                current->next->data = current->data;
                current->data = temp;
                flag=1;
            }
            current=current->next;
        }
        last = current;
    }while(flag);
}
//2 5 10 15 12
void findnth(struct Node *head,int n){
    struct Node *refptr=head,*mainptr=head;

    for(int i=0;i<n;i++){
        if(refptr==NULL){
            return;
        }
        refptr=refptr->next;
    }
    while(refptr!=NULL){
        mainptr=mainptr->next;//15
        refptr=refptr->next;//NULL
    }
    printf("\nNth Node is %d\n",mainptr->data);
}
void removal(struct Node *head){
    struct Node *fast=head,*slow=head;

    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow=slow->next;

        if(fast==slow){
            printf("Loop Detected");
            break;
        }

    }
    if(fast==NULL || fast->next==NULL){
        printf("No Loop Formed");
        return;
    }
    struct Node *prev=NULL;
    int count=0;
    slow=head;
    while(slow!=fast){
        prev = fast;
        slow=slow->next;
        fast = fast->next;
        count++;
    }
    prev->next = NULL;
    printf("\n%d\n",count);


}
int palindrome(struct Node *head){
struct Node *current = head;
int arr[5];
int size=0;
while(current!=NULL){
    arr[size++]=current->data;
    current=current->next;
}
int i=0,j=size-1;
while(i<j){
    if(arr[i]!=arr[j]){
        return 0;
    }
    i++;
    j--;
}

return 1;
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
    insertAtEnd(&head,3);
    insertAtEnd(&head,2);
    insertAtBegin(&head,2);
    insertAtBegin(&head,1);
    insertAtEnd(&head,1);
    // display(head);
    // printf("\n");
    // findnth(head,3); 2 5 10 15 12
    //head->next->next->next->next->next = head->next->next;
    //removal(head);
    //display(&head);
    //printf("\nDeletion Starts\n");
    //deleteAtEnd(&head);
    // deleteAtBegin(&head);
    // deleteAtpos(&head,2);
    // //display(&head);
    // int found = search(head,6);
    // if(found)
    //     printf("\nIts there");
    // else
    //     printf("\nIts not there");

    //reverse(&head);
    // struct Node *head2 = NULL;
    // insertAtEnd(&head2,1);
    // insertAtEnd(&head2,4);
    // insertAtEnd(&head2,3);
    //display(head2);
    // bubbleSort(head);
    // bubbleSort(head2);
    // struct Node *res = mergelist(head,head2);
    //printf("Before Calling Find Nth: ");
    //display(head);
    // findnth(head,2);
    //display(res);
    display(head);
    if(palindrome(head))
        printf("Its a Palindrome");
    else
        printf("Not a Palindrome");
    return 0;
}
