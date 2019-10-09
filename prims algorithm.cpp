#include<iostream>
using namespace std;
#include<stdlib.h>

typedef struct ver{
	char name;
	int key;
	ver *parent;
	ver *next;
}ver;

typedef struct Q{
	int f,r;
	ver **p;
}Q;

void heapify(Q *q,int ind){
	int l,r,smallest;
	l=2*ind+1;r=l+1;
	smallest=ind;
	if(q->p[l]<q->p[ind] && l<=q->r)smallest=l;
	if(q->p[r]<q->p[smallest] && r<=q->r)smallest=r;
	if(ind != smallest){
		ver *temp;
		temp=q->p[smallest];q->p[smallest]=q->p[ind];q->p[ind]=temp;
		heapify(q,smallest);
	}
}
ver* adjacent(ver *u){
	ver *v;char c;
	cout<<"\nenter name of adjacent vertex : ";cin>>c;
	if(c=='Z')	return NULL;
	v=(ver *)malloc(sizeof(ver));
	v->key=10000;
	v->name=c;
	v->parent=u;
	v->next=adjacent(v);
	return v;
	
}

ver* extractmin(Q *que){
	ver *ptr;
	ptr=que->p[0];
	que->p[0]=que->p[que->r];
	que->r--;
	heapify(que,0);
	return ptr;
}

int main(){
	ver **prim;
	Q *queue;
	int n,i,j,w;
	cout<<"how many vertices in your graph : ";
	cin>>n;
	int e[n][n];
	prim=(ver **)malloc(n*sizeof(ver *));
	for(i=0;i<n;i++)prim[i]=(ver *)malloc(sizeof(ver));
	
	cout<<"enter name of vertices : ";
	for(i=0;i<n;i++){
		cin>>prim[i]->name;
		prim[i]->key=10000;
	}
	queue=(Q *)malloc(n*sizeof(Q));
	queue->f=queue->r=-1;
	queue->p=(ver **)malloc(n*sizeof(ver *));
	for(i=0;i<n;i++) queue->p[++queue->r]=prim[i];
	for(i=0;i<n;i++){
		cout<<"enter adjacet of "<<prim[i]->name<<" (enter -1 for no further adjacent vertex)";
		prim[i]->next=adjacent(prim[i]);
	}
	cout<<endl<<"enter ewight of edeges as adjacency metrix if no edge enter 0 : ";
	for(i=0;i<n;i++){
		for(j=0;j<n;j++) {
			cin>>e[i][j];
		}
	}
	queue->p[0]->key=0;
	heapify(queue,0);
	while(queue->f!=queue->r){
		ver *a,*u;
		u=extractmin(queue);
		a=u->next;
		while(a!=NULL){
			for(i=0;i<=queue->r;i++){
				if(queue->p[i]->name==a->name)break;
			}
			cout<<endl<<i<<endl;
			
			if(queue->p[i]->key > e[u->name-65][a->name-65] && i<=queue->r){
				queue->p[i]->key=e[u->name-65][a->name-65];
				
				queue->p[i]->parent=u;
			}
			a=a->next;
		}
	}
	cout<<"\nin mst edges are of weight : \n";
	for(j=0;j<n;j++)cout<<prim[j]->key<<"   ";
} 
