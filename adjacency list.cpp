#include<stdio.h>
#include<stdlib.h>

typedef struct adj{
	int c;
	adj *next;
}adj;

//adjoint of vertex
adj * adjoint(){
	int v;
	adj *node;
	printf("enter -1 for no further verties :");
	scanf("%d",&v);
	if(v==-1)return NULL;
	node=(adj *)malloc(sizeof(adj));
	node->c=v;
	node->next=NULL;
	node->next=adjoint();
	return node;
}

//print adjoint list
void print(adj *ver){
	if (ver==NULL)printf("no adjecent vertex :");
	else{
		while(ver!=NULL){
			printf("%d  ",ver->c);
			ver=ver->next;
		}
	}
	printf("\n");
}

int main(){
	int n,i;
	adj **a;
	printf("how many vertices is there in your graph : ");
	scanf("%d",&n);
	a=(adj **)malloc(n*sizeof(adj *));
	for(i=0;i<n;i++)a[i]=(adj *)malloc(sizeof(adj));
	printf("enter vertices (name in integer):  ");
	for (i=0;i<n;i++)scanf("%d",&(a[i]->c));
	for (i=0;i<n;i++){
		printf("enter adjoint of %d : ",a[i]->c);
		a[i]->next=adjoint();
		
	}
	for(i=0;i<n;i++){
		printf("adjoint vertices to %d are : ",a[i]->c);
		print(a[i]->next);
	}	
}
