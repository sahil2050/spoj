#include<bits/stdc++.h>
using namespace std;

#define pb push_back
int const N=1e3;
int const LogN=11;

int n,P[N],L[N],dp[N][LogN]; // dp[i][j]=2^jth ancestor of ith node
vector< vector <int> > G;
int root;

void dfs(int u){
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        L[v]=L[u]+1;
        dp[v][0]=u;
        dfs(v);
    }
}

void preprocess(){
    for(int j=1;j<LogN;j++){
        for(int i=0;i<n;i++){
            dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }
}

int lca(int a,int b){
    if(L[a]>L[b])swap(a,b);
    int d=L[b]-L[a];
    for(int i=LogN;i>=0;i--)
        if(d&(1<<i))b=dp[b][i];
    if(a==b)return a;
    for(int i=LogN-1;i>=0;i--){
        if(dp[a][i]!=dp[b][i])
            a=dp[a][i],b=dp[b][i];
    }
    return dp[a][0];
}

int main(){
    int t;scanf("%d",&t);
    for(int T=1;T<=t;T++){
        printf("Case %d:\n",T);
        scanf("%d",&n);
        G.clear();
        memset(P,-1,sizeof(P));
        for(int i=0;i<n;i++){
            vector<int> adjList;
            int size;scanf("%d",&size);
            for(int j=0;j<size;j++){
                int v;scanf("%d",&v);
                adjList.pb(--v);
                P[v]=i;
            }
            G.pb(adjList);
        }
        for(int i=0;i<n;i++)
            if(P[i]==-1)root=i;
        L[root]=0,P[root]=root,dp[root][0]=root;
        dfs(root);
        preprocess();
        int q;scanf("%d",&q);
        while(q--){
            int a,b;scanf("%d %d",&a,&b);
            printf("%d\n",lca(--a,--b)+1);
        }
    }
}
