#include<bits/stdc++.h>
using namespace std;
#define inf 1e9

int main(){
    int t;cin>>t;
    while(t--){
        string A,B;
        cin>>A>>B;
        int n=A.length(),m=B.length();
        int dp[n+1][m+1];
        dp[0][0]=0;
        for(int i=1;i<=n;i++)
            dp[i][0]=i;
        for(int i=1;i<=m;i++)
            dp[0][i]=i;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(A[i-1]==B[j-1])
                    dp[i][j]=1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]-1);
                else
                    dp[i][j]=1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
        cout<<dp[n][m]<<endl;
    }
}
