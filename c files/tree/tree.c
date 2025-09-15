#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *left,*right;
	
};

//tree 
struct node *root;

struct node *createnode(){
	struct node *newnode ;
	newnode = (struct node*)malloc(sizeof(struct node));
	int x;
	printf("Enter data:(-1 for stop creating node):");
	scanf("%d",& x);
	if(x== -1){
		return 0;
	}
	newnode ->data =x;
	printf("Enter left child of %d ",x);
	newnode ->left = createnode();
	printf("Enter right child of %d ",x);
	newnode ->right = createnode();
	return newnode;
	
	
	
}
//preorder traversal
void preorder(struct node *root){
	if( root == 0){
		return ;
	}
	printf("%d ", root ->data);
	preorder(root ->left);
	preorder(root ->right);
	
}

//inorder
void inorder(struct node *root){
	if( root == 0){
		return ;
	}
	inorder(root ->left);
	printf("%d ",root ->data);
	inorder(root ->right );
}
//postorder
void postorder(struct node *root){
	if( root == 0){
		return ;
	}
	inorder(root ->left);

	inorder(root ->right );
    printf("%d ",root ->data);
}



int main(){
	root = 0;
	root = createnode();
	printf("printing preorder traversal -- ");
	preorder(root);
	printf("\n printing inorder traversal -- ");
	inorder(root);
	printf("\n printing postorder traversal -- ");
	postorder(root);
	
}
