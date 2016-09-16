#include<bits/stdc++.h>
using namespace std;

struct Query{
    int first;
    int second;
    int idx;
    Query(){
    }
    Query (int a,int b,int c){
        first=a;
        second=b;
        idx=c;
    }
};

int n,sqrt_n,temp;
int Count[1000100];

bool comp(struct Query pair1,struct Query pair2){
    if(pair1.first/sqrt_n < pair2.first/sqrt_n) return 1;
    else if (pair1.first/sqrt_n > pair2.first/sqrt_n) return 0;
    else return (pair1.second < pair2.second);
}

void add(int a){
    Count[a]++;
    if(Count[a]==1)temp++;
}

void del(int a){
    Count[a]--;
    if(Count[a]==0)temp--;
}

int main(){
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);
    sqrt_n=floor(sqrt(n));
    int q;cin>>q;
    struct Query queries[q];
    struct Query queryIndex[q];
    int ans[q];
    for(int i=0;i<q;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        l--;
        queryIndex[i]=Query(l,r,i);
        queries[i]=Query(l,r,i);
    }

    sort(queries,queries+q,comp);
    
    //for(int i=0;i<q;i++){
    //    cout<<queries[i].first<<" "<<queries[i].second<<endl;
    //}

    for(int i=0;i<n;i++)
        Count[i]=0;

    temp=0;
    
    int l=0,r=0;
    
    for(int i=0;i<q;i++){
        while(l<queries[i].first){
            del(A[l]);
            l++;
        }

        while(l>queries[i].first){
            l--;
            add(A[l]);
        }

        while(r>queries[i].second){
            r--;
            del(A[r]);
        }

        while(r<queries[i].second){
            add(A[r]);
            r++;
        }

        ans[queries[i].idx]=temp;
    }

    for(int i=0;i<q;i++)
        printf("%d\n",ans[i]);

}
