#include<bits/stdc++.h>
using namespace std;

#define Q struct Query 

int const MAX=1e5;
int const N=2*MAX+1;
int t[2*N];
int A[MAX+1],ans[MAX+1];
int n,q;
int sqrt_n;

void update(int pos,int val){
    for(t[pos+=N]+=val;pos>1;pos>>=1)
        t[pos>>1]=max(t[pos],t[pos^1]);
}

int query(int l,int r){  // [l,r)
    l+=N,r+=N;
    int lmax=0,rmax=0;
    for(;l<r;l>>=1,r>>=1){
        if(l&1)lmax=max(lmax,t[l]);
        if(r&1)rmax=max(rmax,t[r]);
    }
    return max(lmax,rmax);
}

struct Query{
    int l,r,pos;
    Query(int L=0,int R=0,int p=0){
        l=L,r=R,pos=p;
    }
};

bool comp(Q q1,Q q2){   //sqrt decomposition
    if(q1.l/sqrt_n<q2.l/sqrt_n)return 1;
    if(q1.l/sqrt_n>q2.l/sqrt_n)return 0;
    return (q1.r<q2.r);
}

int main(){
    memset(t,0,sizeof(t));
    scanf("%d",&n);if(n==0)return 0;
    scanf("%d",&q);
    sqrt_n=floor(sqrt(n));
    for(int i=0;i<n;i++){scanf("%d",&A[i]);A[i]+=MAX;}
    Q queries[q];
    for(int i=0;i<q;i++){
        int l,r;scanf("%d %d",&l,&r);
        queries[i]=Query(--l,r,i);
    }
    sort(queries,queries+q,comp);
    int l=0,r=0;
    for(int i=0;i<q;i++){ //process queries
        while(l<queries[i].l){
            update(A[l],-1);l++;
        }
        while(l>queries[i].l){
            l--;update(A[l],1);
        }
        while(r<queries[i].r){
            update(A[r],1);r++;
        }
        while(r>queries[i].r){
            r--;update(A[r],-1);
        }
        ans[queries[i].pos]=query(0,N);
    }
    for(int i=0;i<q;i++)
        printf("%d\n",ans[i]);
    return main();
}
