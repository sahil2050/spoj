#include<bits/stdc++.h>
using namespace std;
#define node struct TreeNode

struct TreeNode{
    int mode,mode_freq,left,left_freq,right,right_freq;
    TreeNode(int a=0,int b=0,int c=0,int d=0,int e=0,int f=0){
        mode=a,mode_freq=b,left=c,left_freq=d,right=e,right_freq=f;
    }
};

int const N=1e5;
node t[2*N];
int n,q;

node combine(node left_node,node right_node){
    node ans=TreeNode();
    ans.left=left_node.left,ans.right=right_node.right;
    if(left_node.right==right_node.left){
        int mid_freq=left_node.right_freq+right_node.left_freq;
        if(mid_freq==max(max(mid_freq,left_node.mode_freq),right_node.mode_freq)){
            ans.mode=left_node.right,ans.mode_freq=mid_freq;
        }
        else if(right_node.mode_freq==max(max(mid_freq,left_node.mode_freq),right_node.mode_freq)){
            ans.mode=right_node.mode,ans.mode_freq=right_node.mode_freq;
        }
        else {
            ans.mode=left_node.mode,ans.mode_freq=left_node.mode_freq;
        }
        if(left_node.left==left_node.right)ans.left_freq=left_node.left_freq+right_node.left_freq;
        else ans.left_freq=left_node.left_freq;
        if(right_node.left==right_node.right)ans.right_freq=left_node.right_freq+right_node.right_freq;
        else ans.right_freq=right_node.right_freq;
    }
    else{
        if(left_node.mode_freq==max(left_node.mode_freq,right_node.mode_freq)){
            ans.mode=left_node.mode,ans.mode_freq=left_node.mode_freq;
        }
        else{
            ans.mode=right_node.mode,ans.mode_freq=right_node.mode_freq;
        }
        ans.left_freq=left_node.left_freq;
        ans.right_freq=right_node.right_freq;
    }
    return ans;
}

void build(){
    for(int i=n-1;i>0;i--)t[i]=combine(t[i<<1],t[i<<1|1]);
}

node query(int l,int r){
    l+=n,r+=n;
    node left_node=TreeNode(),right_node=TreeNode();
    for(;l<r;l>>=1,r>>=1){
        if(l&1)left_node=combine(left_node,t[l++]);
        if(r&1)right_node=combine(t[--r],right_node);
    }
    return combine(left_node,right_node);
}

int main(){
    scanf("%d",&n);if(n==0)return 0;
    scanf("%d",&q);
    for(int i=0;i<n;i++){
        int temp;scanf("%d",&temp);
        t[i+n]=TreeNode(temp,1,temp,1,temp,1);
    }
    build();
    while(q--){
        int l,r;scanf("%d %d",&l,&r);
        printf("%d\n",query(--l,r).mode_freq);
    }
    return main();
}
