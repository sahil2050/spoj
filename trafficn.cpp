#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,int> ii;
typedef vector<ii> vii;
ll const inf=3000000000;

int main(){
    //cout<<inf<<endl;
    int t;cin>>t;
    while(t--){
        int n,m,k,s,t;
        cin>>n>>m>>k>>s>>t;
        s--,t--;
        vector<vii> graph,graph_t;
        for(int i=0;i<n;i++){
            vii temp1;
            graph.push_back(temp1);
            vii temp2;
            graph_t.push_back(temp2);
        }
        for(int i=0;i<m;i++){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            u--,v--;
            graph[u].push_back(make_pair(w,v));
            graph_t[v].push_back(make_pair(w,u));
        }
       
        //for(int i=0;i<n;i++)
        //    for(int j=0;j<graph_t[i].size();j++)
        //        cout<<graph_t[i][j].first<<" "<<graph_t[i][j].second<<endl;

        ll ds[n],dt[n];
        for(int i=0;i<n;i++)
            ds[i]=inf,dt[i]=inf;

        priority_queue< ii , vii , greater<ii> > pq;
        ds[s]=0;
        pq.push(make_pair(0,s));
        while(!pq.empty()){
            ii top=pq.top();
            pq.pop();
            int u=top.second;
            int dist=top.first;
            if(ds[u]==dist){
                for(int i=0;i<graph[u].size();i++){
                    int v=graph[u][i].second;
                    int w=graph[u][i].first;
                    if(ds[v]>ds[u]+w){
                        ds[v]=ds[u]+w;
                        pq.push(make_pair(ds[v],v));
                    }
                }
            }
        }

        dt[t]=0;
        pq.push(make_pair(0,t));
        while(!pq.empty()){
            ii top=pq.top();
            pq.pop();
            int u=top.second;
            int dist=top.first;
            if(dt[u]==dist){
                for(int i=0;i<graph_t[u].size();i++){
                    int v=graph_t[u][i].second;
                    int w=graph_t[u][i].first;
                    if(dt[v]>dt[u]+w){
                        dt[v]=dt[u]+w;
                        pq.push(make_pair(dt[v],v));
                    }
                }
            }
        }
        
        ll ans=ds[t];
        while(k--){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            u--,v--;
            ans=min(ans,ds[u]+w+dt[v]);
            ans=min(ans,ds[v]+w+dt[u]);
        }
        
        /*
        for(int i=0;i<n;i++)
            cout<<ds[i]<<" ";
        cout<<endl;

        for(int i=0;i<n;i++)
            cout<<dt[i]<<" ";
        cout<<endl;
        */
        if(ans>=inf)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}

