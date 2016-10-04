#include<bits/stdc++.h>
using namespace std;

int const N=255,inf=1e7;
int G[N+2][N+2];
int RG[N+2,N+2];  // source -> 0 sink -> n+1
int p[N+2];
int n,m,k,l,g;

int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d %d",&n,&m,&k,&l,&g);
        memset(G,0,sizeof(G));
        for(int i=1;i<=n;i++)scanf("%d",&G[0][i]);
        for(int i=1;i<=n;i++)scanf("%d",&G[i][n+1]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&G[i][j]);
        int flow=0;
        while(1){
            memset(p,-1,sizeof(p));
            queue<int> q;
            q.push(0);
            bool x=0;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(int v=n+1;v>0;--v){
                    if(G[u][v]>0 && p[v]==-1){
                        q.push(v),p[v]=u;
                        if(v==n+1){
                            x=true;
                            break;
                        }
                    }
                }
                if(x)break;
            }
            if(x){
                int temp=n+1,f=inf;
                while(temp!=0){
                    f=min(f,G[p[temp]][temp]);
                    temp=p[temp];
                }
                temp=n+1;
                while(temp!=0){
                    G[p[temp]][temp]-=f;
                    G[temp][p[temp]]+=f;
                    temp=p[temp];
                }
                flow+=f;
            }
            else break;
        }
        printf("%d\n",flow);
    }
}
