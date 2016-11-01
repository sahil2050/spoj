/* Author : Sahil Aggarwal
 * topic : Suffix Array 
 * probem name : MINMOVE
 */
#include<bits/stdc++.h>
using namespace std;

int const N=2e5+10;
char T[N];
int SA[N],tempSA[N],RA[N],tempRA[N],C[N],n;

void count_sort(int k){
    memset(C,0,sizeof(C));
    for(int i=0;i<n;i++)C[i+k<n ? RA[i+k] : 0]++;
    int sum=0;
    for(int i=0;i<max(300,n);i++){
        int temp=C[i];
        C[i]=sum;
        sum+=temp;
    }
    for(int i=0;i<n;i++)
        tempSA[C[SA[i]+k<n ? RA[SA[i]+k] : 0]++]=SA[i];
    for(int i=0;i<n;i++)SA[i]=tempSA[i];
}

void constructSA(){
    for(int i=0;i<n;i++)RA[i]=T[i],SA[i]=i;
    for(int k=1;k<n;k<<=1){
        count_sort(k);
        count_sort(0);
        int r=0;
        tempRA[SA[0]]=r;
        for(int i=0;i<n;i++)
            tempRA[SA[i]]=(RA[SA[i]]==RA[SA[i-1]] && RA[SA[i]+k]==RA[SA[i-1]+k]) ? r : ++r;
        for(int i=0;i<n;i++)
            RA[i]=tempRA[i];
    }
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%s",T);
        n=strlen(T);
        int j=n;
        for(int i=0;i<n-1;i++)T[j++]=T[i];
        T[j++]='{';
        n=j;
        constructSA();
        for(int i=0;i<n;i++){
            if(SA[i]<=(n>>1)){
                printf("%d\n",SA[i]+1);
                break;
            }
        }
    }
}