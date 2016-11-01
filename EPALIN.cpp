#include<bits/stdc++.h>
using namespace std;

int const N=2e5+10;
char P[N],T[N];
int prefix[N],n;

void preprocess(){
    int k=prefix[0]=-1;
    for(int i=1;i<n;i++){
        while(k>=0 && P[i]!=P[k+1])k=prefix[k];
        if(P[i]==P[k+1])k++;
        prefix[i]=k;
    }
}

int main(){
    while(scanf("%s",T)!=EOF){
        int j=0;
        for(int i=strlen(T)-1;i>=0;i--)P[j++]=T[i];
        P[j++]='$';
        for(int i=0;i<strlen(T);i++)P[j++]=T[i];
        n=j;
        preprocess();
        j=strlen(T);
        int maxi=strlen(T)-1-prefix[n-1];
        for(int i=maxi-1;i>=0;i--)T[j++]=T[i];
        for(int i=0;i<j;i++)printf("%c",T[i]);
        printf("\n");
    }
}
