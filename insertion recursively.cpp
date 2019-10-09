#include<iostream>
#include<stdlib.h>
using namespace std;
void insert(int *a,int n){
	int temp;
	if(a[n]<a[n-1])
}

int main(){
	int *arr,i,n;
	cout<<"how many elelments : ";
	cin>>n;
	arr=(int *)malloc(n*sizeof(int));
	cout<<"enter elelments : ";
	for(i=0;i<n;i++)cin>>arr[i];
	insert(arr,n-1);
	cout<<"sorted array is :  ";
	for(i=0;i<n;i++)cout<<arr[i]<<"  ";
}
