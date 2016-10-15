#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define ll long long
typedef pair<ll,ll> ii;

struct line{
    ll m,c;
    line(ll a,ll b){
        m=a,c=b;
    }
};

vector<ii> plots;
vector<ii> new_plots;
vector<line> S;
int pointer;

void insert(ll m,ll c){
    if(S.size()==0 || S.size()==1 ){
        S.pb(line(m,c));
        return;
    }
    int n=S.size()-1;
    if((S[n-1].c-c)*(S[n].m-S[n-1].m)<(S[n-1].m-m)*(S[n].c-S[n-1].c)){  // if intersection of l1 & l3 is on left of l1 & l2 intersection
        S.pop_back();
        insert(m,c);
        return;
    }
    S.pb(line(m,c));
}

ll search(ll x){
    if(pointer>=S.size())pointer=S.size()-1;
    while(pointer<S.size()-1 && S[pointer].m*x+S[pointer].c>S[pointer+1].m*x+S[pointer+1].c)pointer++;
    return S[pointer].m*x+S[pointer].c;
}

bool comp(ii p1,ii p2){
    if(p1.ff!=p2.ff)return p1.ff<p2.ff;
    else return p1.ss<p2.ss;
}

int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        ll l,w;scanf("%lld %lld",&l,&w);
        plots.pb(ii(l,w));
    }
    sort(plots.begin(),plots.end(),comp);
    new_plots.pb(plots[0]);
    for(int i=1;i<n;){
        int top=new_plots.size()-1;
        if(top>=0 && new_plots[top].ss<=plots[i].ss)new_plots.pop_back();
        else new_plots.pb(plots[i++]);
    }
    int m=new_plots.size();
    ll ans=0;
    insert(new_plots[0].ss,0);
    pointer=0;
    for(int i=1;i<=m;i++){
        ans=search(new_plots[i-1].ff);
        insert(new_plots[i].ss,ans);
    }
    printf("%lld\n",ans);
}
