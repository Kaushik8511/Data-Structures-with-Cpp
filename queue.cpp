#include<stdio.h>
#include<stdlib.h>
struct queue{
	int f,r,size;
	int *a;
};
void enqueue(struct queue *Q,int val){
	if(Q->r == (Q->size)-1)printf("queue is full");
	else{(Q->r)++;
		Q->a[(Q->r)]=val;
	}
}
void dequeue(struct queue *Q){
	if (Q->f==Q->size-1)printf("queue is empty!");
	else{
		Q->a[++(Q->f)]=-1;
	}
}

void print(struct queue *Q){
	int temp;
	temp=Q->f+1;
	if (Q->f==Q->r)printf("queue is empty !");
	else{
		while(temp<=Q->r){printf("%d  ",Q->a[temp]);
		temp++;
		}printf("\n");
	}
}
int main(){
	struct queue *Queue;
	Queue=(struct queue*)malloc(sizeof(struct queue));
	Queue->f=-1;
	Queue->r=-1;
	printf("enter size of queue :");
	scanf("%d",&Queue->size);
	Queue->a=(int *)malloc(Queue->size*sizeof(int));
	enqueue(Queue,40);
	enqueue(Queue,10);
	enqueue(Queue,30);
	dequeue(Queue);
	print(Queue);
	return 0;  
}
