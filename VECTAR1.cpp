#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll const mod = 1e9+7;
ll dp[1024],F[1001000];

ll fact(ll n){
    ll ans=1;
    for(ll i=1;i<=n;i++)ans=(ans*i)%mod;
    return ans;
}

int main(){
    int t;scanf("%d",&t);
    F[0]=1;
    for(ll i=1;i<1001000;i++)F[i]=(F[i-1]*i)%mod;
    while(t--){
        memset(dp,0,sizeof(dp));
        ll N,M;scanf("%lld %lld",&N,&M);
        for(int i=1;i<=M;i++)
            for(int j=1;j<=N;j++)
                dp[i^j]++;
        ll ans=1;
        for(int i=0;i<1024;i++)ans=(ans*F[dp[i]])%mod;
        printf("%lld\n",ans%mod);
    }
}
