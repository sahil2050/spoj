#include<bits/stdc++.h>
using namespace std;

#define ll long long
int const M=1e3+10;
ll inf=1e15;
int n,m;
ll dp[M][M],opt[M][M],p[M];

int main(){
    while(scanf("%d %d",&n,&m)!=EOF){
        p[0]=0;
        for(int i=1;i<=m;i++)scanf("%lld",&p[i]);
        p[m+1]=n;
        for(int i=0;i<=m;i++)dp[i][i+1]=0;
        for(int i=0;i<m;i++)dp[i][i+2]=p[i+2]-p[i],opt[i][i+2]=i+1;
        for(int x=3;x<m+2;x++){
            for(int i=0;i+x<m+2;i++){
            int j=i+x;
            dp[i][j]=inf;
            for(int k=opt[i][j-1];k<=opt[i+1][j];k++)
                if(dp[i][j]>dp[i][k]+dp[k][j]+p[j]-p[i])
                dp[i][j]=dp[i][k]+dp[k][j]+p[j]-p[i],opt[i][j]=k;
            }
        }
        printf("%lld\n",dp[0][m+1]);
    }
}
