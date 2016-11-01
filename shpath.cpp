#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
typedef pair<int,int> ii;
int const inf=1e9;

int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        vector< vector <ii> > graph;
        map<string,int> vertex_map;
        for(int i=0;i<n;i++){
            string name;cin>>name;
            vertex_map[name]=i;
            vector<ii> temp;
            int m;scanf("%d",&m);
            while(m--){
                int v,w;scanf("%d %d",&v,&w);
                temp.pb(ii(w,--v));
            }
            graph.pb(temp);
        }
        
        int r;scanf("%d",&r);
        while(r--){
            string name1,name2;
            cin>>name1>>name2;
            int src = vertex_map.find(name1)->ss, dst = vertex_map.find(name2)->ss;
            
            priority_queue< ii, vector<ii>, greater<ii> > pq;
            pq.push(ii(0,src));

            int d[n];
            for(int i=0;i<n;i++)d[i]=inf;
            d[src]=0;

            while(!pq.empty()){
                ii top=pq.top(); pq.pop();
                int u=top.ss,dist=top.ff;
                if(d[u]==dist){
                    for(int i=0;i<graph[u].size();i++){
                        int v=graph[u][i].ss,w=graph[u][i].ff;
                        if(d[v]>d[u]+w){
                            d[v]=d[u]+w;
                            pq.push(ii(d[v],v));
                        }
                    }
                }
            }

            cout<<d[dst]<<endl;
        }
    }
}
