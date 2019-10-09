#include<iostream>
using namespace std;

class ver{
public:
    char name;
    ver *parent;
    ver(){
        parent=NULL;
    }
};
typedef struct edge{
    char source,dest;
    int weight;
}edge;

void merging(edge **e2,int s,int m,int e){
    edge **left,**right;
    int i=m-s+1;
    int j=e-m;
    left=new edge*[i];
    right=new edge*[j];
    int n,k,l;n=s;
    for(k=0;k<i;k++){
        left[k]=new edge;
        left[k]=e2[s+k];
    }
    for(l=0;l<j;l++){
        right[l]=new edge;
        right[l]=e2[m+1+l];
    }k=l=0;
    while(k!=i&&l!=j){
        if(left[k]->weight<=right[l]->weight){
            e2[n]=left[k];
            n++;k++;
        }
        else{
            e2[n]=right[l];
            n++;l++;
        }
    }
    while(k!=i){
        e2[n]=left[k];
        k++;n++;
    }
    while(l!=j){
        e2[n]=right[l];
        n++;l++;
    }
}

void mergesort(edge **e1,int i,int j){
    int m;
    if(i<j){
        m=(i+j)/2;
        mergesort(e1,i,m);
        mergesort(e1,m+1,j);
        merging(e1,i,m,j);
    }
}

char finder(char c,ver **v,int n){
    int i;
    for(i=0;i<n;i++){
        if(v[i]->name==c)break;
    }
    ver *ptr;
    ptr=v[i];
    while(ptr->parent!=NULL){
        ptr=ptr->parent;
    }
    return ptr->name;
}

void uniona(edge *ee,ver **v1,int n){
    int i,j;
    for(i=0;i<n;i++)if(v1[i]->name==ee->source)break;
    for(j=0;j<n;j++)if(v1[j]->name==ee->dest)break;
    ver *ptr1,*ptr2;ptr1=v1[i];
    ptr2=v1[j];
    while(ptr1->parent!=NULL)ptr1=ptr1->parent;
    while(ptr2->parent!=NULL)ptr2=ptr2->parent;
    ptr2->parent=ptr1;
}

int main(){
    ver **vertex;
    edge **e;
    int n,i;
    cout<<"how many vertices in your graph : ";
    cin>>n;
    vertex=new ver*[n];
    for(i=0;i<n;i++)vertex[i]=new ver;
    cout<<"enter name of vertices : ";
    for(i=0;i<n;i++){
        cin>>vertex[i]->name;
    }
    cout<<"how many edges in your graph: ";
    int m;cin>>m;
    e=new edge*[m];
    for(i=0;i<m;i++)e[i]=new edge;
    for(i=0;i<m;i++){
        cout<<"enter source, destination and weight of edge: ";
        cin>>e[i]->source;cin>>e[i]->dest;
        cin>>e[i]->weight;
    }
    mergesort(e,0,m-1);
    edge **mst;
    int w=0;
    mst=new edge*[n-1];
    for(i=0;i<n-1;i++)mst[i]=new edge;
    for(i=0;i<m;i++){
            if(finder(e[i]->dest,vertex,n)!=finder(e[i]->source,vertex,n)){
                mst[w]=e[i];w++;
                uniona(e[i],vertex,n);
            }
    }
    cout<<"\nedges in the MST are : \n";
    for(i=0;i<n-1;i++){
        cout<<"source : "<<mst[i]->source<<"    destination : "<<mst[i]->dest<<"    weight : "<<mst[i]->weight<<endl;
    }
    return 0;
}
