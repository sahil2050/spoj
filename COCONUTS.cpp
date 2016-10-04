#include<bits/stdc++.h>
using namespace std;

#define pb push_back
int const N=300;
int n,m;
vector< vector<int> > graph;
int G[N+2][N+2]; // source =0, sink=n+1;
int p[N+2];

int main(){
    scanf("%d %d",&n,&m);
    if(n==0 && m==0) return 0;
    graph.clear();
    for(int i=0;i<n+2;i++){
        vector<int> temp;
        graph.pb(temp);
    }
    bool A[n+1]; 
    memset(G,0,sizeof(G));
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        A[i]=x;
        if(x==1)G[0][i]=1,graph[0].pb(i),graph[i].pb(0);
        else G[i][n+1]=1,graph[i].pb(n+1),graph[n+1].pb(i);
    }
    for(int i=0;i<m;i++){
        int u,v;scanf("%d %d",&u,&v);
        graph[u].pb(v),graph[v].pb(u),G[u][v]++,G[v][u]++;
    }
    int flow=0;
    while(1){
        queue<int> q;
        memset(p,-1,sizeof(p));
        q.push(0);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int i=0;i<graph[u].size();i++){
                int v=graph[u][i];
                if(G[u][v] >0 && p[v]==-1 && v!=0)
                    p[v]=u,q.push(v);
            }
        }
        if(p[n+1]!=-1){
            flow++;
            int temp=n+1;
            while(p[temp]!=-1){
                G[p[temp]][temp]--;
                G[temp][p[temp]]++;
                temp=p[temp];
            }
        }
        else break;
    }
    printf("%d\n",flow);
    return main();
}
