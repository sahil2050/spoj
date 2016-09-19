#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define sq struct query
typedef pair<int,int> ii;

int n;
int sqrt_N;

struct query{
    int l,r,p,ans;
    query(){}
    query(int a,int b,int c){
        l=a,r=b,p=c;
    }
};

bool comp(sq q1,sq q2){
    if(q1.l/sqrt_N < q2.l/sqrt_N)return 1;
    else if(q1.l<sqrt_N < q2.l/sqrt_N)return 0;
    else return (q1.r < q2.r);
}

int main(){
    cin>>n;
    if(n==0)return 0;
    int q;cin>>q;
    sqrt_N=floor(sqrt(n));
    int A[n];
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    sq queries[q];

    for(int i=0;i<q;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        queries[i]=query(--l,r,i);
    }

    sort(queries,queries+q,comp);
    map<int,int> freq_map; //maps int -> freq
    set<ii> S; //first -> freq second-> val
    int l=0,r=0;
    map<int,int>::iterator it;
    set<ii>::iterator It;

    cout<<"**"<<endl;
    
    for(int i=0;i<q;i++){
        while(l<queries[i].l){
            cout<<"#1"<<endl;
            it=freq_map.find(A[l]);
            if(it!=freq_map.end()){
               It=S.find(*it);
               if(It!=S.end()){
                   S.erase(It);
                   S.insert(make_pair(it->ss-1,it->ff));
               }
               else
                   S.insert(make_pair(-1,A[l]));
               it->ss--;
            }
            else{
                freq_map[A[l]]=-1;
                S.insert(make_pair(-1,A[l]));
            }
            l++;
        }
        while(l>queries[i].l){
            cout<<"#2"<<endl;
            --l;
            it=freq_map.find(A[l]);
            if(it!=freq_map.end()){
                It=S.find(*it);
                if(It!=S.end()){
                    S.erase(It);
                    S.insert(make_pair(it->ss+1,it->ff));
                }
                else
                    S.insert(make_pair(1,A[l]));
                it->ss++;
                }
            else{
                freq_map[A[l]]=1;
                S.insert(make_pair(1,A[l]));
            }
        }
        while(r<queries[i].r){
            cout<<"#3"<<endl;
            it=freq_map.find(A[r]);
            if(it!=freq_map.end()){
                It=S.find(*it);
                if(It!=S.end()){
                    S.erase(It);
                    S.insert(make_pair(it->ss+1,it->ff));
                }
                else
                    S.insert(make_pair(1,A[r]));
                it->ss++;
            }
            else{
                freq_map[A[r]]=1;
                S.insert(make_pair(1,A[r]));
            }
            r++;
        }
        while(r>queries[i].r){
            cout<<"#4"<<endl;
            r--;
            it=freq_map.find(A[l]);
            if(it!=freq_map.end()){
                It=S.find(*it);
                if(It!=S.end()){
                    S.erase(It);
                    S.insert(make_pair(it->ss-1,it->ff));
                    it->ss--;
                }
                else
                    S.insert(make_pair(-1,A[r]));
                it->ss--;
            }
            else{
                freq_map[A[r]]=-1;
                S.insert(make_pair(-1,A[r]));
            }
        }
        queries[i].ans=(--S.end())->ff;
     }
    cout<<" Done! "<<endl;
    vector<int> retval(q);
    for(int i=0;i<q;i++){
        retval[queries[i].p]=queries[i].ans;
    }
    for(int i=0;i<q;i++)
        printf("%d\n",retval[i]);
    return main();
}
