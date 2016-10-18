#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int t;scanf("%d",&t);
    while(t--){
        int id,n;scanf("%d %d",&id,&n);
        ll dp[n+1][10],ans=0;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            dp[i][0]=1;
            for(int j=1;j<10;j++)
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
        }
        for(int i=0;i<10;i++)ans+=dp[n][i];
        printf("%d %lld\n",id,ans);
    }
}
