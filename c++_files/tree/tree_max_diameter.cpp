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


int max_height(Node* root){
    if(root == NULL)return 0;
    int lh = max_height(root->left);
    int rh = max_height(root->right);
    
    int h = max(lh,rh)+1;
    return h;
}

void find_maxDiameter(Node* root,int &maxi){
    if(root == NULL)return;
    int left_h = max_height(root->left);
    int right_h = max_height(root->right);
    
    maxi = max(maxi,left_h+right_h);
    
    //go on left and right nodes
    find_maxDiameter(root->left,maxi);
    find_maxDiameter(root->right,maxi);
    
    
        
    //T.C = O(n^2) in worst case
    //for every node we are calculating height again
    //height function can traverse till extreme left/right leaf
    
    //balanced tree:
    //for each node height takes around logn
    //so close to O(nlogn)
    
    //skewed tree:
    //for each node height can take O(n)
    //so total becomes O(n^2)
    
    
}



int diameter(Node* root){
    int maxi = 0;
    find_maxDiameter(root,maxi);
    return maxi;
}

//same as find max depth 
int findMax_dia(Node* root,int& maxi){
    if(root ==  NULL) return 0;
    
    int lh = findMax_dia(root->left,maxi);
    int rh = findMax_dia(root->right,maxi);
    
    maxi = max(maxi,lh+rh);
    
    return max(lh,rh)+1;//return tree height
}

int diameter_optimal(Node* root){
    int maxi = 0;
    findMax_dia(root,maxi);
    return maxi;
}

int main(){
    
    Node* root = new Node(1);
    
    root->left = new Node(2);
    root->right = new Node(3);
    
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << diameter(root) << endl;
    
    cout << diameter_optimal(root);
    
}