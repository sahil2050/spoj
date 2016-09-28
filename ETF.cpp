#include<bits/stdc++.h>
using namespace std;

#define pb push_back
int const N=1e6+1;
vector<int> primes;
bool is_prime[N];
int ETF[N];

void sieve(){
    memset(is_prime,1,sizeof(is_prime));
    for(int i=2;i<N;i++){
        if(is_prime[i])primes.pb(i);
        for(int j=2;i*j<N;j++)
            is_prime[i*j]=0;
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
            int cp=i;
            if(i%primes[j]==0){
                while(cp%primes[j]==0)cp/=primes[j];
                if(cp==1)ETF[i]=i-i/primes[j];
                else ETF[i]=ETF[cp]*ETF[i/cp];
                break;
            }
            j++;
        }
    }
}

int main(){
    sieve();
    totient();
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        printf("%d\n",ETF[n]);
    }
}
