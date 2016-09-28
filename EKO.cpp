#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int const N=1e6;
ll n,m,A[N];

bool F(ll x){
    ll sum=0;
    for(int i=0;i<n;i++)sum+=max(A[i]-x,(ll)0);
    return sum>=m;
}

int binary_search(int l,int r){
    if(l==r-1)return l;
    int mid=(l+r)/2;
    if(F(mid))return binary_search(mid,r);
    else return binary_search(l,mid);
}

int main(){
    scanf("%lld %lld",&n,&m);
    for(int i=0;i<n;i++)scanf("%lld",&A[i]);
    printf("%d\n",binary_search(0,(int)1e9+1));
}
