#include <iostream>
#include <stdio.h>

typedef struct Node{
    int i;
    Node *next;
} TNode;


Node* reverseNext(Node *cur,Node **head){
    if(cur->next){
        Node *n = reverseNext(cur->next,head);
        n->next = cur;
        cur->next = NULL;
        return cur;
    }else{
        *head = cur;
        return cur;
    }
}

Node *reverse(Node *head){
    Node *nhead = NULL;
    reverseNext(head,&nhead);
    return nhead;
}

Node *reverseUseLoop(Node *head){
    Node *tail = head;
    Node *prev = NULL;
    Node *temp = NULL;
    while(tail->next != NULL){
        temp = tail;
        tail = tail->next;
        temp->next = prev;
        prev = temp;
    }
    tail->next = prev;
    return tail;
}

int main() {
    Node *head = NULL;
    Node *curr = NULL;

    for(int i =0;i<5;i++){
        Node * node = (Node *)malloc(sizeof(TNode));
        node->next  = NULL;
        node->i = i;
        if(curr){
            curr->next = node;
            curr = curr->next;
        }else{
            curr = node;
            head = curr;
        }
    }
    curr = head;

    while(curr!=NULL){
        printf("node %d\n",curr->i);
        curr = curr->next;
    }
    printf("%s\n","-----------------after reverse:");
    Node *nhead = reverseUseLoop(head);
    curr = nhead;

    while(curr){
        printf("node %d\n",curr->i);
        curr = curr->next;
    }

}
