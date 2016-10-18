#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
int const N=1e6+10;
int n,m,prefix[N];
char T[N],P[N];

void comp_prefix(){
    int k=-1;
    prefix[0]=-1;
    for(int i=1;i<m;i++){
        while(k>=0 && P[i]!=P[k+1])
            k=prefix[k];
        if(P[i]==P[k+1])k++;
        prefix[i]=k;
    }
}

vi kmp(){
    comp_prefix();
    int q=-1;
    vi ans;
    for(int i=0;i<n;i++){
        while(q>=0 && P[q+1]!=T[i])
            q=prefix[q];
        if(P[q+1]==T[i])q++;
        if(q==m-1){
            ans.push_back(i-m+1);
            q=prefix[q];
        }
    }
    return ans;
}

int main(){
    while(scanf("%d",&m)!=EOF){
        scanf("%s",P);
        scanf("%s",T);
        n=(int)strlen(T);
        vi ans=kmp();
        for(int i=0;i<ans.size();i++)printf("%d\n",ans[i]);
        printf("\n");
    }
}
