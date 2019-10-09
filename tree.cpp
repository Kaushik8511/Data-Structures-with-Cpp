#include<stdio.h>
#include<stdlib.h>
struct tree{
	int val;
	struct tree *left,*right;
};

//create tree
struct tree* createtree(){
	struct tree *node;
	int val;
	printf("if no data then enter -1 ");
	printf("\nenter value: ");
	scanf("%d",&val);
	if(val==-1) return NULL;
	node=(struct tree*)malloc(sizeof(struct tree));
	node->val=val;
	node->left=NULL;
	node->right=NULL;
	printf("enter left child of %d: ",node->val);
	node->left=createtree();
	printf("enter right node of %d : ",node->val);
	node->right=createtree();
	return node;
}

//print tree
int print(struct tree* node){
	if (node!=NULL){
	print(node->left);
	printf("%d  ",node->val);
	print(node->right);}
}

int main(){
	struct tree *root;
	
	root=createtree();
	print(root);
}
