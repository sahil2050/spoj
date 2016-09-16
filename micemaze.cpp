#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int const inf=100000000;

int main(){
    int n,m,t,e;
    cin>>n>>e>>t>>m;
    vector< vector <ii> > graph; //<weight,neighbour>
    for(int i=0;i<n;i++){
        vector<ii> temp;
        graph.push_back(temp);
    }
    e--;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        graph[v].push_back(make_pair(w,u));
    }
    
    priority_queue< ii,vector<ii>,greater<ii> > pq;
    pq.push(make_pair(0,e));
    int d[n];
    for(int i=0;i<n;i++)
        d[i]=inf;
    d[e]=0;

    while(!pq.empty()){
        ii top=pq.top();
        pq.pop();
        int u=top.second;
        int dist=top.first;
        if(d[u]==dist){
            //d[u]=dist;
            for(int i=0;i<graph[u].size();i++){
                int v=graph[u][i].second;
                int w=graph[u][i].first;
                if(d[v]>d[u]+w){
                    d[v]=d[u]+w;
                    pq.push(make_pair(d[v],v));
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        //cout<<d[i];
        if(d[i]<=t)
            ans++;
    }
    cout<<ans<<endl;
}
