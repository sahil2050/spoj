// Sahil Aggarwal
// topic : dp (advanced edit distance)
#include<bits/stdc++.h>
using namespace std;

char A[1010],B[1010];

int main(){
    cin>>B>>A;
    if(A[0]=='*' && B[0]=='*')return 0;
    int n=strlen(A),m=strlen(B);
    int dp[n+1][m+1],da[26];// da[i] = last position in string A st A[da[i]]=i
    dp[0][0]=0;
    for(int i=1;i<=n;i++)dp[i][0]=i;
    for(int i=1;i<=m;i++)dp[0][i]=i;
    memset(da,0,sizeof(da));
    for(int i=1;i<=n;i++){
        int db=0; //the pos in string B st B[pos]==A[i-1] 
        for(int j=1;j<=m;j++){
            int cost=1,l=da[B[j-1]-'a'],k=db;
            if(A[i-1]==B[j-1])cost=0,db=j;
            if(l>0 && k>0)
                dp[i][j]=min(min(dp[i-1][j]+1,dp[i][j-1]+1),min(dp[i-1][j-1]+cost,dp[l-1][k-1]+1+(i-l-1)+(j-k-1)));
            else
                dp[i][j]=min(min(dp[i-1][j],dp[i][j-1])+1,dp[i-1][j-1]+cost);
        }
        da[A[i-1]-'a']=i;
    }
    printf("%d\n",dp[n][m]);
    return main();
}
