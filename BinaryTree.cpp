//
// Created by 范鑫磊 on 17/4/5.
//

#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

typedef struct Node{
    int val;
    Node *left;
    Node *right;
}Node;


void INORDER_TREE_WALK(Node *root){
    if(root == NULL) return;
    INORDER_TREE_WALK(root->left);
    cout << root->val << endl;
    INORDER_TREE_WALK(root->right);
}

void PREORDER_TREE_WALK(Node *root){
    if(root == NULL) return;

    cout << root->val << endl;

    PREORDER_TREE_WALK(root->left);

    PREORDER_TREE_WALK(root->right);
}

void POSTORDER_TREE_WALK(Node *root){
    if(root == NULL) return;
    POSTORDER_TREE_WALK(root->left);

    POSTORDER_TREE_WALK(root->right);

    cout << root->val << endl;
}


void INSERT_TREE(Node *root,int val){

    Node *node = root;
    Node *parent=NULL;
    int left = 1;
    while(node != NULL){
        parent = node;
        if(val <= node->val ){
            node = node->left;
            left = 1;
        }else{
            node = node->right;
            left = 0;
        }
    }
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->val  = val;
    temp->left = NULL;
    temp->right= NULL;
    if (left == 1){
        parent->left =temp;
    }else{
        parent->right=temp;
    }
}


int main(){
    vector<int> keys = {3,1,4,2,8,6,9,7};
    Node *root = (Node *)malloc(sizeof(Node));
    root->val  = 5;
    root->left = NULL;
    root->right= NULL;
    for(auto i : keys){
        INSERT_TREE(root,i);
    }
    INORDER_TREE_WALK(root);
    return 0;
}