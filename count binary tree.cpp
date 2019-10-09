#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
	int val;
	tree *left,*right;
}tree;

//create a tree
tree* create(){
	int val;
	tree* node;
	printf("\nenter value (for no value enter -1) : ");
	scanf("%d",&val);
	if (val==-1) return NULL;
	node=(tree*)malloc(sizeof(tree));
	node->left=NULL;
	node->right-NULL;
	node->val=val;
	printf("enter left of %d  :",val);
	node->left=create();
	printf("enter right of %d  :",val);
	node->right=create();
	
}

//print tree
void print(tree* node){
	if (node!=NULL){
	print(node->left);
	printf("%d  ",node->val);
	print(node->right);}
}
//count binary tree
int count(tree *node){
	int c=1;
	if(node==NULL)return 0;
	if(node->left==NULL && node->right==NULL) return 1;
	if(node->left==NULL) c=c+count(node->right);
	else if(node->right==NULL) c=c+count(node->left);
			else{
		c = c+count(node->left)+count(node->right);
	}
	return c;
}

int main(){
	tree* Tree;
	Tree=create();
	print(Tree);
	printf("number of binary trees in a tree is :  %d",count(Tree));
	return 0;
}
