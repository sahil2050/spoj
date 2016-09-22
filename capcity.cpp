#include<bits/stdc++.h>
using namespace std;

int const N=1e5+1;

vector< vector <int> > graph;
stack<int> s;
int color[N+1];// 0-> unvisited 1-> in progress 2-> finished
int d[N+1]; // dfs_count of dfs call
int low[N+1];
int scc_label[N+1];
int dfs_count=0;
int scc_count=0;

int capital;

void scc(int u){
    low[u]=d[u]=dfs_count++;
    color[u]=1,s.push(u);
    for(int i=0;i<graph[u].size();i++){
        int v=graph[u][i];
        if(color[v]==0)scc(v);
        if(color[v]==1)low[u]=min(low[u],low[v]);
    }
    if(low[u]==d[u]){
        while(!s.empty()&&s.top()!=u){
            int v=s.top();s.pop();
            scc_label[v]=scc_count;
            color[v]=2;
        }
        if(!s.empty())//s.top == u
            scc_label[u]=scc_count,color[u]=2,s.pop();
        //cout<<scc_count<< "**"<<u<<"##"<<scc_label[u]<<endl;
        if(scc_count>scc_label[capital])capital=u;
        scc_count++;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        vector<int> vi;
        graph.push_back(vi);
    }

    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        u--,v--;
        graph[v].push_back(u);//construct G transpose
    }
    memset(color,0,sizeof(color));
    
    for(int i=0;i<n;i++)
        if(color[i]==0)scc(i);
    
    bool is_reachable[n];
    memset(is_reachable,0,sizeof(is_reachable));
    stack<int> s;
    s.push(capital);
    is_reachable[capital]=1;
    while(!s.empty()){
        int u=s.top();
        s.pop();
        for(int i=0;i<graph[u].size();i++){
            int v=graph[u][i];
            if(!is_reachable[v])is_reachable[v]=1,s.push(v);
        }
    }
    bool x=true;
    for(int i=0;i<n;i++)x&=is_reachable[i];
    if(!x){
        cout<<0<<endl;
        return 0;
    }
    
    vector<int> cities;
    for(int i=0;i<n;i++)
        if(scc_label[i]==scc_label[capital])cities.push_back(i);
    sort(cities.begin(),cities.end());
    cout<<cities.size()<<endl;
    for(int i=0;i<cities.size();i++)
        cout<<++cities[i]<<" ";
}
