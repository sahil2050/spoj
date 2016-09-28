#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int const N=100;
int n,A[N];

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&A[i]);
    unordered_map<int,int> m; // maps d*(e+f) ->count 
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++){
                if(A[k]==0)continue;
                int temp=A[k]*(A[j]+A[i]);
                if(m.find(temp)!=m.end())
                    m.find(temp)->second++;
                else
                    m[temp]=1;
            }
    long long ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++){
                int temp=A[i]*A[j]+A[k];
                if(m.find(temp)!=m.end())
                    ans+=(long long)m[temp];
            }
    printf("%lld\n",ans);

}
