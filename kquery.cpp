#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define Q struct query
#define ii pair<int,int>
int const N=3e4;
int const QMAX=2e5;
int n,q;
int BIT[N+1];
ii A[N+1];

void update(int pos,int val){
    for(int i=pos;i<=n;i+=i&(-i))BIT[i]+=val;
}

int count(int pos){
    int ans=0;
    for(int i=pos;i>0;i-=i&(-i))ans+=BIT[i];
    return ans;
}

struct query{
    int l,r,k,id;
    query(int a=0,int b=0,int c=0,int d=0){
        l=a,r=b,k=c,id=d;
    }
};

bool comp(Q q1,Q q2){
    return q1.k>q2.k;
}

bool comp2(ii pair1,ii pair2){
    return pair1.ff>pair2.ff;
}

Q queries[QMAX];

int main(){
    memset(BIT,0,sizeof(BIT));
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int temp;scanf("%d",&temp);
        A[i]=ii(temp,i+1);
    }
    sort(A,A+n,comp2);
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int l,r,k;scanf("%d %d %d",&l,&r,&k);
        queries[i]=query(l,r,k,i);
    }
    sort(queries,queries+q,comp);
    int ans[q];
    int pos=0;
    for(int i=0;i<q;i++){
        while(pos<n && A[pos].ff>queries[i].k){
            update(A[pos].ss,1);
            pos++;
        }
        ans[queries[i].id]=count(queries[i].r)-count(queries[i].l-1);
    }
    for(int i=0;i<q;i++)printf("%d\n",ans[i]);
}
