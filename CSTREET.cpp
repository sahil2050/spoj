#include<bits/stdc++.h>
using namespace std;

#define pb push_back
typedef pair<int,int> ii;
typedef vector<ii> vii;

vii G[1000];
int n,price,m;
int p[1000];

int root(int u){
    if(p[u]<0)return u;
    return p[u]=root(p[u]);
}

void merge(int u,int v){
    if((u=root(u))==(v=root(v)))return;
    else if(p[u])
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&price,&m);
        for(int i=0;i<n;i++)G[i].clear(),p[i]=i;
        for(int i=0;i<n;i++){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            --u,--v;
            G[u].pb(v),G[v].pb(u);
        }
        priority_queue < ii ,vii ,greater<ii> > pq;

    }
}
