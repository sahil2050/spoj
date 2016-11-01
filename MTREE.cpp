#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<ll,ll>
#define vii vector<ii>
#define ff first
#define ss second
#define pb push_back

int const N=1e5+10;
int const mod=1e9+7;
vii G[N];
int n,p[N],root;
ll ans[N],dp[N];

void dfs(ll u){
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i].ff;
        if(v!=root && p[v]==-1){
            p[v]=u;
            dfs(v);
        }
    }
}

ll combine(vector<ll> A){
    if(A.size()==0)return 0;
    ll sum=0,sumsq=0;
    for(int i=0;i<A.size();i++){
        sum+=A[i],sumsq+=A[i]*A[i];
        sum%=mod,sumsq%=mod;
    }
    ll ret = ((sum*sum-sumsq)%mod+mod)%mod;
    ll two_inv=500000004;
    ret=(ret*two_inv)%mod;
    return (ret+sum)%mod;
}

void solve(ll u){
    dp[u]=1;
    vector<ll> A;
    for(int i=0;i<G[u].size();i++){
        ll v=G[u][i].ff,w=G[u][i].ss;
        if(v!=p[u]){
            solve(v);
            A.pb(dp[v]*w%mod);
            dp[u]+=dp[v]*w;
            dp[u]%=mod;
        }
    }
    ans[u]=combine(A);
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        ll u,v,w;
        scanf("%lld %lld %lld",&u,&v,&w);
        u--,v--;
        G[u].pb(ii(v,w));
        G[v].pb(ii(u,w));
    }
    memset(p,-1,sizeof(p));
    dfs(root=0);
    solve(0);
    ll x=0;
    for(int i=0;i<n;i++){
        x+=ans[i];
        x%=mod;
    }
    printf("%lld\n",x);
}
