#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

double inf=10000000000000.0;

int main(){
    int m;cin>>m;
    if(m==0)return 0;

    double p[m],a[m];
    double discount[m][m];

    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            discount[i][j]=0;
    
    for(int i=0;i<m;i++){
        int n_i;
        cin>>p[i]>>a[i]>>n_i;
        for(int j=0;j<n_i;j++){
            int x;
            double y;
            cin>>x>>y;
            x--;
            discount[i][x]=y;
        }
    }

    double dp[(1<<m)][m];
    for(int i=0;i<m;i++)
        dp[0][i]=0.0;

    for(int mask=1;mask<(1<<m);mask++){
        for(int i=0;i<m;i++){
            dp[mask][i]=inf;
            if(mask==(1<<i))
                dp[mask][i]=p[i];
            if(mask&(1<<i)){
                double temp=p[i];
                for(int k=0;k<m;k++)
                    if(((1<<k)&mask)&&(k!=i))
                        temp*=(1.0-discount[k][i]/100);
                for(int j=0;j<m;j++)
                    if((mask&(1<<j))&&(j!=i)){
                        dp[mask][i]=min(dp[mask][i],dp[mask-(1<<i)][j]+temp);
                    }
            }
        }
    }

    /*
    for(int mask=1;mask<(1<<m);mask++){
        for(int i=0;i<m;i++){
            cout<<dp[mask][i]<<" ";
        }
        cout<<endl;
    }
    */
    double ans=inf;
    for(int mask=1;mask<(1<<m);mask++){
        double area=0;
        for(int k=0;k<m;k++)
            if(mask&(1<<k))
                area+=a[k];
        for(int i=0;i<m;i++){
            //cout<<mask<<" "<<area<<" "<<dp[mask][i]/area<<endl;
            if(mask&(1<<i))
                ans=min(ans,dp[mask][i]/area);
        }
    }
    cout<<setprecision(4)<<fixed<<ans<<endl;
    return main();
}
