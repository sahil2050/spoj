#include<bits/stdc++.h>
using namespace std;

#define ll long long 

ll pow(ll b,ll e,ll mod){
    if(e==0)return 1;
    ll temp=pow(b,e>>1,mod);
    temp=(temp*temp)%mod;
    if(e&1)return temp*b%mod;
    else return temp;
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        ll a,p;scanf("%lld %lld",&a,&p);
        if(a%p==0){
            printf("0\n");
            continue;
        }
        ll ans=pow(a,(p-1)>>1,p);
        if(ans!=1)ans=-1;
        printf("%lld\n",ans);
    }
}

