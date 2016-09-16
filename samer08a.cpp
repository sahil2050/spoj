#include<bits/stdc++.h>
using namespace std;

int const inf=1000000000;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
    int n,m;
    cin>>n>>m;
    if(n==0&&m==0)return 0;
    int s,t;
    cin>>s>>t;
    int graph[n][n];
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++)
           graph[i][j]=inf;
       graph[i][i]=0;
    }
        
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        graph[u][v]=w;
    }

    int ds[n],dt[n];
    for(int i=0;i<n;i++)
        ds[i]=inf,dt[i]=inf;

    priority_queue < ii , vii , greater<ii> > pq;
    pq.push(make_pair(0,s));
    ds[s]=0;

    while(!pq.empty()){
        ii top = pq.top();
        pq.pop();
        int u = top.second;
        int dist = top.first;
        if(ds[u]==dist){
            for(int v=0;v<n;v++)
                if(ds[v]>ds[u]+graph[u][v]){
                    ds[v]=ds[u]+graph[u][v];
                    pq.push(make_pair(ds[v],v));
                }
        }
    }

    pq.push(make_pair(0,t));
    dt[t]=0;

    while(!pq.empty()){
        ii top = pq.top();
        pq.pop();
        int u = top.second;
        int dist = top.first;
        //cout<< u << dist << "**"<<endl; 
        if(dt[u]==dist){
            for(int v=0;v<n;v++)
                if(dt[v]>dt[u]+graph[v][u]){
                    dt[v]=dt[u]+graph[v][u];
                    pq.push(make_pair(dt[v],v));
                }
        }
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(ds[i]+graph[i][j]+dt[j]==ds[t]&&i!=j)
                graph[i][j]=inf;
    
    for(int i=0;i<n;i++)
        ds[i]=inf;
    
    pq.push(make_pair(0,s));
    ds[s]=0;

    while(!pq.empty()){
        ii top = pq.top();
        pq.pop();
        int u = top.second;
        int dist = top.first;
        if(ds[u]==dist){
            for(int v=0;v<n;v++)
                if(ds[v]>ds[u]+graph[u][v]){
                    ds[v]=ds[u]+graph[u][v];
                    pq.push(make_pair(ds[v],v));
                }
        }
    }


    if(ds[t]<inf)cout<<ds[t]<<endl;
    else cout<<-1<<endl;

    return main();
}
