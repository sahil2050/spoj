#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector< set <int> > graph;
    for(int i=0;i<n;i++){
        set<int> s;
        graph.push_back(s);
    }
    
    for(int i=0;i<m;i++){
        int u,k;
        cin>>u>>k;
        u--;
        while(k--){
            int v;cin>>v;
            v--;
            graph[v].insert(u);
        }
    }

    set<int> ans;
    vector<int> ans_vec;
    while(ans.size()<n){
        int d[n];
        for(int i=0;i<n;i++)
            d[i]=0;
        for(int i=0;i<n;i++){
            for(set<int>::iterator it=graph[i].begin();it!=graph[i].end();it++)
                d[*it]++;
        }
        //for(int i=0;i<n;i++)
        //    cout<<d[i]<< " ";
        //cout<<endl;
        int i=0;
        while(d[i]!=0 || ans.find(i)!=ans.end())
            i++;
        ans.insert(i);
        ans_vec.push_back(i);
        graph[i].clear();
    }

    for(int i=0;i<n;i++)
        cout<<++ans_vec[i]<<" ";
}
