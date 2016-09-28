/*
 * My first Binary Search Problem.
 */
#include<bits/stdc++.h>
using namespace std;

int const N=1e5;
int X[N];
int n,c;

bool F(int x){ // if F(x)=0 => F(y)=0 for all y>x
    int i=1,prev=0;
    int count =c-1;
    while(count > 0 && i < n){
        if(X[i]-X[prev]>=x)count--,prev=i;
        i++;
    }
    if(count==0)return 1;
    else return 0;
}

int binary_search(int l,int r){
    if(l==r-1)return l;
    int mid=l+(r-l)/2;
    if(F(mid))return binary_search(mid,r);
    else return binary_search(l,mid);
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&c);
        for(int i=0;i<n;i++)scanf("%d",&X[i]);
        sort(X,X+n);
        printf("%d\n",binary_search(0,X[n-1]-X[0]+1));
    }
}
