#include<bits/stdc++.h>
using namespace std;

int const N=1e5+10;
int const logN=20;
int const inf=1e9;

int dp[N][logN],L[N],par[N],sub[N];
multiset<int> ans[N];
set<int> G[N];
int n,q;

/*******preprocess**********/
void dfs(int u){
    for(auto it=G[u].begin();it!=G[u].end();it++){
        int v=*it;
        if(v!=dp[u][0]){
            L[v]=L[u]+1;
            dp[v][0]=u;
            dfs(v);
        }
    }
}

void preprocess(){
    L[0]=0;
    dp[0][0]=0;
    dfs(0);
    for(int j=1;j<20;j++)
        for(int i=0;i<n;i++)
            dp[i][j]=dp[dp[i][j-1]][j-1];
}

int lca(int a,int b){
    if(L[a]>L[b])swap(a,b);
    int d=L[b]-L[a];
    for(int i=0;i<logN;i++)
        if((1<<i)&d)b=dp[b][i];
    if(a==b)return a;
    for(int i=logN-1;i>=0;i--)
        if(dp[a][i]!=dp[b][i])
            a=dp[a][i],b=dp[b][i];
    return dp[a][0];
}

int dist(int a,int b){
    return L[a]+L[b]-2*L[lca(a,b)];
}
/***centroid decomposition***/
int nn=0;

void dfs1(int u,int p){ //sets the subtree size for each node
    sub[u]=1;
    for(auto it=G[u].begin();it!=G[u].end();it++){
        int v=*it;
        if(v!=p){
            dfs1(v,u);
            sub[u]+=sub[v];
        }
    }
    nn=sub[u];
}

int dfs2(int u,int p){ //return the centroid
    for(auto it=G[u].begin();it!=G[u].end();it++){
        int v=*it;
        if(v!=p && sub[v]>nn/2)return dfs2(v,u);
    }
    return u;
}

void decompose(int u,int p){
    nn=0;
    dfs1(u,u);
    int centroid=dfs2(u,u);
    //if(p==-1)p=centroid;
    par[centroid]=p;
    for(auto it=G[centroid].begin();it!=G[centroid].end();it++){
        int v=*it;
        if(v!=p){
            G[v].erase(centroid);
            decompose(v,centroid);
        }
    }
    G[centroid].clear();
}

/********handle queries****/

void update(int u){
    if(*ans[u].begin()==0){ // color[u]=white;
        ans[u].erase(0);
        for(int i=par[u];i!=-1;i=par[i])
            ans[i].erase(dist(i,u));
    }
    else {
    	ans[u].insert(0);
    	for(int i=par[u];i!=-1;i=par[i])
        	ans[i].insert(dist(i,u));
    }
}

int query(int v){
    int ret=inf;
    for(int i=v;i!=-1;i=par[i])
        ret=min(ret,*ans[i].begin()+dist(i,v));
    if(ret==inf)return -1;
    return ret;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int u,v;scanf("%d %d",&u,&v);
        --u,--v;
        G[u].insert(v),G[v].insert(u);
    }
    preprocess();
    decompose(0,-1);
    scanf("%d",&q);
    for(int i=0;i<n;i++)ans[i].insert(inf);
    while(q--){
        int x,u;scanf("%d %d",&x,&u);
        if(x==1)printf("%d\n",query(--u));
        else update(--u);
    }
}
