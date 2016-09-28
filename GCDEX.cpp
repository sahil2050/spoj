#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int> 
#define pb push_back

int const N=1e6+1;
vi primes;
bool is_prime[N];
int ETF[N];
ll DivisorSum[N];
ll prefix[N];
ll F[N]; // stores sum i*phi(n/i) as i|n
ll ans[N];

void sieve(){
    memset(is_prime,1,sizeof(is_prime));
    for(int i=2;i<N;i++){
        if(is_prime[i])primes.pb(i);
        for(int j=2;i*j<N;j++)is_prime[i*j]=0;
    }
}

void totient(){
    ETF[1]=1;
    for(int i=2;i<N;i++){
        if(is_prime[i]){
            ETF[i]=i-1;
            continue;
        }
        int j=0;
        while(1){
            if(i%primes[j]==0){
                int cp=i;
                while(cp%primes[j]==0)cp/=primes[j];
                if(cp!=1)ETF[i]=ETF[cp]*ETF[i/cp];
                else ETF[i]=i-(i/primes[j]);
                break;
            }
            j++;
        }
    }
}

ll sum_divisors(int n){
    int i=0;
    int cp=n;
    int temp=1;
    if(is_prime[n])return DivisorSum[n]=n+1;
    while(1){
        if(n%primes[i]==0){
            while(cp%primes[i]==0)cp/=primes[i],temp=temp*primes[i]+1;
            break;
        }
        i++;
    }
    if(cp==1)DivisorSum[n]=temp;
    else DivisorSum[n]=DivisorSum[cp]*DivisorSum[n/cp];
    return DivisorSum[n];
}

ll f(int n){
    int i=0;
    int cp=n;
    ll count=0;
    if(is_prime[n])return F[n]=2*n-1;
    while(1){
        if(n%primes[i]==0){
            while(cp%primes[i]==0)cp/=primes[i],count++;
            break;
        }
        i++;
    }
    if(cp==1)F[n]=(count+1)*n-count*n/primes[i];
    else F[n]=F[cp]*F[n/cp];
    return F[n];
}

int main(){
    sieve();
    totient();
    prefix[1]=ETF[1];
    for(int i=2;i<N;i++)prefix[i]=prefix[i-1]+ETF[i];
    ans[1]=1,F[1]=1;
    for(ll i=2;i<N;i++)ans[i]=ans[i-1]+f(i);
    while(1){
        ll n;scanf("%lld",&n);
        if(n==0)break;
        printf("%lld\n",ans[n]-(n*(n+1))/2);
    }
}
