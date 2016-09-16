#include<bits/stdc++.h>
using namespace std;

vector< vector <int> > graph;
vector< vector <int> > graph_t;

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
        graph[u].push_back(v);
        graph_t[v].push_back(u);
    }

    

}
