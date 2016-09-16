#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        if(n==0){
            cout<<10<<endl;
            continue;
        }
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        int freq[10];
        for(int i=0;i<10;i++)
            freq[i]=0;
        for(int k=9;k>=2;k--)
            while(n%k==0){
                n/=k;
                freq[k]++;
            }
        if(n!=1)cout<<-1<<endl;
        else{
            for(int k=2;k<10;k++)
                for(int i=0;i<freq[k];i++)
                    cout<<k;
            cout<<endl;
        }
    }
}
