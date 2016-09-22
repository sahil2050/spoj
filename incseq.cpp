#include<bits/stdc++.h>
using namespace std;

int const mod=5000000;

int BIT[51][100001];
int A[10001];
int n,k;

void update(int pos,int val,int j){
    for(int i=pos;i<=1e5;i+=i&(-i)){
        BIT[j][i]+=val;
        BIT[j][i]%=mod;
    }
}

int query(int pos,int j){
    int ans=0;
    for(int i=pos;i>0;i-=i&(-i)){
        ans+=BIT[j][i];
        ans%=mod;
    }
    return ans%mod;
}

int main(){
    //cout<<mod<<endl;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&A[i]);
    memset(BIT,0,sizeof(BIT));
    int dp[n+1][k+1];
    for(int i=1;i<=n;i++){
            dp[i][1]=1;
        for(int j=2;j<=k;j++)
            dp[i][j]=query(A[i],j-1)%mod;
        for(int j=1;j<=k;j++)
            update(A[i]+1,dp[i][j],j);
    }
    printf("%d\n",query(100000,k));
}
