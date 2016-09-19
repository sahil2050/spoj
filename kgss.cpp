#include<bits/stdc++.h>
using namespace std;

int const N=1e5+1;
int t[2*N][2]; // 0>-max 1-> second max
int n;

void build(){
    for(int i=n-1;i>0;i--){
        t[i][0]=max(t[i<<1][0],t[i<<1|1][0]);
        t[i][1]=max(min(t[i<<1][0],t[i<<1|1][0]),max(t[i<<1][1],t[i<<1|1][1]));
    }
}

void update(int p,int val){
    for(t[p+=n][0]=val;p>1;p>>=1){
        t[p>>1][0]=max(t[p][0],t[p^1][0]);
        t[p>>1][1]=max(max(t[p][1],t[p^1][1]),min(t[p][0],t[p^1][0]));
    }
}

int query(int l,int r){
    l+=n,r+=n;
    int resl[2]={0,0};
    int resr[2]={0,0};
    for(;l<r;l>>=1,r>>=1){
        if(l&1){
            resl[1]=max(max(resl[1],t[l][1]),min(resl[0],t[l][0]));
            resl[0]=max(resl[0],t[l][0]);
            l++;
        }
        if(r&1){
            r--;
            resr[1]=max(max(resr[1],t[r][1]),min(resr[0],t[r][0]));
            resr[0]=max(resr[0],t[r][0]);
        }
    }
    return max(resl[0],resr[0])+max(min(resl[0],resr[0]),max(resl[1],resr[1]));
}

int main(){
    cin>>n;
    memset(t,0,sizeof(t));
    for(int i=0;i<n;i++){
        scanf("%d",&t[n+i][0]);
    }
    build();
    int q;cin>>q;
    while(q--){
        char c;cin>>c;
        if(c=='U'){
            int pos,val;
            scanf("%d %d",&pos,&val);
            update(--pos,val);
        }
        else if(c=='Q'){
            int l,r;
            scanf("%d %d",&l,&r);
            printf("%d\n",query(--l,r));
        }
    }
}
