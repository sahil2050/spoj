#include<bits/stdc++.h>
using namespace std;

int const N=100000;
int t[2*N+1][4]; // 0 -> most freq value 1-> count of that value 3-> left value of interval 4-> right value of interval
int n;


void build(){
    for(int i=n-1;i>0;i--){
        if(t[i<<1][0]==t[i<<1|1][0]){
            t[i][0]=t[i<<1][0];
            t[i][1]=t[i<<1][1]+t[i<<1|1][1];
        }
        else if(t[t[i<<1][3]][0]!=t[t[i<<1|1][2]][0]){
            if(t[i<<1][1]>t[i<<1|1][1]){
                t[i][0]=t[i<<1][0];
                t[i][1]=t[i<<1][1];
            }
            else{
                t[i][0]=t[i<<1|1][0];
                t[i][1]=t[i<<1][1];
            }
        }
        else{
            if(t[i<<1][0]==t[t[i<<1][3]][0]){
                int count=t[i<<1][1];
                int j=t[i>>1|1][2]+n;
                while(t[j][0]==t[i<<1][0]&&j<2*n){
                    j++;
                    count++;
                }
                if(count>t[i<<1|1][1]){
                    t[i][0]=t[i<<1][0];
                    t[i][1]=count;
                }
                else{
                    t[i][0]=t[i<<1|1][0];
                    t[i][0]=t[i<<1|1][1];
                }
            }
            else if(t[i<<1|1][0]==t[t[i<<1|1][2]][0]){
                int count=t[i<<1|1][1];
                int j=t[i>>1][3]+n;
                while(t[j][0]==t[i<<1|1][0]&&j>=n){
                    count++;
                    j--;
                }
                if()
            }
            else{
            
            }
        }
        t[i][2]=t[i<<1][2];
        t[i][3]=t[i<<1|1][3];
    }
}

int query(int l,int r){
    l+=n,r+=n;
    int l[2]={0,0},r[2]={0,0};
    while(;l<r;l>>=1,r>>=1){
        if(l&1){
            
            l++;
        }
        if(r&1){
            --r;

        }
    }

}

int main(){
    int t;cin>>t;
    while(t--){
        memset(t,0,sizeof(t));
        cin>>n;
        for(int i=0;i<n;i++){
            scanf("%d",&t[n+i][0]);
            t[n+i][1]=1;
            t[n+i][2]=t[n+i][3]=i;
        }

        build();

        int q;cin>>q;
        while(q--){
            int l,r;
            scanf("%d %d",&l,&r);
            printf("%d\n",query(--l,r));
        }
    }
}
