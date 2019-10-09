#include<stdio.h>
#include<stdlib.h>

typedef struct bst{
	int val;
	bst *left,*right;
}bst;
//insert element in binary search tree
bst* insert(bst *node,int val){
	bst *newnode;
	newnode=(bst *)malloc(sizeof(bst));
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->val=val;
	if (node==NULL)return newnode;
	if (val<node->val) node->left=insert(node->left,val);
	else node->right=insert(node->right,val);
}

//print tree
void print(bst* node){
	if (node!=NULL){
	print(node->left);
	printf("%d  ",node->val);
	print(node->right);}
}

int main(){
	bst *root=NULL;
	root=insert(root,11);
	root=insert(root,6);
	root=insert(root,8);
	root=insert(root,19);
	root=insert(root,4);
	root=insert(root,10);
	root=insert(root,5);
	root=insert(root,17);
	root=insert(root,43);
	root=insert(root,49);
	root=insert(root,31);
	
	
	print(root);
}
