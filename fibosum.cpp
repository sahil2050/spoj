#include<bits/stdc++.h>
using namespace std;

#define mat struct matrix
typedef long long ll;
ll const mod=1e9+7;

struct matrix{
    ll M[2][2];
    matrix(int a=1,int b=0,int c=0,int d=1){
        M[0][0]=a,M[0][1]=b,M[1][0]=c,M[1][1]=d;
    }
};

mat matmult(mat A,mat B){
    mat ans;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++){
            ans.M[i][j]=0;
            for(int k=0;k<2;k++)
                ans.M[i][j]+=(A.M[i][k]*B.M[k][j])%mod;
            ans.M[i][j]%=mod;
        }
    return ans;
}

mat pow(mat A,int e){
    mat ans=matrix();
    if(e==0)return ans;
    mat temp=pow(A,e>>1);
    if(e&1)return matmult(matmult(temp,temp),A);
    else return matmult(temp,temp);
}

ll fib(int n){
    if(n<0)return 1;
    if(n==0)return 0;
    if(n==1)return 1;
    mat A=matrix(1,1,1,0);
    mat F=pow(A,n-1);
    return F.M[0][0];
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n,m;//cin>>n;cout<<fib(n)<<endl;
        scanf("%d %d",&n,&m);
        printf("%lld\n",((fib(m+1)-fib(n)+fib(m)-fib(n-1))%mod+mod)%mod);
    }
}
