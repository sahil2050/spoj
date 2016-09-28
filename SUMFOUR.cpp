#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    int A[n],B[n],C[n],D[n];
    for(int i=0;i<n;i++)
        scanf("%d %d %d %d",&A[i],&B[i],&C[i],&D[i]);
    unordered_map<int,int> S;
    S.reserve(2*n*n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            int temp=A[i]+B[j];
            unordered_map<int,int>::iterator it=S.find(temp);
            if(it!=S.end())it->second++;
            else S[temp]=1;
        }
    long long ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            int temp=-(C[i]+D[j]);
            unordered_map<int,int>::iterator it=S.find(temp);
            if(it!=S.end())ans+=(long long)it->second;
        }
    printf("%lld\n",ans);
}
