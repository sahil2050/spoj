#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
typedef pair<int,int> ii;

comp(ii p1,ii p2){
    return p1.ss<p2.ss;
}

int main(){
    int t;scanf("%d",&t);
    for(int T=1;T<=t;T++){
        int n;scanf("%d",&n);
        ii A[n+1];
        int dp[n+1];
        for(int i=1;i<=n;i++){
            int p,q;scanf("%d %d",&p,&q);
            A[i]=ii(p,q);
        }
        sort(A+1,A+n+1,comp);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            for(int k=0;k<i-1;k++)
                if(A[k+1].ss>=A[i].ff)dp[i]=max(dp[i],dp[k]+i-k);
        printf("Case #%d: %d\n",T,dp[n]);
    }
}
