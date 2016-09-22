#include<bits/stdc++.h>
using namespace std;

vector< vector < int > > G;
int n;
int d[10000];

void dfs(int u){
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(d[v]==-1){
            d[v]=d[u]+1;
            dfs(v);
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){vector<int> vi;G.push_back(vi);}
    for(int i=0;i<n-1;i++){
        int u,v;scanf("%d %d",&u,&v);
        --u,--v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    memset(d,-1,sizeof(d));
    d[0]=0;
    dfs(0);
    int s=0;
    for(int i=0;i<n;i++)
        if(d[s]<d[i])s=i;
    memset(d,-1,sizeof(d));
    d[s]=0;
    dfs(s);
    int ans=0;
    for(int i=0;i<n;i++)
        ans=max(ans,d[i]);
    printf("%d\n",ans);
}
