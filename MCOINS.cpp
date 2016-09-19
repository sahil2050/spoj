#include<bits/stdc++.h>
using namespace std;

int const N=1e6;
bool dp[N+1];

int main(){
    int k,l,m;
    scanf("%d %d %d",&k,&l,&m);
    dp[0]=0,dp[1]=1;
    for(int i=2;i<=N;i++){
        bool x,y;
        x=(i>=k)?dp[i-k]:1;
        y=(i>=l)?dp[i-l]:1;
        dp[i]=!(dp[i-1]&&y&&x);
    }
    while(m--){
        int n;scanf("%d",&n);
        if(dp[n])printf("%c",'A');
        else printf("%c",'B');
    }
}
