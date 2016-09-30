#include<bits/stdc++.h>
#define pb push_back
using namespace std;

struct point{
    int x,y;
    point(int a=0,int b=0){
        x=a,y=b;
    }
    bool operator ==(point other)const{
        return x==other.x && y==other.y;
    }
    bool operator <(point other)const{
        return y<other.y || (y==other.y && x<other.x);
    }
    point operator -(point other)const{
        return point(x-other.x,y-other.y);
    }
    int operator ^(point other)const{ //cross
        return x*other.y-y*other.x;
    }
    int operator *(point other)const{
        return x*other.x+y*other.y;
    } 
};

point pivot;

bool angleComp(point p1,point p2){
    p1=p1-pivot,p2=p2-pivot;
    if((p1 ^ p2) != 0)return (p1 ^ p2) >0;
    else return (p1*p1) < (p2*p2);
}

int Solve(vector<point> &S){
    int n=S.size();
    if(n<3)return 0;
    if(n==3)return 1;
    sort(S.begin(),S.end());
    pivot=S[0];
    //for(int i=0;i<n;i++)cout<<S[i].x<<"%%"<<S[i].y<<endl;
    sort(++S.begin(),S.end(),angleComp);
    //for(int i=0;i<n;i++)cout<<S[i].x<<"##"<<S[i].y<<endl;
    vector<point> CH,S1;
    CH.pb(S[n-1]);
    CH.pb(S[0]);
    CH.pb(S[1]);
    for(int i=2;i<n;){
        int j=CH.size()-1;
        if(((CH[j]-CH[j-1]) ^ (S[i]-CH[j])) > 0)CH.pb(S[i++]);
        else {
            S1.pb(CH[j]);
            CH.pop_back();
        }
    }
    return 1+Solve(S1);
}

int main(){
    int n;scanf("%d",&n);
    vector<point> S;
    for(int i=0;i<n;i++){
        int x,y;scanf("%d %d",&x,&y);
        S.pb(point(x,y));
    }
    printf("%d\n",Solve(S));
}
