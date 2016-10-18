#include<bits/stdc++.h>
using namespace std;

int const N=1e6+10;
int n,prefix[N];
char P[N];

inline void preprocess(){
    int k=prefix[0]=-1;
    for(int i=1;i<n;i++){
        while(k>=0 && P[i]!=P[k+1])k=prefix[k];
        if(P[i]==P[k+1])k++;
        prefix[i]=k;
    }
}

int main(){
    int t;scanf("%d",&t);
    for(int T=1;T<=t;T++){
        scanf("%d",&n);
        scanf("%s",P);
        preprocess();
        printf("Test case #%d\n",T);
        for(int i=0;i<n;i++){
            int period=(i+1)%(i-prefix[i])==0 ? (i+1)/(i-prefix[i]) : 1;
            if(period>1)printf("%d %d\n",i+1,period);
        }
        printf("\n");
    }
}
