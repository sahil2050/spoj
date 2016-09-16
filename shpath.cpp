#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
int const inf=100000000;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector< vector <ii> > graph;
        map<string,int> vertex_map;
        for(int i=0;i<n;i++){
            string name;
            cin>>name;
            vertex_map[name]=i;
            vector<ii> temp;
            int m;scanf("%d",&m);
            while(m--){
                int v,w;
                scanf("%d %d",&v,&w);
                v--;
                temp.push_back(make_pair(w,v));
            }
            graph.push_back(temp);
        }
        
        int r;scanf("%d",&r);
        while(r--){
            string name1,name2;
            cin>>name1>>name2;
            int src=vertex_map.find(name1)->second;
            int dst=vertex_map.find(name2)->second;
            
            priority_queue< ii, vector<ii>, greater<ii> > pq;
            pq.push(make_pair(0,src));
            

            int d[n];
            for(int i=0;i<n;i++)
                d[i]=inf;
            d[src]=0;

            while(!pq.empty()){
                ii top=pq.top();
                pq.pop();
                int u=top.second;
                int dist=top.first;
                if(d[u]==dist){
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
            
            cout<<d[dst]<<endl;
        }
    }
}
