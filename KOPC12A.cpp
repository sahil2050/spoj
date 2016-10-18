#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll const N=1e4+10;
ll H[N],C[N];
int n;

ll cost(ll x){
    ll ans=0;
    for(int i=0;i<n;i++)ans+=abs(x-H[i])*C[i];
    return ans;
}

ll solve(ll l,ll r){
    if(l==r)return cost(l);
    ll mid=(l+r)/2;
    ll costL=cost(mid-1);
    ll costM=cost(mid);
    ll costR=cost(mid+1);
    if(costL <= costM && costM <= costR)return solve(l,mid-1);
    if(costL >= costM && costM >= costR)return solve(mid+1,r);
    return costM;
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%lld",&H[i]);
        for(int i=0;i<n;i++)scanf("%lld",&C[i]);
        printf("%lld\n",solve(0,10000));
    }
}
