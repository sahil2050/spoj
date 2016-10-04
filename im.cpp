#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n,m;scanf("%d %d",&n,&m);
        map<int,int> G[2*n+1];
        G[0][1]=1;G[0][5]=1;
        for(int i=1;i<=n;i++)
            G[2*i-1][2*i]=1;
        for(int i=0;i<m;i++){
            int u,v;scanf("%d %d",&u,&v);
            if(max(u,v)>n)continue;
            G[2*u][2*v-1]=1;
            G[2*v][2*u-1]=1;
        }
        int source=0,sink=3;
        int flow=0; // source=0, sink=3
        int p[2*n+1];
        map<int,int>::iterator it;
        while(1){
            memset(p,-1,sizeof(p));
            queue<int> q;
            q.push(0);
            while(!q.empty()){
                int u=q.front();
                q.pop();
                if(u==sink)break;
                for(it=G[u].begin();it!=G[u].end();it++){
                    int v=it->first;
                    if(p[v]==-1 && it->second > 0){
                        q.push(v);p[v]=u;
                    }
                }
            }
            if(p[sink]==-1)break;
            int temp=sink;
            while(temp!=source){
                G[p[temp]][temp]--;
                G[temp][p[temp]]++;
                temp=p[temp];
            }
            flow++;
        }
        if(flow==2)printf("YES\n");
        else printf("NO\n");
    }
}
