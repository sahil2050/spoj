#include<bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second

using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vii G[1000];
int n,price,m;
bool v[1000];

int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&price,&n,&m);
        memset(v,0,sizeof(v));
        for(int i=0;i<n;i++)G[i].clear();
        for(int i=0;i<m;i++){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            --u,--v;
            G[u].pb(ii(w,v)),G[v].pb(ii(w,u));
        }
        priority_queue < ii ,vii ,greater<ii> > pq;
        int ans=0;
        pq.push(ii(0,0));
        while(!pq.empty()){
            ii top=pq.top();
            pq.pop();
            int u=top.ss,w=top.ff;
            if(!v[u]){
                v[u]=1,ans+=w;
                for(int i=0;i<G[u].size();i++)
                    pq.push(G[u][i]);
            }
        }
        printf("%d\n",ans*price);
    }
}
