#include<bits/stdc++.h>
#define pb push_back
using namespace std;
double const eps=1e-9;

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
    long long operator ^(point other)const{ //cross
        return (long long)(x*other.y-y*other.x);
    }
    int operator *(point other)const{
        return x*other.x+y*other.y;
    } 
};

long long cross(point p1,point p2){
    return (p1^p2);
}

struct segment{
    point a,b;
    segment(){};
    segment(point p1,point p2){
        a=p1,b=p2;
    }
};

void print(segment s){
    point a=s.a,b=s.b;
    cout<<a.x<<" "<<a.y<<endl;
    cout<<b.x<<" "<<b.y<<endl;
}

point pivot;

bool angleComp(point p1,point p2){
    p1=p1-pivot,p2=p2-pivot;
    if((p1 ^ p2) != 0)return (p1 ^ p2) > 0;
    else return (p1*p1) < (p2*p2);
}

double angle(point p1,point p2){
    return acos(((double)(p1*p2))/(sqrt(p1*p1)*sqrt(p2*p2)));
}

bool onSegment(point p,segment s){
    point a=s.a,b=s.b;
    if(((a-p)^(b-p))==0)
            return (p.x >= min(a.x,b.x) && p.x <= max(a.x,b.x));
    else return 0;
}

bool intersect(segment s1,segment s2){
    //print(s1);
    //print(s2);
    //cout<<cross(s1.a-s2.a,s1.b-s2.a)<<" "<<cross(s1.a-s2.b,s1.b-s2.b)<<" "<<cross(s2.a-s1.a,s2.b-s1.a)<<" "<<cross(s2.a-s1.b,s2.b-s1.b)<<endl;
    if(onSegment(s1.a,s2))return 1;
    if(onSegment(s1.b,s2))return 1;
    if(onSegment(s2.a,s1))return 1;
    if(onSegment(s2.b,s1))return 1;
    return ((cross(s1.a-s2.a,s1.b-s2.a)*cross(s1.a-s2.b,s1.b-s2.b)) < 0) && ((cross(s2.a-s1.a,s2.b-s1.a)*cross(s2.a-s1.b,s2.b-s1.b)) < 0);
}

bool isInside(vector<point> poly, point p){
    int n=poly.size();
    if(n<3)return 0;
    if(n==3){
        return onSegment(p,segment(poly[0],poly[1]));
    }
    for(int i=1;i<n;i++){
        if(onSegment(p,segment(poly[i-1],poly[i])))return 1;
        if(((poly[i-1]-p) ^ (poly[i]-p)) == 0)return 0;
        if(i!=n-1 && cross(poly[i-1]-p,poly[i]-p)*(cross(poly[i-1]-poly[i+1],poly[i]-poly[i+1])) < 0)return 0;
        if(i==n-1 && cross(poly[i-1]-p,poly[i]-p)*(cross(poly[i-1]-poly[1],poly[i]-poly[1])) < 0)return 0;
    }
    //cout<<fabs(fabs(sum)-2*M_PI)<<endl;
    return 1;
}

vector<point> ConvexHull(vector<point> & S){
    int n=S.size();
    sort(S.begin(),S.end());
    if(n<=3){
        S.pb(S[0]);return S;
    }
    pivot=S[0];
    sort(++S.begin(),S.end(),angleComp);
    vector<point> CH;
    CH.pb(S[n-1]);
    CH.pb(S[0]);
    CH.pb(S[1]);
    for(int i=2;i<n;){
        int j=CH.size()-1;
        if(((CH[j]-CH[j-1]) ^ (S[i]-CH[j])) > 0)CH.pb(S[i++]);
        else CH.pop_back();
    }
    return CH;
}

int main(){
    int n,m;scanf("%d %d",&n,&m);
    if(n==0 && m==0)return 0;
    vector<point> SW,SB;
    for(int i=0;i<n;i++){
        int x,y;scanf("%d %d",&x,&y);
        SB.pb(point(x,y));
    }
    for(int i=0;i<m;i++){
        int x,y;scanf("%d %d",&x,&y);
        SW.pb(point(x,y));
    }
    if(n==1 && m==1){
        printf("YES\n");
        return main();
    }
    vector<point> HB=ConvexHull(SB);
    vector<point> HW=ConvexHull(SW);
    /*cout<<"HB"<<endl;
    for(int i=0;i<HB.size();i++)cout<<HB[i].x<<" "<<HB[i].y<<endl;
    cout<<"HW"<<endl;
    for(int i=0;i<HB.size();i++)cout<<HW[i].x<<" "<<HW[i].y<<endl;
    */
    for(int i=1;i<HB.size();i++){
        segment s1(HB[i-1],HB[i]);
        for(int j=1;j<HW.size();j++){
            segment s2(HW[j-1],HW[j]);
            if(intersect(s1,s2)){
                printf("NO\n");
                return main();
            }
        }
    }

    if(isInside(HW,HB[0]) || isInside(HB,HW[0])){
        printf("NO\n");
        return main();
    }

    printf("YES\n");
    return main();
}
