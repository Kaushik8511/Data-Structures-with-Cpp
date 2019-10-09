#include<iostream>
#include<stdlib.h>
using namespace std;
int ls=0;int rs=0;
int count(int *ar,int s,int m,int e){
	int sum;
	sum=0;
	int n,i,j,k,l;
	i=m-s+1;
	j=e-m;
	for(k=0;k<i;k++){
		sum=sum+ar[k+i];
		}if(sum>ls) ls=sum;
	sum=0;
	for(l=0;l<j;l++){
		sum=sum+ar[l+m+1];
		
	}if(sum>rs) rs=sum;
	if(ls>0&&rs>0)return(ls+rs);
	else if(ls>rs)return ls;
	else return rs;
}

int sub(int *arr,int start,int end){
	int sum=0;
	int mid;
	mid=(start+end)/2;
	if(start<end){
		
		
		sub(arr,start,mid);
		sub(arr,mid+1,end);
		
	}
	sum=sum+count(arr,start,mid,end);
	return sum;
}

int main(){
	int *a,n,i;
	cout<<"how many numbers in your arary :  ";
	cin>>n;
	a=(int *)malloc(n*sizeof(int));
	for (i=0;i<n;i++)cin>>a[i];
	cout<<"max sum is :  "<<sub(a,0,n-1);
}
