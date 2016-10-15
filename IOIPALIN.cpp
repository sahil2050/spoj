#include<bits/stdc++.h>
using namespace std;
int const N=5000;

int main(){
    int n;scanf("%d",&n);
    char A[N];cin>>A;
    int dp[2][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(A[i-1]==A[n-j])dp[1][j]=dp[0][j-1]+1;
            else dp[1][j]=max(dp[0][j],dp[1][j-1]);
        }
        for(int j=0;j<=n;j++)dp[0][j]=dp[1][j];
    }
    printf("%d\n",n-dp[0][n]);
}
