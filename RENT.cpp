#include<bits/stdc++.h>
using namespace std;

int const NMAX=1e4;
int const TMAX=2e6;

struct Order{
    int s,f,p;
    Order(int a=0,int b=0,int c=0){
        s=a,f=b,p=c;
    }
};

struct Order orders[NMAX];
int dp[TMAX];
int n;

bool comp(struct Order order1,struct Order order2){
    return order1.f<order2.f;
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int s,d,p;scanf("%d %d %d",&s,&d,&p);
            orders[i]=Order(s,s+d-1,p);
        }
        sort(orders,orders+n,comp);
        dp[0]=0;
        int j=0;
        for(int i=0;i<TMAX;i++){
            dp[i]=dp[i-1];
            while(orders[j].f==i && j<n){
                dp[i]=max(dp[i],dp[orders[j].s-1]+orders[j].p);
                j++;
            }
        }
        printf("%d\n",dp[TMAX-1]);
    }
}
