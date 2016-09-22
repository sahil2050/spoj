#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool A[20][20];
ll dp[1<<20];
int n;

ll solve(int mask){
    if(dp[mask]!=-1)return dp[mask];
    dp[mask]=0;
    int i=0;
    for(int k=0;k<n;k++)
        if(mask&(1<<k))i++;
    for(int k=0;k<n;k++){
        if((mask&(1<<k))&&A[k][i-1]){
            dp[mask]+=solve(mask-(1<<k));
        }
    }
    return dp[mask];
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>A[i][j];
        memset(dp,-1,sizeof(dp));
        dp[0]=1;
        printf("%lld\n",solve((1<<n)-1));
    }
}
