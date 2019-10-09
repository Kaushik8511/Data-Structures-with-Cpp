#include<stdio.h>
#include<stdlib.h>

typedef struct lt{
	int val;
	lt *left,*right;
}lt;

typedef struct Q{
	lt **p;
	int front,rear;
}Q;

void enqueue(Q *queue,lt *ptr){
		queue->p[++(queue->rear)] = ptr;
	}	


lt * dequeue(Q *queue){
	lt *temp;
	temp=queue->p[++(queue->front)];
	return temp;
}


lt* create(){
	lt *p;
	int val;
	printf("enter value (-1 for no data);  ");
	scanf("%d",&val);
	if(val==-1)return NULL;
	p=(lt *)malloc(sizeof(lt));
	p->left=NULL;
	p->right=NULL;
	p->val=val;
	printf("enter left child of %d ",val);
	p->left=create();
	printf("enter right child of %d ",val);
	p->right=create();
	return p;
}

void print(lt *node,Q *que){
	lt *a;
	if(node==NULL)printf("tree is empty :  ");
	else enqueue(que,node);
	while(que->front!=que->rear){
		a=dequeue(que);
		printf("%d   ",a->val);
		if(a->left!=NULL)enqueue(que,a->left);
		if(a->right!=NULL)enqueue(que,a->right);
	}
}

int main(){
	Q *q;
	lt *root;
	q=(Q *)malloc(sizeof(Q));
	q->front=-1;
	q->rear=-1;
	q->p=(lt **)malloc(30*sizeof(lt));
	root=create();
	printf("\n\n");
	print(root,q);
}
