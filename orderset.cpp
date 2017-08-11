#include<bits/stdc++.h>

using namespace std;
 
int const N = 200005;

struct Query{
    char type;
    int x;
    Query(char c, int a){
        type = c;
        x = a;
    }
};

unordered_map<int,int> compress,decompress;
vector<Query> queries;
set<int> v;
int BIT[N];
 
void update(int idx, int x){
     for(; idx < N; idx += idx&-idx)
        BIT[idx] += x;
}
 
int query(int idx){
    int ans = 0;
    for(; idx > 0; idx -= idx&-idx)
        ans+=BIT[idx];
    return ans;
}

int search(int l,int r,int x){
    if(l == r)return l;
    int mid = (l+r)>>1;
    if(query(mid) < x)
        search(mid+1,r,x);
    else
        search(l,mid,x);
}

int main(){
    int q;scanf("%d",&q);
    while(q--){
        char c;
        int x;
        cin>>c>>x; 
        queries.push_back(Query(c,x));
        v.insert(x);
    }
    int i = 1;
    for(auto it = v.begin(); it !=v.end(); it++){
        compress[*it] = i;
        decompress[i++] = *it;
    }
 
    memset(BIT,0,sizeof BIT);
    for(int i=0;i<queries.size();i++){
        char c = queries[i].type;
        int x = queries[i].x;
        switch (c){
            case 'I':
                if(query(compress[x]) - query(compress[x] -1) == 0)
                    update(compress[x],1);
                break;
            case 'D':
                if(query(compress[x]) - query(compress[x] -1) == 1)
                    update(compress[x],-1);
                break;
            case 'K':
                if(query(N-1) < x)
                    printf("invalid\n");
                else
                    printf("%d\n",decompress[search(1,N-1,x)]);
                break;
            case 'C':
                printf("%d\n",query(compress[x]-1));
                break;
        }
        //cout<<query(N-1)<<"**"<<endl;
    }
}
