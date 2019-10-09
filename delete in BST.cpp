#include<stdio.h>
#include<stdlib.h>
typedef struct BST{
	int val;
	BST *left,*right;
}BST;

BST* insert(BST *node,int val){
	BST *newnode;
	newnode=(BST *)malloc(sizeof(BST));
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->val=val;
	if(node==NULL)return newnode;
	if(val<node->val) node->left=insert(node->left,val);
	else node->right=insert(node->right,val);
	
}

//print tree
void print(BST* node){
	if (node!=NULL){
	print(node->left);
	printf("%d  ",node->val);
	print(node->right);}
}

//delete a node
void del(BST *ptr,int val){
	BST *parent,*newnode;
	parent=NULL;
	while(ptr!=NULL){
		if(ptr->val==val)break;
		else if(val<ptr->val){
			parent=ptr;
			ptr=ptr->left;
		}
		else{
			parent=ptr;
			ptr=ptr->right;
		}
	}
	if(ptr==NULL)printf("Eror! element not found  :\n");
	else{
		if(ptr->left==NULL && ptr->right==NULL){
			if(parent->val<ptr->val)parent->right=NULL;
			else parent->left=NULL;
		}
		else if(ptr->left==NULL){
			if(ptr->val<parent->val)parent->left=ptr->right;
			else parent->right=ptr->right;
		}
		else if(ptr->right==NULL){
			if(ptr->val<parent->val)parent->left=ptr->left;
			else parent->right=ptr->left;
		}
		else{
			newnode=ptr;
			if(ptr->left->right==NULL){
				ptr->val=ptr->left->val;
				ptr->left=NULL;
			}
			else{
				ptr=ptr->left;
				while(ptr->right!=NULL){
				parent=ptr;
				ptr=ptr->right;}
				newnode->val=ptr->val;
				parent->right=NULL;
				
			}
		}
	}
}

int main(){
	BST *root=NULL;
	int val;
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
	root=insert(root,46);
	root=insert(root,25);
	printf("BST inorder traversal is :  ");
	print(root);
	printf("\nwhich node you want to delete : ");
	scanf("%d",&val);
	del(root,val);
	printf("new BST inorder traversal is :  ");
	print(root);
}

