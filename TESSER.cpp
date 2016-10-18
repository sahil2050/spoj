/*Author : Sahil Aggarwal
 *Problem Type : kmp
 *Problem Name : TESSER
 */

#include<iostream>
#include<cstring>
using namespace std;

int const N=1e5+10;
int n,m,A[N],prefix[N];
char T[N],P[N];

void compute_prefix(){
    int k=prefix[0]=-1;
    for(int i=1;i<m;i++){
        while(k>=0 && P[k+1]!=P[i])
            k=prefix[k];
        if(P[k+1]==P[i])k++;
        prefix[i]=k;
    }
}

bool kmp(){
    m=(int)strlen(P);
    compute_prefix();
    int q=-1;
    for(int i=0;i<n;i++){
        while(q>=0 && T[i]!=P[q+1])
            q=prefix[q];
        if(T[i]==P[q+1])q++;
        if(q==m-1)return 1;
    }
    return 0;
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&A[i]);
        for(int i=0;i<n-1;i++){
            if(A[i+1]>A[i])T[i]='G';
            else if(A[i+1]<A[i])T[i]='L';
            else T[i]='E';
        }
        n--;
        scanf("%s",P);
        bool x=kmp();
        if(x)printf("YES\n");
        else printf("NO\n");
    }
}
