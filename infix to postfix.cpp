#include<stdio.h>
#include<stdlib.h>
char ip[100],st[50],op[100];
int j,top;

int precedence(char a){
	if (a=='*'||a=='/') return 2;
	if (a=='^') return 3;
	if (a=='+'||a=='-')return 1;
	
}

void push(char *a,char b){
	a[++top]=b;
}

char pop(char *a){
	char temp;
	temp=a[top--];
	return temp;
}
int main(){
	char temp;
	int i=0;
	top=-1;j=0;
	st[++top]=NULL;
	printf("enter infix expression :  ");
	scanf("%s",ip);
	while(ip[i]!=NULL){
		switch(ip[i]){
			case '^':
			case'*':
			case'/':
			case '+':
			case '-':if(st[top]=='(')push(st,ip[i]);
					else {while(precedence(ip[i])<=precedence(st[top]))
						{op[j]=pop(st);j++;}
					push(st,ip[i]);}
					break;
			case '(':push(st,ip[i]);break;
			case')':while(st[top]!='('){
				op[j]=pop(st);j++;}temp=pop(st);
				break;
			default :op[j]=ip[i];j++;break;
						
		}
		
		i++;
	}
	while(st[top]!=NULL){
		op[j++]=pop(st);
	}
	printf("postfix is :   %s",op);
	return 0;
}

