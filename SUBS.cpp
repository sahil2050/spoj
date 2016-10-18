#include<bits/stdc++.h>
using namespace std;

int const N=5e5+20;
char X[N],Y[N];
int n,m;

bool is_subSeq(int k){
    int i=0,j=0;
    for(;i<m;i++){
        if(X[j/k]==Y[i])j++;
        if(j==n*k)return 1;
    }
    return 0;
}

int search(int l,int r){
    if(l==r-1)return l;
    int mid=(l+r)>>1;
    if(is_subSeq(mid))return search(mid,r);
    else return search(l,mid);
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%s",X);
        scanf("%s",Y);
        n=strlen(X),m=strlen(Y);
        printf("%d\n",search(0,1+m/n));
    }
}
