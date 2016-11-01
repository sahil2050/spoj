#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
int const N=2e6+10;
int prefix[N],n;
char P[N];
map<string,int> M;

void preprocess(){
    int k=prefix[0]=-1;
    for(int i=1;i<n;i++){
        while(k>=0 && P[i]!=P[k+1])k=prefix[k];
        if(P[i]==P[k+1])k++;
        prefix[i]=k;
    }
}

int main(){
    int m;scanf("%d",&m);
    while(m--){
        scanf("%d",&n);
        scanf("%s",P);
        preprocess();
        int power,base_len;
        power = n%(n-1-prefix[n-1]) == 0 ? n/(n-1-prefix[n-1]) : 1; 
        base_len=n/power;
        string base;
        for(int i=0;i<base_len;i++)base.pb(P[i]);
        if(M.find(base)!=M.end())M[base]++;
        else M[base]=1;
    }
    ll ans=0;
    for(auto it=M.begin();it!=M.end();it++){
        ll x=(ll)it->second;
        ans+=x*x;
    }
    printf("%lld\n",ans);
}
