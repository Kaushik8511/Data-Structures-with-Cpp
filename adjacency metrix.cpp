#include<stdio.h>
#include<stdlib.h>

int main(){
	char v[5]={'A','B','C','D','E'};
	int temp;
	int i,a[5][5]={0},j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
				printf("%c is adjacent to %c ? (enter 1 for yes or 0 for no) :  ",v[i],v[j]);
				scanf("%d",&temp);
				a[i][j]=temp;	
		}
	}
	printf("    ");
	for(i=0;i<5;i++)printf("%c   ",v[i]);
	printf("\n");
	for(i=0;i<5;i++){
		printf("%c   ",v[i]);
		for(j=0;j<5;j++)printf("%d   ",a[i][j]);
		printf("\n");}	
}
