#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll const mod=1e9+7;

int main(){
    int t;cin>>t;
    string s;
    getline(cin,s);
    while(t--){
        string s;getline(cin,s);
        int n=s.length();
        ll count[26];
        memset(count,0,sizeof(count));
        ll dp[n+1];
        dp[0]=1;
        for(int i=1;i<=n;i++){
            dp[i]=(2*dp[i-1]-count[s[i-1]-'A'])%mod;
            count[s[i-1]-'A']=dp[i-1]%mod;
        }
        printf("%lld\n",(dp[n]%mod+mod)%mod);
    }
}
