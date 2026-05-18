#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


int maxPath_sum(Node* root,int& maxSum){
    if(root == NULL)return 0;
    
    int leftSum = maxPath_sum(root->left,maxSum);
    int rightSum = maxPath_sum(root->right,maxSum);
    
    maxSum = max(maxSum, leftSum + rightSum + (root->data));
    
    //now return the max sum path 
    return (root->data) + max(leftSum ,rightSum);
}


int maxPath(Node* root){
    int maxSum = INT_MIN;
    maxPath_sum(root,maxSum);
    
    return maxSum;
}


int main(){
    
    Node* root = new Node(1);
    
    root->left = new Node(2);
    root->right = new Node(3);
    
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << maxPath(root);

  
}