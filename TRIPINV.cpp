#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int const N=1e5;
int n,A[N];

ll BIT[3][N+1];

void update(int pos,ll val,int k){
    for(int i=pos;i<=N;i+=i&(-i))BIT[k][i]+=val;
}

ll query(int pos,int k){
    ll ans=0;
    for(int i=pos;i>0;i-=i&(-i))ans+=BIT[k][i];
    return ans;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&A[i]);
    memset(BIT,0,sizeof(BIT));
    for(int i=0;i<n;i++){
        ll temp1=query(1e5,0)-query(A[i],0);
        ll temp2=query(1e5,1)-query(A[i],1);
        update(A[i],1,0);
        update(A[i],temp1,1);
        update(A[i],temp2,2);
    }
    printf("%lld\n",query(1e5,2));
}
