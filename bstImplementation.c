#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//creating Node
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

// inserting node in bst
struct Node* insertNode(struct Node *root, int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    if(root == NULL) return newNode;
    else if(root->data >= data){
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

//traversals in bst
void inorder(struct Node *root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node *root){
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}




//deleting node from bst
int minValue(struct Node *root){
    if(root==NULL) return -1;
    int minVal = root->data;
    if(root->left != NULL) {
        minVal = minValue(root->left);
    }
    return minVal;
}

struct Node* DeleteFromBst(struct Node *root, int data){
    if(root == NULL) return NULL;
    else if(root->data > data) root->left = DeleteFromBst(root->left, data);
    else if(root->data < data) root->right = DeleteFromBst(root->right, data);
    else{
        if(root->left == NULL) return root->right;
        else if(root->right == NULL) return root->left;
        else{
            int minVal = minValue(root->right);
            root->data = minVal;
            return root->right = DeleteFromBst(root->left, minVal);
        }
    }
    return root;
}

// searching a node in bst
bool SearchInBst(struct Node *root, int data){
    if(root == NULL) return false;
    if(root->data == data) return true;
    if(root->data > data) return SearchInBst(root->left, data);
    else if(root->data < data) return SearchInBst(root->right, data);
}
 
int main(){
    struct Node *root = NULL;
    root = insertNode(root, 1);
    insertNode(root, 4);
    insertNode(root, 6);
    insertNode(root, 2);
    insertNode(root, 7);
    insertNode(root, 3);
    inorder(root);
    printf("\n%d \n",SearchInBst(root, 3));
    DeleteFromBst(root, 6);
    inorder(root);
}