#include<bits/stdc++.h>
#define pb push_back
using namespace std;

struct point{
    int x,y;
    point(int a=0,int b=0){
        x=a,y=b;
    }
    point operator -(point other)const {
        return point(x-other.x,y-other.y);
    }
    bool operator ==(point other) const{
        return abs(x-other.x)==0 && abs(y-other.y)==0;
    }
    bool operator <(point other) const{
        return y<other.y || (y==other.y && x<other.x);
    }
};

double dot(point p){
    return p.x*p.x+p.y*p.y;
}

double dist(point p1,point p2){
    return sqrt(dot(p1-p2));
}

double cross(point p1,point p2){ //vec joining origin to p1 & p2
    return (p1.x*p2.y-p2.x*p1.y);
}

bool ccw(point p1,point p2,point p3){
    return cross(p2-p1,p3-p2)>=0;
}

point pivot;

double perimeter(vector<point> &polygon){
    double ans=0;
    for(int i=0;i<polygon.size()-1;i++)
        ans+=dist(polygon[i],polygon[i+1]);
    return ans;
}

bool angleComp(point p1,point p2){
    point d1=p1-pivot,d2=p2-pivot;
    if(cross(d1,d2)==0)return dist(pivot,p1)<dist(pivot,p2);
    return atan2(d1.y,d1.x)<atan2(d2.y,d2.x);
}

vector<point> convexHull(vector<point> &S){
    int n=S.size(),idx=0;               
    if(n<=1)return S;
    for(int i=1;i<n;i++)
        if(S[i].y<S[idx].y||(S[i].y==S[idx].y && S[i].x<S[idx].x))idx=i;
    pivot=S[idx];
    S[idx]=S[0];
    S[0]=pivot;
    sort(++S.begin(),S.end(),angleComp);
    vector<point> CH;
    CH.pb(S[n-1]);
    CH.pb(S[0]);
    CH.pb(S[1]);
    for(int i=2;i<n;){
        int j=CH.size();
        if(ccw(CH[j-2],CH[j-1],S[i]))CH.pb(S[i++]);
        else CH.pop_back();
    }
    return CH;
}

int main(){
    int t;scanf("%d",&t);
    for(int T=0;T<t;T++){
        if(T!=0)printf("\n");
        int n;scanf("%d",&n);
        map<point,int> M;
        vector<point> S;
        for(int i=0;i<n;i++){
            int x,y;scanf("%d %d",&x,&y);
            point P(x,y);
            if(M.find(P)==M.end()){
                M[P]=i+1;
                S.pb(P);
            }
        }
        vector<point> CH=convexHull(S);
        printf("%.2lf\n",perimeter(CH));
        for(int i=1;i<CH.size();i++){
            if(i==CH.size()-1||i==1||abs(cross(CH[i]-CH[i-1],CH[i+1]-CH[i]))>0)
                printf(i==1?"%d":" %d",M.find(CH[i])->second);
        }
        if(CH.size()==1)printf("1");
        printf("\n");
    }
}
