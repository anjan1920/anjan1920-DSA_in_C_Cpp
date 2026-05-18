//check balanced binary tree
#include<bits/stdc++.h>
using namespace std;

//node of tree
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

int check_balancedBt(Node* root){
    if(root == NULL)return 0;
    
    int lh = check_balancedBt(root->left);
    int rh = check_balancedBt(root->right);
    
    //already unbalanced
    if(lh == -1 || rh == -1)return -1;
    
    //curr node unbalanced
    if(abs(lh-rh) > 1)return -1;
    
    //return height
    return (1 + max(lh,rh));
}

int main(){
    //create the tree
    Node* root = new Node(1);
    
    root->left = new Node(2);
    root->right = new Node(3);
    
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    root->right->left = new Node(6);
    
    int ans = check_balancedBt(root);
    
    if(ans == -1){
        cout<<"Not Balanced";
    }
    else{
        cout<<"Balanced";
    }
    
    //T.C = O(N)
    //visited each node once
    
    //S.C = O(H)
    //recursive stack space
    
    //worst case skew tree = O(N)
    //balanced tree = O(log N)
    
}