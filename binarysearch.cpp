#include<stdio.h>
void binarysearch(int A[],int val,int start,int end){
	int i=(start+end)/2;
	while(start<end){
		if(A[i]==val){printf("index of %d is %d",val,(i+1));break;}
		else if(val>A[i])
			binarysearch(A,val,i+1,end);
		else if(val<A[i])
			binarysearch(A,val,start,i-1);		
		else{
			printf("value is not found");break;
	}
	
}}
int main(){
	int a[20]={1,3,4,5,6,7,8,9,12,234,32,543};
	int value,i;
	printf("enter value to be search : ");
	scanf("%d",&value);
	for(i=0;i<12;i++)printf(" %d  ",a[i]);
	binarysearch(a,value,0,11);
	return 0;
}
