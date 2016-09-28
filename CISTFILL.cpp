#include<bits/stdc++.h>
using namespace std;

int const N=5e4;
double rect[N][4],V;
int n;

double F(double x){
    double V_Sum=0;
    for(int i=0;i<n;i++){
        double h=max(min(x,rect[i][1]+rect[i][0])-rect[i][0],(double)0);
        V_Sum+=rect[i][2]*rect[i][3]*h;
    }
    return(V_Sum-V);
}

double binary_search(double l,double r){
    if(r-l<1e-9)return l;
    double mid=(l+r)/2;
    double temp=F(mid);
    if(abs(temp)<1e-9)return binary_search(l,mid);
    else if(temp<0)binary_search(mid,r);
    else binary_search(l,mid);
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        double V_Sum=0;
        for(int i=0;i<n;i++){
            scanf("%lf %lf %lf %lf",&rect[i][0],&rect[i][1],&rect[i][2],&rect[i][3]);
            V_Sum+=rect[i][1]*rect[i][2]*rect[i][3];
        }
        scanf("%lf",&V);
        if(V_Sum<V){
            printf("OVERFLOW\n");
            continue;
        }
        printf("%.2lf\n",binary_search((double)0,1e8));
    }
}
