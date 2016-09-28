#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
int const N=1e6+1;
bool is_prime[N];
vector<int> primes;
int ETF[N];
ll F[N];

void sieve(){
    memset(is_prime,1,sizeof(is_prime));
    for(int i=2;i<N;i++){
        if(is_prime[i])primes.pb(i);
        for(int j=2;i*j<N;j++)is_prime[i*j]=0;
    }
}

int totient(int n){
    if(n==1)return ETF[1]=1;
    if(is_prime[n])return ETF[n]=n-1;
    int i=0,cp=n;
    while(1){
        if(n%primes[i]==0){
            while(cp%primes[i]==0)cp/=primes[i];
            break;
        }
        i++;
    }
    if(cp==1)return ETF[n]=n-n/primes[i];
    else return ETF[n]=ETF[cp]*ETF[n/cp];
}

void precomp(){
    memset(F,0,sizeof(F));
    for(int d=1;d<N;d++){
        for(int j=1;j*d<N;j++)
            F[j*d]+=(ll)d*(ll)ETF[d];
    }
}

int main(){
    sieve();
    for(int i=1;i<N;i++)totient(i);
    precomp();
    int t;scanf("%d",&t);
    while(t--){
        ll n;scanf("%lld",&n);
        ll ans=n*(1+F[n])/2;
        printf("%lld\n",ans);
    }
}
