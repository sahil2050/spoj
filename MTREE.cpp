#include<bits/stdc++.h>
using namespace std;

#define  pb push_back
#define ff first
#define ss second

int const mod = 1e9+7;
int const N=100000;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

vector<vii> graph;
ll p[N];
int n,root=0;
ll dp[N][2];

void solve(int u){
    if(dp[u][0]!=-1)return ;
    dp[u][0]=1,dp[u][1]=1;
    for(int i=0;i<graph[u].size();i++){
        int v=graph[u][i].ff,w=graph[u][i].ss;
        if(v!=p[u]){
            solve(v);
            dp[u][0]+=(w*dp[v][1])%mod;
            dp[u][1]+=(w*dp[v][1])%mod;
            dp[u][0]%=mod,dp[u][1]%=mod;
            for(int j=0;j<i;j++){
                int v2=graph[u][j].ff,w2=graph[u][j].ss;
                if(v2!=p[u]){
                    solve(v2);
                    dp[u][0]+=((w*dp[v][1])%mod)*((w2*dp[v2][1])%mod)%mod;
                    dp[u][0]%=mod;
                }
            }
        }
    } 
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        vii temp;graph.pb(temp);
    }
    for(int i=0;i<n-1;i++){
        ll u,v,w;scanf("%lld %lld %lld",&u,&v,&w);
        u--,v--;
        graph[u].pb(ii(v,w));
        graph[v].pb(ii(u,w));
    }
    
    memset(p,-1,sizeof(p));
    stack<ll> s;
    s.push(root);
    while(!s.empty()){
        int u=s.top();
        s.pop();
        for(int i=0;i<graph[u].size();i++){
            int v=graph[u][i].ff;
            if(p[v]==-1&&v!=root){
                s.push(v);
                p[v]=u;
            }
        }
    }
    
    memset(dp,-1,sizeof(dp));
    solve(root);
    ll ans=0;
    for(int i=0;i<n;i++)ans+=dp[i][0];
    printf("%lld",(ans-n+mod)%mod);
}
