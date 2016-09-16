#include<bits/stdc++.h>
using namespace std;

int main(){
    int i=0;
    string s;
    getline(cin,s);
    map<string,int> packages;
    while(s!=EOF){
        vector<string> tokens;
        string token="";
        for(int i=0;i<s.length();i++){
            if(s[i]!=' ')
                token.push_back(s[i]);
            else{
                if(token.length()>0)
                    tokens.push_back(token);
                token="";
            }
        }
        
    }
}
