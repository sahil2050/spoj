#include<bits/stdc++.h>
using namespace std;

#define ll long long
int const N=1e9;
int const Log2N=32;
int const Log3N=20;

ll dp[Log2N][Log3N];
ll n;

ll solve(int i,int j){
	ll temp=n/(pow(2,i)*pow(3,j));
	if(temp==0)return dp[i][j]=0;
	if(dp[i][j]==-1)return dp[i][j]=max(temp,solve(i+1,j)+solve(i,j+1)+solve(i+2,j));
	else return dp[i][j];
}

int main(){
	while(scanf("%lld",&n)!=EOF){
		memset(dp,-1,sizeof(dp));
		printf("%lld\n",solve(0,0));
	}
}