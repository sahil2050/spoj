#include<bits/stdc++.h>
using namespace std;

#define ll long long
int const N=1e3+10;
ll const mod=1e9+7;
char s[N];
ll dp[N][2];

int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        ll ans=1;
        int n=strlen(s);
        memset(dp,0,sizeof(dp));
        dp[0][1]=1;
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                for(int j=N-1;j>=1;j--)dp[j][0]=(dp[j-1][0]+dp[j-1][1])%mod;
            else{
                for(int j=0;j<N-1;j++)dp[j][1]=(dp[j+1][0]+dp[j+1][1])%mod;
                dp[0][1]=(dp[0][1]+1)%mod;
            }
        }
        printf("%lld\n",dp[0][1]);
    }
}
