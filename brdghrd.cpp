#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        int A[n],B[n];
        for(int i=0;i<n;i++)scanf("%d",&A[i]);
        for(int i=0;i<n;i++)scanf("%d",&B[i]);
        vector<ii> v;
        for(int i=0;i<n;i++)v.push_back(ii(A[i],B[i]));
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)A[i]=v[i].second;
        multiset<int> s;
        for(int i=0;i<n;i++){
            s.insert(A[i]);
            set<int>:: iterator it=s.upper_bound(A[i]);
            if(it!=s.end())s.erase(it);
        }
        printf("%d\n",(int)s.size());
    }
}
