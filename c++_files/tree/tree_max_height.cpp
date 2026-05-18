//depth of binary tree
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

int maxDepth_rec(Node* root){
    
    if(root == NULL)return 0;
    int left_h = maxDepth_rec(root->left);
    int right_h = maxDepth_rec(root->right);
    int max_h = 1 + max(left_h , right_h);
    return max_h;
}


int maxDepth_level(Node* root){
    //eaach level = deapth ++
    if(root == NULL)return 0;
    int h = 0;
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()){
        int size = q.size();
        h++;
        for(int i = 0 ; i < size ;i++ ){
            Node* curr = q.front();q.pop();
            if(curr->left != NULL)q.push(curr->left);
            if(curr->right != NULL)q.push(curr->right);
        }
    }
    return h;
    
}

int main(){
    //create the tree
    Node* root = new Node(1);
    
    root->left = new Node(2);
    root->right = new Node(3);
    
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    root->right->left = new Node(6);
    
    //use the rec method
    
    cout<<maxDepth_rec(root)<<endl;
    
    //T.C = O(N)
    //visited all nodes once
    
    //S.C = O(H)
    //recursive stack space -- depth of tree max
    
    //worst case skew tree = O(N)
    //best/average balanced tree = O(log N)
    
    
    //using level order
    
    cout<<maxDepth_level(root);
    //T.C = O(N)
    //each node visited exactly once
    
    //S.C = O(N)
    //queue stores nodes level by level
    //in worst case last level can contain N/2 nodes
    
    
}