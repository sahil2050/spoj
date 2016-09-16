#include<bits/stdc++.h>
using namespace std;

vector< vector <int> > graph;
vector< vector <int> > graph_t;

int d[5001];
int f[5001];
int color[5001];
int scc[5001];

int t=0;

void dfs_visitG(int u){
    color[u]=1;
    d[u]=t;
    t++;
    for(int i=0;i<graph[u].size();i++){
        int v=graph[u][i];
        if(color[v]==0)
            dfs_visitG(v);
    }
    color[u]=2;
    f[u]=t;
    t++;
}                                                          


void dfs_visitGT(int u){
    color[u]=1;
    for(int i=0;i<graph_t[u].size();i++){
        int v=graph_t[u][i];
        if(color[v]==0){
            scc[v]=scc[u];
            dfs_visitGT(v);
        }
    }
    color[u]=2;
}

int main(){
    graph.clear();
    graph_t.clear();
    int n;cin>>n;
    if(n==0)return 0;
    int m;cin>>m;
    
    for(int i=0;i<n;i++){
        vector<int> vi1,vi2;
        graph.push_back(vi2);
        graph_t.push_back(vi2);
    }
    

    for(int i=0;i<n;i++){
        d[i]=-1;
        f[i]=-1;
        color[i]=0; // 0-> white 1-> gray 2-> black
    }

    //cout<<"n:"<<n<<endl;

    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        u--,v--;
        //cout<<u<<" "<<v<<endl;
        graph[u].push_back(v);
        graph_t[v].push_back(u);
    }
    
    //cout<<"1**"<<endl;

    t=0;
    for(int i=0;i<n;i++){
        if(color[i]==0){
            dfs_visitG(i);
        }
    }
    
    //cout<<"2**"<<endl;

    vector< pair <int,int> > finish_map;
    for(int i=0;i<n;i++)
        finish_map.push_back(make_pair(f[i],i));

    sort(finish_map.begin(),finish_map.end());
    
    //cout<<"3**"<<endl;

    for(int i=0;i<n;i++)
        color[i]=0;
    int curr=0;
    t=0;
    for(int i=n-1;i>=0;i--){
        int u= finish_map[i].second;
        if(color[u]==0){
            scc[u]=curr;
            dfs_visitGT(u);
            curr++;
        }
    }
    
    //cout<<"DONE!"<<endl;

    vector<bool> is_bottom;
    for(int i=0;i<=curr;i++){
        is_bottom.push_back(1);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<graph[i].size();j++){
            int v=graph[i][j];
            if(scc[i]!=scc[v])
                is_bottom[scc[i]]=0;
        }
    vector<int> bottom;
    for(int i=0;i<n;i++){
        //cout<<scc[i]<<" ";
        if(is_bottom[scc[i]])
            bottom.push_back(i);
    }
    
    //cout<<endl;
    //for(int i=0;i<curr;i++)
    //    cout<<is_bottom[i]<<" ";
    //cout<<endl;

    sort(bottom.begin(),bottom.end());

    for(int i=0;i<bottom.size();i++)
        cout<<bottom[i]+1<<" ";
    cout<<endl;
    return main();
}
