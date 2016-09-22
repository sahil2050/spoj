#include<bits/stdc++.h>
using namespace std;

#define rect struct rectangle
#define pb push_back

struct rectangle{
    int l,b,count;
    rectangle(int i=-1,int j=-1,int k=0){
        l=i,b=j,count=k;
    }
};

bool comp(rect R1,rect R2){
    return (R1.count<R2.count);
}

int main(){
    int r,c,k;
    scanf("%d %d %d",&r,&c,&k);
    char seats[r][c];
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            scanf("%c",&seats[i][j]);

    int dp[r][c];
    dp[0][0]=(seats[0][0]=='.');
    for(int i=1;i<r;i++)
        dp[i][0]=dp[i-1][0]+(seats[i][0]=='.');
    for(int j=1;j<c;j++)
        dp[0][j]=dp[0][j-1]+(seats[0][j]=='.');

    for(int i=1;i<r;i++)
        for(int j=1;j<c;j++)
            dp[i][j]=dp[i-1][j]+dp[i][j-1]+dp[i-1][j-1]+(seats[i][j]=='.');

    vector<rect> vi;
    vi.pb(rectangle(-1,-1,0));
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            vi.pb(rectangle(i,j,dp[i][j]));

    sort(vi.begin(),vi.end(),comp);
    int ans=1e9;
    int i=r*c,j=r*c;
    while(i>=0&&j>=0){
        int temp=vi[j].count-vi[i].count;
        if(temp>=k){
            ans=min(ans,(vi[j].l-vi[i].l)*(vi[j].b-vi[i].b));
            j--;
        }
        else i--;
    }
    printf("%d\n",ans);
}
