#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

bool comp(ii P1,ii P2){
    if(P1.first!=P2.first)return P1.first<P2.first;
    else return P1.second>P2.second;
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        ii dolls[n];
        for(int i=0;i<n;i++){
            int x,y;scanf("%d %d",&x,&y);
            dolls[i]=ii(x,y);
        }
        sort(dolls,dolls+n,comp);
        multiset<int> s;
        s.insert(dolls[0].second);
        for(int i=1;i<n;i++){
            s.insert(dolls[i].second);
            multiset<int>::iterator it=s.lower_bound(dolls[i].second);
            if(it!=s.begin()){
                it--;
                s.erase(it);
            }
        }
        printf("%d\n",(int)s.size());
    }
}
