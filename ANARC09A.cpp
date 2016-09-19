#include<bits/stdc++.h>
using namespace std;

#define inf 1e9

int main(){
    for(int t=1;;t++){
        string A;
        cin>>A;
        if(A[0]=='-')break;
        int n=A.length();
        int dp[n+1][n+1];
        memset(dp,inf,sizeof(dp));
        dp[1][0]=inf;
        if(A[0]=='{')dp[1][1]=0;
        else dp[1][1]=1;
        for(int i=2;i<=n;i++){
            if(A[i-1]=='{')dp[i][0]=dp[i-1][1]+1;
            else dp[i][0]=dp[i-1][1];
            for(int j=1;j<=i;j++)
                if(A[i-1]=='{')dp[i][j]=min(dp[i-1][j-1],dp[i-1][j+1]+1);
                else dp[i][j]=min(dp[i-1][j-1]+1,dp[i-1][j+1]);
            if(A[i-1]=='{')dp[i][i]=dp[i-1][i-1];
            else dp[i][i]=dp[i-1][i-1]+1;
        }
        cout<<t<<". "<<dp[n][0]<<endl;
    }
}
