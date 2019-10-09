#include<stdio.h>
#include<stdlib.h>
struct stack{
	int size;
	int *a;
	int top;
};
void push(struct stack *Stack,int val){
	if(Stack->top == (Stack->size-1))printf("stack is full !");
	else{
				Stack->a[++(Stack->top)]=val;
	}
}

//pop the stack
void pop(struct stack *Stack){
	
	if(Stack->top == -1)printf("stack is empty ! ");
	else Stack->a[(Stack->top)--]=-1;
}

//print stack
void print(struct stack *Stack){
	int temp=Stack->top;
	if(Stack->top == -1)printf("stack is empty ! ");
	else{
		
		while(temp!=-1){
			printf("%d  ",Stack->a[temp]);
			temp--;
		}
		printf("\n");
	}
}

int main(){
	struct stack* S;
	S=(struct stack*)malloc(sizeof(struct stack));
	S->top=-1;
	printf("enter size of stack");
	scanf("%d",&(S->size));
	S->a=(int *)malloc(S->size*sizeof(int));
	push(S,5);
	push(S,10);
	push(S,6);
	push(S,12);
	print(S);
	pop(S);
	print(S);
	return 0;
}
