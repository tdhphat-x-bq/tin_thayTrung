#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;

string st,s="",t="";

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("keylogger.inp","r",stdin);
    //freopen("keylogger.out","w",stdout);
    cin>>st;
    for(char c:st){
        if(c == '<'){
            if(!s.empty()){
                char x = s.back();
                t += x;
                s.pop_back();
            }
        }else if(c == '>'){
            if(!t.empty()){
                s+=t.back();
                t.pop_back();
            }
        }else if(c == '-'){
            if(!s.empty()){
                s.pop_back();
            }
        }
        else{
            s+=c;
        }
    }
    if(!t.empty()){
        reverse(t.begin(),t.end());
        s+=t;
    }
    cout<<s;
}
