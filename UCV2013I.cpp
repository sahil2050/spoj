#include<bits/stdc++.h>
using namespace std;

int main(){
    double n,r;
    scanf("%lf %lf",&r,&n);
    if(n*r==0)return 0;
    double ans=r/sin(M_PI/(2*n));
    printf("%.2lf\n",ans);
    return main();
}
