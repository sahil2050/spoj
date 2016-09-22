#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll const mod=1e9+7;

ll pow(ll b,ll e){
    if(e==0)return 1;
    ll temp=pow(b,e>>1);
    if(e&1) return (((temp*temp)%mod)*b)%mod;
    else return (temp*temp)%mod;
}

ll inv(ll n){
    return pow(n,mod-2);
}

int main(){
    ll n,l;
    scanf("%lld %lld",&n,&l);
    if(n==0&&l==0)return 0;
    ll ans=(((pow(n,l+1)-n)*inv(n-1)%mod)+mod)%mod;
    printf("%lld\n",ans);
    return main();
}
