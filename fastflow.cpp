#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
ll const N=1e5+10;
ll const INF=1e9;

struct edge{
    ll from,to,cap,flow;
    edge(ll a,ll b,ll c){
        from=a,to=b,cap=c,flow=0;
    }
};

vector<edge> E;
vector<ll> G[N];
ll n,m,size,d[N],ptr[N],s,t;

inline void add_edge(ll u,ll v,ll cap){
    G[u].pb((ll)E.size());
    E.pb(edge(u,v,cap));
    G[v].pb((ll)E.size());
    E.pb(edge(v,u,cap));
}

inline bool bfs(){
    memset(d,-1,sizeof(d));
    queue<ll> q;
    q.push(s);
    d[s]=0;
    while(!q.empty()){
        ll u=q.front();
        q.pop();
        for(ll i=0;i<G[u].size();++i){
            ll id = G[u][i];
            edge e = E[id];
            ll v = e.to;
            if(d[v] == -1 && e.cap > e.flow){
                d[v] = d[u]+1;
                q.push(v);
            }
        }
    }
    return (d[t]!=-1);
}

ll dfs(ll u,ll flow){
    if(flow == 0)return flow;
    if(u == t)return flow;
    for(;ptr[u]<G[u].size();++ptr[u]){
        ll id = G[u][ptr[u]];
        edge e = E[id];
        ll v = e.to;
        if(d[v] == d[u]+1 && e.cap > e.flow){ 
            if(ll pushed =  dfs(v,min(e.cap-e.flow,flow))){
                E[id].flow += pushed;
                E[id^1].flow -= pushed;
                return pushed;
            }
        }
    }
    return 0;
}

inline ll dinic(){
    ll flow=0;
    while(bfs()){
        memset(ptr,0,sizeof(ptr));
        while(ll pushed = dfs(s,INF))
            flow += pushed;
    }
    return flow;
}

int main(){
    scanf("%lld %lld",&n,&m);
    s=0,t=n-1;
    for(ll i=0;i<m;i++){
        ll x,y,z;scanf("%lld %lld %lld",&x,&y,&z);
        add_edge(x-1,y-1,z);
    }
    printf("%lld\n",dinic());
}
