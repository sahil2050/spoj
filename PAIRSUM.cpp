#include<bits/stdc++.h>
using namespace std;

#define ll long long
int const N=1e5+1;
ll A[N],prefix[N],sq_prefix[N];
int n,q;

int main(){
    scanf("%d",&n);
    prefix[0]=0,sq_prefix[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&A[i]);
        prefix[i]=prefix[i-1]+A[i];
        sq_prefix[i]=sq_prefix[i-1]+A[i]*A[i];
    }
    scanf("%d",&q);
    while(q--){
        int l,r;scanf("%d %d",&l,&r);
        ll ans=(prefix[++r]-prefix[l]);
        ans*=ans;
        ans-=sq_prefix[r]-sq_prefix[l];
        ans/=2;
        ans+=sq_prefix[r]-sq_prefix[l];
        printf("%lld\n",ans);
    }
}
