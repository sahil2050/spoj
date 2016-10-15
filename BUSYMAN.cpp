#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int,int> ii;

int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        ii A[n];
        for(int i=0;i<n;i++){
            int s,e;scanf("%d %d",&s,&e);
            A[i]=ii(e,s);
        }
        sort(A,A+n);
        int ans=0;
        int curr=0;
        for(int i=0;i<n;i++)
            if(A[i].ss>=curr)ans++,curr=A[i].ff;
        printf("%d\n",ans);
    }
}
