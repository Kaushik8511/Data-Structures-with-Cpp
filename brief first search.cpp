#include<stdio.h>
#include<stdlib.h>

typedef struct BFS{
	int ver;
	bool visited;
	BFS *next;
}BFS;

typedef struct Q{
	BFS **p;
	int front,rear;
}Q;

int n;//number of vertises
//adjecent vertises
BFS * adjacent(){
	BFS *newnode;
	int v;
	printf("enter -1 fo no futrher adj ver :  ");
	scanf("%d",&v);
	if (v==-1)return NULL;
	newnode=(BFS *)malloc(sizeof(BFS));
	newnode->ver=v;
	newnode->visited=false;
	newnode->next=adjacent();
	return newnode;
}

//insertion in queue
void enqueue(Q *q,BFS *a,BFS **arr){
	int i;
	while(a!=NULL){
		for(i=0;i<n;i++){
			if(arr[i]->ver==a->ver&&arr[i]->visited==false){
				q->p[++q->rear]=arr[i];
				arr[i]->visited=true;
			}
		}
	a=a->next;
	}
}
BFS * dequeue(Q *q){
	return (q->p[++q->front]);
}
//BFS travers

void travers(BFS *V,Q *que,BFS **arr){
		BFS *temp;
		enqueue(que,V,arr);
		while(que->front!=que->rear){
			temp=dequeue(que);
			printf("%d   ",temp->ver);
			enqueue(que,temp,arr);
		}
}

int main(){
	int i,ver;
	Q *queue;
	BFS **arr;
	printf("enter how many verties in your graph :  ");
	scanf("%d",&n);
	queue=(Q *)malloc(sizeof(Q));
	queue->front=queue->rear=-1;
	queue->p=(BFS **)malloc(n*sizeof(BFS *));
	arr=(BFS **)malloc(n*sizeof(BFS *));
	for(i=0;i<n;i++) arr[i]=(BFS *)malloc(sizeof(BFS));
	printf("Enter vertices (in numbers) : ");
	for(i=0;i<n;i++){
		scanf("%d",&(arr[i]->ver));
		arr[i]->visited=false;
	}
	for(i=0;i<n;i++){
		printf("Enter adjacent vertises to %d : ",arr[i]->ver);
		arr[i]->next=adjacent();
	}
	travers(arr[0],queue,arr);
}
