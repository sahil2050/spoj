#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int A[n];
        vector < pair <int,int> > vii;
        for(int i=0;i<n;i++)
            scanf("%d",&A[i]);
        for(int i=0;i<n;i++){
            int temp;scanf("%d",&temp);
            vii.push_back(make_pair(A[i],temp));
        }

        sort(vii.begin(),vii.end());
        for(int i=0;i<n;i++)
            A[i]=vii[i].second;
        // now find longest inc subseq in A[]
        
        int dp[n];
        dp[0]=1;
        for(int i=1;i<n;i++){
            dp[i]=1;
            for(int j=0;j<i;j++)
                if(A[j]<=A[i])
                    dp[i]=max(dp[i],dp[j]+1);
        }
        int ans=1;
        for(int i=1;i<n;i++)
            ans=max(ans,dp[i]);
        printf("%d\n",ans);
    }
}
