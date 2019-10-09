#include<iostream>
#include<stdlib.h>
using namespace std;

int min(int *temp,int n){
	int min=temp[0];
	int i;
	for(i=1;i<=n;i++){
		if(min>temp[i])min=temp[i];
	}
	return min;
}

int mul(int *a,int start,int end){
	int *temp;
	temp=(int *)malloc((end-start)*sizeof(int));
	if (start==end)return 0;
	int k=start;
	int i;
	while(k<end){
		i=0;
		temp[i]=mul(a,start,k)+mul(a,k+1,end)+a[start]*a[end+1]*a[k+1];i++;k++;
	}
	int m=min(temp,i-1);
	return m;
}

int main(){
	int a[]={5,3,2,6,4,7};
	int minimum=mul(a,0,4);
	cout<<minimum;
	
	return 0;
}
