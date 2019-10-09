#include<stdio.h>
#include<stdlib.h>
struct Node{
	int val;
	struct Node* next;
};
struct Node* head;

//create a node
void create(struct Node *x){
	struct Node *y,*p;
	int i;
	y=(struct Node*) malloc(sizeof(struct Node));
	printf("enter value you want to add in list : ");
	scanf("%d",&i);
	y->val=i;
	y->next=NULL;
	p=head;
	if(head==NULL){
		x=y;
		head=x;
	}
	else{
		while(p->next!=NULL)
			p=p->next;
		p->next=y;
	}
}

//print the data structure
void print(struct Node *p){
	p=head;
	if(head==NULL) printf("list is empty !\n");
	else{
		printf("list is : \n");
		while(p!=NULL){
			printf("  %d  ",p->val);
			p=p->next;
		}
	}
	}

//insert at any
void insert(struct Node *x){
	struct Node *p,*y;
	int i,key;
	printf("after which key you want to enter value :");
	scanf("%d",&key);
	printf("enter value :");
	scanf("%d",&i);
	if(head==NULL)printf("sorry! list is empty : ");
	else{
		p=head;
		while(p!=NULL){
			if(p->val==key){
				y=(struct Node*)malloc(sizeof(struct Node));
				y->val=i;
				y->next=p->next;
				p->next=y;
				break;				
			}
			p=p->next;
		}
		if(p==NULL)printf("sorry! key is not found !\n");
	}
}

//insert at first
void insertft(struct Node *x){
	struct Node *y;
	int i;
	printf("enter value which you want to enter : ");
	scanf("%d",&i);
	y=(struct Node*)malloc(sizeof(struct Node));
	y->val=i;
	if(head==NULL) {
		head=y;
		y->next=NULL;
	}
	else{
		y->next=head;
		head=y;
	}
}

//delete first node
void deleteft(struct Node* x){
	struct Node *temp;
	temp=head;
	if(head==NULL)printf("list is empty :\n");
	else{
		head=temp->next;
		temp->next=NULL;
		free(temp);
	}
}

//delete after any key
void deletekey(struct Node*x){
	struct Node *p,*temp;
	int key;
	if(head==NULL)printf("list is empty :");
	else{
		p=head;
		printf("after which key you want to delete value :");
		scanf("%d",&key);
			while(p->next!=NULL){
			if(p->val==key){
				temp=p->next;
				p->next=p->next->next;
				free(temp);
				break;				
			}
			p=p->next;
		}
		if(p->next==NULL)printf("key is not found or its last node :");
	}
}

//delete last node
void deletelast(struct Node *x){
	struct Node *p,*temp;
	if(head==NULL)printf("list is empty :");
	else{
		p=head;
		while(p->next->next!=NULL)p=p->next;
		temp=p->next;
		p->next=NULL;
		free(temp);
	}
}

int main(){
	struct Node* node;
	int c;
	int flag=1;	
	while(flag){
		printf("enter your choice :\n1.create node\n2.insert not after any key\n3.insert first\n4.delete first\n5.delete after any key\n");
		printf("6.delete last node\n7.print\n8.exit");
		scanf("%d",&c);
		switch(c){
			case 1:create(node);
					break;
			case 2:	insert(node);break;
			case 3:insertft(node);break;
			case 4:deleteft(node);break;
			case 5:deletekey(node);
			case 6:deletelast(node);break;
			case 7:	print(node);break;
			case 8:flag=0;break;
			default:printf("ooops! wrong choice : renter your choice");
		}
	}
	
	return 0;
}
