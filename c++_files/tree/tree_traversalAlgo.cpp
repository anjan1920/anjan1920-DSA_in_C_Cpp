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


//pre order traversal -- root - left - right
void preOrder(Node* root)
{
    if(root == NULL)return ;

    cout<<root->data<<",";

    //go left subtree
    preOrder(root->left);

    //go right subtree
    preOrder(root->right);
}


//in order traversal -- left - root - right
void inOrder(Node* root)
{
    if(root == NULL)return ;

    //go left subtree
    inOrder(root->left);

    cout<<root->data<<",";

    //go right subtree
    inOrder(root->right);
}


//post order traversal -- left - right - root
void postOrder(Node* root)
{
    if(root == NULL)return ;

    //go left subtree
    postOrder(root->left);

    //go right subtree
    postOrder(root->right);

    cout<<root->data<<",";
}


//level order traversal--BFS
vector<vector<int>> levelOrder(Node* root)
{
    vector<vector<int>> ans;

    if(root == NULL)return ans;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;

        //process one level
        for(int i = 0 ; i < size ; i++){
            Node* curr = q.front();
            q.pop();
            level.push_back(curr->data);

            //push left child
            if(curr->left != NULL){
                q.push(curr->left);
            }
            //push right child
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }

        ans.push_back(level);
    }

    return ans;
}



int main(){

    Node* root = new Node(1); //level 1

    //level 2
    root->left = new Node(2);
    root->right = new Node(3);

    //level 3
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);


    //pre order
    cout<<"Pre order traversal:";
    preOrder(root);
    cout<<endl;


    //in order
    cout<<"In order traversal:";
    inOrder(root);
    cout<<endl;


    //post order
    cout<<"Post order traversal:";
    postOrder(root);
    cout<<endl;


    //level order
    vector<vector<int>> level_order_nodes = levelOrder(root);

    cout<<"Level order traversal:"<<endl;

    for(int i = 0 ; i < level_order_nodes.size() ; i++){

        for(int j = 0 ; j < level_order_nodes[i].size() ; j++){
            cout<<level_order_nodes[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}