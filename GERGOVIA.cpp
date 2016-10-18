#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back
typedef pair<ll,ll> ii;
vector<ii> s;
ll ans=0;

void relax(){
    ll m=s.size()-1;
    if(m<1)return;
    if(s[m].ff*s[m-1].ff>0)return;
    ans+=min(abs(s[m].ff),abs(s[m-1].ff))*abs(s[m].ss-s[m-1].ss);
    if(abs(s[m].ff)==abs(s[m-1].ff)){
        s.pop_back();
        s.pop_back(); 
        relax();
    }
    else if(abs(s[m].ff)>abs(s[m-1].ff)){
        ii temp=ii(s[m].ff+s[m-1].ff,s[m].ss);
        s.pop_back();
        s.pop_back();
        s.pb(temp);
        relax();
    }
    else{
        ii temp=ii(s[m].ff+s[m-1].ff,s[m-1].ss);
        s.pop_back();
        s.pop_back();
        s.pb(temp);
        relax();
    }
    return;
}

int main(){
    while(1){
    s.clear(),ans=0;
    ll n;scanf("%lld",&n);
    if(n==0)break;
    for(ll i=0;i<n;i++){
        ll m,temp;
        m=(ll)s.size()-1;
        scanf("%lld",&temp);
        if(temp!=0)s.pb(ii(temp,i));
        if(m>=0 && s[m].ff*temp<0)relax();
    }
    printf("%lld\n",ans);
    }
}
