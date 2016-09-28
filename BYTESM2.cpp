#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n,m;scanf("%d %d",&n,&m);
        int A[n][m],dp[n][m];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&A[i][j]);
        for(int j=0;j<m;j++)dp[0][j]=A[0][j];
        for(int i=1;i<n;i++){
            dp[i][0]=A[i][0]+max(dp[i-1][0],dp[i-1][1]);
            for(int j=1;j<m-1;j++)
                dp[i][j]=A[i][j]+max(dp[i-1][j-1],max(dp[i-1][j],dp[i-1][j+1]));
            dp[i][m-1]=A[i][m-1]+max(dp[i-1][m-2],dp[i-1][m-1]);
        }
        int ans=0;
        for(int i=0;i<m;i++)ans=max(ans,dp[n-1][i]);
        printf("%d\n",ans);
    }
}
