#include<bits/stdc++.h>
using namespace std;

#define ll long long
int const mod=1e9+7;
int const N=1e5;
ll t[2*N][2];
int n,q;

void build(){
    for(int j=0;j<2;j++)
        for(int i=n-1;i>0;i--)t[i][j]=(t[i<<1][j]+t[i<<1|1][j])%mod;
}

ll query(int l,int r,int k){
    l+=n,r+=n;
    ll ans=0;
    for(;l<r;l>>=1,r>>=1){
        if(l&1)ans=(ans+t[l++][k])%mod;
        if(r&1)ans=(ans+t[--r][k])%mod;
    }
    return (ans%mod+mod)%mod;
}

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&q);
        for(int i=0;i<n;i++){
            scanf("%lld",&t[i+n][0]);
            t[i+n][1]=(i+1)*t[i+n][0];
        }
        build();
        while(q--){
            int x,y,z,w;scanf("%d %d %d %d",&w,&x,&y,&z);
            int l=y+x-1,r=z+x;
            ll ans=query(l,r,1)+(ll)(w-x)*query(l,r,0);
            ans=(ans%mod+mod)%mod;
            printf("%lld\n",ans);
        }
    }
}
