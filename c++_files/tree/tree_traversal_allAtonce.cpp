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

vector<vector<int>> pre_in_post_order(Node* root){
    vector<vector<int>>ans;
    
    if(root == NULL)return ans;
    
    vector<int>pre;
    vector<int>in;
    vector<int>post;
    
    stack<pair<Node*,int>>st;
    st.push({root,1});
    
    while( !st.empty()){
        auto curr= st.top();
        st.pop();
        
        //pre order case
        if(curr.second == 1){
            pre.push_back(curr.first->data);
            
            //increement the rank
            curr.second++;
            
            //push back to st
            st.push(curr);
            
            if(curr.first->left != NULL){
                st.push({curr.first->left,1});
            }
        }
        
        //in order case
        else if(curr.second == 2){
            in.push_back(curr.first->data);
            
            //increement the rank
            curr.second++;
            
            //push back to st
            st.push(curr);
            
            if(curr.first->right != NULL){
                st.push({curr.first->right,1});
            }
        }
        
        //post order case
        else{
            post.push_back(curr.first->data);
        }
    }
    
    ans.push_back(pre);
    ans.push_back(in);
    ans.push_back(post);
    
    return ans;
}


int main(){
    
    //lv2
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    
    //lv3
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    vector<vector<int>>ans = pre_in_post_order(root);
    
    vector<int>pre = ans[0];
    vector<int>in = ans[1];
    vector<int>post = ans[2];
    
    cout<<"Pre Order : ";
    for(auto val : pre){
        cout<<val<<" ";
    }
    
    cout<<endl;
    
    cout<<"In Order : ";
    for(auto val : in){
        cout<<val<<" ";
    }
    
    cout<<endl;
    
    cout<<"Post Order : ";
    for(auto val : post){
        cout<<val<<" ";
    }
    
    return 0;
    
}