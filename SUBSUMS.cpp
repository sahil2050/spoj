#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
int const N=35;
int n,arr[N],A,B;
ll ans;

vector<int> subset_sum(int l,int r){
    vi ret;
    int n=r-l;
    for(int mask =0;mask<(1<<n);mask++){
        int temp=0;
        for(int  i=0;i<n;i++)
            if(mask&(1<<i))temp+=arr[i+l];
        ret.pb(temp);
    }
    return ret; 
}

int main(){
    int a,b;
    scanf("%d %d %d",&n,&a,&b);
    A=min(a,b),B=max(a,b);
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    ans=0;
    vi left=subset_sum(0,(n>>1));
    vi right=subset_sum((n>>1),n);
    sort(right.begin(),right.end());
    for(int i=0;i<left.size();i++){
        ans+=(ll)(upper_bound(right.begin(),right.end(),B-left[i])-lower_bound(right.begin(),right.end(),A-left[i]));
    }
    printf("%lld",ans);
}
