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

vector<int> preOrder_iterative(Node* root){
    stack<Node*>st;
    vector<int>ans;
    if(root == NULL)return ans;
    
    st.push(root);
    while(!st.empty()){
        Node* curr = st.top();
        st.pop();
        ans.push_back(curr->data);
        //go extreme left subtree
        if(curr->right != NULL)st.push(curr->right);
        if(curr->left != NULL)st.push(curr->left);
        //left is on top of stack ,,root-left -right
    }
    return ans;
    
}


//post oder iterator
vector<int>postOrder_iterative(Node* root){
    vector<int>ans;
    if(root == NULL)return ans;
    
    stack<Node*>st1;
    stack<Node*>st2;
    
    st1.push(root);
    //O(n)
    while( !st1.empty() ){
        Node *curr = st1.top();
        st1.pop();
        st2.push(curr);
        if(curr->left != NULL)st1.push(curr->left);
        if(curr->right != NULL)st1.push(curr->right);
        
    }
    //now extcat the values
    //O(n)
    while(!st2.empty()){
        Node* curr = st2.top();
        st2.pop();
        ans.push_back(curr->data);
    }
    
    return ans;
}

int main(){
    Node* root = new Node(1);//lv1
    //lv2
    root->left = new Node(2);
    root->right = new Node(3);
    
    //lv3
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    vector<int>ans_preOrder = preOrder_iterative(root);
    for(auto val : ans_preOrder){
        cout<<val<<" ";
        
    }

    vector<int>ans_postOrder = postOrder_iterative(root);
    for(auto val : ans_postOrder){
        cout<<val<<" ";
        
    }
    return 0;
    
    
}