#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int const N=2e5;
int n;
int A[N];

ll countinv(int l,int r){
    if(l==r-1)return 0;
    int mid=(l+r)/2;
    ll ans=0;
    ans+=countinv(l,mid);
    ans+=countinv(mid,r);
    vector<int> merge;
    int i=l,j=mid;
    while(i<mid&&j<r){
        if(A[i]>A[j])ans+=(ll)(mid-i),merge.push_back(A[j++]);
        else merge.push_back(A[i++]);
    }
    while(i<mid)merge.push_back(A[i++]);
    while(j<r)merge.push_back(A[j++]);
    for(int i=l;i<r;i++)A[i]=merge[i-l];
    return ans;
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&A[i]);
        printf("%lld\n",countinv(0,n));
    }
}
