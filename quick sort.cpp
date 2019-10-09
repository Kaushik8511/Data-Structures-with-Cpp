#include<iostream>
#include<stdlib.h>
using namespace std;


int sort(int *a,int s,int e){
	int pivot,i,j,temp;
	pivot=a[e];j=s-1;
	for(i=s;i<e;i++){
		if(pivot>a[i]){
			j++;
			temp=a[i];a[i]=a[j];a[j]=temp;
		}
	}
	temp=a[j+1],a[j+1]=a[e];a[e]=temp;
	return (j+1);
}

void part(int *ar,int start,int end){
	if(start<end){
		int mid;
		mid=sort(ar,start,end);
		part(ar,start,mid-1);
		part(ar,mid+1,end);
	}
}

int main(){
	int *a,n,i;
	cout<<"how many elements you have :  ";
	cin>>n;
	a=(int *)malloc(n*sizeof(int));
	cout<<"enter elements : ";
	for(i=0;i<n;i++)cin>>a[i];
	part(a,0,n-1);
	cout<<"sorted array is : ";
	for(i=0;i<n;i++)cout<<a[i]<<"   ";
}
