#include<bits/stdc++.h>
using namespace std;

#define dd double
dd powi(dd base,int exp) {
    if(exp==0)return 1.0;
    dd tmp=powi(base,exp>>1);
    if(exp&1)return tmp*tmp*base;
    else return tmp*tmp;
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        dd p;int n,m;
        scanf("%lf %d %d",&p,&n,&m);
        dd ans=0;
        for(int i=1;i<m;i++)
            ans+=(dd)n*powi(1-pow(p,i),n-1)*powi(p,i);
        printf("%.4lf\n",ans);
    }
}
