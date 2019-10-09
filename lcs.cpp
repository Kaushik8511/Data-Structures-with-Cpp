#include<iostream>
using namespace std;

int max(int x,int y){
	return (x>y ? x:y);
}

int sub(char *a,char *b,int m[17][17],int i,int j){
	if(i==0 || j==0)return 0;
	int k,l;
	for (k=1;k<=i;k++){
		for (l=1;l<=j;l++){
			if(a[k]==b[l])m[k][l]=m[k-1][l-1]+1;
			else m[k][l]=max(m[k][l-1],m[k-1][l]);
		}
	}
	return (m[i][j]);
}

int main(){
	char *a="kaushik_prajapati";
	char *b="kaushik_prajapati";
	int m[17][17];
	int i,j;
	for(i=0;i<17;i++)m[i][0]=0;
	for(j=0;j<17;j++)m[0][j]=0;
	int c=sub(a,b,m,17,17);
	cout<<c;
	return 0;
}
