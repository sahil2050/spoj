#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
typedef long long ll;
typedef pair<ll,ll> ii;

bool comp(ii p1,ii p2){
    return p1.ss>p2.ss;
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        ii A[n+1];
        for(int i=0;i<n;i++)
            scanf("%lld %lld",&A[i].ss,&A[i].ff);
        A[n]=ii(0,0);
        sort(A,A+n+1,comp);
        ll C[n+1];
        C[n]=0;
        for(int i=n-1;i>=0;i--){
            C[i]=min(A[i].ff,C[i+1]+A[i].ss);
        }
        ll currD,currF;
        scanf("%lld %lld",&currD,&currF);
        int ans=0;
        priority_queue<ii, vector<ii>, less<ii> > pq;
        for(int i=0;i<=n;i++){
            //cout<<currF<<" "<<currD<<endl;
            while(currF < currD - A[i].ss && (!pq.empty())){
                ans++;
                currF+=(pq.top()).ff;
                pq.pop();
            }
            if(currF < currD - A[i].ss){
                ans=-1;
                break;
            }
            currF-=currD-A[i].ss;
            currD=A[i].ss;
            pq.push(A[i]);
        }
        cout<<ans<<endl;
    }
}
