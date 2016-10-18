#include<bits/stdc++.h>
using namespace std;

int const N=1e5+10;
int n,prefix[N];
char P[N];

void preprocess(){
    int k=-1;
    prefix[0]=-1;
    for(int i=1;i<n;i++){
        while(k>=0 && P[i]!=P[k+1])
            k=prefix[k];
        if(P[i]==P[k+1])k++;
        prefix[i]=k;
    }
}

int main(){
    scanf("%s",P);
    if(P[0]=='*')return 0;
    n=(int)strlen(P);
    preprocess();
    int ans=n%(n-1-prefix[n-1])==0 ? n/(n-1-prefix[n-1]) : 1;
    printf("%d\n",ans);
    return main();
}
