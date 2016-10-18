#include<bits/stdc++.h>
using namespace std;

int const N=1e5+10;
int n,m,s,prefixP[N],prefixT[N],T[N],P[N];

void preprocess(){
    int k=prefixP[0]=-1;
    for(int i=1;i<m;i++){
        while(k>=0 && P[i]!=P[k+1])k=prefixP[k];
        if(P[i]==P[k+1])k++;
        prefixP[i]=k;
    }
    k=prefixT[0]=-1;
    for(int i=1;i<n;i++){
        while(k>=0 && T[i]!=T[k+1])k=prefixT[k];
        if(T[i]==T[k+1])k++;
        prefixT[i]=k;    
    }
}
int main(){
    scanf("%d %d %d",&n,&m,&s);
    for(int i=0;i<n;i++)scanf("%d",&T[i]);
    for(int i=0;i<m;i++)scanf("%d",&P[i]);
    preprocess();
    for(int i=0;i<n;i++)cout<<prefixT[i]<<" ";
    cout<<endl;
    for(int i=0;i<m;i++)cout<<prefixP[i]<<" ";
    cout<<endl;
}
