#include<bits/stdc++.h>
using namespace std;

int const N=50001;
int n;

#define nd struct node

struct node{
    int sum,max_prefix,max_suffix,max_subarray;
    node(int a=0,int b=-1e9,int c=-1e9,int d=-1e9){
        sum=a,max_prefix=b,max_suffix=c,max_subarray=d;
    }
};

nd t[2*N];

nd combine(nd node1,nd node2){
    int sum=node1.sum+node2.sum;
    int max_prefix=max(node1.max_prefix,node1.sum+node2.max_prefix);
    int max_suffix=max(node1.max_suffix+node2.sum,node2.max_suffix);
    int max_subarray=max(max(node1.max_subarray,node2.max_subarray),node1.max_suffix+node2.max_prefix);
    return node(sum,max_prefix,max_suffix,max_subarray);
}

void build(){
    for(int i=n-1;i>0;--i)t[i]=combine(t[i<<1],t[i<<1|1]);
}

int query(int l,int r){
    l+=n,r+=n;
    nd left_node=node(),right_node=node();
    for(;l<r;l>>=1,r>>=1){
        if(l&1)left_node=combine(left_node,t[l++]);
        if(r&1)right_node=combine(t[--r],right_node);
    }
    nd ans=combine(left_node,right_node);
    return ans.max_subarray;
}

void update(int pos,int val){
    pos+=n;
    t[pos]=node(val,val,val,val);
    for(;pos>1;pos>>=1)
        if(pos&1)t[pos>>1]=combine(t[pos^1],t[pos]);
        else t[pos>>1]=combine(t[pos],t[pos^1]);
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int temp;scanf("%d",&temp);
        t[n+i]=node(temp,temp,temp,temp);
    }
    build();
    int q;cin>>q;
    while(q--){
        int x,l,r;scanf("%d %d %d",&x,&l,&r);
        if(x==0)update(--l,r);
        else printf("%d\n",query(--l,r));
    }
}
