#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int const N=1e5;
ll t[2*N],d[N];
int n,q,h;

void apply(int pos,ll val,ll k){
    t[pos]+=val*k;
    if(pos<n)d[pos]+=val;
}

void build(int pos){
    for(ll k=2;pos>1;pos>>=1,k<<=1)t[pos>>1]=t[pos]+t[pos^1]+d[pos>>1]*k;
}

void push(int pos){
    for(ll s=h,k=1<<(h-1);s>0;--s,k>>=1){
        int i=pos>>s;
        if(d[i]!=0){
            apply(i<<1,d[i],k);
            apply(i<<1|1,d[i],k);
            d[i]=0;
        }
    }
}

void inc(int l,int r,ll val){
    l+=n,r+=n;
    ll l0=l,r0=r;
    push(l);
    push(r-1);
    for(ll k=1;l<r;l>>=1,r>>=1,k<<=1){
        if(l&1)apply(l++,val,k);
        if(r&1)apply(--r,val,k);
    }
    build(l0);
    build(r0-1);
}

ll query(int l,int r){
    l+=n,r+=n;
    push(l);
    push(r-1);
    ll ans=0;
    for(;l<r;l>>=1,r>>=1){
        if(l&1)ans+=t[l++];
        if(r&1)ans+=t[--r];
    }
    return ans;
}

int main(){
    int c;scanf("%d",&c);
    while(c--){
        scanf("%d %d",&n,&q);
        memset(t,0,sizeof(t));
        memset(d,0,sizeof(d));
        h=(ll)(sizeof(int)*8-__builtin_clz(n));
        while(q--){
            int x;scanf("%d",&x);
            if(x==1){
                int l,r;scanf("%d %d",&l,&r);
                printf("%lld\n",query(min(l,r)-1,max(l,r)));
            }
            else{
                int l,r;ll v;scanf("%d %d %lld",&l,&r,&v);
                inc(min(l,r)-1,max(l,r),v);
            }
        }
    }
}
