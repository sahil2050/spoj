/*Author : Sahil Aggarwal
 * Topic : Suffix Array
 * Problem : spoj/SARRAY
 */

#include<iostream>
#include<cstring>
using namespace std;

int const N=1e5+10;
char T[N];
int n,C[N],RA[N],tempRA[N],SA[N],tempSA[N];

void counting_sort(int k){
    memset(C,0,sizeof(C));
    for(int i=0;i<n;i++)C[i+k<n ? RA[i+k] : 0]++;
    int sum=0;
    for(int i=0;i<max(n,300);i++){
        int temp=C[i];
        C[i]=sum;
        sum+=temp;
    }
    for(int i=0;i<n;i++)tempSA[C[SA[i]+k<n ? RA[SA[i]+k] : 0]++]=SA[i];
    for(int i=0;i<n;i++)SA[i]=tempSA[i];
}

void constructSA(){
    for(int i=0;i<n;i++)RA[i]=T[i],SA[i]=i;
    for(int k=1;k<n;k<<=1){
        counting_sort(k);
        counting_sort(0);
        int r=0;
        tempRA[SA[0]]=r;
        for(int i=1;i<n;i++)
            tempRA[SA[i]]=(RA[SA[i-1]]==RA[SA[i]] && RA[SA[i]+k]==RA[SA[i-1]+k]) ? r : ++r;
        for(int i=0;i<n;i++)RA[i]=tempRA[i];
        if(RA[SA[n-1]]==n-1)break;
    }
}

int main(){
    scanf("%s",T);
    n=(int)strlen(T);
    constructSA();
    for(int i=0;i<n;i++)printf("%d\n",SA[i]);
}
