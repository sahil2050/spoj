#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

#define pb push_back
int const N=1e5+10;
int const INF=1e9;

struct edge{
    int from,to,cap;
};

vector<edge> E;
vector<int> G[N];
int n,m,size,d[N],ptr[N],s,t;

inline void add_edge(int u,int v){
    G[u].pb((int)E.size());
    E.pb({u,v,1});
    G[v].pb((int)E.size());
    E.pb({v,u,0});
}

inline bool bfs(){
    memset(d,-1,(n+m+2)*sizeof(d[0]));
    queue<int> q;
    q.push(s);
    d[s]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<G[u].size();++i){
            int id = G[u][i];
            int v = E[id].to;
            if(d[v] == -1 && E[id].cap > 0){
                d[v] = d[u]+1;
                q.push(v);
            }
        }
    }
    return (d[t]!=-1);
}

int dfs(int u,int flow){
    if(flow == 0)return flow;
    if(u == t)return flow;
    for(;ptr[u]<G[u].size();++ptr[u]){
        int id = G[u][ptr[u]];
        int v = E[id].to;
        if(d[v] == d[u]+1 && E[id].cap > 0){ 
            if(int pushed =  dfs(v,min(E[id].cap,flow))){
                E[id].cap -= pushed;
                E[id^1].cap += pushed;
                return pushed;
            }
        }
    }
    return 0;
}

inline int dinic(){
    int flow=0;
    while(bfs()){
        memset(ptr,0,(n+m+2)*sizeof(ptr[0]));
        while(int pushed = dfs(s,INF))
            flow += pushed;
    }
    return flow;
}

int main(){
    scanf("%d %d %d",&n,&m,&size);
    s=0,t=n+m+1;
    for(int i=1;i<=n;++i)add_edge(s,i);
    for(int i=1;i<=m;++i)add_edge(n+i,t);
    int x,y;
    for(int i=0;i<size;i++){
        scanf("%d %d",&x,&y);
        add_edge(x,n+y);
    }
    printf("%d\n",dinic());
}