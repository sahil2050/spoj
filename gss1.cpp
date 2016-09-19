#include<bits/stdc++.h>
using namespace std;

int const N=50001;
int t[2*N][4]; // 0->sum ; 1-> max prefix 2-> max suffix; 4-> max subarray
int n;

void build(){
    for(int i=n-1;i>0;i--){
        t[i][0]=t[i<<1][0]+t[(i<<1)|1][0];
        t[i][1]=max(t[i<<1][0]+t[i<<1|1][1],t[i<<1][1]);
        t[i][2]=max(t[i<<1][2]+t[i<<1|1][0],t[i<<1|1][2]);
        t[i][3]=max(max(t[i<<1][3],t[i<<1|1][3]),t[i<<1][2]+t[i<<1|1][1]);
        //cout<<"hi!"<<t[i<<1]<<" "<<t[i<<1|1]<<endl;
    }
}

int query(int l,int r){
    l+=n,r+=n;
    int suml=0,max_prefixl=-1e9,max_suffixl=-1e9,max_subarrayl=-1e9;
    int sumr=0,max_prefixr=-1e9,max_suffixr=-1e9,max_subarrayr=-1e9;
    for(;l<r;l>>=1,r>>=1){
        if(l&1){
            suml+=t[l][0];
            max_prefixl=max(suml+t[l][1],max_prefixl);
            max_subarrayl=max(max(max_subarrayl,t[l][3]),max_suffixl+t[l][1]);
            max_suffixl=max(max_suffixl+t[l][0],t[l][2]);
            l++;
        }
        if(r&1){
            r--;
            max_suffixr=max(max_suffixr,sumr+t[r][2]);
            sumr+=t[r][0];
            max_subarrayr=max(max(max_subarrayr,t[r][3]),max_prefixr+t[r][2]);
            max_prefixr=max(t[r][1],t[r][0]+max_prefixr);
        }
    }
    return max(max(max_subarrayl,max_subarrayr),max_suffixl+max_prefixr);
}

int main(){
    cin>>n;
    memset(t,-1e9,sizeof(t));
    for(int i=0;i<n;i++){
        scanf("%d",&t[n+i][0]);
        t[n+i][1]=t[n+i][2]=t[n+i][3]=t[n+i][0];
    }
    build();

    
    //for(int i=1;i<2*n;i++)
    //    cout<<t[i][0]<<" "<<t[i][1]<<" "<<t[i][2]<<" "<<t[i][3]<<endl;
    
    int q;cin>>q;
    while(q--){
        int l,r;
        scanf("%d %d",&l,&r);
        printf("%d\n",query(l-1,r));
    }
}
                                                                                         

