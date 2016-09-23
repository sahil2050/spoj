#include<bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;
ll const mod=1e9+7;

ll pow(ll b,int e){
    if(e==0)return 1;
    ll temp=pow(b,e>>1);
    if(e&1)return (((temp*temp)%mod)*b)%mod;
    else return (temp*temp)%mod;
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n,m;scanf("%d %d",&n,&m);
        int color[n];
        int curr=0;
        memset(color,-1,sizeof(color));
        vector<int> G[n];
        for(int i=0;i<m;i++){
            int u,v;scanf("%d %d",&u,&v);
            --u,--v;
            G[u].pb(v),G[v].pb(u);
        }
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                stack<int> s;
                s.push(i);
                color[i]=curr;
                while(!s.empty()){
                    int u=s.top();s.pop();
                    for(int j=0;j<G[u].size();j++){
                        int v=G[u][j];
                        if(color[v]==-1){
                            color[v]=curr;
                            s.push(v);
                        }
                    }
                }
                curr++;
            }
        }
        int k=curr;
        if(k<2){
            printf("-1\n");
            continue;
        }
        ll freq[k];
        memset(freq,0,sizeof(freq));
        for(int i=0;i<n;i++)freq[color[i]]++;
        ll ans=pow((ll)n,k-2);
        for(int i=0;i<k;i++)ans=(ans*freq[i])%mod;
        printf("%lld\n",ans);
    }
}
