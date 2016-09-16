#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
//vector< vector <ii> > graph;
int G[200][200];

int const inf=1000000;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        
        //graph.clear();
        //cout<<graph.size()<<endl;
        //for(int i=0;i<n;i++){
        //    vector<ii> vii;
        //    graph.push_back(vii);
        //}

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                G[i][j]=0;

        for(int i=0;i<n-1;i++){
            int k;cin>>k;
            while(k--){
                int v;cin>>v;
                v--;
                if(i==0||v==n-1){
                    //graph[i].push_back(make_pair(1,v));
                    G[i][v]=1;
                }
                else{
                    //graph[i].push_back(make_pair(inf,v));
                    G[i][v]=inf;
                }
            }
        }
        
        int f=0;
        //find augmenting path
        while(true){
            stack<int> s;
            s.push(0);
            int p[n];
            for(int i=0;i<n;i++)p[i]=-1;
            while(!s.empty()){
                int u=s.top();
                s.pop();
                for(int v=0;v<n;v++){
                    if(G[u][v]>0 && p[v]==-1){
                        s.push(v);
                        p[v]=u;
                    }
                }
            }
            if(p[n-1]==-1)break;
            f++;
            int v=n-1;
            while(v!=0){
                G[p[v]][v]-=1;
                G[v][p[v]]+=1;
                v=p[v];
            }
        }
        cout<<f<<endl;
    }
}
