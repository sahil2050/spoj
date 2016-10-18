#include<bits/stdc++.h>
using namespace std;

int const N=1e6+10;
int n,A[N][3],dp[N][3];

int main(){
    for(int t=1;;t++){
        scanf("%d",&n);
        if(n==0)return 0;
        for(int i=0;i<n;i++)scanf("%d %d %d",&A[i][0],&A[i][1],&A[i][2]);
        dp[0][0]=1e9,dp[0][1]=A[0][1],dp[0][2]=A[0][2]+A[0][1];
        for(int i=1;i<n;i++){
            dp[i][0]=A[i][0]+min(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=A[i][1]+min(min(dp[i-1][0],dp[i][0]),min(dp[i-1][1],dp[i-1][2]));
            dp[i][2]=A[i][2]+min(dp[i][1],min(dp[i-1][1],dp[i-1][2]));
        }
        printf("%d. %d\n",t,dp[n-1][1]);
    }
}
