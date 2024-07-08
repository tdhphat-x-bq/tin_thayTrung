#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;


main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("strdel.inp","r",stdin);
    freopen("strdel.out","w",stdout);
    int t;cin>>t;
    while(t--){
        string s;cin>>s;

        stack<char>st;
        for(int i=1;i<=s.size();i++){
            string t="";
            t=s[i-1]+t;
            if(!st.empty()) t=st.top()+t;
            if(t == "AB" or t == "BB"){
                st.pop();
            }else st.push(s[i-1]);

        }
        cout<<st.size()<<endl;
    }
}
