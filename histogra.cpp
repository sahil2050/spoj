#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;scanf("%d",&n);
    if(n==0)return 0;
    int A[n],l[n],r[n];
    stack<int> s;
    for(int i=0;i<n;i++)scanf("%d",&A[i]),l[i]=-1,r[i]=n-1;
    for(int i=0;i<n;i++){
        if(s.empty())s.push(i);
        else if(A[s.top()]<=A[i])l[i]=s.top(),s.push(i);
        else r[s.top()]=--i,s.pop();
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        //cout<<A[i]<<" "<<l[i]<<" "<<r[i]<<endl;
        ans=max(ans,((ll)(r[i]-l[i]))*((ll)A[i]));
    }
    printf("%lld\n",ans);
    return main();
}
