#include<bits/stdc++.h>
using namespace std;

int n,m;
vector< vector < int > > graph; 
int d[100],f[100];
int color[100]; // 0->white(not visited) 1-> grey(in stack) 2->black (finished)
int t=0;

void dfs(int u){
    color[u]=1,d[u]=t;
    t++;
    for(int i=0;i<graph[u].size();i++){
        int v=graph[u][i];
        if(color[v]==0)dfs(v);
    }
    color[u]=2,f[u]=t;
    t++;
}

bool comp(int i,int j){
    return f[i]>f[j];
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        vector<int> temp;
        graph.push_back(temp);
    }

    for(int i=0;i<m;i++){
        int u,k;scanf("%d %d",&u,&k);
        u--;
        while(k--){
            int v;scanf("%d",&v);
            graph[--v].push_back(u);
        }
    }

    for(int i=0;i<n;i++){
        d[i]=-1,f[i]=-1,color[i]=0;
        sort(graph[i].begin(),graph[i].end());
    }

    for(int i=0;i<n;i++)
        if(color[i]==0)dfs(i);

    int tasks[100];
    for(int i=0;i<n;i++)tasks[i]=i;
    sort(tasks,tasks+n,comp);
    for(int i=0;i<n;i++)printf("%d ",++tasks[i]);
}
