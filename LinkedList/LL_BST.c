#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int data;
    struct ListNode* next;
};


struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct ListNode* createListNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct TreeNode* createTreeNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct ListNode* findMiddle(struct ListNode* head, struct ListNode** prev) {
struct ListNode* slow = head;
    struct ListNode* fast = head;
    *prev = NULL;

    while (fast && fast->next) {
        *prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


struct TreeNode* sortedListToBST(struct ListNode* head) {
if (!head) return NULL;

    struct ListNode* prev = NULL;
    struct ListNode* mid = findMiddle(head, &prev);

    struct TreeNode* root = createTreeNode(mid->data);


    if (mid == head) return root;


    if (prev) prev->next = NULL;
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(mid->next);

    return root;

}


void preorderTraversal(struct TreeNode* root) {
if (!root) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}


int main() {
    int n, value;
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;


    scanf("%d", &n);


    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct ListNode* newNode = createListNode(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    struct TreeNode* root = sortedListToBST(head);


    preorderTraversal(root);


    return 0;
}
